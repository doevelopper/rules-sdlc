
#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include <rules/sdlc/common/demo/BookStore.hpp>

namespace details {

    // for this demonstration keep this bookstore alive as static
    // there is also the opportunity to use ScenarioScope<>, look in cucumber-cpp calculator example
    rules::sdlc::stds::demo::BookStore& get_bookstore()
    {
        static rules::sdlc::stds::demo::BookStore bs;
        return bs;
    }
}


GIVEN("^A bookstore with following books$")
{
    REGEX_PARAM(std::string, books);

    std::stringstream ss;
    ss << books;

    details::get_bookstore().add_books_from_json(ss);
}

GIVEN("^An empty bookstore$")
{
    // improves readability of tests, do some initializing stuff here ...
}

WHEN("^Add \"(.*?)\" by \"(.*?)\" with id (\\d+)$")
{
    REGEX_PARAM(std::string, title);
    REGEX_PARAM(std::string, author);
    REGEX_PARAM(std::size_t, id);

    rules::sdlc::stds::demo::Book b{author, title};
    details::get_bookstore().add_book(id, b);
}

WHEN("^Remove book with id (\\d+)$")
{
    REGEX_PARAM(std::size_t, id);
    details::get_bookstore().remove_book(id);
}
WHEN("^Remove all books$")
{
    details::get_bookstore().clear();
}


THEN("^Bookstore has \"(.*?)\" by \"(.*?)\"$")
{
    REGEX_PARAM(std::string, title);
    REGEX_PARAM(std::string, author);

    rules::sdlc::stds::demo::Book book{author, title};
    EXPECT_TRUE(details::get_bookstore().has(book));
}

THEN("^Total books count is (\\d+)$")
{
    REGEX_PARAM(std::size_t, expected_count);
    EXPECT_EQ(
        expected_count,
        details::get_bookstore().get_books_count()
    );
}

BEFORE()
{
    std::cout << "BEFORE every scenarios\n";
}
AFTER()
{
    std::cout << "AFTER every scenarios\n";

    // since this quick n dirty approach with static we
    // clear the bookstore after every scenario
    details::get_bookstore().clear();
}

BEFORE_ALL()
{
    std::cout << "BEFORE_ALL scenarios\n";
}

AFTER_ALL()
{
    std::cout << "AFTER_ALL scenarios\n";
}


BEFORE("@foo")
{
    std::cout << "BEFORE every scenario tagged with @foo\n";
}
BEFORE("@foo,@bar,@baz")
{
    std::cout << "BEFORE every scenario tagged with @foo, @bar or @baz\n";
}

AFTER("@foo")
{
    std::cout << "AFTER every scenario tagged with @bar\n";
}

AROUND_STEP("@baz")
{
    std::cout << "AROUND_STEP: Befoer every step tagged with @baz\n";
    step->call();
    std::cout << "AROUND_STEP: After every step tagged with @baz\n";
}

AFTER_STEP("@bar")
{
    std::cout << "AFTER_STEP every step tagged with @bar\n";
}
