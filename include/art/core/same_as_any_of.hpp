#ifndef ART_CORE_SAME_AS_ANY_OF_HPP
#define ART_CORE_SAME_AS_ANY_OF_HPP


#include <concepts>


namespace art {
    template<class T, class... Types>
    concept same_as_any_of = (... or std::same_as<T, Types>);
}


#endif
