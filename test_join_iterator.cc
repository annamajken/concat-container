#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include "join_iterator.h"

int main()
{   
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{2, 3, 4};
    using iter_type = decltype(a.begin());
    join_iterator<iter_type> j_iter(a.begin(), a.end(), nullptr);
    std::string res = j_iter.testNext();
    std::cout << res << std::endl;
}