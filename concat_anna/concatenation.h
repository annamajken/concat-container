template<typename CollectionType>
class concatenation{
    public:
        using value_type = typename CollectionType::value_type;
        using iter = join_iterator<value_type>;
        concatenation(CollectionType& c1, CollectionType& c2) : collection1(c1), collection2(c2) {}

        iter begin() {
            return it_begin;
        }
        iter end() {
            return it_end;
        }

    private:
        CollectionType& collection1;
        CollectionType& collection2;
        iter it_begin{collection1.begin(), collection1.end(), collection2.begin()};
        iter it_end{collection2.end()};

};