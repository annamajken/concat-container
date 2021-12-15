#include <string>
#include <utility>

// T is an iterator type
template <typename Iterator>
class join_iterator
{
public:
    using value_type = typename Iterator::value_type;
    using iterator_category = std::input_iterator_tag;
    using difference_type = typename Iterator::difference_type;
    using pointer = value_type *;
    using reference = value_type &;

    join_iterator(Iterator begin, Iterator end) : first(begin), last(end), _pos(begin) {}


    reference operator*()
    {
        return *_pos;
    }

    Iterator& operator++()
    {
        _pos++;
        return _pos;
    }

    Iterator operator++(int)
    {
        Iterator res = _pos;
        _pos++;
        return res;
    }

    // returns true if iterators are pointing to the same element
    bool operator==(const join_iterator other)
    {
        return _pos == other._pos;
    }

    // returns true if iterators are pointing to different elements
    bool operator!=(const join_iterator other)
    {
        return !(_pos == other._pos);
    }

private:
    Iterator first;
    Iterator last;
    Iterator _pos;
};
