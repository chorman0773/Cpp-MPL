#ifndef __MetaTypes_hpp_2018_05_31_14_33
#define __MetaTypes_hpp_2018_05_31_14_33

#include <ratio> //For ratio
#include <type_traits> //For integral_constant, true_type, and false_type
#include <string> //For string

using std::string;

namespace detail{
  
};

typedef<char... chars> struct meta_string{
  constexpr static const char str[] = {chars...};
  constexpr static const size_t length = sizeof...(chars);
  constexpr meta_string() = default;
  constexpr string operator()(){
    return string(str);
  }
};



using std::integral_constant;
using std::false_type;
using std::true_type;

template<int i> struct meta_int:integral_constant<int,i>{};
template<size_t s> struct meta_size:integral_constant<size_t,s>{};

template<long long l> struct meta_long:integral_constant<long long,l>{};
template<unsigned long long ul> struct meta_long:integral_constant<unsigned long long,ul>{};

template<bool> struct meta_boolean:false_type{};
template<> struct meta_boolean<true>:true_type{};

#endif
