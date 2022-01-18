
//     https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string res="";
        int i=0;
        string temp="";
        while(i<s.length()){
            if(s[i]>='A' && s[i]<='Z'){
                res+=temp;
                if(temp!=""){
                    temp=" ";
                }
                temp+=(s[i]+32);
            }else{
                temp+=s[i];
            }
            
            i++;
        }
        res+=temp;
        return res;
    }
};