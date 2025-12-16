export module cango.nstd.type_trans.count_of;

import cango.nstd.type_trans.just_type;
import cango.nstd.type_trans.just_value;

export namespace cango {

template<unsigned int, typename...>
struct count_of;

template<unsigned int N>
struct count_of<N> : just_value<unsigned int, N> {};

template<unsigned int N, typename TFirst, typename... TRest>
struct count_of<N, TFirst, TRest...> : count_of<N + 1, TRest...> {};

/// @brief 计算给定类型列表的长度
/// @tparam TList 类型列表
template<typename... TList>
inline constexpr unsigned int count_of_v = count_of<0, TList...>::value;
}