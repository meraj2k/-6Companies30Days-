
//   https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/




class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int help(Node* root){
        if(root==NULL) return 0;
        int l=help(root->left);
        int r=help(root->right);
        int x=root->data;
        root->data= l+r;
        return l+r+x;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        help(node);
    }
};