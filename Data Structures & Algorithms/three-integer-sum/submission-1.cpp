class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> res={nums[i],nums[j],nums[k]};
                        sort(res.begin(),res.end());
                        if(s.find(res)==s.end()){
                            s.insert(res);
                            ans.push_back(res);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
