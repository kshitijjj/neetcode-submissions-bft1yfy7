class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN;
        int buy=INT_MAX;
        int profit=INT_MIN;

        for(int i=0;i<prices.size()-1;i++){
            buy=min(buy,prices[i]);
            profit=max(profit,prices[i+1]-buy);
            maxi=max(maxi,profit);
        }
        if(maxi < 0)return 0;
        return maxi;
    }
};
