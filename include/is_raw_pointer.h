#include <iostream>
namespace Session_13_14_15{

    /**
     * @brief This allows us to  check if a type is a raw pointer or not.
     * @tparam The typename that allows us to check.
     */
    template <typename T>
    struct IsRawPointer{
        static constexpr bool value = false;

    };

    template <typename T>
    struct IsRawPointer<T*>{
        static constexpr bool value = true;
    };

    template <typename T>
    constexpr bool IsRawPointer_v = IsRawPointer<T>::value;

}