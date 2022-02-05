
//   https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart


class Solution{
public:
    int height(int N){
        // code here
        return (int)(-1+sqrt(1+8*N))/2;
    }
};
