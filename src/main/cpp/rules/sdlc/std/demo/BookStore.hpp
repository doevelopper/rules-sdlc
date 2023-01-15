
#ifndef RULES_SDLC_STD_DEMO_BOOKSTORE_HPP
#define RULES_SDLC_STD_DEMO_BOOKSTORE_HPP


#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stds::demo
{

    struct Book
    {
        std::string m_author;
        std::string m_title;

        bool operator==(const Book& rhs) const
        {
            return  this->m_author.compare(rhs.m_author) == 0
            && this->m_title.compare(rhs.m_title) == 0;
        }
    };

    class BookStore
    {
    public:
        BookStore();
        BookStore(const BookStore&) = default;
        BookStore(BookStore&&) = default;
        BookStore& operator=(const BookStore&) = default;
        BookStore& operator=(BookStore&&) = default;
        ~BookStore();
    protected:
    private:
        std::unordered_map<std::size_t, Book> m_books;
    };
}
#endif
