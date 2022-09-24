class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;
    void solve(TreeNode* root, int vertical, int level) {
        if (root == nullptr) return;
        nodes[vertical][level].insert(root->val);
        solve(root->left, vertical - 1, level + 1);
        solve(root->right, vertical + 1, level + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        solve(root, 0, 0);
        for (auto &v : nodes) {
            vector<int> verticalOrder;
            for (auto x : v.second) {
                verticalOrder.insert(verticalOrder.end(), x.second.begin(), x.second.end());
            }
            result.push_back(verticalOrder);

        }
        return result;
    }
};
