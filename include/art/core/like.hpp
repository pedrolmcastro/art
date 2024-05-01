#ifndef ART_CORE_LIKE_HPP
#define ART_CORE_LIKE_HPP


#include <concepts>
#include <type_traits>

#include "art/core/different_from.hpp"
#include "art/core/same_as_any_of.hpp"


namespace art {
    template<class T, class U>
    concept like = std::same_as<std::remove_cvref_t<T>, std::remove_cvref_t<U>>;

    template<class T, class... Types>
    concept like_any_of = same_as_any_of<std::remove_cvref_t<T>, std::remove_cvref_t<Types>...>;


    template<class T, class U>
    concept unlike = different_from<std::remove_cvref_t<T>, std::remove_cvref_t<U>>;

    template<class T, class... Types>
    concept unlike_all_of = different_from_all_of<std::remove_cvref_t<T>, std::remove_cvref_t<Types>...>;
}


#endif
