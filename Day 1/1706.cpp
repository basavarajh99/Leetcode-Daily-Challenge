/*

    1706. Where Will the Ball Fall

    Problem Statement: 
    You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.
    Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the 
    left.
    A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the 
    grid as 1. A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is 
    represented in the grid as -1. We drop one ball at the top of each column of the box. Each ball can get stuck in the box or
    fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the 
    ball into either wall of the box. Return an array answer of size n where answer[i] is the column that the ball falls out of
    at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

*/

class Solution {
    int getPosition(vector<vector<int>>& grid, int c, int r, int rows, int cols){
        if(grid[r][c] == 1){
            if(c == cols-1 || grid[r][c+1] == -1) return -1;
            return c+1;
        } else{
            if(c == 0 || grid[r][c-1] == 1) return -1;
            return c-1;
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ans;
        for(int c = 0; c < cols; c++){
            int position = c;
            for(int r = 0; r < rows; r++){
                position = getPosition(grid, position, r, rows, cols);
                if(position == -1)
                    break;
            }
            
            ans.push_back(position);
        }
        
        return ans;
    }
};
