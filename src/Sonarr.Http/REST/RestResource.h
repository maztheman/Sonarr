#pragma once

namespace Sonarr::Http::REST
{
    struct Type
    {
        std::string_view FullName;
        std::string_view Name;
    };


    class RestResource
    {
    public:

        virtual const Type& GetType() const = 0; 
        /* example impl:
        {
            static Type type = {
                "Sonarr.Http.REST.RestResource",
                "RestResource"
            };
            return type;
        };
        */
        virtual int GetId() const = 0;
        virtual void SetId(int value) = 0;

        virtual const std::string& GetResourceName() const
        {
            static std::string retval = ModifyResourceName(GetType());
            return retval;
        }

    private:
        static std::string ModifyResourceName(const Type& type)
        {
            std::string retval = type.Name.data();
            //replace(retval, "resource", "");
            return retval;
        }
    };
}