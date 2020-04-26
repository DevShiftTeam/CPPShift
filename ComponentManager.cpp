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

#include "ComponentManager.h"

int ComponentManager::start(std::string component_name, ECRunType type) {
    switch (type) {
        case ECRunType::COMPONENT:
            break;
        case ECRunType::THREAD:
            // TODO: Open Thread & run component
            break;
        case ECRunType::PROCESS:
            // TODO: Create component in shared memory for IPC
            // TODO: Start child process
            // TODO: Child process loads shared component
            break;
    }
    return 0;
}

void ComponentManager::destroy(std::string component_name) {

}