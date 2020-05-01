
#ifndef CFS_COM_TEST_HPP
#define CFS_COM_TEST_HPP

#include <vector>
#include <gmock/gmock.h>
#include <cfs/com/LoggingService.hpp>

namespace cfs::com::test
{
    class Test
    {

        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        Test();
        Test(std::string & suite, unsigned int iteration = 1);
        Test(const Test & orig) = default;
        virtual
        ~Test();

        int run (int argc = 0, char * argv[] = NULL);
        static void showUsage(std::string name);

    protected:

    private:

        std::string m_testSuites;
        unsigned int m_numberOfTestIteration;
        static const unsigned long LOGGER_WATCH_DELAY;
        LoggingService *           m_loggerService;
    };

}
#endif
