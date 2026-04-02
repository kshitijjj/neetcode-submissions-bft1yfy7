class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> pq;

        for(auto i:nums)pq[i]++;
        
        vector<pair<int,int>> ans;

        for(auto i:pq){
            ans.push_back({i.second,i.first});
        }

        sort(ans.begin(),ans.end());

        vector<int>res;
        for(int i=ans.size()-1;i>=0;i--){
            if(k==0)break;
            res.push_back(ans[i].second);
            k--;
        }
        return res;
    }
};
