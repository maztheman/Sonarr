#pragma once

#include "DotNet/FluentValidation/AbstractValidator.h"
#include "DotNet/FluentValidation/IRuleBuilderInitial.h"
#include "DotNet/System/Collections/Generic/IEnumerable.h"
#include "DotNet/System/Linq/Expressions/Expression.h"
#include "DotNet/System/Reflections/Field.h"

namespace Sonarr::Http::REST
{
    //this is going to be tricky.
    using namespace FluentValidation;
    using namespace System::Collections::Generic;
    using namespace System::Linq::Expressions;


    template<typename TResource>
    class ResourceValidator : AbstractValidator<TResource>
    {
    public:
        template<typename TProperty>
        IRuleBuilderInitial<TResource, TProperty> RuleForField<TProperty>(Expression<Func<TResource, IEnumerable<Field>>> fieldListAccessor, std::string fieldName)
        {
            auto rule = std::make_shared<PropertyRule>(fieldListAccessor.GetMember(), [] (auto&& c) { return GetValue(c, fieldListAccessor.Compile(), fieldName) }, null, () => CascadeMode.Continue, typeof(TProperty), typeof(TResource));
            rule.PropertyName = fieldName;
            rule.DisplayName = std::make_shared<StaticStringSource>(fieldName);
            AddRule(rule);
            return std::make_shared<RuleBuilder<TResource, TProperty>>(rule, this);
        }

    private:
        static object GetValue(object container, Func<TResource, IEnumerable<Field>> fieldListAccessor, string fieldName)
        {
            auto resource = fieldListAccessor((TResource)container).SingleOrDefault(c => c.Name == fieldName);

            if (resource == nullptr)
            {
                return nullptr;
            }

            return resource.Value;
        }
    }
}
