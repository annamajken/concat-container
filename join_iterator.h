


// T is an iterator type
template <typename T> 
class join_iterator {
    public:
       using value_type = typename T::value_type;
       using iterator_category = std::input_iterator_tag;
       using difference_type = T::difference_type;
       using pointer = value_type*;
       using reference = value_type&;

       join_iterator<value_type>(T& begin, T& end, T* next);
    private:
        T* next = nullptr;

   
};
