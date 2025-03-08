class Solution {
public:
    /*
        int fibonacci(int n) {
            if (n <= 1) {
                return n;
            }
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    */
    int fibonacci(int n) {
        std::vector<int> fib(n);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n - 1];
    }

    int climbStairs(int n) {
        if (n < 3)
            return n;
        return fibonacci(n);
    }
};