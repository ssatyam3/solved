class Solution {
public:
    int climbStairs(int n) {
        // Proper DP soln.
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // std::vector<int> opt(n, 0);
        // opt[0] = 1;
        // opt[1] = 2;
        // for (int i = 2; i < n; i++) {
        //     opt[i] = opt[i - 1] + opt[i-2];
        // }
        // return opt[n - 1];
        
        // Optimized
        if (n == 1) return 1;
        if (n == 2) return 2;
        int oldest = 1;
        int middle = 2;
        int newest = 0;
        
        for (int i = 2; i < n; ++i) {
            newest = oldest + middle;
            oldest = middle;
            middle = newest;
        }
        return newest;
    }
};