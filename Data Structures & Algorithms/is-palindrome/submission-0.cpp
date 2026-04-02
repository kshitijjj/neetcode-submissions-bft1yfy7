class Solution {
public:
    bool isPalindrome(string s) {
        string a;

        for(auto i:s){
            if(isalnum(i)) {
                a += tolower(i);
            }
        }

        int i=0;
        int j=a.length()-1;

        while(i<j){
            if(a[i] != a[j]) return false;
            i++;j--;
        }
        return true;
    }
};
