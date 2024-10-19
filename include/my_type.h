// include/mytype.h
#pragma once
#include <iostream>
#include <fstream>
namespace Session_13_14_15
{
    /**
     * @brief A type with some members that can be serialized
     */
    class MyType
    {
        int i;
        double d;

    public:
        MyType(int i, double d) : i(i), d(d)
        {
        }
        /**
         * @brief Equality operator
         */
        auto operator==(const MyType &other) const
        {
            return i == other.i && d == other.d;
        }

        /**
         * @brief Writing the Mytype into an output stream using ostream
         * @param mt The MyType object to write.
         * @param os The output stream we are writing into.
         */
        friend std::ostream &operator<<

            (std::ostream &os, const MyType &mt)
        {
            os << mt.i << " " << mt.d;
            return os;
        }

        /**
         * @brief Writing the Mytype into an input stream using istream
         * @param mt The MyType object to write.
         * @param is The input stream we are reading from.
         */
        friend std::istream &operator>>(std::istream &is, MyType &mt)
        {
            is >> mt.i >> mt.d;
            return is;
        }
    }; 
    /**
     * @brief Write the MyType object to a file
     * @param mt The MyType object to write
     * @param filename The name of the file to write to
     */
    void writeToFile(const MyType &mt, const std::string &filename);

    /**
     * @brief Read the MyType object from a file
     * @param filename The name of the file to read from
     * @return The MyType object read from the file
     */
    MyType readFromFile(const std::string &filename);
} // namespace Session_13_14_15
