#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_ALL_OF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_ALL_OF

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<template<typename>typename, bool, typename...>
struct all_of : true_tv {};

template<template<typename>typename TPredicate, typename... TList>
struct all_of<TPredicate, false, TList...> : false_tv {};

template<template<typename>typename TPredicate, typename TFirst, typename... TRest>
struct all_of<TPredicate, true, TFirst, TRest...> : all_of<TPredicate, TPredicate<TFirst>::value, TRest...> {};

/// @brief 判断给定的类型列表是否所有类型都满足目标谓词
/// @tparam TPredicate 断言谓词，Predicate<T> 应当有 static bool value 成员以指示谓词是否成立
/// @tparam TList 待检查的类型列表
template<template<typename>typename TPredicate, typename...TList>
inline constexpr bool all_of_v = all_of<TPredicate, true, TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_ALL_OF
