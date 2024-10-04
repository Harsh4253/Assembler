// important to save time, as anyways it is priority queue, next things will require more effort
// important, as the height difference may be more than the present max effort or lesser
// TC is O( 4*N*M * log( N*M) ) as 4*N*M is for loop 4 times for all N*M cells in worst case and log(N*M) is insertion-deletion operations in a priority queue in worst case
// SC is O( N*M ) as for PQ in worst case

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
                                            greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> distTo(n, vector<int>(m, INT_MAX));
        distTo[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // important to save time, as anyways it is priority queue, next things will require more effort
            if(row==n-1 && col==m-1) return effort;

            int drow[4] = {1,0,-1,0};
            int dcol[4] = {0,-1,0,1};
            for (int i=0;i<4;i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                    
                    // important, as the height differe may be more than the present max effort or lesser
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), effort);
                    if (newEffort < distTo[nrow][ncol]) {
                        distTo[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};