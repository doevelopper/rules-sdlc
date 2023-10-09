
#include <com/github/doevelopper/rules/sdlc/app/NotificationTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

template <typename V>
log4cxx::LoggerPtr NotificationTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.NotificationTest"));

template <typename V>
NotificationTest<V>::NotificationTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
NotificationTest<V>::~NotificationTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void NotificationTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Notification();
}

template <typename V>
void NotificationTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TYPED_TEST_P(NotificationTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
}

REGISTER_TYPED_TEST_SUITE_P(NotificationTest, Test_Not_Yet_Implemented);

INSTANTIATE_TYPED_TEST_SUITE_P(TestOfNotification, NotificationTest, ParameterValueTypes);
// INSTANTIATE_TYPED_TEST_SUITE_P(TestActivator, ActivatorTest, bool);
