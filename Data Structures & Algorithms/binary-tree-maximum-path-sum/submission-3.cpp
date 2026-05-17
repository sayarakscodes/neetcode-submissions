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
    int ans = -1e9;
    int getMaxPathSum(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            ans = max(ans, root->val);
            return root->val;
        } 

        int curr = root->val;
        int leftSum = 0;
        int rightSum = 0;
        if(root->left != NULL) {
            leftSum = max(0, getMaxPathSum(root->left));
        }
        if(root->right != NULL) {
            rightSum = max(0, getMaxPathSum(root->right));
        }

     
        ans = max(ans, curr);
        ans = max(ans, leftSum + curr + rightSum);

        return max(curr+leftSum, curr + rightSum);


    }
public:
    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return ans;

    }
};
