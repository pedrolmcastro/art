#ifndef ART_CORE_SPECIALIZATION_OF_HPP
#define ART_CORE_SPECIALIZATION_OF_HPP


namespace art::detail {
    template<class, template<class...> class> inline constexpr bool is_specialization_of{false};

    template<template<class...> class Primary, class... Args>
    inline constexpr bool is_specialization_of<Primary<Args...>, Primary>{true};
}

namespace art {
    // https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p2098r0.pdf
    template<class T, template<class...> class Primary>
    concept specialization_of = detail::is_specialization_of<T, Primary>;
}


#endif
