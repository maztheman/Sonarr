#pragma once

#include "../Exceptions/ApiException.h"

namespace Sonarr::Http::REST
{
    using namespace Sonarr::Http::Exceptions;

    class BadRequestException : ApiException
    {
    public:
        BadRequestException(std::string content = "")
            : ApiException(HttpStatusCode::BadRequest, content)
        {
        }
    }
}