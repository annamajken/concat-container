template<typename T>
class concatenation{
    public:
        using value_type = typename T::value_type;
        using iter = join_iterator<typename T::iterator>;
        concatenation(T& c1, T& c2) : collection1(c1), collection2(c2) {}
        

        iter begin() {
            return iter{collection1.begin(), collection1.end(), collection2.begin()};
        }
        iter end() {
            return iter{collection2.end()};
        }

        void push_back(const value_type& newItem) {
            collection2.push_back(newItem);
        }

    private:
        T& collection1;
        T& collection2;
};
