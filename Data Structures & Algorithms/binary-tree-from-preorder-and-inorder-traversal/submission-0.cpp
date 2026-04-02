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
    TreeNode* solve(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>& pq){
        if(prestart > preend || instart > inend)return NULL;
        
        TreeNode* root=new TreeNode(preorder[prestart]);
        int pos=pq[root->val];
        int left=pos-instart;

        root->left=solve(preorder,prestart+1,prestart+left,inorder,instart,pos-1,pq);
        root->right=solve(preorder,prestart+left+1,preend,inorder,pos+1,inend,pq);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pq;
        for(int i=0;i<inorder.size();i++){
            pq[inorder[i]]=i;
        }

        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,pq);

    }
};
