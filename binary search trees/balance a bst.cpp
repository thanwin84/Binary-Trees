class Solution {
    vector<int> inorder_list;
public:
    void inorder(TreeNode * root){
        if (!root){
            return;
        }
        inorder(root->left);
        inorder_list.push_back(root->val);
        inorder(root->right);
    }
    TreeNode * NormalBSTtoBalanceBST(int start, int end){
        if (start > end){
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode * root = new TreeNode(inorder_list[mid]);
        root->left = NormalBSTtoBalanceBST(start, mid - 1);
        root->right = NormalBSTtoBalanceBST(mid + 1, end);
        return root;
    }
   
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int size = inorder_list.size() -1;
        return NormalBSTtoBalanceBST(0, size);
        
    }
};
