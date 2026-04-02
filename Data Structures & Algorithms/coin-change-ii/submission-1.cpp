class Solution {
public:
    int solve(int index,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0)return 1;

        if(index==0){
            if(amount%coins[index]==0){
                return 1;
            }
            return 0;
        }

        if(dp[index][amount]!=-1)return dp[index][amount];

        int nottake=solve(index-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[index]){
            take=solve(index,amount-coins[index],coins,dp);
        }

        return dp[index][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int i=0;i<n;i++)dp[i][0]=1;
        for(int j = 0; j <= amount; j++){
    dp[0][j] = (j % coins[0] == 0) ? 1 : 0;
}

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(j>=coins[i]){
                    take=dp[i][j-coins[i]];
                }
                dp[i][j]=take+nottake;

            }
        }
        return dp[n-1][amount];
        return solve(n-1,amount,coins,dp);
    }
};
