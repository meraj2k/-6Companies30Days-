

//    https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/


class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int arr[],int n){
        if(n<=0) return 0;
        if(n==1) return arr[0];
        
        return max(arr[n-1]+helper(arr,n-2),helper(arr,n-1));
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};