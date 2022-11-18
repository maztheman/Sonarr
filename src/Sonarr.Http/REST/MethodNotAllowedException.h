#pragma once

#include "../Exceptions/ApiException.h"

namespace Sonarr::Http::REST
{
    using namespace Sonarr::Http::Exceptions;

    class MethodNotAllowedException : ApiException
    {
    public:
         MethodNotAllowedException(std::string content = "")
            : ApiException(HttpStatusCode::MethodNotAllowed, content)
        {
        }

        virtual ~MethodNotAllowedException()
        {
            
        }
    };
}
