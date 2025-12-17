export module cango.nstd.type_trans.remove_v;

import cango.nstd.type_trans.just_type;

export namespace cango {
template<typename T>
struct remove_volatile : just_type<T> {};

template<typename T>
struct remove_volatile<volatile T> : remove_volatile<T> {};

template<typename T>
using remove_v = remove_volatile<T>;

/// @brief 移除目标类型的 volatile 修饰
/// @tparam T 目标类型
template<typename T>
using remove_volatile_t = remove_v<T>::type;

template<typename T>
using remove_v_t = remove_volatile_t<T>;
}
