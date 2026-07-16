class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0 ;
        int j = m - 1;

        while(target > matrix[i][m - 1]) {
            i++;
            if(i == n) return false;
        }

        int low = 0;

        while(low <= j) {
            int mid = (low + j) / 2;

            if(matrix[i][mid] == target) return true;
            if(matrix[i][mid] < target) {
                low = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return false;
    }
};
