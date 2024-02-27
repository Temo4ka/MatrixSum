#include <iostream>
#include <assert.h>

//-------------------------PRINT-------------------------------------
template<typename... T>
void Print() {};

template<typename T0, typename... T1>
void Print(const T0& Head, const T1&... Tail) {
    std::cout << Head << ' ';
    Print(Tail...);
}
//-------------------------------------------------------------------

template<int... line> struct matrix_line {
    const size_t length = sizeof...(line);

    void print() {
        Print(line...);
    }
};

using ZERO = matrix_line<>;

//--------------------------SUM---------------------------------------
template <class A, class B> struct SUM;
template <class A> struct SUM <ZERO, A> { using RESULT = A; };
template <class A> struct SUM <A, ZERO> { using RESULT = A; };
template <> struct SUM <ZERO, ZERO> { using RESULT = ZERO; };

template<class A, class B>
struct Concatenate {
    using Result = void;
};

template <int... line1, int... line2> 
struct SUM<matrix_line<line1...>, matrix_line<line2...>> {
    using RESULT = matrix_line< (line1 + line2) ...>;
};
//-------------------------------------------------------------------



// template<typename... T>
// void print(const matrix_line<>&) {}

// template<int Head, int... Tail>
// void print(const matrix_line<Head, Tail...> line) {
//     std::cout << Head << ' ';

//     matrix_line<Tail...> tail;
//     print<Tail...>(tail);
// }

// template<typename... T> void print() { assert("cringanull!\n"); }

// template<typename... T> void print<ZERO>() {}

// template<int Head, int... Tail>
// void print<matrix_line<Head, Tail...>>() {
//     std::cout << Head << '\n';

//     matrix_line<Tail...> tail;
//     print<Tail...>();
// }

// template <typename... T> struct PRINT;

// template <int Head, int... Tail>
// struct PRINT<matrix_line<Head, Tail...>> {
//     void print() {
//         std::cout << Head << ' ';

//         if (sizeof...(Tail) == 0) return;
//         PRINT<matrix_line<Tail...>>::print();
//     }
// };

//-------------------------------------------------------------------


template<int size>
struct Matrix {
    
};