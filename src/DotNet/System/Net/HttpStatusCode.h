#pragma once

namespace System::Net
{
    enum class HttpStatusCode
    {
        NotFound, //404
        UnsupportedMediaType, //whateva
        MethodNotAllowed, //304 or something,
        BadRequest, //
    };

    inline std::string_view ToString(HttpStatusCode value)
    {
        using namespace std::string_view_literals;

        return "na"sv;
    }
}