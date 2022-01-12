


//   https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution{
public:
    void printPara(vector<vector<int>>&bracket,int i,int j,string &res){
        if(i==j){
            res.push_back('A'+i);
            return;
        }
        res.push_back('(');
        int k=bracket[i][j];
        printPara(bracket,i,k,res);
        printPara(bracket,k+1,j,res);
        res.push_back(')');
    }
    
    int help(int arr[],int s,int e,vector<vector<int>> &dp,vector<vector<int>> &bracket){
        
        if(s+1==e){
            return 0;
        }
        
        if(dp[s][e-1]!=-1) return dp[s][e-1];
        int res=INT_MAX;
        for(int k=s;k<e-1;k++){
            int l=help(arr,s,k+1,dp,bracket);
            int r=help(arr,k+1,e,dp,bracket);
            int m=arr[s]*arr[k+1]*arr[e];
            if(res>l+r+m){
                res=l+r+m;
                bracket[s][e-1]=k;
            }
        }
        return dp[s][e-1]=res;
    }
    
    string matrixChainOrder(int p[], int N){
        // code here
        string res;
        vector<vector<int>> dp(N-1,vector<int>(N-1,-1)),bracket(N-1,vector<int>(N-1,-1));
        help(p,0,N-1,dp,bracket);
        //  for(auto v: bracket){
        //     for(auto x: v){
        //         cout<<x<<"  ";
        //     }
        //     cout<<endl;
        // }
        printPara(bracket,0,N-2,res);
        return res;
    }
};