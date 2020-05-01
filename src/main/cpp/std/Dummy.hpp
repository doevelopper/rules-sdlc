

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

#ifndef COMPUTER_SCIENCE_DUMMY_HPP
#define COMPUTER_SCIENCE_DUMMY_HPP

#include <computer/science/LoggingService.hpp>

namespace computer::science
{
    /*!
     * @brief The Dummy class used as walking Skeleton class for the unit, spec and feature tests of the template
     */
    class Dummy
    {
        static log4cxx::LoggerPtr logger;

        public:

            Dummy();
            /*!
             * @brief Dummy who knows how to say hello world
             * @param hello_string 'Hello' in my language
             * @param world_string 'World' in my language
             */
            Dummy(const std::string& hello_string, const std::string& world_string);
            Dummy(const Dummy&) = default;
            Dummy(Dummy&&) = default;
            Dummy& operator=(const Dummy&) = default;
            Dummy& operator=(Dummy&&) = default;
            virtual ~Dummy();

            std::string speak() const;
            bool speechless() const;

        private:

            std::string m_hello{};
            std::string m_world{};
            bool        m_speechless {true};
    };
}
#endif

