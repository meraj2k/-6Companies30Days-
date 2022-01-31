
//    https://leetcode.com/problems/course-schedule-ii/




class Solution {
public:
     bool isCycle(vector<vector<int>> &adj,int s,vector<int> &visited,vector<int> &callStack,vector<int> &a){
        visited[s]=1;
        callStack[s]=1;
        for(int v:adj[s]){
            if(visited[v]==0){
                if(isCycle(adj,v,visited,callStack,a))
                    return true;
            }else if(callStack[v]==1){
                return true;
            }
        }
        callStack[s]=0;
        a.push_back(s);
        return false;
    }
    
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> a;
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> visited(n,0),callStack(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0)
                if(isCycle(adj,i,visited,callStack,a)){
                    return {};
                }
        }
         reverse(a.begin(),a.end());
        return a;
    }
};
