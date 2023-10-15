#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLERMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLERMOCK_HPP

#include <com/github/doevelopper/rules/sdlc/app/PluginInterface.hpp>

#include <gmock/gmock.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class QueuedHandlerMock : public ::testing::NiceMock<QueuedHandler>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        QueuedHandlerMock();
        QueuedHandlerMock(const QueuedHandlerMock &)             = delete;
        QueuedHandlerMock(QueuedHandlerMock &&)                  = delete;
        QueuedHandlerMock & operator=(const QueuedHandlerMock &) = delete;
        QueuedHandlerMock & operator=(QueuedHandlerMock &&)      = delete;
        virtual ~QueuedHandlerMock();

        MOCK_METHOD(void, execute, (), (override));

    protected:
    private:
    };
}
#endif
