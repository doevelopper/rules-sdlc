

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
#include <cstdlib>

#include <rules/sdlc/std/app/Application.hpp>

// #include <boost/program_options.hpp>
// #include <rules/sdlc/std/logging/LoggingService.hpp>


// namespace po = boost::program_options;
int main(
    [[maybe_unused]] int argc,
    [[maybe_unused]] char**argv)
{
    // rules::sdlc::stdc::logging::LoggingService * loggingService = new rules::sdlc::stdc::logging::LoggingService();

    // LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "CPP-101: C++ Object Oriented Programming!");
    // LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "A Few Things All Freshmen Should Know...");
    // LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),
    //               "The course is current to ANSI standard C++ and is designed so that it can be taught in any environment with an ANSI C++ compiler.");

    // po::options_description desc("Allowed options");
    // std::vector<std::vector<std::string> > Lists(2);
    // desc.add_options()
    //     ("help", "produce help message")
    //     ("List0", po::value<vector<string> >(&Lists[0])->multitoken(), "List0.")
    //     ("List1", po::value<vector<string> >(&Lists[1])->multitoken(), "List1.")
    // ;
	// po::variables_map vm;
	// po::store(po::parse_command_line(argc, argv, desc), vm);
	// po::notify(vm); //assign the variables (if they were specified)
    // if (vm.count("help"))
    //     LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Usage: " << desc);

    // for(unsigned int list = 0; list < Lists.size(); list++)
    // {
    //     LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "List: " << list);
    //     for(unsigned int item = 0; item < Lists[list].size(); item++)
    //     {
    //         LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "List: " << list << " Opt: " << item << " " << Lists[list][item]);
    //     }
    // }

    // if(loggingService)
    // {
    //     delete loggingService;
    //     loggingService = nullptr;
    // }

    std::uint_fast64_t runStatus = 0;

    std::cout << "argc == " << argc << std::endl;

    for(int ndx{}; ndx != argc; ++ndx)
    {
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << std::endl;
    }

    std::cout << "argv[" << argc << "] == " << static_cast<void*>(argv[argc]) << std::endl;

    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
