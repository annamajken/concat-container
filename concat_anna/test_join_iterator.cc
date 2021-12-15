#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>

#include"join_iterator.h"
#include"concatenation.h"

using std::vector;
using std::cout;
using std::endl;

void equalsOperators() {
    cout << "-------- Testing == and != --------" << endl;
    vector<int> a{1, 2, 3};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> it1(a.begin(), a.end(), a.end());
    join_iterator<iter_type> it2(a.begin() + 1, a.end(), a.end());
   
    bool equals = !(it1 == it2);
    bool notEquals = (it1 != it2);
    
    if(equals && notEquals) cout << "== and != PASSED" << endl;
    else cout << "== and != FAILED" << endl;
    cout << endl;
}

void incrementOperators() { 
    cout << "-------- Testing ++it and it++ --------" << endl;
    vector<int> a{1, 2, 3};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> it1(a.begin(), a.end(), a.end());
    join_iterator<iter_type> it2(a.begin(), a.end(), a.end());
    join_iterator<iter_type> it3(a.begin() + 1, a.end(), a.end());
    it1++;
    ++it2;

    bool test1 = it1 == it3;
    bool test2 = it2 == it3;
    
    if(test1 && test2) cout << "++it and it++ PASSED" << endl;
    else cout << "++it and it++ FAILED" << endl;
    cout << endl;
}

void iterate() { 
    cout << "-------- Testing iteration --------" << endl;

    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
    using iterType = decltype(a.begin());

    for(join_iterator<iterType> it{a.begin(), a.end(), b.begin()}; 
        it != join_iterator<iterType>{b.end()}; it++) { 
        cout << *it << " ";
    }
    cout << endl;

    for(join_iterator<iterType> it{a.begin(), a.end(), b.begin()}; 
        it != join_iterator<iterType>{b.end()}; ++it) { 
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
}

void copy() { 
    cout << "-------- Testing std::copy --------" << endl;
    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
    vector<int> c{};
    
    using iterType = decltype(a.begin());
    join_iterator<iterType> itBegin{a.begin(), a.end(), b.begin()};
    join_iterator<iterType> itEnd{b.end()};

    std::copy(itBegin, itEnd, std::back_inserter(c));
    for(int i : c) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

}

void testConcatenation() {
     cout << "-------- Testing concatenation --------" << endl;
     
    vector<std::string> a{"hej", "på", "dig"};
    vector<std::string> b{"din", "fule", "faan"};

    using collectionType = decltype(a);
    concatenation<collectionType> conCat(a, b);
    for (auto& item : conCat) {
        cout << item << " ";
    }
    cout << endl;
    cout << endl;

}

void testConcatCopy() {
    cout << "-------- Testing concatenation copy --------" << endl;
    vector<std::string> a{"hej", "på", "dig"};
    vector<std::string> b{"din", "fule", "faan"};
    using collectionType = decltype(a);
    concatenation<collectionType> conCat(a, b);
    std::vector<std::string> res{};
    std::copy(conCat.begin(), conCat.end(), std::back_inserter(res));
    for (std::string& s : res) {
        cout << s << " ";
    }
    cout << endl; cout << endl;
}

void testConcatFind() {
    cout << "-------- Testing concatenation find --------" << endl;
    vector<int> a{1, 2, 3};
    vector<int> b{6, 7, 9};
    using collectionType = decltype(a);
    concatenation<collectionType> conCat(a, b);
    auto pos1 = std::find(conCat.begin(), conCat.end(), 3);
    auto pos2 = std::find(conCat.begin(), conCat.end(), 4);
    if (pos1 != conCat.end() || pos2 == conCat.end()) {
        cout << "PASSED";
    } else {
        cout<< "FAILED";
    }
    cout << endl;
    cout << endl;
}

void testConcatWrite() {
    cout << "-------- Testing push_back--------" << endl;
    vector<std::string> a{"hej", "på", "dig"};
    vector<std::string> b{"din", "fule"};
    using collectionType = decltype(a);
    concatenation<collectionType> c{a, b};

    c.push_back("faan");
    
    for (auto& s : c) {
        cout << s << " ";
    }
    cout << endl;
    cout << endl;
}

int main() {
   equalsOperators(); 
   incrementOperators();
   iterate();
   copy();
   testConcatenation();
   testConcatCopy();
   testConcatFind();
   testConcatWrite();

}
