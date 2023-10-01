
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_SDLCPRINTER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_SDLCPRINTER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class SDLCPrinter : public ::testing::EmptyTestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        SDLCPrinter();
        SDLCPrinter(const SDLCPrinter &)             = delete;
        SDLCPrinter(SDLCPrinter &&)                  = delete;
        SDLCPrinter & operator=(const SDLCPrinter &) = delete;
        SDLCPrinter & operator=(SDLCPrinter &&)      = delete;
        virtual ~SDLCPrinter();

        virtual void OnTestProgramStart(const ::testing::UnitTest & /* aUnitTest */) override;
        virtual void OnTestProgramEnd(const ::testing::UnitTest & aUnitTest) override;
        virtual void OnTestStart(const ::testing::TestInfo & aTestInfo) override;
        virtual void OnTestEnd(const ::testing::TestInfo & aTestInfo) override;
        virtual void OnTestPartResult(const ::testing::TestPartResult & aTestPartResult) override;

    protected:
    private:

        const ::testing::TestInfo * m_testInfo;
    };
}
#endif
