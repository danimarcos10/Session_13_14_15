// include/sum.h
#pragma once
#include <vector>
#include <string>
#include <iostream>
namespace Session_13_14_15
{
    /**
     * @brief Metafunction for summing the elements of a vector holding elements of any type
     * @param s The vector to sum
     * @param v The initial value of the sum
     * @tparam T The type of the elements in the vector
     * @return The sum of the elements in the vector, plus the initial value
     */
    template <typename T>
    auto sum_elements(std::vector<T> &s, T v)
    {
        for (const auto &elements : s)
        {
            v += elements;
        }
        return v;
    }

    // for string implementation
    template <>
    auto sum_elements <std::string>(std::vector<std::string>& s, std::string v){
        for(const auto& elements : s){
            v += elements;
        }
        std::cout << v << std::endl;
        return v;
    }
} // namespace Session_13_14_15