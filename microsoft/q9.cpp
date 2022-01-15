

//   https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/


int helper(Node* root,int x,int &count){
    if(root==NULL) return 0;
    int l=helper(root->left,x,count);
    int r=helper(root->right,x,count);
    if(l+r+root->data==x){
        count++;
    }
    return l+r+root->data;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count=0;
	helper(root,X,count);
	return count;
}