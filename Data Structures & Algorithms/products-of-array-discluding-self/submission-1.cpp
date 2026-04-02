class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int zc=0;
        bool iszero=false;

        for(auto i:nums){
            if(i==0){
                zc++;
                iszero=true;
                continue;
            }
            else{
                product*=i;
            }
        }


        vector<int> ans(nums.size(),0);

        if(zc>1)return ans;
        if(iszero){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0)ans[i]=product;
                else ans[i]=0;
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};
