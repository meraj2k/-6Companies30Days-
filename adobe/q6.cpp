
//   https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/ 


class Solution
{
    public:
    void helper(int o,int c,string str,vector<string> &res){
        if(c==0){
            res.push_back(str);
            
        }
        else if(o==0){
           helper(o,c-1,str+')',res);
        }
        else if(o==c){
             helper(o-1,c,str+'(',res);
        }
        else{
             helper(o-1,c,str+'(',res);
            helper(o,c-1,str+')',res);
         
         }
         //return ;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }
};