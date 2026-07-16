class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }


        queue<int> que;

        for(int i = 0 ; i < numCourses ; i++) {
            if(indegree[i] == 0) que.push(i);
        }
        int cnt = 0;
        while(!que.empty()) {
            int course = que.front();
            que.pop();
            cnt++;
            for(auto it : adj[course]) {
                indegree[it]--;
                if(indegree[it] == 0) que.push(it);
            }
        }
        return cnt == numCourses;
    }
};
