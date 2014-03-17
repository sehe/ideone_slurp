// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-01-26 18:46:25
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/flyweight.hpp>

using namespace boost;
using namespace boost::flyweights;
typedef flyweight<
    std::string,
    hashed_factory<
        boost::hash<std::string>,
        std::equal_to<std::string>,
        std::allocator<boost::mpl::_1> // here we get errors like C2065: 'key_value' : undeclared identifier    
    >
> customString;

typedef std::map<customString, customString> Map;

void pass_and_modify_data(boost::shared_ptr<Map> map) { /* TBI */ }

int main()
{
    // boring part -  load plugin... into something like boost::shared_ptr<plugin> my_plugin 
    //intresting part - create map in main heap and make all its values and keys be forced to be allocated or reallocated in main heap

    std::cout << std::endl << "Map allocator based memory management:" << std::endl;
    std::cin.get();
    {
        customString x;
        Map xxx;
        boost::shared_ptr<Map > a  (new Map());
        pass_and_modify_data(a);

        customString key1("hello"), key2("world");

        std::cout << "modified data: " << (*a)[key1] << (*a)[key2] << std::endl;
    }
    std::cout << "removed data" << std::endl;
    std::cin.get();

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
/home/5FmZyt/cc61g3Fa.o: In function `global constructors keyed to _Z20pass_and_modify_dataN5boost10shared_ptrISt3mapINS_10flyweights9flyweightISsNS2_14hashed_factoryINS_4hashISsEESt8equal_toISsESaIN4mpl_3argILi1EEEELi0EEENS_9parameter5void_ESF_SF_SF_EESG_St4lessISG_ESaISt4pairIKSG_SG_EEEEE':
prog.cpp:(.text+0x130b): undefined reference to `pthread_mutexattr_init'
prog.cpp:(.text+0x131b): undefined reference to `pthread_mutexattr_settype'
prog.cpp:(.text+0x1333): undefined reference to `pthread_mutexattr_destroy'
/home/5FmZyt/cc61g3Fa.o: In function `boost::flyweights::static_holder_class<boost::flyweights::detail::flyweight_core<boost::flyweights::detail::default_value_policy<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, mpl_::na, boost::flyweights::refcounted, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::flyweights::simple_locking, boost::flyweights::static_holder>::holder_arg>::get()':
prog.cpp:(.text._ZN5boost10flyweights19static_holder_classINS0_6detail14flyweight_coreINS2_20default_value_policyISsEEN4mpl_2naENS0_10refcountedENS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaINS6_3argILi1EEEELi0EEENS0_14simple_lockingENS0_13static_holderEE10holder_argEE3getEv[boost::flyweights::static_holder_class<boost::flyweights::detail::flyweight_core<boost::flyweights::detail::default_value_policy<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, mpl_::na, boost::flyweights::refcounted, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::flyweights::simple_locking, boost::flyweights::static_holder>::holder_arg>::get()]+0x124): undefined reference to `pthread_mutexattr_init'
prog.cpp:(.text._ZN5boost10flyweights19static_holder_classINS0_6detail14flyweight_coreINS2_20default_value_policyISsEEN4mpl_2naENS0_10refcountedENS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaINS6_3argILi1EEEELi0EEENS0_14simple_lockingENS0_13static_holderEE10holder_argEE3getEv[boost::flyweights::static_holder_class<boost::flyweights::detail::flyweight_core<boost::flyweights::detail::default_value_policy<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, mpl_::na, boost::flyweights::refcounted, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::flyweights::simple_locking, boost::flyweights::static_holder>::holder_arg>::get()]+0x134): undefined reference to `pthread_mutexattr_settype'
prog.cpp:(.text._ZN5boost10flyweights19static_holder_classINS0_6detail14flyweight_coreINS2_20default_value_policyISsEEN4mpl_2naENS0_10refcountedENS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaINS6_3argILi1EEEELi0EEENS0_14simple_lockingENS0_13static_holderEE10holder_argEE3getEv[boost::flyweights::static_holder_class<boost::flyweights::detail::flyweight_core<boost::flyweights::detail::default_value_policy<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, mpl_::na, boost::flyweights::refcounted, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::flyweights::simple_locking, boost::flyweights::static_holder>::holder_arg>::get()]+0x14c): undefined reference to `pthread_mutexattr_destroy'
/home/5FmZyt/cc61g3Fa.o: In function `boost::flyweights::flyweight<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::flyweight()':
prog.cpp:(.text._ZN5boost10flyweights9flyweightISsNS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaIN4mpl_3argILi1EEEELi0EEENS_9parameter5void_ESD_SD_SD_EC1Ev[boost::flyweights::flyweight<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::flyweight()]+0x6ab): undefined reference to `pthread_mutexattr_init'
prog.cpp:(.text._ZN5boost10flyweights9flyweightISsNS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaIN4mpl_3argILi1EEEELi0EEENS_9parameter5void_ESD_SD_SD_EC1Ev[boost::flyweights::flyweight<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::flyweight()]+0x6bb): undefined reference to `pthread_mutexattr_settype'
prog.cpp:(.text._ZN5boost10flyweights9flyweightISsNS0_14hashed_factoryINS_4hashISsEESt8equal_toISsESaIN4mpl_3argILi1EEEELi0EEENS_9parameter5void_ESD_SD_SD_EC1Ev[boost::flyweights::flyweight<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, boost::flyweights::hashed_factory<boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<mpl_::arg<1> >, 0>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::flyweight()]+0x6d3): undefined reference to `pthread_mutexattr_destroy'
collect2: ld returned 1 exit status

#endif
