

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

#include <com/github/doevelopper/rules/sdlc/guide/Dummy.hpp>
#include <string>

using namespace com::github::doevelopper::rules::sdlc::guide;

log4cxx::LoggerPtr Dummy::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.guide.Dummy"));

Dummy::Dummy() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::~Dummy() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Dummy::Dummy(const std::string & hello, const std::string & world)
// : m_hello{hello}
// , m_world{world}
// , m_speechless{}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // return (hello);
}

bool Dummy::speechless() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_speechless;
}
