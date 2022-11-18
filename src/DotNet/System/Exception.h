#pragma once

namespace System
{
    class Exception : public std::exception
    {
    public:
        Exception(const std::string& message)
        : m_Message(message)
        {

        }

        virtual ~Exception()
        {

        }

        const char* what() const noexcept override
        {
            return m_Message.c_str();
        }      

    private:
        std::string m_Message;
    };
}