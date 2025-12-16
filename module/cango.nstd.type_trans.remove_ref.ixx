export module cango.nstd.type_trans.remove_ref;

import cango.nstd.type_trans.just_type;

export namespace cango {
template<typename T>
struct remove_reference : just_type<T> {};

template<typename T>
struct remove_reference<T &> : remove_reference<T> {};

template<typename T>
struct remove_reference<T &&> : remove_reference<T> {};

template<typename T>
using remove_ref = remove_reference<T>;

/// @brief 移除目标类型的引用修饰
/// @tparam T 目标类型
template<typename T>
using remove_reference_t = remove_ref<T>::type;

template<typename T>
using remove_ref_t = remove_reference_t<T>;
};
