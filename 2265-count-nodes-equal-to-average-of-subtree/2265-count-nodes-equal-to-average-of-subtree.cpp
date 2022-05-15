class Solution 
{
public:
    int ans = 0;
    int averageOfSubtree(TreeNode* root) 
    {
        auto p = DFS(root);
        return ans;
    }
    
    pair<int,int> DFS(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0};

        auto left = DFS(root -> left); 
        auto right = DFS(root -> right);

        int sum = left.first + right.first + root -> val;
        int count = left.second + right.second + 1;
        
        if(sum / count == root->val)
            ans++;
        
        return {sum, count};
    }
};

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