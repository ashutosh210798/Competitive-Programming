https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// stack overflow link : https://stackoverflow.com/questions/38554083/how-can-i-use-a-c-unordered-set-for-a-custom-class

class StepState{
    public:
    int steps, row, col, k;
    
     StepState(int steps, int row, int col, int k){
        this->steps=steps;
        this->row=row;
        this->col=col;
        this->k=k; 
    }
     bool operator==(const StepState& p) const
    {
        return (row == p.row) && (col == p.col) && (k == p.k);
    }
};
class MyHashFunction {
public:
 
    // We use predefined hash functions of strings
    // and define our hash function as XOR of the
    // hash values.
    size_t operator()(const StepState& p) const
    {
        return (hash<int>()(row+1)) * (hash<int>()(p.col+1))*(hash<int>()(p.k+1));
    }
};
class Solution {
public:
    vector<vector<int> > dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isValid(int x,int y, int rows,int cols){
        return x>=0 && y>=0 && x<rows && y<cols;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
    int rows= grid.size();
    int cols=grid[0].size(); 
    
    pair<int,int> target = {rows-1,cols-1};
    
    if(k>=rows+cols-2){
        return rows+cols-2;
    } 
        queue<StepState> q;
        unordered_set<StepState,MyHashFunction>seen;
        
       // (steps, row, col, remaining quota to eliminate obstacles)
        StepState start(0, 0, 0, k);
       q.push(start);
        seen.insert(start);
        while(!q.empty()){
            
            StepState curr =q.front();
            q.pop();
            
             // we reach the target here
            if (target.first == curr.row && target.second == curr.col) {
                return curr.steps;
            }
            
            for(auto dir: dirs){
                int nx=curr.row+dir[0];
                int ny=curr.col+dir[1];
                if(!isValid(nx,ny,rows,cols)){
                    continue;
                }
                int nextElimination = curr.k - grid[nx][ny];
                StepState newState(curr.steps + 1, nx, ny, nextElimination);
                 // add the next move in the queue if it qualifies.
                if (nextElimination >= 0 && seen.find(newState)==seen.end()) {
                    seen.insert(newState);
                    q.push(newState);
                }
            }
        }
        
        //did not reach the target
        return -1;
    }
};

