export module cango.nstd.type_trans.false_tv;

import cango.nstd.type_trans.type_value;

export namespace cango {
/// @brief 逻辑假对应的类型
using false_type_value = type_value<bool, false>;
using false_tv = false_type_value;
}
