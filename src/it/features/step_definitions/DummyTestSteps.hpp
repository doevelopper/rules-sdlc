
#ifndef RULES_SDLC_STDC_FEATURES_STEP_DEFINITIONS_DUMMYTESTSTEPS_HPP
#define RULES_SDLC_STDC_FEATURES_STEP_DEFINITIONS_DUMMYTESTSTEPS_HPP

#include <chrono>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

// #include <cucumber-cpp/generic.hpp>
#include <com/github/doevelopper/rules/sdlc/guide/Dummy.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::guide::test::it
{
    class DummyTestSteps
    {
    public:

        // LOG4CXX_DEFINE_CLASS_LOGGER(DummyTestSteps)

        DummyTestSteps();
        DummyTestSteps(const std::string & hello_string, const std::string & world_string);
        DummyTestSteps(const DummyTestSteps &)             = default;
        DummyTestSteps(DummyTestSteps &&)                  = default;
        DummyTestSteps & operator=(const DummyTestSteps &) = default;
        DummyTestSteps & operator=(DummyTestSteps &&)      = default;
        virtual ~DummyTestSteps();

        std::vector<com::github::doevelopper::rules::sdlc::guide::Dummy> dummies {};
        std::string say_hello_result {};
        void loop(std::mutex & mutex, bool const & running);
        void yield(std::chrono::milliseconds ms);
        // static log4cxx::LoggerPtr logger;
    private:
    };

}
#endif
