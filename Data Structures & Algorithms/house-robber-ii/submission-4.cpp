class Solution {
public:
    int solve(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end) return 0;
        if (dp[index] != -1) return dp[index];

        int take    = nums[index] + solve(index + 2, end, nums, dp);
        int nottake = solve(index + 1, end, nums, dp);

        return dp[index] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1); // ✅ fresh dp for range [0, n-2]
        vector<int> dp2(n, -1); // ✅ fresh dp for range [1, n-1]

        return max(solve(0, n-2, nums, dp1),
                   solve(1, n-1, nums, dp2));
    }
};