
#ifndef RULES_SDLC_STD_LOG_COLORPATTERNLAYOUT_HPP
#define RULES_SDLC_STD_LOG_COLORPATTERNLAYOUT_HPP

#include <log4cxx/helpers/pool.h>
#include <log4cxx/patternlayout.h>

namespace log4cxx
{

class LOG4CXX_EXPORT ColorPatternLayout : public log4cxx::PatternLayout
{
public:
    DECLARE_LOG4CXX_OBJECT ( ColorPatternLayout )
    BEGIN_LOG4CXX_CAST_MAP ( )
    LOG4CXX_CAST_ENTRY ( ColorPatternLayout )
    LOG4CXX_CAST_ENTRY_CHAIN ( Layout )
    END_LOG4CXX_CAST_MAP ( )

    ColorPatternLayout ( );
    ColorPatternLayout ( const log4cxx::LogString & s );
    virtual void format ( log4cxx::LogString & output, const log4cxx::spi::LoggingEventPtr & event,
                 log4cxx::helpers::Pool & pool ) const override;
};

LOG4CXX_PTR_DEF ( ColorPatternLayout );
}     // namespace log4cxx

#endif
