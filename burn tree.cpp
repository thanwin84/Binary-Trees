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
    TreeNode * startNode;   
    void getStartNode(TreeNode * root, int target){
        if (root == nullptr){
            return;
        }
        if (root->val == target){
            startNode = root;
            return;
        }
        getStartNode(root->left, target);
        getStartNode(root->right, target);
    }
    void markParent(TreeNode * root, unordered_map<TreeNode*, TreeNode*> & trackParent){
        if (root == nullptr){
            return;
        }
        if (root->left) trackParent[root->left] = root;
        if (root->right) trackParent[root->right] = root;
        markParent(root->left, trackParent);
        markParent(root->right, trackParent);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> trackParent;
        unordered_map<TreeNode*, bool> visited;
        getStartNode(root, start);
        markParent(root, trackParent);
        int time = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;
        while (q.size() > 0) {
            int size = q.size();
            bool burn = false;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left && !visited[current->left]) {
                    burn = true;
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    burn = true;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (trackParent[current] && !visited[trackParent[current]]) {
                    burn = true;
                    visited[trackParent[current]] = true;
                    q.push(trackParent[current]);
                }
            }
            if (burn) time++;
        }
        return time;
    }
};
