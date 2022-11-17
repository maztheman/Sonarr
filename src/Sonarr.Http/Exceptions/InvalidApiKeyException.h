#pragma once

namespace Sonarr::Http::Exceptions
{
    class InvalidApiKeyException : std::exception
    {
    public:
        InvalidApiKeyException()
        {
        }

        InvalidApiKeyException(const std::string& message)
            : std::exception(message)
        {
        }
    };
}
