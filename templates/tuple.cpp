#include <iostream>

using namespace std;

template <size_t idx, typename Ttuple> struct TupleElement;

template <typename Tvalue, typename... Trest>
struct TupleElement<0, Tuple<Tvalue, Trest...>> {
    using type_t Tvalue;
    using TupleType_t = Tuple<Tvalue, Trest...>;
};

template <size_t idx, typename Tvalue, typename... Trest>
struct TupleElement<idx, Tuple<Tvalue, Trest...>>
    : public TupleElement<idx - 1, Tuple<Trest...> > {};


template <size_t idx, typename... Ttypes>
typename TupleElement<idx, Tuple<Ttypes>>::type_t&
get(Tuple<Ttypes...>& tuple) {
    using TupleType_t = 
        typename TupleElement<idx, Tuple<Ttypes...>>::TupleType_t;
    return static_cast<TupleType_t&>(tuple).value;
}   
