#pragma once

#include "DotNet/System/Exception.h"

namespace Sonarr::Http::Exceptions
{
    class InvalidApiKeyException : System::Exception
    {
    public:
        InvalidApiKeyException()
        : System::Exception("")
        {
        }

        InvalidApiKeyException(const std::string& message)
            : System::Exception(message)
        {
        }

        virtual ~InvalidApiKeyException()
        {
            
        }
    };
}
