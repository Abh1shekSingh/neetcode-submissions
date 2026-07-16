class Solution {
public:
    unordered_map<int, vector<int>> adj;
    set<int> vis;
    bool DFS(int course) {
        if(vis.count(course)) return false;
        if(adj.empty()) return true;

        vis.insert(course);

        for(auto it : adj[course]) {
            if(DFS(it) == false) return false;
        }
        vis.erase(course);
        adj[course].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0 ; i < numCourses ; i++) {
            if(DFS(i) == false) {
                return false;
            }
        }
        return true;
    }
};
