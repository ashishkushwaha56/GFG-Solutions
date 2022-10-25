
class Solution
{
    public:
    
    vector<int> ans;
    void dfs(vector<int>&temp,Node *root){
        if(!root) return;
        if(!root->left and !root->right){
            temp.push_back(root->key);
            for(auto &it:temp){
                ans.push_back(it);
            }
            temp.clear();
            return;
        }
        temp.push_back(root->key);
        dfs(temp,root->left);
        dfs(temp,root->right);
    }
    
    void f(int &i, Node *root){
        if(!root)
            return;
        f(i,root->left);
        root->key = ans[i];
        i++;
        f(i,root->right);
    }
    void flatten(Node *root)
    {
      vector<int> temp;
      
        dfs(temp,root);
        int i = 0;
        f(i,root);
        
    }
};
