
//    https://leetcode.com/problems/construct-quad-tree/



/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>> &grid,int s,int e,int size){
        if(size==1) return new Node(grid[s][e],1);
        int count=0;
        for(int i=s;i<s+size;i++){
            for(int j=e;j<e+size;j++){
                count+=grid[i][j];
            }
        }
        if(count==0){
            return new Node(0,1);
        }
        if(count==size*size){
            return new Node(1,1);
        }
        Node* root=new Node(1,0);
        size=size/2;
        root->topLeft=helper(grid,s,e,size);
        root->topRight=helper(grid,s,e+size,size);
        root->bottomLeft=helper(grid,s+size,e,size);
        root->botomRight=helper(grid,s+size,e+size,size);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,0,grid.size());
    }
};