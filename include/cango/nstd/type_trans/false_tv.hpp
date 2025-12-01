#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_FALSE_TV
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_FALSE_TV

#include "type_value.hpp"

namespace cango::nstd::type_trans {
/// @brief 逻辑假对应的类型
using false_type_value = type_value<bool, false>;
using false_tv = false_type_value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_FALSE_TV
