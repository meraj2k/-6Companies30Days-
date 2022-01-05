

//  https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/

int help(string str,int i,int &p,vector<int> &dp){
	        if(i>=str.length()) return 1;
	        if(dp[i]!=-1) return dp[i];
	        if(str[i]=='0'){
	            return dp[i]=0;
	        }
	        int res=help(str,i+1,p,dp)%p;
	        if(i+1<str.length()){
	            int x=(str[i]-'0')*10+(str[i+1]-'0');
	            if(x>9 && x<=26){
	                res+=(help(str,i+2,p,dp)%p);
	            }
	        }
	        return dp[i]=res%p;
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    vector<int> dp(n,-1);
		    if(str=="") return 1;
		    int p=1000000007;
		    return help(str,0,p,dp);
		    
		}