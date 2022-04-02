// using level order treversal with line tehnique
// time complexity: O(nlongn). Cause insertion in map is logN
// space: O(n)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> result;
        if (!root) return result;
        map<int, int> lookup;
        queue<pair<Node*, int>> q;
        Node * current = root;
        int line = 0;
        q.push({current, line});
        while (q.size() > 0){
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                auto p = q.front();
                q.pop();
                current = p.first;
                line = p.second;
                if (!lookup.count(line)){
                    lookup[line] = current->data;
                }
                if (current->left){
                    q.push({current->left, line -1});
                }
                if (current->right){
                    q.push({current->right, line + 1});
                }
            }
        }
        for (auto it: lookup){
            result.push_back(it.second);
        }
        return result;
        
    }

};
