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
static int preindex=0;

class Solution {
public:
    TreeNode* build(vector<int> &in,vector<int> &pre,int s,int e)
    {
        
        if(s>e)
        return NULL;
        TreeNode* head=new TreeNode(pre[preindex++]);
        if(s==e)
        return head;
        int mid=s;
        while(in[mid] != head->val) mid++;
        head->left=build(in,pre,s,mid-1);
        head->right=build(in,pre,mid+1,e);
        
        return head;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        preindex=0;
                return build(in,pre,0,pre.size()-1);

    }
};