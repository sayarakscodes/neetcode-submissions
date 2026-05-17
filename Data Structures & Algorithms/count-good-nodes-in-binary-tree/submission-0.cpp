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
    int countGoodNodes(TreeNode* root, multiset<int, greater<int>> &s) {
        int res = 0;
        int val = root->val;
        if(s.size() == 0) res = 1;
        if(val >= *s.begin()) {
            res =  1;
        }
        if (root->left == NULL && root->right == NULL) {
            return res;
        }
        s.insert(val);

        if(root->left != NULL) {
            res += countGoodNodes(root->left, s);
        } 
        if(root->right != NULL) {
            res += countGoodNodes(root->right, s);
        }
        s.erase(s.find(val));

        return res;

        
    }
    int goodNodes(TreeNode* root) {
        multiset<int, greater<int>> s;
        return countGoodNodes(root, s);
    }
};
