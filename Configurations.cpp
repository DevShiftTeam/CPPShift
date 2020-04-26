/**
 * Copyright 2020-present Sapir Shemer, DevShift (devshift.com)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <boost/filesystem.hpp>
#include "Configurations.h"

Configurations::Configurations(std::string name) {
    this->APP_NAME = name;
    // Open or create main shared memory
    this->main_config = boost::interprocess::shared_memory_object(
            boost::interprocess::open_or_create,
            (this->APP_NAME + "Config").data(),
            boost::interprocess::read_write
        );
    // Find memory region of shared memory
    boost::interprocess::offset_t size = 0;
    this->main_config.get_size(size);
    boost::interprocess::mapped_region region;
    std::stringstream ss; // Stream to read the configuration's data

    // Upload application configurations from file if not present
    if(size == 0) {
        if(!boost::filesystem::exists(this->APP_NAME + ".json")) {
            std::cerr << "Couldn't find configuration file" << std::endl;
            return;
        }
        // Read configurations from JSON into string
        boost::property_tree::read_json(this->APP_NAME + ".json", this->config_data);
        this->config_data.add("ref_counter", 1);
        boost::property_tree::write_json(ss, this->config_data);

        // Upload string data to shared memory
        this->main_config.truncate(ss.str().size());
        region = boost::interprocess::mapped_region(this->main_config, boost::interprocess::read_write);
        std::memcpy(region.get_address(), ss.str().data(), ss.str().size());
    }
    else {
        // Get configuration from shared memory
        region = boost::interprocess::mapped_region(this->main_config, boost::interprocess::read_write);
        ss << static_cast<char*>(region.get_address());
        boost::property_tree::read_json(ss, this->config_data);
        this->updateReferenceCounter(1);
    }

}

Configurations::~Configurations() {
    int ref_counter = this->config_data.get<int>("ref_counter") - 1;
    if(ref_counter == 0) boost::interprocess::shared_memory_object::remove((this->APP_NAME + "Config").data());
    else this->updateReferenceCounter(-1);
}

void Configurations::updateReferenceCounter(int inc) {
    std::stringstream ss; // Stream to read the configuration's data
    int ref_counter = this->config_data.get<int>("ref_counter") + inc; // Updated value
    boost::interprocess::mapped_region region(this->main_config, boost::interprocess::read_write);
    this->config_data.put("ref_counter", ref_counter);
    // Load new ref counter data to shared memory
    boost::property_tree::write_json(ss, this->config_data);
    this->main_config.truncate(ss.str().size());
    std::memcpy(region.get_address(), ss.str().data(), ss.str().size());
}
