#pragma once


namespace nav
{
namespace utils
{
    template <typename T, typename P>
    bool IsOneOf(const T& value, P first, P last)
    {
        for (auto& it = first; it != last; it = ++it)
        {
            if(value == *it)
            {
                return true;
            }
        }
        return false;
    }
}
}