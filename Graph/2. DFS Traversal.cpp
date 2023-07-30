
void dfs(int node,vector<int> &temp,vector<int> adj[],vector<int> &vis){

    vis[node] = 1;
    temp.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]) dfs(it,temp,adj,vis);
    }
    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   
    vector<int> adj[V+1];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V,0);
    vector<vector<int>> ans;

    for(int i=0;i<V;i++){
        if(vis[i]) continue;

        vector<int> temp;
        dfs(i,temp,adj,vis);
        ans.push_back(temp);
    }

    return ans;
}
//Sc = O(N)(storing n nodes int dfs traversal) + O(N)(vis array) + O(N) recusrion
//Tc = O(N) + O(2*E);