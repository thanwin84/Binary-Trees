// time: O(n) and stack: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        vector<TreeNode*> even_level;
        vector<TreeNode*> odd_level;
        odd_level.push_back(root);
        while (even_level.size() > 0 || odd_level.size() > 0){
            vector<int> temp;
            while(odd_level.size() > 0){
                TreeNode * current = odd_level.back();
                odd_level.pop_back();
                temp.push_back(current->val);
                // in the next level(even level) we need to treverse from right to left
                // so in this level if we push left node first, at the end we will end up 
                // with right node on top of the stack
                if (current->left) even_level.push_back(current->left);
                if (current->right) even_level.push_back(current->right);
            }
            if (temp.size() > 0){
                result.push_back(temp);
            }
            temp = {};
            while(even_level.size() > 0){
                TreeNode * current = even_level.back();
                even_level.pop_back();
                temp.push_back(current->val);
                if (current->right) odd_level.push_back(current->right);
                if (current->left) odd_level.push_back(current->left);
            }
            if (temp.size() > 0){
                result.push_back(temp);
            }
        }
        return result;
    }
};
