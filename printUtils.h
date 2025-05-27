#pragma once
#include <iostream>

template<typename T>
void print(const T& value) {
    std::cout << value;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... rest) {
    std::cout << first;
    print(rest...);
}


template<typename T>
void println(const T& value) {
    std::cout << value << '\n';  // or use std::endl if you need flushing
}

template<typename T, typename... Args>
void println(const T& first, const Args&... rest) {
    std::cout << first;
    println(rest...);
}

