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

#ifndef CPPSHIFT_CONFIGURATIONS_H
#define CPPSHIFT_CONFIGURATIONS_H

#include <string>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class Configurations {
public:
    explicit Configurations(std::string name);
    ~Configurations();
    std::string APP_NAME = "app";
private:
    void updateReferenceCounter(int inc);

    boost::property_tree::ptree config_data; // Configuration's tree
    boost::property_tree::ptree personal_config_data; // Personal configurations
    boost::interprocess::shared_memory_object main_config; // Shared configurations
};


#endif //CPPSHIFT_CONFIGURATIONS_H
