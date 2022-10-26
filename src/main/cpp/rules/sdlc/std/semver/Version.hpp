
#ifndef RULES_SDLC_STD_SEMVER_VERSION_HPP
#define RULES_SDLC_STD_SEMVER_VERSION_HPP
/**
 * @file Version.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-05-12
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <rules/sdlc/std/app/AppInfo.hpp>
#include <rules/sdlc/std/logging/LoggingService.hpp>
#include <rules/sdlc/std/semver/GitRevision.hpp>

#include <charconv>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

#define RELEASE_INFO   RELEASE_LEVEL
#define RELEASE_SERIAL 0

/*!
 * @brief  True if the current version is newer than the given one.
 */
#define VERSION_GT( MAJOR, MINOR, PATCH )                                                                              \
    ( ( VERSION_MAJOR > MAJOR ) ||                                                                                     \
      ( VERSION_MAJOR == MAJOR && ( VERSION_MINOR > MINOR || ( VERSION_MINOR == MINOR && VERSION_PATCH > \
                                                               PATCH ) ) ) )

/*!
 * @brief True if the current version is equal or newer to the given.
 */
#define VERSION_GE( MAJOR, MINOR, PATCH )                                                                              \
    ( ( VERSION_MAJOR > MAJOR ) ||                                                                                     \
      ( VERSION_MAJOR == MAJOR && ( VERSION_MINOR > MINOR || ( VERSION_MINOR == MINOR && VERSION_PATCH >= \
                                                               PATCH ) ) ) )

/*!
 * @brief  True if the current version is older than the given one.
 */
#define VERSION_LT( MAJOR, MINOR, PATCH )                                                                              \
    ( ( VERSION_MAJOR < MAJOR ) ||                                                                                     \
      ( VERSION_MAJOR == MAJOR && ( VERSION_MINOR < MINOR || ( VERSION_MINOR == MINOR && VERSION_PATCH < \
                                                               PATCH ) ) ) )

/*!
 * @brief  True if the current version is older or equal to the given.
 */
#define VERSION_LE( MAJOR, MINOR, PATCH )                                                                              \
    ( ( VERSION_MAJOR < MAJOR ) ||                                                                                     \
      ( VERSION_MAJOR == MAJOR && ( VERSION_MINOR < MINOR || ( VERSION_MINOR == MINOR && VERSION_PATCH <= \
                                                               PATCH ) ) ) )

/*
 * These helper macros generate a numerical and alphanumerical (see http://www.semver.org) representation of the library
 * version number, i.e
 *
 * | SemVer       | Numerical   | Comments
 * |--------------|-------------|------------------
 * | 2.1.0        | 0x020100FF  | final
 * | 2.1.1-beta   | 0x02010100  | first pre-release
 * | 2.1.1        | 0x020101FF  | final
 * | 2.2.0-beta1  | 0x02020000  | 2nd pre-release
 * | 2.2.0-rc1    | 0x02020001  |
 * | 2.2.0-rc2    | 0x02020002  |
 * | 2.2.0        | 0x020200FF  | final
 * | 1.0.0-alpha  |             |
 * | 1.0.0-alpha1 |             |
 * | 1.3.7+build.2.b8f12d7
 * | 1.3.7+build.11.e0f985a.
 * | 2.2.0-rc.1-rc1-7de458254[-dirty]
 */
namespace rules::sdlc::stdc::semver
{

    constexpr int LSL = -1;
    constexpr int ESL = 0;
    constexpr int USL = 1;

/*!
 * @brief ReleaseLevel indicates the release level of this API
 *          This enum follows the release level convention used by python.
 * @ref https://docs.python.org/3/c-api/apiabiversion.html
 * @ref https://docs.python.org/3.7/c-api/apiabiversion.html
 * @ref https://hg.python.org/cpython/file/3.6/Include/patchlevel.h
 */

    enum class ReleaseLevel : std::uint8_t
    {
        SNAPSHOOT = 0xD, /**< API is not tested, work in progress. */
        ALPHA     = 0xA, /**< API is in alpha state, i.e. work in progress. */
        BETA      = 0xB, /**< API is in beta state, i.e. close to be finished. */
        CANDIDATE = 0xC, /**< API is in release candidate state. */
        FINAL     = 0xF, /**< API is in final state, i.e. officially approved. */
    };

    const std::regex rex ( "([a-z]+)\\.([a-z]+)" );
    const std::string nid = R"(0|[1-9]\d*)";

    class SDLC_API_EXPORT Version
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        Version ( ) noexcept;
        Version ( const Version & );
        Version ( Version && ) = delete;
        Version & operator= ( const Version & rhs );
        Version & operator= ( Version && ) = delete;
        virtual ~Version ( ) noexcept;

        explicit Version ( const std::string & version );
        explicit Version ( const std::uint8_t major, const std::uint8_t minor, const std::uint8_t patch, ReleaseLevel
                           m_releaseType = ReleaseLevel::SNAPSHOOT, std::uint8_t m_tweak = 0 );
        Version(std::uint8_t, std::uint8_t, std::uint8_t, const std::string &, const std::string &);

        bool isEquals      (const Version& ver) const;
        bool isNewerThen   (const Version& ver) const;
        bool isOlderThen   (const Version& ver) const;

        bool operator>     (const Version& ver) const;
        bool operator<     (const Version& ver) const;
        bool operator==    (const Version& ver) const;

        std::string maturity ( ) const noexcept;

    protected:

    private:

        void set(std::uint8_t, std::uint8_t, std::uint8_t);
        void set(std::uint8_t, std::uint8_t, std::uint8_t, const char *, const char *);
        void set(std::uint8_t, std::uint8_t, std::uint8_t, const std::string &, const std::string &);
        void set(const char *);
        void set(const std::string &);
        int compareVersion ( const Version & rhs ) const noexcept;

        std::uint8_t m_major;             ///< Major version, change only on incompatible API modifications.
        std::uint8_t m_minor;             ///< Minor version, change on backwards-compatible API modifications.
        std::uint8_t m_patch;             ///< Patch version, change only on bugfixes.
        ReleaseLevel m_releaseType;       ///< Release identification.
        std::uint8_t m_tweak;             ///< CI Build Identification.
        std::string m_extra;              ///< GI sha1
        std::string m_build;            ///< Major.Minor.Patch-[RC|Alpha|...]-Build[0-9]
        std::ostringstream oss;
    };
}
#endif
