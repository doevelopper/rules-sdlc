

/*!
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


#include <iostream>
#include <cstdlib>
#include <std/LoggingService.hpp>

int main(int argc, char**argv)
{
    st::LoggingService * loggingService = new st::LoggingService();

    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "CPP-101: C++ Object Oriented Programming!");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "A Few Things All Freshmen Should Know...");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),
                  "The course is current to ANSI standard C++ and is designed so that it can be taught in any environment with an ANSI C++ compiler.");

    if(loggingService)
    {
        delete loggingService;
        loggingService = nullptr;
    }

    return (EXIT_SUCCESS);
}

