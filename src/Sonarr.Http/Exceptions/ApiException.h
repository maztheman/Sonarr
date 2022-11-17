#pragma once

namespace Sonarr::Http::Exceptions
{
    enum class HttpStatusCode
    {
        NotFound, //404
        UnsupportedMediaType, //whateva
        MethodNotAllowed, //304 or something,
        BadRequest, //
    };

    inline std::string ToString(HttpStatusCode value)
    {
        return "na";
    }


    class ApiException : std::exception
    {
    protected:
        
        ApiException(HttpStatusCode statusCode, std::string content = "")
            : m_StatusCode(statusCode)
            , m_Content(content)
            , std::exception(GetMessage(statusCode, content))
        {
        }

    private:

        HttpStatusCode m_StatusCode;
        std::string m_Content;

        static std::string GetMessage(HttpStatusCode statusCode, std::string content)
        {
            auto result = ToString(statusCode);

            if (!content.empty())
            {
                result = fmt::format("{}: {}", result, content);
            }

            return result;
        }
    };
}