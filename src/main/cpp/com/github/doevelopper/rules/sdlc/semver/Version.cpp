
#include <com/github/doevelopper/rules/sdlc/semver/Version.hpp>

using namespace com::github::doevelopper::rules::sdlc::semver;

template <typename B>
log4cxx::LoggerPtr Version<B>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.semver"));

template <typename B>
Version<B>::Version() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
Version<B>::~Version() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
void Version<B>::set(std::uint8_t, std::uint8_t, std::uint8_t)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
void Version<B>::set(std::uint8_t, std::uint8_t, std::uint8_t, const char *, const char *)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
void Version<B>::set(std::uint8_t, std::uint8_t, std::uint8_t, const std::string &, const std::string &)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
void Version<B>::set(const char *)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
void Version<B>::set(const std::string &)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
int Version<B>::compareVersion(const Version & rhs) const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename B>
[[nodiscard]] auto Version<B>::major() const & -> const std::uint8_t &
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_major;
}

template <typename B>
[[nodiscard]] auto Version<B>::major() && -> std::uint8_t &&
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return std::move(m_major);
}

template <typename B>
[[nodiscard]] auto Version<B>::minor() const & -> const std::uint8_t &
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_minor;
}

template <typename B>
[[nodiscard]] auto Version<B>::minor() && -> std::uint8_t &&
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return std::move(m_minor);
}

template <typename B>
[[nodiscard]] auto Version<B>::patch() const & -> const std::uint8_t &
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_patch;
}

template <typename B>
[[nodiscard]] auto Version<B>::patch() && -> std::uint8_t &&
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return std::move(m_patch);
}

template <typename B>
std::string Version<B>::name() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::name();
}

template <typename B>
std::string Version<B>::version() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::version();
}

template <typename B>
std::string Version<B>::description() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::description();
}

template <typename B>
std::string Version<B>::copyright() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::copyright();
}

template <typename B>
std::string Version<B>::copyright_full() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::copyright_full();
}

template <typename B>
std::string Version<B>::project_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::project_str();
}

template <typename B>
std::string Version<B>::package_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::package_str();
}

template <typename B>
std::string Version<B>::author_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::author_str();
}

template <typename B>
std::string Version<B>::release_isodate_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_isodate_str();
}

template <typename B>
std::string Version<B>::release_year_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_year_str();
}

template <typename B>
std::string Version<B>::release_date_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_date_str();
}

template <typename B>
std::string Version<B>::release_time_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_time_str();
}

template <typename B>
std::string Version<B>::full_revision_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::full_revision_str();
}

template <typename B>
std::string Version<B>::revision_str() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::revision_str();
}

template <typename B>
int Version<B>::release_year() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_year();
}

template <typename B>
std::time_t Version<B>::release_epoch_time() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::release_epoch_time();
}

template <typename B>
int Version<B>::major_revision() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::major_revision();
}

template <typename B>
int Version<B>::minor_revision() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::minor_revision();
}

template <typename B>
int Version<B>::patchlevel() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return VersionInfo::patchlevel();
}
