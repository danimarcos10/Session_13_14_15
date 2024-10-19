//include/transform.h
#pragma once
namespace Session_13_14_15 {
    /**
    * @brief A function that transforms each element of a container in place.↪→
    * @tparam Container The type of the container.
    * @tparam UnaryFunction The type of the function that transforms the elements.↪→
    * @param container The container to transform.
    * @param function The function that transforms the elements.
    */
    template <typename Container, typename Func>
    
    void transform(Container& container, Func function){
        for(auto& x: container)
            x = function(x);
    }
} // namespace Session_13_14_15