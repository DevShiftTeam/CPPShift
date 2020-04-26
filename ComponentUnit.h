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

#ifndef CPPSHIFT_COMPONENTUNIT_H
#define CPPSHIFT_COMPONENTUNIT_H

#include "ComponentTypes.h"
#include <any>
#include <boost/function.hpp>

class ComponentUnit {
public:
    boost::function<int()> start;
    boost::function<int()> run;
    boost::function<void(std::string, std::any&, size_t)> send;
    boost::function<void()> destroy;
private:
    int cu_id;
};

#endif //CPPSHIFT_COMPONENTUNIT_H
