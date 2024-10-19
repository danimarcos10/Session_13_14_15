#include "my_type.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace Session_13_14_15 {
    void writeToFile(const MyType& mt, const std::string& filename){
        // Write the MyType object to a file with the given filename
        ofstream outfile(filename);
        if (!outfile){
            cerr<< "Error opening the file" <<endl;
        }
        outfile<< mt << endl;
    }

    MyType readFromFile(const std::string& filename){
        // Read the MyType object from a file with the given filename and return it
        ifstream infile(filename);
        if (!infile){
            cerr<< "Error opening the file" <<endl;
        }
        //I stored a temporary object to retrieve the members in the Mytype Class.
        MyType mt(0, 0.0);
        infile>>mt;

        return mt;
    }
}