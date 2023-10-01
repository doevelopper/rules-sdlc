#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_TOKEN_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_TOKEN_HPP

#include <utility>
#include <variant>

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::semver
{
    class Token
    {
        enum Kind
        {

            Eq, /// `=`
            Gt, /// `>`
            Lt, /// `<`
            LtEq, /// `<=`
            GtEq, /// `>=`
            Caret, /// '^`
            Tilde, /// '~`
            Star, /// '*`
            Dot, /// `.`
            Comma, /// `,`
            Hyphen, /// `-`
            Plus, /// `+`
            Or, /// '||'
            Whitespace, /// any number of whitespace (`\t\r\n `) and its span.
            Numeric, /// Numeric component, like `0` or `42`.
            AlphaNumeric, /// Alphanumeric component, like `alpha1` or `79deadbe`.
            Unexpected /// UnexpectedChar
        };

        using null_type         = std::monostate;
        using whitespace_type   = std::pair<std::size_t, std::size_t>;
        using numeric_type      = std::uint64_t;
        using alphanumeric_type = std::string_view;
        using variant_type      = std::variant<null_type, whitespace_type, numeric_type, alphanumeric_type>;
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Token() noexcept;
        Token(const Token &) noexcept             = default;
        Token(Token &&) noexcept                  = default;
        Token & operator=(const Token &) noexcept = default;
        Token & operator=(Token &&) noexcept      = default;
        virtual ~Token() noexcept;

    protected:
    private:
    };
}
#endif
