
#include <project/object/model/features/step_definitions/DummyTestSteps.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::features;
using namespace rules::sdlc::stdc::features::it;
using cucumber::ScenarioScope;
using namespace ::testing;

log4cxx::LoggerPtr DummyTestSteps::logger =
    log4cxx::Logger::getLogger(std::string("cfs.platform.it.DummyTestSteps"));

// @see include/cucumber-cpp/internal/hook/HookMacros.hpp

BEFORE_ALL()
{
    LOG4CXX_TRACE(DummyTestSteps::logger, "Before all scenarios" );
}

AFTER_ALL()
{
    LOG4CXX_TRACE(DummyTestSteps::logger, "After all scenarios" );
}

AFTER_STEP()
{
    LOG4CXX_TRACE(DummyTestSteps::logger, "After each steps" );
}

BEFORE()
{
    LOG4CXX_TRACE(DummyTestSteps::logger, "Before any scenario" );
}

AFTER()
{
    LOG4CXX_TRACE(DummyTestSteps::logger, "After any scenario" );
}



/*
   GIVEN("^a dummy initialised with \"([^\"]*)\" and \"([^\"]*)\"$")
   {
    REGEX_PARAM(std::string, hello_string);
    REGEX_PARAM(std::string, world_string);
    ScenarioScope<DummyTestSteps> context{};
    //context->dummies.emplace_back(cfs::platform::Dummy{hello_string, world_string});
   }

   BEFORE("@foo,@bar","@baz")
   {
    std::cout << "Before scenario (\"@foo,@baz\",\"@bar\")" << std::endl;
   }

   AROUND_STEP("@baz")
   {
    std::cout << "Around step (\"@baz\") ...before" << std::endl;
    // step->call();
    std::cout << "Around step (\"@baz\") ..after" << std::endl;
   }

   AFTER_STEP("@bar")
   {
    std::cout << "After step (\"@bar\")" << std::endl;
   }

   AFTER("@foo")
   {
    std::cout << "After scenario (\"@foo\")" << std::endl;
   }

   AFTER("@gherkin")
   {
    std::cout << "After scenario (\"@gherkin\")" << std::endl;
   }

   GIVEN("^a step$")
   {
    pending();
   }


   GIVEN("^execute dummy$")
   {
   pending();
   }

   WHEN("^do nothing$")
   {
   pending();
   }

   THEN("^should see$")
   {
   pending();
   }

   THEN("^Success$")
   {
   pending();
   }
 */
