
#include <cfs/com/GTestEventListener.hpp>

using namespace cfs::com::test;

log4cxx::LoggerPtr GTestEventListener::logger = log4cxx::Logger::getLogger(std::string("cfs.com.test.GTestEventListener"));

GTestEventListener::GTestEventListener()
: m_currentTestCaseName("UKN"),
  m_currentTestName("UKN"),
  m_testCount(0),
  m_failedTestCount(0)

{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
	//const ::testing::TestInfo * const testInfo = ::testing::UnitTest::GetInstance()->current_test_info();
    //    LOG4CXX_TRACE(didactics::test::logger , ">>>>>>>>!!!!Test Name!!!!>>>>>>>> ("
    //                << testInfo->name() <<")");
    //
    //    LOG4CXX_TRACE(didactics::test::logger , ">>>>>>>>!!!!Test Case Name!!!!>>>>>>>> ("
    //                << testInfo->test_case_name() <<")");

    //    LOG4CXX_TRACE(didactics::test::logger , ">>>>>>>>!!!!Star running unit test!!!!>>>>>>>> ("
    //                << ::testing::UnitTest::GetInstance()->test_case_to_run_count() <<")");
    //    LOG4CXX_TRACE(didactics::test::logger , "Running unit test" <<  ::testing::UnitTest::GetInstance()->current_test_info());
}

GTestEventListener::~GTestEventListener()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest& /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest& /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnTestSuiteStart(const testing::TestSuite& /*test_suite*/)
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
	LOG4CXX_INFO(logger, ">>>>>>>>!!!!!!!!>>>>>>>>");
}

void GTestEventListener::OnTestSuiteEnd(const testing::TestSuite& /*test_suite*/)
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
	LOG4CXX_INFO(logger, "<<<<<<<<!!!!!!!!<<<<<<<<");
}

void GTestEventListener::OnTestProgramStart(const testing::UnitTest& /*unit_test*/)
{
    // LOG4CXX_TRACE(logger, "unit test started" );
	LOG4CXX_INFO(logger, "UT to run: " << ::testing::UnitTest::GetInstance()->test_case_to_run_count());
}

void GTestEventListener::OnTestProgramEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, "Test case finished: Pass(" << m_testCount
            << "), Failed(" << m_failedTestCount << ")"
            << " for elapsed time: (" << unit_test.elapsed_time() << " )");
}

void GTestEventListener::OnTestStart(const testing::TestInfo& test_info)
{
    ++m_testCount;
    m_currentTestCaseName = test_info.test_case_name();
    m_currentTestName =  test_info.name();

    //std::string tcn = std::string(test_info.name()) + "." + std::string(test_info.test_case_name());

    LOG4CXX_TRACE(logger, "Test case: (" << m_currentTestCaseName << ") Test suite: (" << m_currentTestName << ")");
}

void GTestEventListener::OnTestEnd(const testing::TestInfo& test_info)
{
    LOG4CXX_TRACE(logger, "Test case finished: " << m_currentTestCaseName <<
            " Test suite: " << m_currentTestName <<
            " GOOD: " << !test_info.result()->Failed());

    if (test_info.result()->Failed())
        ++m_failedTestCount;
    m_currentTestCaseName.clear();
    m_currentTestName.clear();
}

void GTestEventListener::OnTestPartResult( const testing::TestPartResult& test_part_result)
{
    if (test_part_result.failed())
    {
        LOG4CXX_TRACE(logger, "Test case failed : " << m_currentTestCaseName <<
                " Test suite: " << m_currentTestName <<
                " File: " << test_part_result.file_name() <<
                " Line: " << test_part_result.line_number() <<
                " Summary: " << test_part_result.summary());

    }
}

void GTestEventListener::OnTestIterationEnd(const testing::UnitTest& unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnTestIterationStart(const testing::UnitTest& /*unit_test*/, int /*iteration*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest& /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest& /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}
