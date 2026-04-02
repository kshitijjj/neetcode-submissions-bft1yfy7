class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>> s;
        vector<int> left(n);
        vector<int> right(n);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first >= heights[i]){
                s.pop();
            }
            right[i]=s.empty()?n:s.top().second;
            s.push({heights[i],i});
        }

        while(!s.empty())s.pop();

        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first >= heights[i]){
                s.pop();
            }
            left[i]=s.empty()?-1:s.top().second;
            s.push({heights[i],i});
        }

        for(auto i:left)cout << i << " " ;
        cout << endl;
        for(auto i:right)cout << i << " ";
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            int w=right[i]-left[i]-1;
            int area=heights[i]*w;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
