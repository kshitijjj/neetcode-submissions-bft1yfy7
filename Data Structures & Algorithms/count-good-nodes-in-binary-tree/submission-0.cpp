/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int count=0;
    void solve(TreeNode* root,int mini){
        if(root==NULL)return ;

        if(root->val >= mini){
            cout << "before mini" << " " << mini << endl;
            mini=max(mini,root->val);
            cout << "after mini" << " " << mini << endl;
            cout << "root" << " " << root->val << endl;
            count ++ ;
        }

        solve(root->left,mini);
        solve(root->right,mini);
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return count;
    }
};
