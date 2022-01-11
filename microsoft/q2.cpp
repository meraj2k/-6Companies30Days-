
//  https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

class Solution
{
public:
    bool isCycle(vector<vector<int>> &adj, int s, vector<bool> &callStack, vector<bool> &visited)
    {
        visited[s] = 1;
        callStack[s] = 1;
        for (int v : adj[s])
        {
            if (!visited[v])
            {
                if (isCycle(adj, v, callStack, visited))
                {
                    return true;
                }
            }
            else if (callStack[v])
            {
                return true;
            }
        }
        callStack[s] = 0;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<vector<int>> adj(N, vector<int>());
        for (auto p : prerequisites)
        {
            adj[p.second].push_back(p.first);
        }
        vector<bool> visited(N, 0), callStack(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && isCycle(adj, i, callStack, visited))
            {
                return false;
            }
        }
        return true;
    }
};