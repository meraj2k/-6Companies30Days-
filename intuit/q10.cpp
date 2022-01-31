
//    https://leetcode.com/problems/number-of-provinces/



class Solution {
public:
    void dfs(int s,vector<vector<int>> &graph,vector<int> &visited,int n){
        visited[s]=1;
        for(int j=0;j<n;j++){
            if(visited[j]==0 && graph[s][j]==1){
                dfs(j,graph,visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,isConnected,visited,n);
                count++;
            }
        }
        return count;
    }
};