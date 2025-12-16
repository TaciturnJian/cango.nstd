export module cango.nstd.type_trans.is_ref;

import cango.nstd.type_trans.logic_or;
import cango.nstd.type_trans.is_lv_ref;
import cango.nstd.type_trans.is_rv_ref;

export namespace cango {
template<typename T>
using is_reference = logic_or<is_lv_ref_v<T>, is_rv_ref_v<T> >;

template<typename T>
using is_ref = is_reference<T>;

/// @brief 判断给定类型是否为引用类型
/// @tparam T 待检查的类型
template<typename T>
inline constexpr bool is_reference_v = is_ref<T>::value;

template<typename T>
inline constexpr bool is_ref_v = is_reference_v<T>;
}
