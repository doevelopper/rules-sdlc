
#ifndef RULES_SDLC_STD_LOG_CENTRALIZEDLOGGING_HPP
#define RULES_SDLC_STD_LOG_CENTRALIZEDLOGGING_HPP

#include <rules/sdlc/common/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::logging
{

    class CentralizedLogging
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        class Log4cxxHandler
        {
        public:

            virtual void log(const std::string & message) = 0;

        protected:
        private:
        };

        CentralizedLogging();
        CentralizedLogging(Log4cxxHandler & log4cxxHandler);
        CentralizedLogging(const CentralizedLogging &) = delete;
        CentralizedLogging(CentralizedLogging &&) = delete;
        CentralizedLogging & operator=(const CentralizedLogging &) = delete;
        CentralizedLogging & operator=(CentralizedLogging &&) = delete;
        virtual ~CentralizedLogging();

    protected:

        void run();
        void error(const std::exception & exception);

    private:

        Log4cxxHandler & m_log4cxxHandler;
    };

}

#endif
