#ifndef SDLC_COM_CUSTOMENVIRONMENT_HPP
#define SDLC_COM_CUSTOMENVIRONMENT_HPP

#include <gtest/gtest.h>

#include <rules/sdlc/common/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::test
{
    class CustomEnvironment : public ::testing::Environment
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        CustomEnvironment();
        CustomEnvironment(const CustomEnvironment &) = delete;
        CustomEnvironment(CustomEnvironment &&) = delete;
        CustomEnvironment & operator=(const CustomEnvironment &) = delete;
        CustomEnvironment & operator=(CustomEnvironment &&) = delete;
        virtual ~CustomEnvironment();

        virtual void SetUp() override;
        virtual void TearDown() override;

    protected:
    private:
    };
}

#endif
