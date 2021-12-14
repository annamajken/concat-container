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

    join_iterator(Iterator start, Iterator end, Iterator nextCollection, Iterator nextEnd) : begin(start), currPtr(&(*start)), currentEnd(end), next(nextCollection),
                                                                                             finalEnd(nextEnd) {}
    join_iterator(Iterator end) : currPtr(&(*end)), currentEnd(end), finalEnd(end) {}

    Iterator&  operator++()
    {
        if (currPtr + 1 == currentEnd)
        {
            currPtr = &(*next);
            currentEnd = finalEnd;
        }
        currPtr++;
        return *this;
    }

    reference operand *()
    {
    }
    bool operator==(const Iterator &other)
    {
        return currPtr == other.currPtr;
    }

private:
    Iterator begin;
    pointer currPtr;
    Iterator currentEnd;
    Iterator next;
    Iterator finalEnd;
};
