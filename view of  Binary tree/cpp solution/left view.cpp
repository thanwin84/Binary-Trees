// using BFS
// Time: O(n) 
// space: q size will be at max n /2 so space complexity is O(n)
vector<int> leftView(Node* root)
{
    vector<int> leftView;
    if (!root){
        return  leftView;
    }
    // Your code here
    queue<Node*> q;
    Node* current = root;
    q.push(current);
    while (q.size() > 0) {
        int currentLevel = q.size();
        Node* leftNode = q.front();
        leftView.push_back(leftNode->data);
        for (int i = 0; i < currentLevel; i++) {
            Node* current = q.front();
            q.pop();
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }
    return leftView;


}
