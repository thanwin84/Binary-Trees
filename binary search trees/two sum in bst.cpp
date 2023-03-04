
///////////// using two pointer
class Solution {
    vector<int> values;
public:
    void inorder(TreeNode *root){
        if (root == nullptr){
            return;
        }
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int start = 0;
        int end = values.size() - 1;
        while(start < end){
            int _sum = values[start] + values[end];
            if (_sum > k){
                end--;
            }
            else if (_sum < k){
                start++;
            }
            else {
                return true;
            }
        }
        return false;

    }
};
// time: O(n) and space: O(n)
