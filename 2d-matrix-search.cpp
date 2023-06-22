/*
First find the row using binary search then col using another binary search. 
Time: O(log (m*n))
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowRow = 0, highRow = matrix.size()-1;
        while(lowRow<highRow){
            int mid = lowRow + (highRow-lowRow)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]<target && target<matrix[mid+1][0]){
                lowRow = mid;
                break;
            }
            if(matrix[mid][0]<target)
                lowRow = mid+1;
            else
                highRow = mid-1;
        }

        int lowCol = 0, highCol = matrix[0].size()-1;
        while(lowCol<=highCol){
            int mid = lowCol + (highCol-lowCol)/2;
            if(matrix[lowRow][mid]==target)
                return true;
            else if(matrix[lowRow][mid]<target)
                lowCol = mid+1;
            else
                highCol = mid-1;
        }      
        return false;
    }
};