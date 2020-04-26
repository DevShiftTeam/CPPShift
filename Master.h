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

#ifndef CPPSHIFT_MASTER_H
#define CPPSHIFT_MASTER_H

#include <boost/interprocess/shared_memory_object.hpp>
#include "ComponentManager.h"
#include "Configurations.h"

class Master {
public:
    Master();
    ~Master();

    void switchMaster(std::string component_name);
    int run();
    void send(int cu_id, std::any& data, size_t size);
    void receive(int cu_id, std::any& data, size_t size);

private:
    std::unique_ptr<Configurations> config;
    ComponentManager componentManager;
    std::string component_key;
};


#endif //CPPSHIFT_MASTER_H
