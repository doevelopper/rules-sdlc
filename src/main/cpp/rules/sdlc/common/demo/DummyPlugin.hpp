#ifndef RULES_SDLC_STDC_DUMMYPLUGIN_HPP
#define RULES_SDLC_STDC_DUMMYPLUGIN_HPP

#include <forward_list>
#include <string>

#include <project/object/model/launcher/Application.hpp>

namespace rules::sdlc::stdc
{
    class POM_API_EXPORT DummyPlugin //: public project::object::model::launcher::Plugin<DummyPlugin>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        DummyPlugin();
        DummyPlugin(const DummyPlugin &) = default;
        DummyPlugin(DummyPlugin &&) = default;
        DummyPlugin & operator=(const DummyPlugin &) = default;
        DummyPlugin & operator=(DummyPlugin &&) = default;
        virtual ~DummyPlugin();

        // virtual void initialize(const OptionMap & options) override;
        // virtual void handleSignalHangUp() override;
        // virtual const std::string & name() const override;
        // virtual void startup() override;
        // virtual void options( OptionDesc & cli, OptionDesc & cfg ) override;
        // virtual void registerPlugings();
        // virtual void shutdown() override;
        // virtual State state() const override;
        /*
                virtual const std::string & name() const override;
                virtual void initialize(const OptionMap & options) override;
                virtual void handleSignalHangUp() override;
                virtual State state() const override;
                virtual void startup() override;
                virtual void shutdown() override;
                virtual void registerPlugings() override;
                virtual void options( OptionDesc & cli, OptionDesc & cfg ) override;
        */
    private:
    };
}

#endif
