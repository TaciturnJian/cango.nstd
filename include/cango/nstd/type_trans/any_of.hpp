#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_ANY_OF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_ANY_OF

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<template<typename>typename, bool, typename...>
struct any_of : false_tv {};

template<template<typename>typename TPredicate, typename... TList>
struct any_of<TPredicate, true, TList...> : true_tv {};

template<template<typename>typename TPredicate, typename TFirst, typename... TRest>
struct any_of<TPredicate, false, TFirst, TRest...> : any_of<TPredicate, TPredicate<TFirst>::value, TRest...> {};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_ANY_OF
