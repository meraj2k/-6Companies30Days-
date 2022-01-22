
//    https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/



class Solution{
  public:
    void reverse(string &s,int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string nextPalin(string N) { 
        //complete the function here
        if(N.size()<=2) return "-1";
        string res=N;
        int l=N.size()/2;
        int i=l-2;
        while(i>=0 && N[i]>=N[i+1]) i--;
        if(i<0){
            return "-1";
        }
        int j=l-1;
        while(N[j]<=N[i])  j--;
        swap(res[i],res[j]);
        //cout<<res<<" "<<i;
        reverse(res,i+1,l-1);
        //cout<<res<<" ";
        i=N.size()-1;
        
        while(i>=l){
            res[i]=res[N.size()-i-1];
            i--;
        }
        return res;
    }
};