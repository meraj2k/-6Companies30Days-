
// https://leetcode.com/problems/pacific-atlantic-water-flow/





class Solution {
public:
    void dfs(vector<vector<int>> &visited,vector<vector<int>> &h,int i,int j,int prevh){
        if(i<0 || j<0 || i>=h.size() || j>=h[0].size() || visited[i][j] || prevh>h[i][j]) return ;
        visited[i][j]=1;
        dfs(visited,h,i+1,j,h[i][j]);
        dfs(visited,h,i-1,j,h[i][j]);
        dfs(visited,h,i,j+1,h[i][j]);
        dfs(visited,h,i,j-1,h[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<int>> visited1(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>> visited2(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights[0].size();i++){
           dfs(visited1,heights,0,i,heights[0][i]);
            dfs(visited2,heights,heights.size()-1,i,heights[heights.size()-1][i]);
        }
        for(int i=0;i<heights.size();i++){
            dfs(visited1,heights,i,0,heights[i][0]);
            dfs(visited2,heights,i,heights[0].size()-1,heights[i][heights[0].size()-1]);
        }
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(visited1[i][j] && visited2[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};