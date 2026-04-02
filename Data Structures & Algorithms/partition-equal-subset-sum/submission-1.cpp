class Solution {
public:
    bool solve(int index,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(index>=nums.size())return false;
        if(target==0)return true;
        if(dp[index][target]!=-1)return dp[index][target];

        int take=solve(index+1,target,nums,dp);
        int nottake=false;
        if(target>=nums[index]){
            nottake=solve(index+1,target-nums[index],nums,dp);
        }

        return dp[index][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int n=nums.size();
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
};
