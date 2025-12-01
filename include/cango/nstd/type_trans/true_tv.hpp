#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_TRUE_TV
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_TRUE_TV

#include "type_value.hpp"

namespace cango::nstd::type_trans {
/// @brief 逻辑真对应的类型
using true_type_value = type_value<bool, true>;
using true_tv = true_type_value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_TRUE_TV
