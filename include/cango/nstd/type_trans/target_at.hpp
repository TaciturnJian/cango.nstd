#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_TARGET_AT
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_TARGET_AT

#include "is_same.hpp"

namespace cango::nstd::type_trans {
template<typename T>
struct target_at {
    using type = T;

    template<typename T1>
    using is_target = is_same<T1, T>;
};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_TARGET_AT
