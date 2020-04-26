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

#include "Master.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

Master::Master() {
    // Load configurations
    this->config = std::make_unique<Configurations>("app");
    this->componentManager = ComponentManager();
}

Master::~Master() {
}


void Master::switchMaster(std::string component_name) {
}

int Master::run() {
    // Run master component
    // TODO: add default component functionality
    return 0;
}

void Master::send(int runner_id, std::any &data, size_t size) {
    // Run master component
    // TODO: add default component functionality
}

void Master::receive(int runner_id, std::any &data, size_t size) {
    // Run master component
    // TODO: add default component functionality
}
