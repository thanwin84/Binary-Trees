// addLeftNodes = O(H)
// addRightNodes = O(H)
// addLeafNodes = O(N)
// so overall time complexity is O(N) and space: O(H)[right subtree will take space] Note: not considering stack space in recursion call
class Solution {
public:
    bool isLeafNode(Node * root){
        if (root->left == nullptr && root->right == nullptr){
            return true;
        }
        return false;
    }
    void addLeftNodes(Node*root, vector<int> &result){
        Node * current = root->left;
        while (current){
            if (!isLeafNode(current)){
                result.push_back(current->data);
            }
            if (current->left) current = current->left;
            else current = current->right;
        }
    }
    void addLeafNodes(Node * root, vector<int> &result){
        if (isLeafNode(root)){
            result.push_back(root->data);
            return;
        }
        if (root->left) addLeafNodes(root->left, result);
        if (root->right) addLeafNodes(root->right, result);
    }
    void addRightNodes(Node * root, vector<int> &result){
        Node * current = root->right;
        vector<int> temp;
        while (current){
            if (!isLeafNode(current)) temp.push_back(current->data);
            if (current->right) current = current->right;
            else current = current->left;
        }
        while(temp.size() > 0){
            result.push_back(temp.back());
            temp.pop_back();
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> result;
        if (root == nullptr){
            return result;
        }
        if (!isLeafNode(root)) result.push_back(root->data);
        addLeftNodes(root, result);
        addLeafNodes(root, result);
        addRightNodes(root, result);
        return result;
    }
};
