#include "../headers/matrix.h"

int main() {

    using a = matrix_line<1, 2, 3>;
    using b = matrix_line<1, 1, 1>;
    using c = SUM<a, b>::RESULT;

    
    // print(std::cout, c);

    return 0;
}