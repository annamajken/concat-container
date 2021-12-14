#include <string>
#include <utility>

// T is an iterator type
template <typename Iterator> 
class join_iterator {
    public:
       using value_type = typename Iterator::value_type;
       using iterator_category = std::input_iterator_tag;
       using difference_type = typename Iterator::difference_type;
       using pointer = value_type*;
       using reference = value_type&;

       join_iterator(Iterator start, Iterator end, Iterator nextCollection) : begin(start), currPtr(&(*begin)), currentEnd(end), next(nextCollection) {} 
       join_iterator(Iterator end) : currentEnd(end) {}
       
       Iterator& operator++() 
       { 
           if (currPtr + 1 == currentEnd) {
               currPtr = &(*next);
               currentEnd
           }
           currPtr++;
           return *this;
       }

       Iterator& begin()
       {
           return begin;
       }

    private:
        Iterator begin = nullptr;
        pointer currPtr = nullptr;
        Iterator currentEnd;
        Iterator next = nullptr;
        
};
