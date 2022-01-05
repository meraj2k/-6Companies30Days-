

// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<int> ist;
        stack<string> st;
        string res="";
        int count;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]>='0' && s[i]<= '9'){
                count=0;
                while(s[i]>='0' && s[i]<='9'){
                    count=count*10 + s[i]-'0';
                    i++;
                }
                
                ist.push(count);
            }else if(s[i]==']'){
                string temp= st.top();
                st.pop();
                count=ist.top();
                ist.pop();
                for(int j=0;j<count;j++){
                    temp+=res;
                }
                res=temp;
                i++;
            }else if(s[i]=='['){
                st.push(res);
                res="";
                i++;
            }else{
                res+=s[i++];
            }
        }
        return res;
    }
};