class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            if(pq.find(target-a)!=pq.end()){
                ans.push_back(pq[target-a]);
                ans.push_back(i);
                break;
            }
            pq[nums[i]]=i;
        }
        return ans;
    }
};
