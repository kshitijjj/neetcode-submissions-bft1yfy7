class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> pq;
        for(auto i:nums){
            pq[i]++;
        }

        for(auto i:pq){
            if(i.second > 1)return i.first;
        }
        return -1;
    }
};
