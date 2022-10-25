struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool ok = true;
    int dfs(Node* root){
        if(root==NULL) return 0;
        int a = dfs(root->left);
        int b = dfs(root->right);
        if(root->data !=(a+b) and root->left and root->right){
            ok = false;
        }
        if((root->left and !root->right)){
            if(root->data !=a){
                ok = false;
            }
        }
        if((!root->left and root->right)){
            if(root->data !=b){
                ok = false;
            }
        }
        return (root->data+a+b);
    }
    bool isSumTree(Node* root)
    {
        dfs(root);
        return ok;
    }
};
