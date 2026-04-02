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
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;i++){
            int a=cost[i-1]+dp[i-1];
            int b=cost[i-2]+dp[i-2];
            dp[i]=min(a,b);
        }
        return dp[n];
    }
};
