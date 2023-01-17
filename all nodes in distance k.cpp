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
    void markParent(TreeNode * root, unordered_map<TreeNode*, TreeNode*> & track_parent){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * current;
        while (q.size() > 0){
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                current = q.front();
                q.pop();
                if (current->left){
                    q.push(current->left);
                    track_parent[current->left] = current;
                }
                if (current->right) {
                    q.push(current->right);
                    track_parent[current->right] = current;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> track_parent;
        unordered_map<TreeNode*, bool> visited;
        markParent(root, track_parent);
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        
        while(q.size() > 0){
            int levelSize = q.size();
            if (distance++ == k){
                break;
            }
            TreeNode * current;
            for (int i = 0; i < levelSize; i++){
                current = q.front();
                q.pop();
                if (current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (track_parent[current] && !visited[track_parent[current]]){
                    q.push(track_parent[current]);
                    visited[track_parent[current]] = true;
                }
            }
            
        }
        vector<int> result;
        while (q.size() > 0){
            TreeNode * current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;

    }
};
