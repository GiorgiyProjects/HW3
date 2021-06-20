#include <iostream>
#include "pretty.h"
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <string>
#include<list>

template <typename T>
decltype(std::declval<T>().emplace_back(0), void())
print_ip(T container)
{
    std::string c = "";
    for(const auto& ip_part : container)
    {
        std::cout << c << ip_part;
        c = ".";
    }
    std::cout << std::endl;
}

template <typename T>
decltype(float(std::declval<T>()), void())
print_ip(T value)
{
    unsigned char bytes[sizeof value];
    std::copy(static_cast<const char*>(static_cast<const void*>(&value)),
              static_cast<const char*>(static_cast<const void*>(&value)) + sizeof value,
              bytes);

    std::reverse(std::begin(bytes), std::end(bytes));

    std::string c = "";
    for(const auto& b:bytes)
    {
        std::cout << c << (int)b;
        c = ".";
    }
    std::cout  << std::endl;
}

template <typename T>
decltype(stoi(std::declval<T>()), void())
print_ip(T value)
{
    std::cout << value << "\n";
}