class Solution {
public:
    bool solve(int index,vector<int>& nums,vector<int>& dp){
        //base case
        if(index>=nums.size()-1)return true;
        if(nums[index]==0 && index!=nums.size()-1)return false;
        if(dp[index]!=-1)return dp[index];

        bool ans=false;
        for(int i=1;i<=nums[index];i++){
            if(solve(index+i,nums,dp)){
                ans=true;
                break;
            }
        }
        return dp[index]=ans;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};
