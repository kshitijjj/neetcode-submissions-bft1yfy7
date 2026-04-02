class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN;

        for(int i=0;i<prices.size();i++){
            int buy=prices[i];
            for(int j=i+1;j<prices.size();j++){
                int sell=prices[j];
                int profit=sell - buy;
                maxi=max(maxi,profit);
            }
        }
        if(maxi < 0)return 0;
        return maxi;
    }
};
