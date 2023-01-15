
#include <memory>
#include <gmock/gmock.h>
#include <cucumber-cpp/autodetect.hpp>


namespace tips
{

    class IFface
    {
    public:

        virtual ~IFface()
        {
        };
        virtual void methodCall () const = 0;
    };

    class IFfaceMock
        : public IFface
    {
    public:

        MOCK_CONST_METHOD( methodCall, void());
    };

    struct MockContext
    {
        std::shared_ptr < IFfaceMock > mock;
    };

    GIVEN( "^a mock class with method methodCall$" )
    {
        ScenarioScope < MockContext > context{ };
        context->mock = std::make_shared < IFfaceMock > ();
    }

    GIVEN( "^the tests expects that methodCall is called once$" )
    {
        ScenarioScope < MockContext > context{ };
        EXPECT_CALL( *context->mock, methodCall());
    }

    WHEN( "^methodCall is called on the mock$" )
    {
        ScenarioScope < MockContext > context{ };
        context->mock->methodCall();
    }

    THEN( "^the test should pass$" )
    {
        ScenarioScope < MockContext > context{ };
        ASSERT_TRUE( ::testing::Mock::VerifyAndClearExpectations( context->mock.get()));
    }
}
