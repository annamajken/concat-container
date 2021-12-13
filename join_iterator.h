#ifndef JOIN_ITERATOR_H
#define JOIN_ITERATOR_H

template <typename T> class join_iterator {
    public:
        typedef T value_type;
        typedef typename value_type::iterator c1_begin;
        typedef typename value_type::iterator c1_end;
        typedef typename value_type::iterator c2_begin;
        typedef typename value_type::iterator c2_end;
        join_iterator(c1_begin, c1_end, c2_begin, c2_end);
    private:
}

#endif