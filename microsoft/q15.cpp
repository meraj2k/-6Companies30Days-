


//         https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

//


class Solution{
    public:
    vector<char> findEdge(string s1,string s2){
        int i=0,j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]!=s2[i]){
                return {s1[i],s2[j]};
            }
            i++;
            j++;
        }
        return {'a','a'};
    }
    
    void topoSort(vector<vector<int>> &adj,int s,vector<bool> &visited,stack<int> &st){
        visited[s]=1;
        for(int v: adj[s]){
            if(!visited[v]){
                topoSort(adj,v,visited,st);
            }
        }
        st.push(s);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(26,vector<int>());
        for(int i=0;i<N-1;i++){
            vector<char> v=findEdge(dict[i],dict[i+1]);
            if(v[0]==v[1]){
                continue;
            }
            adj[v[0]-'a'].push_back(v[1]-'a');
        }
        vector<bool> visited(26,0);
        stack<int> st;
        for(int i=0;i<26;i++){
            if(!visited[i]){
                topoSort(adj,i,visited,st);
            }
        }
        string s;
        while(!st.empty()){
            s+=st.top()+'a';
            st.pop();
        }
        return s;
    }
};