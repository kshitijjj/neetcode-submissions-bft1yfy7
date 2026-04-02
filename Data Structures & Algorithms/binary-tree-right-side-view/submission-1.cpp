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
    vector<int> rightSideView(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;
        map<int,int> temp;
        vector<int> ans;

        if(root==NULL)return ans;
        q.push({root,0});

        while(!q.empty()){
            pair<TreeNode*,int> pq = q.front();
            TreeNode* node=pq.first;
            int level=pq.second;
            q.pop();

            if(temp.find(level)==temp.end()){
                temp[level]=node->val;
            }

            if(node->right){
                q.push({node->right,level+1});
            }
            if(node->left){
                q.push({node->left,level+1});
            }
        }
        for(auto i:temp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
