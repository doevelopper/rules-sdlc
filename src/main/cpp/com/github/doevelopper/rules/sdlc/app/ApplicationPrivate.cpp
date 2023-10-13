
#include <com/github/doevelopper/rules/sdlc/app/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::internal;

namespace bpo = boost::program_options;
using bpo::options_description;
using bpo::variables_map;

log4cxx::LoggerPtr ApplicationPrivate::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.ApplicationPrivate"));

const unsigned long ApplicationPrivate::LOGGER_WATCH_DELAY = 100000;

ApplicationPrivate::ApplicationPrivate()
    // :  m_loggerService(100000)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::setlocale(LC_NUMERIC, "en_US");
    std::setlocale(LC_TIME, "en_US");
    /*
       std::setlocale(LC_COLLATE	);//selects the collation category of the C locale
       std::setlocale(LC_CTYPE	);//selects the character classification category of the C locale
       std::setlocale(LC_MONETARY	);//selects the monetary formatting category of the C locale
     */
}

ApplicationPrivate::~ApplicationPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_loggerService)
    {
        delete m_loggerService;
        m_loggerService = nullptr;
    }
}
