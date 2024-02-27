#include "../headers/matrix.h"

int main() {

    using A = matrix_line<1, 2, 3>;
    using B = matrix_line<1, 1, 1>;
    using Sum = SUM<A, B>::RESULT;

    Sum sum;
    sum.print();

    // SUM<matrix_line<1, 2, 3>, matrix_line<1, 1, 1>>::RESULT sum;

    return 0;
}