export module cango.nstd.type_trans.type_value;

import cango.nstd.type_trans.just_type;
import cango.nstd.type_trans.just_value;

export namespace cango {
/// @brief 内部 type 和 value 为目标类型和目标值
/// @tparam T 目标类型
/// @tparam V 目标值
template<typename T, T V>
struct type_value : just_type<T>, just_value<T, V> {};
}
