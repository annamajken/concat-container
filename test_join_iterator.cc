#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include "join_iterator.h"

bool test_post_increment(join_iterator<typename Iterator> ji) 
{
    ji++;
}

bool test_equals(join_iterator<typename Iterator> it_a, join_iterator<typename Iterator> it_b)
{
    return it_a == it_b;
}

int main()
{   
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{2, 3, 4};
    using iter_type = decltype(a.begin());
    // jag vill ha en pekare till b.begin() - hur?
    join_iterator<iter_type> it_begin(a.begin(), a.end(), b.begin(), b.end());
    join_iterator<iter_type> it_end(b.end());
    bool test = test_equals(it_begin, it_end);

  
}