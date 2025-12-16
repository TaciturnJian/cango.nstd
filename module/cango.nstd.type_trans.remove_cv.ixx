export module cango.nstd.type_trans.remove_cv;

import cango.nstd.type_trans.remove_v;
import cango.nstd.type_trans.remove_c;

export namespace cango {
template<typename T>
using remove_cv = remove_v<remove_c_t<T> >;

/// @brief 移除目标类型的 const 和 volatile 修饰
/// @tparam T 目标类型
template<typename T>
using remove_cv_t = remove_cv<T>::type;
};
