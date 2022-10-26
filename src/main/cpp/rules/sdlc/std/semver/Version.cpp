
#include <boost/algorithm/string.hpp>
#include <rules/sdlc/std/semver/Version.hpp>

#include <variant>

using namespace rules::sdlc::stdc::semver;

log4cxx::LoggerPtr Version::logger =
    log4cxx::Logger::getLogger ( std::string ( "rules.sdlc.stdc.semver.Version" ) );

Version::Version ( ) noexcept
    : m_major ( 0 )
    , m_minor ( 0 )
    , m_patch ( 1 )
    , m_releaseType ( ReleaseLevel::SNAPSHOOT )
    , m_tweak ( 115 )
    , m_extra ( std::string ( GIT_COMMIT_VERSION ) )
    , m_build ( )

{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    oss << "Compiled using"
        << " ("
#if defined( __INTEL_COMPILER )
        << "Intel " << __INTEL_COMPILER << " " << __INTEL_COMPILER_BUILD_DATE
#elif defined( __clang__ )
        << "Clang " << __clang__ << "." << __clang_major__ << "." << __clang_minor__ << "." <<
        __clang_patchlevel__
#elif ( defined( __GNUC__ ) || defined( __GNUG__ ) ) && !defined( __clang__ )
        << "GNU " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__
#else
        << "unknown compiler"
#endif
        << ')';

    LOG4CXX_DEBUG ( logger, oss.str ( ) );
}

Version::Version (
    const std::uint8_t major,
    const std::uint8_t minor,
    const std::uint8_t patch,
    ReleaseLevel releaseType,
    std::uint8_t tweak )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    m_major = major;
    m_minor = minor;
    m_patch = patch;
    m_releaseType = releaseType;
    m_tweak = tweak;
}

Version::~Version ( ) noexcept
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
}

Version::Version ( const std::string & version )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ << " " << version);
    this->set(version);
}

void Version::set(std::uint8_t major, std::uint8_t minor, std::uint8_t patch)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << std::to_string(major) << " " << std::to_string(minor) << " " << std::to_string(patch));
    this->m_major = major;
    this->m_minor = minor;
    this->m_patch = patch;
    this->m_extra = std::string();
    this->m_build = std::string();
}

void Version::set(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, const char * extra, const char * build)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << std::to_string(major) << " " << std::to_string(minor) << " " << std::to_string(patch) << " " << extra << " " << build);
    this->set(major, minor, patch);
    this->m_extra = std::string(extra);
    this->m_build = std::string(build);
}

void Version::set(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, const std::string & extra, const std::string & build)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << std::to_string(major) << " " << std::to_string(minor) << " " << std::to_string(patch) << " " << extra << " " << build);
    this->set(major, minor, patch);
    this->m_extra = std::string(extra);
    this->m_build = std::string(build);
}

void Version::set(const char * pversion)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << pversion );
    std::string version(pversion);
    this->set(version);
}

void Version::set(const std::string & version)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " " << version );

    // regex to capture semantic version
    // the regex matches case insensitive
    // (1) major version 0 or unlimited number
    // (2) . minor version (0 or unlimited number)
    // (3) . patch version (0 or unlimited number)
    // (4) optional pre-release following a dash consisting of a alphanumeric letters
    //     and hyphens using a non-capture subclause to exclude the dash from the
    //     pre-release string
    // (5) optional build following a plus consisting of alphanumeric letters and
    //     hyphens using a non-capture subclause to exclude the plus from the build string
    auto re = std::regex("^(0|[1-9][0-9]*)"                     // (1)
                         "\\.(0|[1-9][0-9]*)"                   // (2)
                         "\\.(0|[1-9][0-9]*)"                   // (3)
                         "(?:\\-([0-9a-z-]+[\\.0-9a-z-]*))?"    // (4)
                         "(?:\\+([0-9a-z-]+[\\.0-9a-z-]*))?"    // (5)
                                   ,
                                   std::regex_constants::ECMAScript |
                                   std::regex_constants::icase);

    auto items_match = std::smatch();

    if(std::regex_match(version, items_match, re))
    {
        this->set(std::atoi(items_match[1].str().c_str()),
            std::atoi(items_match[2].str().c_str()),
            std::atoi(items_match[3].str().c_str()),
            items_match[4],
            items_match[5]
        );
    }
    else
    {
        LOG4CXX_ERROR(logger, "Bad version format.");
    }
}

int Version::compareVersion ( const Version & rhs ) const noexcept
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    if ( m_major != rhs.m_major ) return m_major < rhs.m_major ? LSL : USL;

    if ( m_minor != rhs.m_minor ) return m_minor < rhs.m_minor ? LSL : USL;

    if ( m_patch != rhs.m_patch ) return m_patch < rhs.m_patch ? LSL : USL;

    if ( m_releaseType != rhs.m_releaseType ) return m_releaseType < rhs.m_releaseType ? LSL : USL;

    return ( ESL );
}

bool Version::isEquals (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    return ( this->m_major == rhs.m_major
        && this->m_minor == rhs.m_minor
        && this->m_patch == rhs.m_patch
        && this->m_releaseType == rhs.m_releaseType);
}

bool Version::isNewerThen (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    if(this->m_major > rhs.m_major)
        return true;

    if(this->m_minor > rhs.m_minor)
        return true;

    if(this->m_patch > rhs.m_patch)
        return true;

    if(this->m_releaseType > rhs.m_releaseType)
        return true;

    return false;
}

bool Version::isOlderThen (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    if(this->m_major < rhs.m_major)
        return true;

    if(this->m_minor < rhs.m_minor)
        return true;

    if(this->m_patch < rhs.m_patch)
        return true;

    if(this->m_releaseType < rhs.m_releaseType)
        return true;

    return false;
}

bool Version::operator> (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    return this->isNewerThen(rhs);
}

bool Version::operator< (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    return this->isOlderThen(rhs);
}

bool Version::operator== (const Version& rhs) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    return this->isEquals(rhs);
}

std::string
Version::maturity ( ) const noexcept
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    std::string v = std::to_string ( m_major ) + '.' + std::to_string ( m_minor ) + '.' + std::to_string (m_patch );

    switch ( m_releaseType )
    {

        case ReleaseLevel::SNAPSHOOT:
            v.append ( "-SNAPSHOOT" );
            v.append ( "-Build" );
            v.append ( std::to_string ( m_tweak ) );
            break;

        case ReleaseLevel::ALPHA:
            v.append ( "-alpha" );
            v.append ( "-Build" );
            v.append ( std::to_string ( m_tweak ) );
            break;

        case ReleaseLevel::BETA:
            v.append ( "-beta" );
            v.append ( "-Build" );
            v.append ( std::to_string ( m_tweak ) );
            break;

        case ReleaseLevel::CANDIDATE:
            v.append ( "-rc" );
            v.append ( "-Build" );
            v.append ( std::to_string ( m_tweak ) );
            break;

        default:
            break;
    }

    // m_version = std::string(v);
    // //m_version.assign(v, 0, v.length()-1);
    return ( v );
}
