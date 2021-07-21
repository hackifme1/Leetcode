// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the
center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.


Example 1:

Input: edges = [[1,2],[2,3],[4,2]]
Output: 2

Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.


Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.

*/


Cpp code :

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        
        for(int i=0;i<n;i++)
        {
            if(edges[i][0] > edges[i][1])
                swap(edges[i][1], edges[i][0]);
        }
        
        sort(edges.begin(), edges.end());
        
        
        for(int i=1;i<n;i++)
        {
            if(edges[i][0] == edges[i-1][1])
                return edges[i][0];
            else if(edges[i][0] == edges[i-1][0])
                return edges[i][0];
            else if(edges[i][1] == edges[i-1][1])
                return edges[i][1];
            else if(edges[i][1] == edges[i-1][0])
                return edges[i][1];
        }
        
        return -1;
    }
};
