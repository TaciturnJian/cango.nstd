#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_AT
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_AT

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<unsigned int, typename...>
struct type_at;

template<typename TFirst, typename... TRest>
struct type_at<0, TFirst, TRest...> : just_type<TFirst> {
    using is_found = true_tv;
};

template<unsigned int N, typename TFirst, typename... TRest>
struct type_at<N, TFirst, TRest...> : type_at<N - 1, TRest...> {};

template<unsigned int N>
struct type_at<N> {
    using is_found = false_tv;
};

/// @brief 给定目标类型列表中位于下标 N 位置的类型
/// @tparam N 下标
/// @tparam TList 类型列表
template<unsigned int N, typename... TList>
using type_at_t = type_at<N, TList...>::type;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_AT
