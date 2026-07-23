class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //row check
        for(auto& row : board){
            unordered_map<char, int> hashmap;
            for(char num : row){
                if (num == '.') continue;
                if (hashmap.count(num) == 0) hashmap[num]++;
                else return 0;
            }
        }
        
        //column check
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<n; i++){
            unordered_map<char, int> hashmap;
            for(int j = 0; j<m; j++){
                if (board[j][i] == '.') continue;

                if (hashmap.count(board[j][i]) == 0) hashmap[board[j][i]]++;
                else return 0;
            }
        }

        //box check
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                unordered_map<char, int> hashmap;
                for(int k = 0; k<3; k++){
                    for(int l = 0; l<3; l++){
                        if (board[3*i + k][3*j + l] == '.') continue;

                        if (hashmap.count(board[3*i + k][3*j + l]) == 0) hashmap[board[3*i + k][3*j + l]]++;
                        else return 0;
                    }
                }
            }
        }

        return 1;
    }
};
