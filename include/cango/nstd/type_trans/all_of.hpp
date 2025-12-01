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
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_ALL_OF
