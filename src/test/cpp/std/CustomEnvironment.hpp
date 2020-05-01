#ifndef CFS_COM_CUSTOMENVIRONMENT_HPP
#define CFS_COM_CUSTOMENVIRONMENT_HPP

#include <gtest/gtest.h>
#include <cfs/com/LoggingService.hpp>

namespace cfs::com::test
{
class CustomEnvironment : public ::testing::Environment
{
	LOG4CXX_DECLARE_STATIC_LOGGER
 public:
    CustomEnvironment();
    CustomEnvironment(const CustomEnvironment&) = delete;
    CustomEnvironment(CustomEnvironment&&) = delete;
    CustomEnvironment& operator=(const CustomEnvironment&) = delete;
    CustomEnvironment& operator=(CustomEnvironment&&) = delete;
    virtual ~CustomEnvironment();

    virtual void SetUp() override;
    virtual void TearDown() override;

 protected:
 private:
};
}

#endif
