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
private:
    pair<int, int> getMaxCount(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return {root->val, 0};
        }
        
        int rightChildTaken = 0;
        int rightChildNotTaken = 0;
        int leftChildTaken = 0;
        int leftChildNotTaken = 0;

        if(root->right != NULL) {
            auto rightRes = getMaxCount(root->right);
            rightChildTaken = rightRes.first;
            rightChildNotTaken = rightRes.second;
        }
        if(root->left != NULL) {
            auto leftRes = getMaxCount(root->left);
            leftChildTaken = leftRes.first;
            leftChildNotTaken = leftRes.second;
        }

        int rootTaken = root->val;
        rootTaken += max(0, leftChildNotTaken);
        rootTaken += max(0, rightChildNotTaken);

        int rootNotTaken = 0;
        rootNotTaken += max(0, max(leftChildTaken, leftChildNotTaken));
        rootNotTaken += max(0, max(rightChildTaken, rightChildNotTaken));
        return {rootTaken, rootNotTaken};
    } 
public:
    int rob(TreeNode* root) {
        auto ans = getMaxCount(root);
        return max(ans.first, ans.second);
    }
};