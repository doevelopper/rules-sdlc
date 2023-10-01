
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_TESTDRIVER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_TESTDRIVER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    enum class TestStatus : std::uint8_t
    {
        kRunning,
        kPassed,
        kFailed,
        kSkipped,
    };

    class TestDriver
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        TestDriver(const TestDriver &)             = delete;
        TestDriver(TestDriver &&)                  = delete;
        TestDriver & operator=(const TestDriver &) = delete;
        TestDriver & operator=(TestDriver &&)      = delete;
        virtual ~TestDriver();

        /*!
         * @brief Called when a test is skipped..
         */
        virtual void skip() = 0;
        /*!
         * @brief Return true if the test is allowed to continue execution.
         */
        virtual bool carryOn() const = 0;
        /*!
         * @brief Returns the current status of the test.
         */
        virtual TestStatus status() const = 0;

    protected:

        TestDriver();

    private:
    };
}
#endif
