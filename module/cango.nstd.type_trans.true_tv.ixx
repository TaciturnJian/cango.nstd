export module cango.nstd.type_trans.true_tv;

import cango.nstd.type_trans.type_value;

export namespace cango {
/// @brief 逻辑真对应的类型
using true_type_value = type_value<bool, true>;
using true_tv = true_type_value;
}
