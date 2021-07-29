// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


Example 1:

Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]

Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].


Example 2:

Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]

Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
 

Constraints:

2 <= n <= 10^5
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi < n
All pairs (fromi, toi) are distinct.

*/


Cpp code :

// Simple non reachable node counting approach

class Solution {
public:    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        vector<bool> reachable(n, false);
        vector<int> res;
        
        for(int i=0;i<m;i++)
        {
            reachable[edges[i][1]] = true;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!reachable[i])
                res.push_back(i);
        }     
        
        return res;
    }
};


// DFS approach

class Solution {
public:
    
    void dfs(vector<int> adj[], map<int,int> &mp, vector<bool> &vis, int node)
    {
        vis[node] = true;
        
        for(auto ver : adj[node])
        {
            if(!vis[ver])
                dfs(adj, mp, vis, ver);
            else if(mp[ver] == 1)
                mp[ver] = 0;                
        }            
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<bool> vis(n, false);
        vector<int> adj[n];
        map<int,int> mp;
        
        vector<int> res;
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<n;i++)
        {
             if(!vis[i])
             {
                 dfs(adj, mp, vis, i);
                 mp[i] = 1;
             }
             
        }
       
        for(auto elem : mp)
        {
            if(elem.second == 1)
            res.push_back(elem.first);
        }
        
        return res;
    }
};
