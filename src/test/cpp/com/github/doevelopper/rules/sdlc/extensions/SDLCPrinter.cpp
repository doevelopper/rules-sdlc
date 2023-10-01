
#include <com/github/doevelopper/rules/sdlc/extensions/SDLCPrinter.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr SDLCPrinter::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.SDLCPrinter"));

SDLCPrinter::SDLCPrinter()
    : m_testInfo(nullptr)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SDLCPrinter::~SDLCPrinter()
{
    // FIXME: No appender could be found for logger
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SDLCPrinter::OnTestProgramStart(const ::testing::UnitTest & /* aUnitTest */)
{
    LOG4CXX_INFO(logger, __LOG4CXX_FUNC__ << " TEST-INFO | GTest unit test starting");
}

void SDLCPrinter::OnTestProgramEnd(const ::testing::UnitTest & aUnitTest)
{
    std::string status  = aUnitTest.Passed() ? std::string("PASS") : std::string("UNEXPECTED-FAIL");
    std::string status2 = aUnitTest.Passed() ? std::string("passed") : std::string("failed");

    LOG4CXX_INFO(
        logger, "TEST-" << status << " | "
                        << "GTest unit test: " << status2);
    LOG4CXX_INFO(logger, "Passed: " << aUnitTest.successful_test_count());
    LOG4CXX_INFO(logger, "Failed: " << aUnitTest.failed_test_count());
}

void SDLCPrinter::OnTestStart(const testing::TestInfo & aTestInfo)
{
    m_testInfo = &aTestInfo;
    // LOG4CXX_INFO(logger, "TEST-START | " << m_testInfo->test_case_name() << "." << m_testInfo->name());
}

void SDLCPrinter::OnTestPartResult(const ::testing::TestPartResult & aTestPartResult)
{
    // LOG4CXX_INFO(
    //     logger, "TEST-" << !aTestPartResult.failed() ? "PASS"
    //             : "UNEXPECTED-FAIL"
    //                     << " | " << mTestInfo
    //                 ? mTestInfo->test_case_name()
    //             : "?"
    //                     << "." << mTestInfo
    //                 ? mTestInfo->name()
    //                 : "?"

    //                       << " | " << aTestPartResult.summary() << " @ " << aTestPartResult.file_name() << ":"
    //                       << aTestPartResult.line_number());
}

void SDLCPrinter::OnTestEnd(const ::testing::TestInfo & aTestInfo)
{
    // LOG4CXX_INFO(
    //     logger, "TEST-" << aTestInfo.result()->Passed() ? "PASS"
    //                                                     : "UNEXPECTED-FAIL"
    //                                                           << " | " << aTestInfo.test_case_name() << "."
    //                                                           << aTestInfo.name() << " | test completed (time: %"
    //                                                           << aTestInfo.result()->elapsed_time() << "ms");
    // LOG4CXX_ASSERT(logger, &aTestInfo == m_testInfo << "");

    m_testInfo = nullptr;
}
