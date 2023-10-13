/*
    SPDX-FileCopyrightText: 2020, 2022 Adrien H <rolland.doe@gmail.com>
    SPDX-FileCopyrightText: 2023 Adrien H <rolland.doe@gmail.com>
    SPDX-FileCopyrightText: 2023 Acme Systems Eng CO LTD
    SPDXVersion: SPDX-2.2
    SPDX-License-Identifier: Apache-2.0

      Copyright 2023  {{ organization }}

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

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>

#include <iomanip>
#include <iostream>
#include <sstream>

#include <cstdlib>

using namespace com::github::doevelopper::rules::sdlc::app;

/*!
 * @brief
 * @param argc number of string arguments passed via argv
 * @param argv array to command line arguments as strings
 *             (an array of character pointers)
 * @return the completion status code (zero indicates success)
 */
int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv)
{
    std::uint_fast64_t runStatus = 0;

    // std::cout << "argc == " << argc << '\n';

    // for (int ndx {}; ndx != argc; ++ndx)
    // {
    //     std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
    // }

    // std::cout << "argv[" << argc << "] == " << static_cast<void *>(argv[argc]) << '\n';

    try
    {
        Application * application = new Application();
        runStatus                 = application->start();

        if (application)
        {
            delete application;
            application = nullptr;
        }
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << "unknown exception\n";
        return (EXIT_FAILURE);
    }

    if (runStatus != EXIT_SUCCESS)
    {
        std::cerr << "FAILED!" << std::endl;
    }
    else
    {
        std::cout << "Hello, World!" << std::endl;
    }

    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
