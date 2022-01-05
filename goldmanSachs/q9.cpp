
// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1


class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        string res;
        int count=1;
        //st.push(1);
        int n=S.length(),i=0;
        while(i<n){
            st.push(count);
            count++;
            if(S[i]=='I'){
                while(!st.empty()){
                    res+=(st.top()+'0');
                    st.pop();
                }
            }
            i++;
        }
        st.push(count);
        while(!st.empty()){
            res+=(st.top()+'0');
            st.pop();
        }
        return res;
    }
};