
#ifndef RULES_SDLC_STD_SEMVER_VERSIONERROR_HPP
#define RULES_SDLC_STD_SEMVER_VERSIONERROR_HPP

#include <iostream>
#include <stdexcept>
#include <string_view>

#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::semver
{
	class VersionError :public std::exception
	{
		LOG4CXX_DECLARE_STATIC_LOGGER
  public:
		VersionError() noexcept;
		VersionError(const VersionError&) noexcept = default;
		VersionError(VersionError&&) noexcept =  default;
		VersionError& operator=(const VersionError&) noexcept = default;
		VersionError& operator=(VersionError&&) noexcept = default;

    /*!
    * "brief Destructor. Virtual to allow for subclassing.
     */
		virtual ~VersionError() noexcept;

    /*!
     *  @brief Constructor (C strings).
     *  @param message[in,out] C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller.
     */
    explicit VersionError(const char* message);

    /*!
     * @brief Constructor (C++ STL strings).
     * @param[in,out] message The error message.
     */
    explicit VersionError(const std::string& message);

    /*!
     *  @brief Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in posession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
    virtual const char* what() const noexcept override;
  protected:
  private:
    std::string m_msg;
  };
}
#endif
