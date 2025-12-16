export module cango.nstd.type_trans.is_lv_ref;

import cango.nstd.type_trans.true_tv;
import cango.nstd.type_trans.false_tv;

export namespace cango {
template<typename>
struct is_left_value_reference : false_tv {};

template<typename T>
struct is_left_value_reference<T &> : true_tv {};

template<typename T>
using is_lv_ref = is_left_value_reference<T>;

/// @brief 判断给定类型是否为左值引用
/// @tparam T 待检查类型
template<typename T>
inline constexpr bool is_left_value_reference_v = is_lv_ref<T>::value;

template<typename T>
inline constexpr bool is_lv_ref_v = is_left_value_reference_v<T>;
}
