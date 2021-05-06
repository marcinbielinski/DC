#include <iostream>
#include <functional>

template <typename VectorType>
struct C {
    template <typename Container, typename Function>
    void forEach(Container values, Function func) {
        for (const VectorType &elem : values) {
            func(elem);
        }
    }
};
int main() {
    std::vector<int> my_vec = { 1, 2, 5, 10, 3, 2, 1 };
    std::vector<std::string> my_vec2 { "bunch", "of", "very", "cool", "string" };

    std::function<void(int)> lamb = [](int value) { std::cout << "Value: " << value << std::endl; };
    std::function<void(int)> lamb2 = [](int value) { std::cout << "Multiplied value: " << value*10 << std::endl; };
    std::function<void(double)> lamb3 = [](double value) { std::cout << "Value(double): " << value << std::endl; };
    std::function<void(std::string)> lamb4 = [](std::string str) { std::cout << "String: " << str << std::endl; };

    C<int> object;
    C<std::string> object2;

    object.forEach(my_vec, lamb);
    object.forEach(my_vec, lamb2);
    object.forEach(my_vec, lamb3);
    object2.forEach(my_vec2, lamb4);
    return 0;
}
