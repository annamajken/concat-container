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

    join_iterator(Iterator start, Iterator end) : begin(start), currEnd(end), _pos(&(*start)) {}


    reference operator*()
    {
        return *_pos;
    }

    Iterator& operator++()
    {
        _pos++;
        return *this;
    }

private:

    Iterator begin;
    Iterator currEnd;
    pointer _pos;
};
