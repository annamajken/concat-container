/**
 * Prints the content of a container to an std::string.
 * @tparam T The container to be printed.
 * @return a string representation of the container.
 */

#include <sstream>

template <typename T>
std::string print(T& container)
{
    std::stringstream ss{};
    using value_type = typename T::value_type;
    for (value_type& elem : container) {
        ss << elem << " ";
    }
    return ss.str();

}