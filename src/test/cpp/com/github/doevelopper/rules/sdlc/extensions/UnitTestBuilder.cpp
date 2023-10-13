

#include <span>

#include <com/github/doevelopper/rules/sdlc/extensions/CustomEnvironment.hpp>
#include <com/github/doevelopper/rules/sdlc/extensions/GTestEventListener.hpp>
#include <com/github/doevelopper/rules/sdlc/extensions/SDLCPrinter.hpp>
#include <com/github/doevelopper/rules/sdlc/extensions/UnitTestBuilder.hpp>

using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr UnitTestBuilder::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.UnitTestBuilder"));

const unsigned long UnitTestBuilder::LOGGER_WATCH_DELAY = 30000UL;

UnitTestBuilder::UnitTestBuilder()
    : m_testSuites(std::string())
    , m_moduleUnderTest(std::string())
    , m_numberOfTestIteration(1)
    , m_loggerService(new LoggingService(5000))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

UnitTestBuilder::UnitTestBuilder(std::string & suite, unsigned int iteration)
    : m_testSuites(suite)
    , m_numberOfTestIteration(iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

UnitTestBuilder::~UnitTestBuilder()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_loggerService)
    {
        delete this->m_loggerService;
        m_loggerService = nullptr;
    }
}

void UnitTestBuilder::showUsage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help \t Show this help message\n"
              << "\t-i,--iterration \t Number of iteration on test Default 1\n"
              << "\t-o,--outputpath \t Specify the destination path Default netx to executable\n"
              << "\t-m,--module \t The name of xml test report to be generated\n"
              << "\t-l,--list \t Specify the list of tests to be executed Default netx to executable\n"
              << std::endl;
}

int UnitTestBuilder::run([[maybe_unused]] int argc, [[maybe_unused]] char * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    this->moduleUnderTest(argv);
    // ::testing::TestEventListeners & listeners = testing::UnitTest::GetInstance()->listeners();
    // // auto default_printer                      = listeners.Release(listeners.default_result_printer());
    // delete listeners.Release(listeners.default_result_printer());
    // listeners.Append(new SDLCPrinter);

    // // ::testing::GTEST_FLAG(filter) = suite;
    // // GTEST_FLAG(output) = "xml:" + testOuputPath;
    // // ::testing::GTEST_FLAG(output) = "xml:cfs-osal-Test-Report.xml";
    // // ::testing::FLAGS_gmock_verbose = "verbose";
    // // ::testing::GTEST_FLAG(print_time) = false;

    // ConfigurableEventListener::Builder(default_printer)
    //     // .showEnvironment()
    //     // .showTestCases()
    //     // .showTestNames()
    //     // .showSuccesses()
    //     // .showInlineFailures()
    //     // .showTestSuite()
    //     .build();

    // // listeners.Append(new GTestEventListener);
    // ::testing::AddGlobalTestEnvironment(new CustomEnvironment); // gtest takes ownership of the TestEnvironment ptr
    // // // -// we don't delete it.

    LOG4CXX_INFO(logger, "###################################################################");
    LOG4CXX_INFO(logger, "@@@  Module beeing tested:  " << m_moduleUnderTest << "         @@@");
    LOG4CXX_INFO(logger, "###################################################################");

    std::uint_fast64_t ret_val = RUN_ALL_TESTS();
    // listeners.Release(&GTestEventListener);
    return (ret_val);
}

void UnitTestBuilder::moduleUnderTest(char * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    auto sp = std::span<char>(argv[0], strlen(argv[0]));
    std::transform(sp.begin(), sp.end(), sp.begin(), [](char c) { return std::toupper(c); });
    const std::string runnerProcessName = std::string(sp.begin(), sp.end());
    std::string::size_type i            = runnerProcessName.find("DOEVELOPPER");
    m_moduleUnderTest                   = runnerProcessName;
    m_moduleUnderTest.remove_prefix(m_moduleUnderTest.find_last_of('/') + 1);
}

void UnitTestBuilder::notYetImplemented()
{
    GTEST_NONFATAL_FAILURE_("Test Item Not YET implemented!!!!!!");
}
