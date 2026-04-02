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
    int solve(TreeNode* root){
        if(root==NULL)return 0;

        if(root->left==NULL && root->right==NULL)return 1;

        int lh=solve(root->left);
        int rh=solve(root->right);

        return 1+max(lh,rh);

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;

        int lb=solve(root->left);
        int rb=solve(root->right);

        if(abs(lb-rb)>1)return false;

        bool ans1=isBalanced(root->left);
        bool ans2=isBalanced(root->right);

        return ans1 && ans2;
    }
};
