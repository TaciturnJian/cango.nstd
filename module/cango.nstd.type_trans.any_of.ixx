export module cango.nstd.type_trans.any_of;

import cango.nstd.type_trans.true_tv;
import cango.nstd.type_trans.false_tv;

export namespace cango {
template<template<typename>typename, bool, typename...>
struct any_of : false_tv {};

template<template<typename>typename TPredicate, typename... TList>
struct any_of<TPredicate, true, TList...> : true_tv {};

template<template<typename>typename TPredicate, typename TFirst, typename... TRest>
struct any_of<TPredicate, false, TFirst, TRest...> : any_of<TPredicate, TPredicate<TFirst>::value, TRest...> {};

/// @brief 判断给定的类型列表是否存在一个满足目标谓词的类型
/// @tparam TPredicate 断言谓词，Predicate<T> 应当有 static bool value 成员以指示谓词是否成立
/// @tparam TList 待检查的类型列表
template<template<typename>typename TPredicate, typename... TList>
inline constexpr bool any_of_v = any_of<TPredicate, false, TList...>::value;
}
