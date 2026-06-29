// Last updated: 6/29/2026, 8:45:51 AM
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    vector<long long> multiplyVector(
        const Matrix& M,
        const vector<long long>& v
    ) {
        int n = M.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0) continue;

                cur = (cur + M[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // State:
        // [up(0..m-1), down(0..m-1)]

        for (int v = 0; v < m; v++) {

            // up'[v] = sum down[x], x < v
            for (int x = 0; x < v; x++) {
                T[v][m + x] = 1;
            }

            // down'[v] = sum up[x], x > v
            for (int x = v + 1; x < m; x++) {
                T[m + v][x] = 1;
            }
        }

        vector<long long> state(S, 0);

        // Length = 2 initialization
        for (int v = 0; v < m; v++) {
            state[v] = v;              // up[v] = count smaller values
            state[m + v] = m - 1 - v; // down[v] = count larger values
        }

        if (n > 2) {
            Matrix P = power(T, n - 2);
            state = multiplyVector(P, state);
        }

        long long ans = 0;

        for (long long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};