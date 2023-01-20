

#ifndef PROJECT_OBJECT_MODEL_DUMMYTEST_HPP
#define PROJECT_OBJECT_MODEL_DUMMYTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/common/Dummy.hpp>

namespace rules::sdlc::stdc::test
{

    class DummyTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:
        DummyTest();
        DummyTest(const DummyTest &) = delete;
        DummyTest(DummyTest &&) = delete;
        DummyTest & operator=(const DummyTest &) = delete;
        DummyTest & operator=(DummyTest &&) = delete;
        virtual ~DummyTest();

        void SetUp() override;
        void TearDown() override;

    protected:
        rules::sdlc::stdc::Dummy * testee;

    private:
    };
}
#endif
