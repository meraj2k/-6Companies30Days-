
//   https://leetcode.com/problems/path-with-maximum-probability/


class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n,vector<pair<int,double>>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool> visited(n,0);
        vector<double> dp(n,0);
        dp[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({double(1.0),start});
        while(!pq.empty()){
            auto p=pq.top();
            int u=p.second;
            double pr=p.first;
            pq.pop();
            if(!visited[u]){
                visited[u]=1;
                for(auto v:adj[u]){
                    if(dp[v.first]<dp[u]*v.second){
                        dp[v.first]=dp[u]*v.second;
                        pq.push({dp[v.first],v.first});
                    }
                }
            }
            
        }
        return dp[end];
    }
};