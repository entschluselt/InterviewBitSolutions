/*

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

    For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

*/
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> ans;
    
    void DFS(string str){
        auto &e = graph[str];
        while(!e.empty()){
            string x = e.top();
            e.pop();
            DFS(x);
        }
        ans.push_back(str);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto e:tickets)
            graph[e[0]].push(e[1]);
        
        DFS("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
