#pragma once

#include "DotNet/System/Exception.h"
#include "DotNet/System/Net/HttpStatusCode.h"

namespace Sonarr::Http::Exceptions
{
    using namespace System::Net;

    class ApiException : System::Exception
    {
    protected:
        
        ApiException(HttpStatusCode statusCode, std::string content = "")
            : m_StatusCode(statusCode)
            , m_Content(content)
            , System::Exception(GetMessage(statusCode, content))
        {
        }

        virtual ~ApiException()
        {
            
        }

    private:

        HttpStatusCode m_StatusCode;
        std::string m_Content;

        static std::string GetMessage(HttpStatusCode statusCode, std::string content)
        {
            std::string result = ToString(statusCode).data();

            if (!content.empty())
            {
                result = fmt::format("{}: {}", result, content);
            }

            return result;
        }
    };
}