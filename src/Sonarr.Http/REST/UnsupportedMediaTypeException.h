#pragma once

#include "../Exceptions/ApiException.h"

namespace Sonarr::Http::REST
{

    class UnsupportedMediaTypeException : public Exceptions::ApiException
    {
    public:
        UnsupportedMediaTypeException(std::string_view content = "")
            : ApiException(Exceptions::HttpStatusCode::UnsupportedMediaType, content.data())
        {
        }
    };

}