#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_VERSION_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_VERSION_HPP

#include <charconv>
#include <ctime>
#include <iostream>
#include <iterator>
#include <regex>

#include <com/github/doevelopper/rules/sdlc/app/AppInfo.hpp>
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/GitRevision.hpp>

namespace com::github::doevelopper::rules::sdlc::semver
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

    const std::regex rex("([a-z]+)\\.([a-z]+)");
    const std::string nid = R"(0|[1-9]\d*)";

    // This class is to be used if you just need access to version info and have no need
    // to instantiate an object that will provide access to that version info.

    struct VersionInfo
    {
        static std::string name()
        {
            return API_LIB_NAME_STR;
        }

        static std::string version()
        {
            return API_LIB_VERSION_STR;
        }

        static std::string description()
        {
            return API_LIB_DESCRIPTION_STR;
        }

        static std::string copyright()
        {
            return API_LIB_COPYRIGHT_STR;
        }

        static std::string copyright_full()
        {
            return API_LIB_COPYRIGHT_FULL_STR;
        }

        static std::string project_str()
        {
            return API_LIB_PROJECT_STR;
        }

        static std::string package_str()
        {
            return API_LIB_PACKAGE_STR;
        }

        static std::string author_str()
        {
            return API_LIB_AUTHOR_STR;
        }

        static std::string release_isodate_str()
        {
            return API_LIB_RELEASE_ISODATE_STR;
        }

        static std::string release_year_str()
        {
            return API_LIB_RELEASE_YEAR_STR;
        }

        static std::string release_date_str()
        {
            return API_LIB_RELEASE_DATE_STR;
        }

        static std::string release_time_str()
        {
            return API_LIB_RELEASE_TIME_STR;
        }

        static std::string full_revision_str()
        {
            return API_LIB_FULL_REVISION_STR;
        }

        static std::string revision_str()
        {
            return API_LIB_REVISION_STR;
        }

        static int release_year()
        {
            return API_LIB_RELEASE_YEAR;
        }

        static std::time_t release_epoch_time()
        {
            return API_LIB_RELEASE_EPOCH_TIME;
        }

        static int major_revision()
        {
            return API_LIB_MAJOR_REVISION;
        }

        static int minor_revision()
        {
            return API_LIB_MINOR_REVISION;
        }

        static int patchlevel()
        {
            return API_LIB_PATCHLEVEL;
        }
    };

    // This class is to be used if you have an existing interface that defines the vinfo
    // functions and expects them to be implemented by a derived class.

    template <typename B>
    class Version : private B
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        Version() noexcept;
        Version(const Version &)             = delete;
        Version(Version &&)                  = delete;
        Version & operator=(const Version &) = delete;
        Version & operator=(Version &&)      = delete;
        virtual ~Version() noexcept;

        explicit Version(const std::string & version);
        explicit Version(
            const std::uint8_t major, const std::uint8_t minor, const std::uint8_t patch,
            ReleaseLevel m_releaseType = ReleaseLevel::SNAPSHOOT, std::uint8_t m_tweak = 0);
        explicit Version(std::uint8_t, std::uint8_t, std::uint8_t, const std::string &, const std::string &);

        bool isEquals(const Version & ver) const;
        bool isNewerThen(const Version & ver) const;
        bool isOlderThen(const Version & ver) const;

        bool operator>(const Version & ver) const;
        bool operator<(const Version & ver) const;
        bool operator==(const Version & ver) const;

        std::string maturity() const noexcept;
        const std::string getVersion() const;
        const int getMajor() const;
        const int getMinor() const;
        const int getPatch() const;
        const std::string getBuild() const;
        const bool isStable() const;

        [[nodiscard]] auto major() const & -> const std::uint8_t &;
        [[nodiscard]] auto major() && -> std::uint8_t &&;
        [[nodiscard]] auto minor() const & -> const std::uint8_t &;
        [[nodiscard]] auto minor() && -> std::uint8_t &&;
        [[nodiscard]] auto patch() const & -> const std::uint8_t &;
        [[nodiscard]] auto patch() && -> std::uint8_t &&;

        virtual std::string name() const;
        virtual std::string version() const;
        virtual std::string description() const;
        virtual std::string copyright() const;
        virtual std::string copyright_full() const;
        virtual std::string project_str() const;
        virtual std::string package_str() const;
        virtual std::string author_str() const;
        virtual std::string release_isodate_str() const;
        virtual std::string release_year_str() const;
        virtual std::string release_date_str() const;
        virtual std::string release_time_str() const;
        virtual std::string full_revision_str() const;
        virtual std::string revision_str() const;
        virtual int release_year() const;
        virtual std::time_t release_epoch_time() const;
        virtual int major_revision() const;
        virtual int minor_revision() const;
        virtual int patchlevel() const;

    protected:
    private:

        void set(std::uint8_t, std::uint8_t, std::uint8_t);
        void set(std::uint8_t, std::uint8_t, std::uint8_t, const char *, const char *);
        void set(std::uint8_t, std::uint8_t, std::uint8_t, const std::string &, const std::string &);
        void set(const char *);
        void set(const std::string &);
        int compareVersion(const Version & rhs) const noexcept;

        // clang-format off
        std::uint8_t        m_major;       ///< Major version, change only on incompatible API modifications.
        std::uint8_t        m_minor;       ///< Minor version, change on backwards-compatible API modifications.
        std::uint8_t        m_patch;       ///< Patch version, change only on bugfixes.
        ReleaseLevel        m_releaseType; ///< Release identification.
        std::uint8_t        m_tweak;       ///< CI Build Identification.
        std::string         m_extra;        ///< GI sha1
        std::string         m_build;        ///< Major.Minor.Patch-[RC|Alpha|...]-Build[0-9]
        std::ostringstream  oss;
        // clang-format on
    };
}
#endif
