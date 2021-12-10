

#ifndef PROJECT_OBJECT_MODEL_DUMMYTEST_HPP
#define PROJECT_OBJECT_MODEL_DUMMYTEST_HPP

#include <gtest/gtest.h>
#include <project/object/model/Dummy.hpp>

namespace project::object::model::test
{

    class DummyTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        DummyTest();
        DummyTest(const DummyTest&) = delete;
        DummyTest(DummyTest&&) = delete;
        DummyTest& operator=(const DummyTest&) = delete;
        DummyTest& operator=(DummyTest&&) = delete;
        virtual ~DummyTest();

        void SetUp() override;
        void TearDown() override;

    protected:
        project::object::model::Dummy * testee;
    private:

    };
}
#endif

