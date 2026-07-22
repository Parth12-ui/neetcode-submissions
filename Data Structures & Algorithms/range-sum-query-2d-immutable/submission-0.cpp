class NumMatrix {
private:
    vector<vector<int>> sum_matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        sum_matrix.assign(m, vector<int>(n, 0));

        for(int i = 0; i<matrix.size(); i++){
            for (int j = 0; j<matrix[i].size(); j++){
                int sum = matrix[i][j];
                if (i > 0) sum += sum_matrix[i-1][j];
                if (j > 0) sum += sum_matrix[i][j-1];
                if (i > 0 && j > 0) sum -= sum_matrix[i-1][j-1];

                sum_matrix[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum_region = sum_matrix[row2][col2];
        
        if (row1 > 0) sum_region -= sum_matrix[row1-1][col2];
        if (col1 > 0) sum_region -= sum_matrix[row2][col1-1];

        if (row1 > 0 && col1 > 0) sum_region += sum_matrix[row1-1][col1-1];

        return sum_region;
    }
};
 
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */