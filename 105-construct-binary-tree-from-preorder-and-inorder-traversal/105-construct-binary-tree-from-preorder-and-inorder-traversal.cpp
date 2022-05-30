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
    TreeNode* build(vector<int> &in,vector<int> &pre,int s,int e,map<int,int> &m)
    {
        
        if(s>e)
        return NULL;
        TreeNode* head=new TreeNode(pre[preindex++]);
        if(s==e)
        return head;
        int mid=m[head->val];
        head->left=build(in,pre,s,mid-1,m);
        head->right=build(in,pre,mid+1,e,m);
        
        return head;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        preindex=0;
        map<int,int> m;
        for(int i=0;i<in.size();i++)
            m[in[i]]=i;
                return build(in,pre,0,pre.size()-1,m);

    }
};