// Time: O(H)
Node * minValueFromRightSubtree(Node * current){
    if (current == nullptr){
        return current;
    }
    if (!current->left){
        return current;
    }
    return minValueFromRightSubtree(current->left);
    
}
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node * current = x;
        if (current == nullptr){
            return nullptr;
        }
        // case 1: has right subtree
        if (current->right){
            return minValueFromRightSubtree(current->right);
        }
        // case 2: No right subtree
        // so we need to treverse from root until X
        else {
            Node * successor = nullptr;
            Node * ancestor = root;
            while (current != ancestor){
                if (ancestor->data > current->data){
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else ancestor = ancestor->right;
            }
            return successor;
        }
        
    }
};
