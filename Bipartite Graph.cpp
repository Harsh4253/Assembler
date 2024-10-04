// I just modified the DFS cycle detection by adding colour c
// Here, one false also return false
// Over there, atleast oen true return true
// For queue method, isntead of parent, add colour to the queue 

// DFS approach

class Solution {
private: 
bool dfs(int node, int colorValue, vector<vector<int>>& graph, vector<int>& color) {
    color[node] = colorValue;
    
    for(auto neighbor : graph[node]) {
        if(color[neighbor] == 0) {
            if(!dfs(neighbor, -colorValue, graph, color)) 
                return false;
        }
        else if(color[neighbor] == colorValue) {
            return false;
        }
    }
    return true;
}

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); 
        
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                if(!dfs(i, 1, graph, color)) 
                    return false;
            }
        }
        return true;
    }
};

// _______________________________________

// BFS approach

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); 
        
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(auto neighbor : graph[node]) {
                        if(color[neighbor] == 0) {
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                        } else if(color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
