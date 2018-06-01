#ifndef __MetaTypes_hpp_2018_05_31_14_33
#define __MetaTypes_hpp_2018_05_31_14_33

#include <ratio> //For ratio
#include <type_traits> //For integral_constant, true_type, and false_type
#include <string> //For string
#include <utility> //For integer_sequence



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
  template<size_t N,size_t... Indecies> constexpr decltype(auto) parseStringHelper(const char (&chr)[N],std::integral_sequence<Idecies...>){
    return meta_string<chr[Indecies]...>();
  }
  template<size_t N> constexpr decltype(auto) parseString(const char (&chr)[N]){
    parseStringHelper(chr,std::make_integer_sequence<N>());
  }
};

#define str(str) decltype((detail::parseString(#str)))


using std::integral_constant;
using std::false_type;
using std::true_type;

template<int i> struct meta_int:integral_constant<int,i>{};
template<size_t s> struct meta_size:integral_constant<size_t,s>{};

template<long long l> struct meta_long:integral_constant<long long,l>{};

template<bool> struct meta_boolean:false_type{};
template<> struct meta_boolean<true>:true_type{};


template<typename a,typename b> struct add;

template<int a,int b> struct add<meta_int<a>,meta_int<b>>:meta_int<a+b>{};
template<size_t a,size_t b> struct add<meta_size<a>,meta_size<b>>:meta_size<a+b>{};
template<int a,size_t b> struct add<meta_int<a>,meta_size<b>>:meta_size<a+b>{};
template<size_t a,int b> struct add<meta_size<a>,meta_int<b>>:meta_size<a+b>{};
template<long long a,long long b> struct add<meta_long<a>,meta_long<b>>:meta_long<a+b>{};
template<int a,long long b> struct add<meta_int<a>,meta_long<b>>:meta_long<a+b>{};
template<long long a,int b> struct add<meta_long<a>,meta_int<b>>:meta_long<a+b>{};
template<long long a,size_t b> struct add<meta_long<a>,meta_size<b>>:meta_long<a+b>{};
template<size_t a,long long b> struct add<meta_size<a>,meta_long<b>>:meta_long<a+b>{};

template<typename a,typename b> struct sub;

template<int a,int b> struct sub<meta_int<a>,meta_int<b>>:meta_int<a-b>{};
template<size_t a,size_t b> struct sub<meta_size<a>,meta_size<b>>:meta_size<a-b>{};
template<int a,size_t b> struct sub<meta_int<a>,meta_size<b>>:meta_size<a-b>{};
template<size_t a,int b> struct sub<meta_size<a>,meta_int<b>>:meta_size<a-b>{};
template<long long a,long long b> struct sub<meta_long<a>,meta_long<b>>:meta_long<a-b>{};
template<int a,long long b> struct sub<meta_int<a>,meta_long<b>>:meta_long<a-b>{};
template<long long a,int b> struct sub<meta_long<a>,meta_int<b>>:meta_long<a-b>{};
template<long long a,size_t b> struct sub<meta_long<a>,meta_size<b>>:meta_long<a-b>{};
template<size_t a,long long b> struct sub<meta_size<a>,meta_long<b>>:meta_long<a-b>{};

template<typename a,typename b> struct mul;

template<int a,int b> struct mul<meta_int<a>,meta_int<b>>:meta_int<a*b>{};
template<size_t a,size_t b> struct mul<meta_size<a>,meta_size<b>>:meta_size<a*b>{};
template<int a,size_t b> struct mul<meta_int<a>,meta_size<b>>:meta_size<a*b>{};
template<size_t a,int b> struct mul<meta_size<a>,meta_int<b>>:meta_size<a*b>{};
template<long long a,long long b> struct mul<meta_long<a>,meta_long<b>>:meta_long<a*b>{};
template<int a,long long b> struct mul<meta_int<a>,meta_long<b>>:meta_long<a*b>{};
template<long long a,int b> struct mul<meta_long<a>,meta_int<b>>:meta_long<a*b>{};
template<long long a,size_t b> struct mul<meta_long<a>,meta_size<b>>:meta_long<a*b>{};
template<size_t a,long long b> struct mul<meta_size<a>,meta_long<b>>:meta_long<a*b>{};

#endif
