class Solution {
public:
    int solve(int index,vector<int>& cost,vector<int>& dp){
        int n=cost.size();
        if(index>=n)return 0;
        if(dp[index]!=-1)return dp[index];

        int a=cost[index]+solve(index+1,cost,dp);
        int b=cost[index]+solve(index+2,cost,dp);

        return dp[index]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int a=solve(0,cost,dp);
        int b=solve(1,cost,dp);
        return min(a,b);
    }
};
