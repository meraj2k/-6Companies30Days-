
//   https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void fun(string &str,int k,string &res){
        if(k==0) return ;
        for(int i=0;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[j]>str[i]){
                    swap(str[i],str[j]);
                    res=str.compare(res)>0?str:res;
                    fun(str,k-1,res);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
    //   string s="213";
    //   cout<<(s.compare("123"));
       string res=str;
       fun(str,k,res);
       return res;
    }
};