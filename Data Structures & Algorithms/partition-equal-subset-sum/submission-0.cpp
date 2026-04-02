class Solution {
public:
    bool solve(int index,int target,vector<int>& nums){
        if(index>=nums.size())return false;
        if(target==0)return true;

        int take=solve(index+1,target,nums);
        int nottake=false;
        if(target>=nums[index]){
            nottake=solve(index+1,target-nums[index],nums);
        }

        return take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        return solve(0,target,nums);
    }
};
