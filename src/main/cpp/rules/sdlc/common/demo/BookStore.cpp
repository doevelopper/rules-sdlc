/*
 *      Copyright {{ year }} {{ organization }}

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing
    permissions and limitations under the License.
 */

#include <rules/sdlc/common/demo/BookStore.hpp>
#include <string>

using namespace rules::sdlc::stds::demo;

log4cxx::LoggerPtr BookStore::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stds.demo.BookStore"));

BookStore::BookStore()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

BookStore::~BookStore()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
