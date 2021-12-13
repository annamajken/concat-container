template <typename T>
class concatenation {
    public:
        using value_type = typename T::value_type;
        using iter = join_iterator<T>();
        concatenation(T&, T&);

        iter begin();
        iter end();
};
