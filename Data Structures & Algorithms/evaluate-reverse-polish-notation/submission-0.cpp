class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/"){
                cout << "i" << " " << i << endl;
                int a=stoi(i);
                s.push(a);
            }
            else{
                if(i=="+" && !s.empty()){
                    cout << "elsse" << " " << i << endl;
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(a+b);
                }
                if(i=="-" && !s.empty()){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(b-a);
                }
                if(i=="*" && !s.empty()){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(a*b);
                }
                if(i=="/" && !s.empty()){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};
