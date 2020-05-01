

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
#include <computer/science/LoggingService.hpp>
#include <computer/science/pluralsight/mocking/APIKEy.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbRepository.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp>
#include <computer/science/pluralsight/mocking/RestApiClient.hpp>
#include <computer/science/pluralsight/mocking/MetaDataProcessor.hpp>

using namespace computer::science;
using namespace computer::science::pluralsight;
using namespace computer::science::pluralsight::mocking;

int main(int argc, char**argv)
{
    LoggingService * loggingService = new LoggingService();

    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "CPP-101: C++ Object Oriented Programming!");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), "A Few Things All Freshmen Should Know...");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),
                  "The course is current to ANSI standard C++ and is designed so that it can be taught in any environment with an ANSI C++ compiler.");
    /*
        {
            TheMovieDbDataFactory dataFactory;
            RestApiClient client;
            TheMovieDbRepository repository(MY_API_KEY, dataFactory, client);
            MetaDataProcessor processor(repository);

            Movies result;
            processor.processMovies({ "Batman Begins" }, result);

            for (auto movie : result)
            {
                std::cout << "Title: " << movie->getTitle() << std::endl;
                std::cout << "IMDB Id: " << movie->getImdbId() << std::endl << std::endl;
                std::cout << movie->getPlot() << std::endl << std::endl;
                std::cout << "Length (min.) " << movie->getLengthMin() << std::endl << std::endl;
                std::cout << "----------------------------------------" << std::endl;
            }
        }//  Scopew to guarantee that static object are destroying logger used by these object on their destruiion
     */
    if(loggingService)
    {
        delete loggingService;
        loggingService = nullptr;
    }

    return (EXIT_SUCCESS);
}

