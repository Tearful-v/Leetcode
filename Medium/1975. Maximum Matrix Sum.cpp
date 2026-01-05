class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        long long sum = 0;
        int min = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] < 0)
                    count++;
                sum += std::abs(matrix[i][j]);
                if(std::abs(matrix[i][j]) < min){
                    min = std::abs(matrix[i][j]);
                }
            }
        }
        return sum - (count & 1) * 2* min;
    }
};