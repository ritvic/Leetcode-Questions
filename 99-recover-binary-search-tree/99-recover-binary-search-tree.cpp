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
        void inorder(TreeNode* root,vector<TreeNode*> &v)
    {
        if(root==NULL)
        return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
        return;
    }
    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*> v;
        inorder(root,v);
        int i,j;
        for (int i = v.size()-1; i > 0; i--)
        {
            // Check if arr[i] is not in order
            if (v[i]->val < v[i-1]->val)
            {
                int j = i-1;
                while (j>=0 && v[i]->val < v[j]->val)
                    j--;
     
                swap(v[i]->val, v[j+1]->val);
                break;
            }
        }
        // if(j==v.size())
        // // j=v.size()-1;
        // int temp=v[i]->data;
        // v[i]->data=v[j]->data;
        // v[j]->data=temp;
        
        
        return;
        
    }
};