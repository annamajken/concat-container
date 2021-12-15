#include <string>
#include <utility>

using std::cout;
using std::endl;

template <typename Iterator>
class join_iterator
{
public:
    using value_type = typename Iterator::value_type;
    using iterator_category = std::input_iterator_tag;
    using difference_type = typename Iterator::difference_type;
    using pointer = value_type *;
    using reference = value_type &;

    join_iterator(Iterator fb, Iterator fe, Iterator sb):
        firstBegin(fb), 
        firstEnd(fe), 
        secondBegin(sb), 
        _pos(fb) {}

    join_iterator(Iterator se): 
        _pos(se) {}


    reference operator*() {
        return *_pos;
    }

    join_iterator& operator++() {
        if(++_pos == firstEnd) {
            _pos = secondBegin;
        }

        return *this;
    }

    join_iterator operator++(int) {
        join_iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    // returns true if iterators are pointing to the same element
    bool operator==(const join_iterator &other) const {
        return _pos == other._pos;
    }

    // returns true if iterators are pointing to different elements
    bool operator!=(const join_iterator &other) const {
        return !(_pos == other._pos);
    }

private:
    Iterator firstBegin{};
    Iterator firstEnd{};
    Iterator secondBegin{};
    Iterator _pos;
};
