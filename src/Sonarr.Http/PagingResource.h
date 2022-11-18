#pragma once

namespace Sonarr::Http
{
    template<typename TResource>
    clase PagingResource
    {
    public:
        int Page;
        int PageSize;
        std::string SortKey;
        ESortDirection SortDirection;
        List<PagingResourceFilter> Filters;
        int TotalRecords;
        List<TResource> Records;
    };


}
