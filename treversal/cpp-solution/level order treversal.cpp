// time: O(n)
// in the worst case q size will be n/2. so space complexity is O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            int levelSize = q.size();
            // q size will be equal to current level size
            vector<int> currentLevel;
            // this will make sure that we loop level by level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                currentLevel.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            // when we finished the loop, we already populated q with next level
            result.push_back(currentLevel);
        }
        return result;
    }
};
