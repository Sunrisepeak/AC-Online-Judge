/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        if (preorder.size() != 0) {
            root = new TreeNode(preorder[0]);
            
            vector<int>::size_type lNum = 0;
            find_if(inorder.cbegin(), inorder.cend(),
                [ &lNum, &preorder ](const int &v) {
                    lNum++;
                    return v == preorder[0];
                }
            );
           
            lNum -= 1;  // minus end_element

            vector<int> newLPreorder(preorder.begin() + 1, preorder.begin() + lNum + 1);
            vector<int> newRPreorder(preorder.begin() + lNum + 1, preorder.end());

            vector<int> newLInorder(inorder.begin(), inorder.begin() + lNum);
            vector<int> newRInorder(inorder.begin() + lNum + 1, inorder.end());
            
            root->left = buildTree(newLPreorder, newLInorder);
            root->right = buildTree(newRPreorder, newRInorder);
        }
        return root; 
    }
};
