/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

*/

// solution :
/*
 THE IDEA HERE IS TO NOTICE IF ANY VERTICE HAS AN INCOMING EDGE THEN IT CAN BE REACHED FROM SOMEWHERE 
  BUT IF ANY EDGE HAS NO ICOMING EDGE IT DEFINATLY HAS TO BE SEARCHED
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) { 
        vector<int> indegree(n,0);
        for(auto x:edges) indegree[x[1]]++;   // CALCULATING INDEGREES OF EVERY NODE
        vector<int> ans;
        for(int i = 0; i < n; i++)       
            if(!indegree[i])
                ans.push_back(i);
        return ans;
    }
};
