class Solution {
public:
    int solve(int index,vector<int>& nums,vector<int>& dp){
        if(index>=nums.size()-1)return 0;
        if(dp[index]!=-1)return dp[index];

        int mini=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            int ans=solve(index+i,nums,dp);
            if(ans!=INT_MAX)mini=min(mini,1+ans);
        }
        return dp[index]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};
