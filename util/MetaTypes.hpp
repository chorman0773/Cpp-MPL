#ifndef __MetaTypes_hpp_2018_05_31_14_33
#define __MetaTypes_hpp_2018_05_31_14_33

#include <ratio> //For ratio
#include <type_traits> //For integral_constant, true_type, and false_type
#include <string> //For string
#include <utility> //For integer_sequence

#define metastring(str) string_converter<sizeof(str),0,str>::type

using std::integer_sequence;
using std::string;



template<char... chars> struct meta_string{
  constexpr static const char str[] = {chars...};
  constexpr static const size_t length = sizeof...(chars);
  constexpr meta_string() = default;
  constexpr string operator()()const{
    return string(str);
  }
};

namespace detail{
  template<size_t N,size_t I = 0,char string[N],char... chars> struct string_converter: string_converter<N,I+1,string,chars...,string[I]>{};
  template<size_t N,char string[N],char... chars>  struct string_converter<N,N-1,string,chars...>{
    typedef meta_string<chars...> type;
  };
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
