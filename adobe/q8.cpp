

//   https://practice.geeksforgeeks.org/problems/implement-atoi/1/


class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0;
        bool flag=false;
        if(str[i]=='-'){
            flag=1;
            i++;
        }
        int res=0;
        while(i<str.length()){
            if(str[i]<'0' || str[i]>'9'){
                return -1;
            }else{
                res= res*10+str[i]-'0';
            }
            i++;
        }
        return flag?-1*res:res;
    }
};