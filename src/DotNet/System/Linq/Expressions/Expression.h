#pragma once

namespace System::Linq::Expressions
{
    template<typename object, typename Func>
    struct ExpressionWrapper
    {
        using ValueT = typename object::value_type;

        ExpressionWrapper(object& obj)
        : m_obj(obj)
        {

        }

        ValueT SingleOrDefault()
        {
            auto it = std::find(std::begin(m_obj), std::end(m_obj), Func{});
            return it != std::end(m_obj) ? *it : ValueT{};
        }

        object& m_obj;
    };


    template<typename Func>
    class Expression
    {
    public:

        template<typename object>
        ExpressionWrapper operator()(object& obj)
        {
            return ExpressionWrapper<object, Func>{obj};
        }

    };
}
