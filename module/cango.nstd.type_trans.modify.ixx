export module cango.nstd.type_trans.modify;

import cango.nstd.type_trans.remove_ref;
import cango.nstd.type_trans.remove_cv;
import cango.nstd.type_trans.remove_c;
import cango.nstd.type_trans.remove_v;
import cango.nstd.type_trans.remove_ref_cv;
import cango.nstd.type_trans.is_same;

export namespace cango {

/// @brief 用于修改目标类型的工具，装载目标类型后可以像命名空间一样调用静态成员，然后通过 result 成员获取结果
template<typename T>
struct modify {
    using type = T;
    using result = type;

    using add_volatile = modify<volatile type>;
    using add_v = add_volatile;

    using add_const = modify<const type>;
    using add_c = add_const;

    using add_left_value_reference = modify<type &>;
    using add_lv_ref = add_left_value_reference;

    using add_right_value_reference = modify<type &&>;
    using add_rv_ref = add_right_value_reference;

    using sub_volatile = modify<remove_v_t<type> >;
    using sub_v = sub_volatile;

    using sub_const = modify<remove_c_t<type> >;
    using sub_c = sub_const;

    using sub_reference = modify<remove_ref_t<type> >;
    using sub_ref = sub_reference;

    using sub_cv = modify<remove_cv_t<type> >;
    using sub_ref_cv = modify<remove_ref_cv_t<type> >;

    template<typename T1>
    using same_as = is_same<type, T1>;

    template<typename T1>
    static constexpr bool same_as_v = same_as<T1>::value;
};
};