//9/11 class
//single forward looking dfs - tarjan's algorithm - to detect cycles 
//discovery
//lowest - earliest discovered node that i can reach from curr node is stored

//time: O(V+E)
//space: O(V+E)
class Solution {
    unordered_map<int, vector<int>> map;
    vector<int> discovery;
    vector<int> lowest;
    vector<vector<int>> result;
    int time;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        discovery.resize(n, -1);
        lowest.resize(n);
        time = 0;

        buildGraph(connections, n);
        dfs(0, -1);

        return result;
    }
private:
    void buildGraph(vector<vector<int>>& connections, int n) {
        for (int i = 0; i < n; i++) {
            map[i] = vector<int>();
        }

        for (const auto& edge : connections) {
            int first = edge[0];
            int second = edge[1];
            map[first].push_back(second);
            map[second].push_back(first);
        }
    }

    void dfs(int v, int u) {
        if (discovery[v] != -1) return;
        discovery[v] = lowest[v] = time++;

        for (int ne : map[v]) {
            if (ne == u) continue;
            if (discovery[ne] == -1) {
                dfs(ne, v);
                if (lowest[ne] > discovery[v]) {
                    result.push_back({ne, v});
                }
                lowest[v] = min(lowest[v], lowest[ne]);
            } else {
                lowest[v] = min(lowest[v], discovery[ne]);
            }
        }
    }
};