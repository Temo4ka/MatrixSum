template<int... line> struct matrix_line {
    matrix_line<> ZERO;

    const size_t length = sizeof...(line);

    matrix_line& operator +(const matrix_line &a, const matrix_line &b) {
        if (a.size == b.size)
            return a.line + b.line;

        return ZERO;
    }
};

// template<int... line>
// template<matrix_line<line>... lines> struct matrix {

// };