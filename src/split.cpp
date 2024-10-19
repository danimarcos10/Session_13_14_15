#include "split.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
namespace Session_13_14_15{
    vector<string> split(const string &s){
        vector<string> elems;
        stringstream ss(s);
        for (string s; ss >> s;){
            elems.push_back(s);
        }
        return elems;
    }

}
