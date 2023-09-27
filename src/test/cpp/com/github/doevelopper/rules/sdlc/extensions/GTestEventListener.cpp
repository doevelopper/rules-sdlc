
#include <com/github/doevelopper/rules/sdlc/extensions/GTestEventListener.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr GTestEventListener::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.GTestEventListener"));

GTestEventListener::GTestEventListener()
    : m_currentTestCaseName(std::string())
    , m_currentTestName(std::string())
    , m_currentTestSuiteName(std::string())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

GTestEventListener::~GTestEventListener()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// void GTestEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest & /*unit_test*/)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void GTestEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest & /*unit_test*/)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// // void OnTestSuiteStart(const testing::TestSuite & test_suite)
// // {
// LOG4CXX_TRACE(logger, "We are in OnTestSuiteStart of " << test_suite.name());
// // }

// // void OnTestSuiteEnd(const testing::TestSuite & test_suite)
// // {
// LOG4CXX_TRACE(logger, "We are in OnTestSuiteEnd of " << test_suite.name());
// // }

// #ifndef GTEST_REMOVE_LEGACY_TEST_CASEAPI_
// void GTestEventListener::OnTestCaseStart(const testing::TestCase & test_case)
// {
//     // // LOG4CXX_TRACE(logger,test_case.name());
//     // LOG4CXX_TRACE(logger,
//     ">--------------->>--------------->>--------------->>--------------->>--------------->");
//     // LOG4CXX_TRACE(
//     //     logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "    "
//     //                    << test_case.test_to_run_count() << "/" << test_case.total_test_count());
//     // LOG4CXX_TRACE(logger,
//     ">--------------->>--------------->>--------------->>--------------->>--------------->");
// }

// void GTestEventListener::OnTestCaseEnd(const testing::TestCase & test_case)
// {
//     // // LOG4CXX_TRACE(logger, test_case.Passed() << " " << test_case.elapsed_time() << "ms");
//     // LOG4CXX_TRACE(logger, "<---------------<<---------------<<---------------<<---------------<<---------------
//     ");
//     // LOG4CXX_TRACE(
//     //     logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "   "
//     //                    << test_case.elapsed_time() << " ms");
//     // LOG4CXX_TRACE(
//     //     logger, " Passed(" << test_case.successful_test_count() << ")"
//     //                        << " Failed(" << test_case.failed_test_count() << ")"
//     //                        << " Skipped(" << test_case.skipped_test_count() << ")"
//     //                        << " Disabled(" << test_case.disabled_test_count() << ")");
//     // LOG4CXX_TRACE(logger, "<---------------<<---------------<<---------------<<---------------<<---------------
//     ");
// }
// #endif

// void GTestEventListener::OnTestProgramStart(const testing::UnitTest & unit_test)
// {
//     // LOG4CXX_INFO(
//     //     logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
//     // LOG4CXX_INFO(
//     //     logger,
//     //     "Total Test Case: " << ::testing::UnitTest::GetInstance()->total_test_suite_count() //
//     //     total_test_case_count()
//     //                         << " Test cases with at least one test: "
//     //                         << ::testing::UnitTest::GetInstance()->test_suite_to_run_count()); //
//     //                         test_case_to_run_count
//     // LOG4CXX_INFO(
//     //     logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
// }

// void GTestEventListener::OnTestProgramEnd(const testing::UnitTest & unit_test)
// {
//     // // std::chrono::milliseconds ut_ms =
//     // // std::chrono::duration_cast<std::chrono::milliseconds>(unit_test.elapsed_time()); LOG4CXX_INFO(logger,
//     // // unit_test.Passed());
//     // LOG4CXX_INFO(
//     //     logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
//     // LOG4CXX_INFO(
//     //     logger, unit_test.reportable_test_count() << " tests Executed: Passed(" <<
//     unit_test.successful_test_count()
//     //                                               << "), Failed(" << unit_test.failed_test_count() << ")"
//     //                                               << ", Skipped(" << unit_test.skipped_test_count() << ")"
//     //                                               << ", Disabled(" << unit_test.reportable_disabled_test_count()
//     <<
//     //                                               ")"
//     //                                               << " Duration: (" << unit_test.elapsed_time() << " ms)");
//     // LOG4CXX_INFO(
//     //     logger, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
// }

// void GTestEventListener::OnTestStart(const testing::TestInfo & test_info)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

//     // // m_currentTestCaseName = test_info.test_case_name();
//     // m_currentTestSuiteName = test_info.test_suite_name();
//     // m_currentTestName      = test_info.name();
// LOG4CXX_TRACE(logger,test_info.test_suite_name() <<"."<< test_info.name());
//     // std::stringstream formatedTestInfo;
//     // formatedTestInfo << "Test : [" << test_info.name() << "]";
//     // formatedTestInfo << " Test suite: [" << test_info.test_suite_name() << "]";
//     // // formatedTestInfo << " of test case [" << test_info.test_case_name() << "]";
//     // // formatedTestInfo << " (" << ::testing::UnitTest::GetInstance()->test_case_to_run_count() << ")";

//     // if (test_info.value_param() != nullptr)
//     // {
//     //     formatedTestInfo << " with value param [" << test_info.value_param() << "]";
//     // }

//     // if (test_info.type_param() != nullptr)
//     // {
//     //     formatedTestInfo << " and with type param [" << test_info.type_param() << "]";
//     // }

//     // LOG4CXX_INFO(logger, "/:\\ " << formatedTestInfo.str());
// }

// void GTestEventListener::OnTestEnd(const testing::TestInfo & test_info)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// LOG4CXX_TRACE(logger, "We are in OnTestEnd of"<< test_info.test_suite_name() <<"."<<test_info.name());
// std::stringstream msg;
// msg << "end:" << test_info.test_case_name() << "." << test_info.name()
//     << "," << (test_info.result()->Failed() ? "failed" : "ok");
// LOG4CXX_TRACE(logger, "msg.str());
//     // std::stringstream formatedTestInfo;
//     // // formatedTestInfo << "Test case [" << test_info.test_case_name() << "] finished: ";
//     // formatedTestInfo << " Test suite: " << test_info.test_suite_name() << "] finished: ";
//     // formatedTestInfo << " Test : " << test_info.name();

//     // if (test_info.result())
//     // {
//     //     if (test_info.result()->Passed())
//     //     {
//     //         formatedTestInfo << " -> PASSED";
//     //     }

//     //     if (test_info.result()->Failed())
//     //     {
//     //         // if (GTEST_FLAG(list_tests))
//     //         // {
//     //         formatedTestInfo << " file [" << test_info.file() << "]";
//     //         formatedTestInfo << " line [" << test_info.line() << "]";
//     //         // }
//     //         formatedTestInfo << " -> FAILED";
//     //     }
//     // }

//     // formatedTestInfo << " ";
//     // formatedTestInfo << (test_info.result())->elapsed_time() << " ms";

//     // LOG4CXX_INFO(logger, "Summary: " << formatedTestInfo.str());

//     // m_currentTestCaseName.clear();
//     // m_currentTestName.clear();
// }

// void GTestEventListener::OnTestIterationStart(const testing::UnitTest & unit_test, int iteration)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << iteration);
// }

// void GTestEventListener::OnTestIterationEnd(const testing::UnitTest & unit_test, int iteration)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // LOG4CXX_INFO(logger,"Test Iteration  " << unit_test.Passed() << " Elapsed time " << unit_test.elapsed_time()
//     <<
//     // " ms");
// }

// void GTestEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest & unit_test)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void GTestEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest & unit_test)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void GTestEventListener::OnTestPartResult(const testing::TestPartResult & test_part_result)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// LOG4CXX_INFO(logger,"We are in OnTestPartResult"
//     << test_part_result.file_name()
//     <<":"
//     << test_part_result.line_number() );
//     // if (test_part_result.failed())
//     // {
//     //     std::string status = test_part_result.failed() ? "*** Failure***" : "Success !!!";

// if (test_part_result.failed()) {
//       std::stringstream msg;
//       msg << "fail:" << test_part_result.file_name() << ","
//           << test_part_result.line_number() << ","
//           << test_part_result.summary();
//       LOG4CXX_ERROR(logger,msg.str());
//     }
//     //     LOG4CXX_WARN(
//     //         logger, status << " Test case failed : [" << m_currentTestCaseName << "] "
//     //                        << " Test suite: " << m_currentTestName << " File: " << test_part_result.file_name()
//     //                        << " Line: " << test_part_result.line_number() << " Message: " <<
//     //                        test_part_result.message()
//     //                        << " Summary: " << test_part_result.summary());
//     // }
// }

// void GTestEventListener::OnTestDisabled(testing::TestInfo const& test_info)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
