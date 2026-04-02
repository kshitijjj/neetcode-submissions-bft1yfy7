class Solution {
public:
    int solve(int index,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(index==coins.size()-1){
            if(amount%coins[index]==0)return amount/coins[index];
            return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];

        int nottake=solve(index+1,amount,coins,dp);
        int take=INT_MAX;
        if(amount>=coins[index]){
            take=1+solve(index,amount-coins[index],coins,dp);
        }

        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);

        if(ans==1e9)return -1;
        return solve(0,amount,coins,dp);
    }
};
