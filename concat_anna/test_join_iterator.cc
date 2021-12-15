#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include"join_iterator.h"

int main()
{
    std::vector<int> a{1, 2, 3};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> it(a.begin(), a.end());
    join_iterator<iter_type> it2(a.begin() + 1, a.end());
    auto test = *it;
    ++it;
    test = *it;
    ++it;
    test = *it;
    it++;
    test = *it;

    
    
}
