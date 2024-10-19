// include/flexible_container.h
#pragma once
#include <vector>
#include <stdexcept>
namespace Session_13_14_15 {
    /**
    * @brief A flexible container that can hold elements of any type.
    * @tparam T The type of the elements in the container.
    */
   template <typename T = int>
    class FlexibleContainer {
    private:
        std::vector<T> elements;

    public:

        FlexibleContainer() {};

        /**
         * @brief We use a constructor and the vardiac template to get the elements.
         * @tparam Args This shows the types of elements we want to add.
         * @param args These are the elements we are adding.
         */
        template <typename... Args>
        FlexibleContainer(Args... args) {
            (add(args), ...);
        }
        
        /**
         * @brief This is a add function that adds the elements to the flexible container.
         * @param element The elements we are adding.
         */       
        void add(const T& element){
            elements.push_back(element);
        }
        
        /**
         * @brief Getting the number of elements that are in the cointainer
         * @return The number of elements in the container
         */
        int size() const{
            return elements.size();
        }

        /**
         * @brief Get a particular element in the container.
         * @param index The index of the element we are getting.
         * @return The element at the given index
         */
        T get(int index) const{
            if (index < 0 || index >= size()) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        /**
         * @brief Applying a function to each of the elements in the container created.
         * @tparam Func This shows the type of function to apply.
         * @param func The function to apply.
         */
        template <typename Func>
        void map(Func func){
            for(auto& element : elements){
                element = func(element);
            }
        }
    };
} // namespace Session_13_14_15