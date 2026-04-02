class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> pq;
        for(auto i:nums){
            pq[i]++;
        }

        for(auto i:pq){
            if(i.second > 1)return true;
        }
        return false;
    }
};