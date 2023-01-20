
#include <rules/sdlc/common/GTestEventListener.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::test;

log4cxx::LoggerPtr GTestEventListener::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdtest.GTestEventListener"));

GTestEventListener::GTestEventListener()
    : m_currentTestCaseName("UKN")
    , m_currentTestName("UKN")
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // const ::testing::TestInfo * const testInfo = ::testing::UnitTest::GetInstance()->current_test_info();
    // LOG4CXX_DEBUG(logger , ">>>>>>>>!!!!Test " << testInfo->name() << "!!!!>>>>>>>>");
    // LOG4CXX_DEBUG(logger , ">>>>>>>>!!!! Test Case" << testInfo->test_case_name() << " !!!!>>>>>>>>");
    // LOG4CXX_DEBUG(logger , ">>>>>>>>!!!!Star running unit test " <<
    // ::testing::UnitTest::GetInstance()->test_case_to_run_count() <<" !!!!>>>>>>>>"); LOG4CXX_DEBUG(logger , "Running
    // unit test " <<  ::testing::UnitTest::GetInstance()->current_test_info());
}

GTestEventListener::~GTestEventListener()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void GTestEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest & /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void GTestEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest & /*unit_test*/)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void GTestEventListener::OnTestSuiteStart(const testing::TestSuite & test_suite)
{
    // const testing::TestInfo* const test_info =
    //     testing::UnitTest::GetInstance()->current_test_info();

    LOG4CXX_INFO(logger, ">>>>>>>>!!!! Test Suite " << test_suite.name() << " start !!!!>>>>>>>>");
    // LOG4CXX_INFO(logger, ">>>>>>>>!!!! Test  "
    //     <<  test_info->name()
    //     << " of Test Suite "
    //     << test_info->test_suite_name()
    //     << " Start !!!!>>>>>>>>");
}

void GTestEventListener::OnTestSuiteEnd(const testing::TestSuite & test_suite)
{
    std::stringstream formatedTestInfo;
    formatedTestInfo << "<<<<<<<<!!!! Test Suite " << test_suite.name() << " END !!!!<<<<<<<< ";
    formatedTestInfo << "Passed(" << test_suite.successful_test_count() << ") ";
    formatedTestInfo << "Failed(" << test_suite.failed_test_count() << ") ";
    formatedTestInfo << "Skipped(" << test_suite.skipped_test_count() << ") ";
    formatedTestInfo << "Disabled(" << test_suite.disabled_test_count() << ") ";
    // const testing::TestInfo* const test_info =
    //     testing::UnitTest::GetInstance()->current_test_info();
    LOG4CXX_INFO(logger, formatedTestInfo.str());
}

void GTestEventListener::OnTestCaseStart(const testing::TestCase & test_case)
{
    // LOG4CXX_TRACE(logger,test_case.name());
    LOG4CXX_TRACE(logger, ">--------------->>--------------->>--------------->>--------------->>--------------->");
    LOG4CXX_TRACE(
        logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "    "
                       << test_case.test_to_run_count() << "/" << test_case.total_test_count());
    LOG4CXX_TRACE(logger, ">--------------->>--------------->>--------------->>--------------->>--------------->");
}

void GTestEventListener::OnTestCaseEnd(const testing::TestCase & test_case)
{
    // LOG4CXX_TRACE(logger, test_case.Passed() << " " << test_case.elapsed_time() << "ms");
    LOG4CXX_TRACE(logger, "<---------------<<---------------<<---------------<<---------------<<--------------- ");
    LOG4CXX_TRACE(
        logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "   "
                       << test_case.elapsed_time() << " ms");
    LOG4CXX_TRACE(
        logger, " Passed(" << test_case.successful_test_count() << ")"
                           << " Failed(" << test_case.failed_test_count() << ")"
                           << " Skipped(" << test_case.skipped_test_count() << ")"
                           << " Disabled(" << test_case.disabled_test_count() << ")");
    LOG4CXX_TRACE(logger, "<---------------<<---------------<<---------------<<---------------<<--------------- ");
}

void GTestEventListener::OnTestProgramStart(const testing::UnitTest & unit_test)
{
    LOG4CXX_INFO(
        logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    LOG4CXX_INFO(
        logger, "Total Test Case: " << ::testing::UnitTest::GetInstance()->total_test_case_count()
                                    << " Test cases with at least one test: "
                                    << ::testing::UnitTest::GetInstance()->test_case_to_run_count());
    LOG4CXX_INFO(
        logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}

void GTestEventListener::OnTestProgramEnd(const testing::UnitTest & unit_test)
{
    // std::chrono::milliseconds ut_ms =
    // std::chrono::duration_cast<std::chrono::milliseconds>(unit_test.elapsed_time()); LOG4CXX_INFO(logger,
    // unit_test.Passed());
    LOG4CXX_INFO(
        logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    LOG4CXX_INFO(
        logger, unit_test.reportable_test_count() << " tests Executed: Passed(" << unit_test.successful_test_count()
                                                  << "), Failed(" << unit_test.failed_test_count() << ")"
                                                  << ", Skipped(" << unit_test.skipped_test_count() << ")"
                                                  << ", Disabled(" << unit_test.reportable_disabled_test_count() << ")"
                                                  << " Duration: (" << unit_test.elapsed_time() << " ms)");
    LOG4CXX_INFO(
        logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}

void GTestEventListener::OnTestStart(const testing::TestInfo & test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_currentTestCaseName = test_info.test_case_name();
    m_currentTestName = test_info.name();

    std::stringstream formatedTestInfo;
    formatedTestInfo << "Test : [" << test_info.name() << "]";
    formatedTestInfo << " Test suite: [" << test_info.test_suite_name() << "]";
    formatedTestInfo << " of test case [" << test_info.test_case_name() << "]";
    // formatedTestInfo << " (" << ::testing::UnitTest::GetInstance()->test_case_to_run_count() << ")";

    if (test_info.value_param() != nullptr)
    {
        formatedTestInfo << " with value param [" << test_info.value_param() << "]";
    }

    if (test_info.type_param() != nullptr)
    {
        formatedTestInfo << " and with type param [" << test_info.type_param() << "]";
    }

    LOG4CXX_INFO(logger, "/:\\ " << formatedTestInfo.str());
}

void GTestEventListener::OnTestEnd(const testing::TestInfo & test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    std::stringstream formatedTestInfo;
    formatedTestInfo << "Test case [" << test_info.test_case_name() << "] finished: ";
    formatedTestInfo << " Test suite: " << test_info.test_suite_name();
    formatedTestInfo << " Test : " << test_info.name();

    if (test_info.result())
    {
        if (test_info.result()->Passed())
        {
            formatedTestInfo << " -> PASSED";
        }

        if (test_info.result()->Failed())
        {
            // if (GTEST_FLAG(list_tests))
            // {
            formatedTestInfo << " file [" << test_info.file() << "]";
            formatedTestInfo << " line [" << test_info.line() << "]";
            // }
            formatedTestInfo << " -> FAILED";
        }
    }

    formatedTestInfo << " ";
    formatedTestInfo << (test_info.result())->elapsed_time() << " ms";

    LOG4CXX_INFO(logger, "Summary: " << formatedTestInfo.str());

    m_currentTestCaseName.clear();
    m_currentTestName.clear();
}

void GTestEventListener::OnTestPartResult(const testing::TestPartResult & test_part_result)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (test_part_result.failed())
    {
        std::string status = test_part_result.failed() ? "*** Failure***" : "Success !!!";

        LOG4CXX_WARN(
            logger, status << " Test case failed : [" << m_currentTestCaseName << "] "
                           << " Test suite: " << m_currentTestName << " File: " << test_part_result.file_name()
                           << " Line: " << test_part_result.line_number() << " Message: " << test_part_result.message()
                           << " Summary: " << test_part_result.summary());
    }
}

void GTestEventListener::OnTestIterationEnd(const testing::UnitTest & unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // LOG4CXX_INFO(logger,"Test Iteration  " << unit_test.Passed() << " Elapsed time " << unit_test.elapsed_time() <<
    // " ms");
}

void GTestEventListener::OnTestIterationStart(const testing::UnitTest & unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << iteration);
}

void GTestEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest & unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void GTestEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest & unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
