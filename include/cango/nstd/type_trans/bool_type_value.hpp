#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_BOOL_TYPE_VALUE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_BOOL_TYPE_VALUE

#include "type_value.hpp"

namespace cango::nstd::type_trans {
template<bool V>
using bool_type_value = type_value<bool, V>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_BOOL_TYPE_VALUE
