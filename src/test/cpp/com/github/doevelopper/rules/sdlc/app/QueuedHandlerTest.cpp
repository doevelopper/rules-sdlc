
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandlerTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

template <typename V>
log4cxx::LoggerPtr QueuedHandlerTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.QueuedHandlerTest"));

template <typename V>
QueuedHandlerTest<V>::QueuedHandlerTest()
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
QueuedHandlerTest<V>::~QueuedHandlerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void QueuedHandlerTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new QueuedHandler();
}

template <typename V>
void QueuedHandlerTest<V>::TearDown()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

// TEST_F(QueuedHandlerTest, Test_Not_Yet_Implemented)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
