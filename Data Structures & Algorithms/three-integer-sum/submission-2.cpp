class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;

        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            set<int> sq;
            for(int j=i+1;j<nums.size();j++){
                int c=target-nums[j];
                if(sq.find(c)!=sq.end()){
                    vector<int> res={nums[i],nums[j],c};
                    sort(res.begin(),res.end());
                    s.insert(res);
                }
                sq.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
