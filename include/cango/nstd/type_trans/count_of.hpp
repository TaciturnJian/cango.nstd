#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_COUNT_OF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_COUNT_OF

#include "just_value.hpp"

namespace cango::nstd::type_trans {
template<unsigned int, typename...>
struct count_of;

template<unsigned int N>
struct count_of<N> : just_value<unsigned int, N> {};

template<unsigned int N, typename TFirst, typename... TRest>
struct count_of<N, TFirst, TRest...> : count_of<N + 1, TRest...> {};

template<typename... TList>
inline constexpr unsigned int count_of_v = count_of<0, TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_COUNT_OF
