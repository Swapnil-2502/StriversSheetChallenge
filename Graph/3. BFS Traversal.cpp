#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0); // Initialize visited array to mark visited vertices (0 - not visited, 1 - visited)
    vector<int> result; // To store the BFS traversal order

    queue<int> q; // Create a queue for BFS traversal
    q.push(0); // Start BFS from vertex 0 (can start from any vertex)

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        if (visited[current] == 1) 
        {
            continue; // Skip already visited vertices
        }

        visited[current] = 1; // Mark the current vertex as visited
        result.push_back(current); // Add the current vertex to the BFS traversal order

        // Explore all neighbors of the current vertex
        for (int neighbor : adj[current]) 
        {
          if (visited[neighbor] == 0) {
            q.push(neighbor); // Add unvisited neighbors to the queue
          }
        }
    }

    return result;
}