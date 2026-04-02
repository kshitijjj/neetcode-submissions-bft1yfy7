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
    bool solve(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        if(root1->val!=root2->val)return false;

        bool ans1=solve(root1->left,root2->left);
        bool ans2=solve(root1->right,root2->right); 

        return ans1 && ans2;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL) return false;

        bool ans=false;

        if(root->val == subRoot->val){
            ans=solve(root,subRoot);
        }

        bool ans1=isSubtree(root->left,subRoot);
        bool ans2=isSubtree(root->right,subRoot);

        return ans || ans1 || ans2;
    }
};
