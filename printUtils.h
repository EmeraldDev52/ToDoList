#pragma once
#include <iostream>


template<typename T>
void println(const T& value) {
    std::cout << value << '\n'; 
}

template<typename T, typename... Args>
void println(const T& first, const Args&... rest) {
    std::cout << first;
    println(rest...);
}

