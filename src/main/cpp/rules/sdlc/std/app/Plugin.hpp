
#ifndef RULES_SDLC_STD_APP_PLUGIN_HPP
#define RULES_SDLC_STD_APP_PLUGIN_HPP

#include <rules/sdlc/std/app/PluginInterface.hpp>

namespace rules::sdlc::stdc::app
{
template < typename I >

class SDLC_API_EXPORT Plugin : public PluginInterface
{
    LOG4CXX_DECLARE_STATIC_LOGGER

public:
    using OptionDesc = boost::program_options::options_description;
    using OptionMap  = boost::program_options::variables_map;

    Plugin ( );
    virtual ~Plugin ( );

    virtual State state ( ) const override;
    virtual const std::string & name ( ) const override;
    virtual void initialize ( const OptionMap & options ) override;
    virtual void handleSignalHangUp ( ) override;
    virtual void startup ( ) override;
    virtual void shutdown ( ) override;
    virtual void registerPlugings ( );
    virtual void options ( OptionDesc & cli, OptionDesc & cfg );

protected:
    Plugin ( const std::string & name );

private:
    Q_DEFAULT_COPY_MOVE ( Plugin )
    std::string            m_pluginName;
    PluginInterface::State m_pluginState;
};
}

#endif
