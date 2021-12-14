#include <string>
#include <utility>

// T is an iterator type
template <typename T> 
class join_iterator {
    public:
       using value_type = typename T::value_type;
       using iterator_category = std::input_iterator_tag;
       using difference_type = typename T::difference_type;
       using pointer = value_type*;
       using reference = value_type&;

       join_iterator<value_type> (T begin, T end, T* nextCollection) : first(begin), last(end), next(nextCollection) {} ;
       T* getNext() const {
           return next; 
       }
       std::string testNext() {
           std::string s = "this collection is last";
           if (next != nullptr) {
               s = "there is another collection after this";
           }
           return s;
       }

      
    private:
        T first;
        T last;
        T* next = nullptr;
};
