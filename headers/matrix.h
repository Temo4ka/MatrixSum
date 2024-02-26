#include <iostream>

template<int... line> struct matrix_line {
    const size_t length = sizeof...(line);
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

//-------------------------PRINT-------------------------------------

template<int Head, int... Tail>
void print() {
    std::cout << Head << ' ';

    if (sizeof...(Tail)) print(Tail);
}
//-------------------------------------------------------------------


// template<int... line>
// template<matrix_line<line>... lines> struct matrix {

// };