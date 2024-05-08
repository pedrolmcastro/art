#ifndef ART_CORE_SATISFIES_HPP
#define ART_CORE_SATISFIES_HPP


namespace art {
    // https://youtu.be/KENynEQoqCo?si=f2_r4dMMh1RQSCAa
    template<class T, auto Concept>
    concept satisfies = requires() { Concept.template operator()<T>(); };


    template<class T, template<class> class Transform, auto Concept>
    concept satisfies_after = satisfies<Transform<T>, Concept>;


    template<class T, auto... Concepts>
    concept satisfies_all_of = (... and satisfies<T, Concepts>);

    template<class T, auto... Concepts>
    concept satisfies_any_of = (... or satisfies<T, Concepts>);

    template<class T, auto... Concepts>
    concept satisfies_none_of = not satisfies_any_of<T, Concepts...>;
}


#endif
