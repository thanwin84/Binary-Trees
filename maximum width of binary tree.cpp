class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int _maxWidth = 1;
        while (q.size() > 0){
            int size = q.size();
            int first = 0, last = 0;
            // first value of current level
            long long int minValue = q.front().second;
            for (int i = 0; i < size; i++){
                pair<TreeNode*, int> current = q.front();
                long long int rootIndex = current.second - minValue;
                q.pop();
                
                if (i == 0) first = current.second;
                if (i == size - 1) last = current.second;
                if (current.first->left){
                    q.push({current.first->left, 2 * (rootIndex) + 1});
                    
                }
                if (current.first->right){
                    q.push({current.first->right, 2 * (rootIndex) + 2});
                }
            }
            _maxWidth = max(_maxWidth, last - first + 1);
             
        }
        return _maxWidth;
    }
};

// time: O(N) where N is the total number of nodes
// space: O(N)
