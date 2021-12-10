
#include <boost/algorithm/string.hpp>
#include <rules/sdlc/std/semver/Version.hpp>

#include <variant>

using namespace rules::sdlc::stdc::semver;

log4cxx::LoggerPtr Version::logger = log4cxx::Logger::getLogger ( std::string ( "cfs.utils.sv.Version" ) );

Version::Version ( ) noexcept
    : m_major ( 0 )
    , m_minor ( 0 )
    , m_patch ( 1 )
    , m_releaseType ( ReleaseLevel::SNAPSHOOT )
    , m_tweak ( 130 )
    , m_extra ( std::string ( "a151c993f80b78b1bb963a51d9b1374191d3c89e" ) )
    , m_version ( )

{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    oss << "Compiled using"
        << " ("
#if defined( __INTEL_COMPILER )
        << "Intel " << __INTEL_COMPILER << " " << __INTEL_COMPILER_BUILD_DATE
#elif defined( __clang__ )
        << "Clang " << __clang__ << "." << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__
#elif ( defined( __GNUC__ ) || defined( __GNUG__ ) ) && ! defined( __clang__ )
        << "GNU " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__
#else
        << "unknown compiler"
#endif
        << ')';

    LOG4CXX_DEBUG ( logger, oss.str ( ) );
}

Version::Version ( const std::uint8_t major, const std::uint8_t minor, const std::uint8_t patch,
                   ReleaseLevel releaseType, std::uint8_t tweak )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    m_major       = major;
    m_minor       = minor;
    m_patch       = patch;
    m_releaseType = releaseType;
    m_tweak       = tweak;
}

Version::Version ( const std::string & version )
    : m_version ( version )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    const std::regex            sep ( "[ .-+]+", std::regex::icase );
    std::sregex_token_iterator  tokens ( version.cbegin ( ), version.cend ( ), sep, -1 );
    std::sregex_token_iterator  end;
    std::variant< std::string > data;

    for ( ; tokens != end; ++tokens )
    {
        data.emplace< std::string > ( *tokens );
        std::sregex_token_iterator::value_type m = *tokens;
        LOG4CXX_TRACE ( logger, "token found: " << *tokens << " " << m.str ( ) );
    }

    // m_major = std::stoi(std::get<0>(data));
    // m_minor = std::stoi(std::get<1>(data));
    // m_patch = std::stoi(std::get<2>(data));

    // std::copy( std::sregex_token_iterator(version.begin(), version.end(), sep, -1),
    //            std::sregex_token_iterator(),
    //            std::ostream_iterator<std::string>(std::cout, "\n"));

    std::smatch match;

    // if (std::regex_match(version, match, std::regex(FULL)))
    {
    }
}

Version::~Version ( ) noexcept { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }

void
    Version::buildVersion ( const std::smatch & strMatch )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    const auto isOk = [] ( const auto & m ) { return m.matched; };
    const auto cnt  = std::count_if ( strMatch.begin ( ), strMatch.end ( ), isOk );
    /*
       <version core> ::= <major> "." <minor> "." <patch>
       <valid semver> ::= <version core>
     | <version core> "-" <pre-release>
     | <version core> "+" <build>
     | <version core> "-" <pre-release> "+" <build>
     */

    // major.minor.patch-pre-release1.pre-release2+build1.build2.build3
    switch ( cnt )
    {

    // case 6: // build meta data ([P1, P2, P3])
    //     m_build = split(sm[5].str(), '.');
    //     [[fallthrough]];
    // case 5: // pre-release version ([B1, B2])
    //     m_pre = split(sm[4].str(), '.');
    //     [[fallthrough]];
    // case 4: // patch version (Z)
    //     m_patch = std::stoull(sm[3].str());
    //     [[fallthrough]];
    // case 3: // minor version (Y)
    //     m_minor = std::stoull(sm[2].str());
    //     [[fallthrough]];
    // case 2: // major version (X)
    //     m_major = std::stoull(sm[1].str());
    //     [[fallthrough]];
    default:
        break;
    }
}

int
    Version::compareVersion ( const Version & rhs ) const noexcept
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    if ( m_major != rhs.m_major ) return m_major < rhs.m_major ? lSl : uSl;

    if ( m_minor != rhs.m_minor ) return m_minor < rhs.m_minor ? lSl : uSl;

    if ( m_patch != rhs.m_patch ) return m_patch < rhs.m_patch ? lSl : uSl;

    if ( m_releaseType != rhs.m_releaseType ) return m_releaseType < rhs.m_releaseType ? lSl : uSl;

    return ( eSl );
}

std::string
    Version::to_string ( ) const noexcept
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    std::string v = std::to_string ( m_major ) + '.' + std::to_string ( m_minor ) + '.' + std::to_string ( m_patch );

    switch ( m_releaseType )
    {

    case ReleaseLevel::SNAPSHOOT:
        v.append ( "-SNAPSHOOT" );
        break;

    case ReleaseLevel::ALPHA:
        v.append ( "-alpha" );
        v.append ( std::to_string ( m_tweak ) );
        break;

    case ReleaseLevel::BETA:
        v.append ( "-beta" );
        v.append ( std::to_string ( m_tweak ) );
        break;

    case ReleaseLevel::CANDIDATE:
        v.append ( "-rc" );
        v.append ( std::to_string ( m_tweak ) );
        break;

    default:
        break;
    }

    // m_version = std::string(v);
    // //m_version.assign(v, 0, v.length()-1);
    return ( v );
}
