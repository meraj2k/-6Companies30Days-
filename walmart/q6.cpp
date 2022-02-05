
https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart


class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       int m=1000000007;
       long n=N,r=R;
       long res=1;
       while(r){
           if(r&1){
               res=(res*n)%m;
               r--;
           }else{
               n=(n*n)%m;
               r=r>>1;
           }
       }
        return res;
    }

};
