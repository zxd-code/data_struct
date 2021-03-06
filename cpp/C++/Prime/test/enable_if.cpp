#include <iostream>
#include <type_traits>

template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
is_odd (T i) {return bool(i%2);}

template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {

    short int i = 1;    // code does not compile if type of i is not integral

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;

    return 0;
}

