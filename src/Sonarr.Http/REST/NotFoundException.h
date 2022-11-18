#pragma once

#include "../Exceptions/ApiException.h"

namespace Sonarr::Http::REST
{
    using namespace Sonarr::Http::Exceptions;

    class NotFoundException : ApiException
    {
    public:
        NotFoundException(std::string content = "")
            : ApiException(HttpStatusCode::NotFound, content)
        {
        }

        virtual ~NotFoundException()
        {
            
        }
    };
}