

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

#include <string>
#include <computer/science/Dummy.hpp>

using namespace computer::science;

log4cxx::LoggerPtr Dummy::logger = log4cxx::Logger::getLogger(std::string("computer.science.Dummy"));

Dummy::Dummy()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::~Dummy()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::Dummy(const std::string& hello,  const std::string& world)
    : m_hello{hello}
    , m_world{world}
    , m_speechless{}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_speechless = (hello.empty() && world.empty());
}

std::string Dummy::speak() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    auto hello = m_hello;
    hello.append(" ");
    hello.append(m_world);

    return (hello);
}

bool Dummy::speechless() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_speechless;
}

