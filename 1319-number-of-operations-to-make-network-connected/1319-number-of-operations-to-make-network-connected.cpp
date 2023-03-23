class Solution {
public:

    void dfs(vector<int> adj[] , vector<int> &visited , int i){
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[ adj[i][j] ]) 
            {
                dfs(adj,visited,adj[i][j]);
            };
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> visited(n,0);

        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]); //양방향
        }
        int c=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                c++;
                dfs(adj,visited,i);
            }
        }


        if( connections.size() >= n-1) return c-1;
        return -1;
    }
};