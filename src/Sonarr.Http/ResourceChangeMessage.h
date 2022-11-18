#pragma once

//using System;
//using NzbDrone.Core.Datastore.Events;
//using Sonarr.Http.REST;

namespace Sonarr::Http
{
    template<typename TResource> //RestResourceT concept
    class ResourceChangeMessage<TResource>
    {
    public:

        ResourceChangeMessage(ModelAction action)
        {
            if (action != ModelAction::Deleted && action != ModelAction::Sync)
            {
                throw InvalidOperationException("Resource message without a resource needs to");
            }

            Action = action;
         }

         ResourceChangeMessage(Ref<TResource> resource, ModelAction action)
         {
            Resource = resource;
            Action = action;
         }

        Ref<TResource> Resource;
        ModelAction Action;

    };
}
