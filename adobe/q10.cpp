
//   https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/



class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        
        map<string,int> mp;
        int res=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            res=max(res,mp[arr[i]]);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==res){
                return {it->first,to_string(res)};
            }
        }
    }
};