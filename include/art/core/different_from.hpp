#ifndef ART_CORE_DIFFERENT_FROM_HPP
#define ART_CORE_DIFFERENT_FROM_HPP


#include <type_traits>


namespace art {
    template<class T, class U>
    concept different_from = not std::is_same_v<T, U>;

    template<class T, class... Types>
    concept different_from_all_of = (... and different_from<T, Types>);
}


#endif
