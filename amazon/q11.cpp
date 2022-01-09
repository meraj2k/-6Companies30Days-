

void helper1(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        res.push_back(-1);
        return;
    }
    res.push_back(root->data);
    helper1(root->left, res);
    helper1(root->right, res);
}
Node *helper2(vector<int> &A, int &i)
{
    if (i >= A.size() || A[i] == -1)
    {
        i++;
        return NULL;
    }
    Node *root = new Node(A[i]);
    i++;
    root->left = helper2(A, i);
    root->right = helper2(A, i);
    return root;
}

class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        //Your code here
        vector<int> v;
        helper1(root, v);
        return v;
    }

    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        //Your code here
        int i = 0;
        return helper2(A, i);
    }
};
