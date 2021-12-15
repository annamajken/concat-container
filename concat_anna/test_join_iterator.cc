#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include"join_iterator.h"

using std::vector;
using std::cout;
using std::endl;

void equalsOperators() {
    cout << "-------- Testing == and != --------" << endl;
    vector<int> a{1, 2, 3};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> it1(a.begin(), a.end());
    join_iterator<iter_type> it2(a.begin() + 1, a.end());
   
    bool equals = !(it1 == it2);
    bool notEquals = (it1 != it2);
    
    if(equals && notEquals) cout << "== and != PASSED" << endl;
    else cout << "== and != FAILED" << endl;
    cout << endl;
    cout << endl;
}

void incrementOperators() { 
    cout << "-------- Testing ++it and it++ --------" << endl;
    vector<int> a{1, 2, 3};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> it1(a.begin(), a.end());
    join_iterator<iter_type> it2(a.begin(), a.end());
    join_iterator<iter_type> it3(a.begin() + 1, a.end());
    it1++;
    ++it2;

    bool test1 = it1 == it3;
    bool test2 = it2 == it3;
    
    if(test1 && test2) cout << "++it and it++ PASSED" << endl;
    else cout << "++it and it++ FAILED" << endl;
    cout << endl;
    cout << endl;
}

void iterate() { 
    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
}

int main() {
   equalsOperators(); 
   incrementOperators();
}
