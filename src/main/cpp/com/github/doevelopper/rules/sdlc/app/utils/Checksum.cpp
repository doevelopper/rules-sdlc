
#include <openssl/md5.h>
#include <openssl/sha.h>

#include <com/github/doevelopper/rules/sdlc/app/utils/Checksum.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

log4cxx::LoggerPtr Checksum::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.Checksum"));

Checksum::Checksum()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Checksum::~Checksum()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string Checksum::toHex(std::vector<std::uint8_t> const & digest)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    static const char alphabet[] = "0123456789abcdef";
    std::string dest(digest.size() * 2, 0);
    size_t j = 0;
    for (size_t i = 0; i < digest.size(); i++)
    {
        dest[j++] = alphabet[digest[i] >> 4];
        dest[j++] = alphabet[digest[i] & 0x0F];
    }
}

std::vector<std::uint8_t> Checksum::sha256sum(void const * data, size_t len)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::vector<uint8_t> digest(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data, len);
    SHA256_Final(digest.data(), &ctx);
    return digest;
}

std::vector<std::uint8_t> Checksum::sha256sum(std::string_view data)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return sha256sum(data.data(), data.size());
}

std::vector<std::uint8_t> Checksum::sha256sum(std::vector<std::uint8_t> const & data)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return sha256sum(data.data(), data.size());
}

std::vector<std::uint8_t> Checksum::md5sum(void const * data, size_t len)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::vector<uint8_t> digest(MD5_DIGEST_LENGTH);
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, len);
    MD5_Final(digest.data(), &ctx);
}

std::vector<std::uint8_t> Checksum::md5sum(std::string_view data)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return md5sum(data.data(), data.size());
}

std::vector<std::uint8_t> Checksum::md5sum(std::vector<std::uint8_t> const & data)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return md5sum(data.data(), data.size());
}
