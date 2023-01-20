
#include <rules/sdlc/common/app/ApplicationPrivate.hpp>

using namespace rules::sdlc::stdc::app;

namespace bpo = boost::program_options;
using bpo::options_description;
using bpo::variables_map;

log4cxx::LoggerPtr ApplicationPrivate::logger = log4cxx::Logger::getLogger (
    std::string ( "rules.sdlc.stdc.app.ApplicationPrivate" ) );

ApplicationPrivate::ApplicationPrivate ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    std::setlocale ( LC_ALL, "en_UK.UTF-8" );
    std::setlocale ( LC_NUMERIC, "en_UK" );
    std::setlocale ( LC_TIME, "en_UK" );
    /*
       std::setlocale(LC_COLLATE	);//selects the collation category of the C locale
       std::setlocale(LC_CTYPE	);//selects the character classification category of the C locale
       std::setlocale(LC_MONETARY	);//selects the monetary formatting category of the C locale
     */
}

ApplicationPrivate::~ApplicationPrivate ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }
