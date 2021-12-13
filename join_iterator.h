#ifndef JOIN_ITERATOR_H
#define JOIN_ITERATOR_H


// T is an iterator type
template <typename T> class join_iterator {
    public:
        typedef T iter_type;
        typedef iter_type c1_begin;
       
        // eller ska man bara ta in två collections istället
        // då kan man ju få tag på iteratorerna i denna klassen
        join_iterator(iter_type& c1_begin, iter_type& c2_begin);
        join_iterator()

    private:
}

#endif