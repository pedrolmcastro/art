#ifndef ART_COMPARISON_BOOLEAN_TESTABLE_HPP
#define ART_COMPARISON_BOOLEAN_TESTABLE_HPP


#include <utility>
#include <concepts>


namespace art::detail {
    template<class B> concept boolean_testable_impl = std::convertible_to<B, bool>;
}

namespace art {
    // https://en.cppreference.com/w/cpp/concepts/boolean-testable
    template<class B> concept boolean_testable =
        detail::boolean_testable_impl<B> and
        requires (B&& b) { { not std::forward<B>(b) } -> detail::boolean_testable_impl; }
    ;
}


#endif
