
// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/

	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n];
	    dp[0]=1;
	    int i2=0,i3=0,i5=0;
	    for(int i=1;i<n;i++){
	        dp[i]=min({dp[i2]*2,dp[i3]*3,dp[i5]*5});
	        if(dp[i2]*2==dp[i]){
	            i2++;
	        }
	        if(dp[i3]*3==dp[i]){
	            i3++;
	        }
	        if(dp[i5]*5==dp[i]){
	            i5++;
	        }
	    }
	    return dp[n-1];
	  
	}
};