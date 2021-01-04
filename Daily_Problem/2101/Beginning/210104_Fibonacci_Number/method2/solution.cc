#include <vector>
using std::vector;

class Solution {
   public:
    // 除去直接使用通项公式的方法，还有一种方法时间复杂度更低，
    // 1 1 ^n f(1) = f(n+1)
    // 1 0    f(0)   f(n)
    using matrix_type = vector<vector<int>>;
    int fib(int n) {
        if (n < 2) return n;

        matrix_type a{{1, 1}, {1, 0}};
        matrix_type r = matrix_pow(a, n - 1);

        return r[0][0];
    }

    matrix_type matrix_pow(matrix_type& matrix, int n) {
        matrix_type result{{1, 0}, {0, 1}};
        while (n) {
            if (n & 1) {
                result = matrix_multiply(result, matrix);
            }
            matrix = matrix_multiply(matrix, matrix);
            n >>= 1;
        }

        return result;
    }

    matrix_type matrix_multiply(matrix_type& a, matrix_type& b) {
        matrix_type c(2, vector<int>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }

        return c;
    }
};