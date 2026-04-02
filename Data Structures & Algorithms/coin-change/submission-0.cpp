class Solution {
public:
    int solve(int index,int amount,vector<int>& coins){
        if(index==coins.size()-1){
            if(amount%coins[index]==0)return amount/coins[index];
            return 1e9;
        }

        int nottake=solve(index+1,amount,coins);
        int take=INT_MAX;
        if(amount>=coins[index]){
            take=1+solve(index,amount-coins[index],coins);
        }

        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(0,amount,coins);
        if(ans==1e9)return -1;
        return solve(0,amount,coins);
    }
};
