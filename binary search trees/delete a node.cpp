
class Solution {
public:
    // get min value in the right subtree
    int getMinValue(TreeNode * root){
        if (root == nullptr){
            return -1;
        }
        if (root->left == nullptr){
            return root->val;
        }
        // min value only exists in left subtree
        return getMinValue(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr){
            return root;
        }
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else {
            //we got the matched node
            // case 1: no child
            if (root->left == nullptr && root->right == nullptr){
                delete root;
                root = nullptr;
            }
            // case 2: one child
            // right subtree is null
            else if (root->right == nullptr){
                TreeNode * temp = root->left;
                delete root;
                root = temp;
            }
            // left subtree is null
            else if (root->left == nullptr){
                TreeNode * temp = root->right;
                delete root;
                root = temp;
            }
            // case 3: two child
            else {
                // find min value in right subtree
                int temp = getMinValue(root->right);
                // set the root node value to temp
                root->val = temp;
                // aftering setting root value to temp
                // we have duplicate value in the subtree, we just have to delete that 
                // node in the right subtree
                root->right = deleteNode(root->right, temp);
            }
        }
        return root;
    }
};
// Another way to solve case 3
 // take the max value from the right subtree and solve in the same way
