//Brute-Force using DFS approach
class Solution {
    bool DFS(int i, int j, string s, vector<vector<char>>& board){
        
        if(s.empty()) return true;
        
        int rows = board.size(), cols = board[0].size();
        char ch = board[i][j];
        board[i][j] = '$';
        string str =  s.substr(1);
        if( (i-1 >= 0 && board[i-1][j] == s[0] && DFS(i-1, j, str, board)) ||
            (i+1 < rows && board[i+1][j] == s[0] && DFS(i+1, j, str, board)) ||
            (j-1 >= 0 && board[i][j-1] == s[0] && DFS(i, j-1, str, board)) ||
            (j+1 < cols && board[i][j+1] == s[0] && DFS(i, j+1, str, board))
        ) {
            board[i][j] = ch;
            return true;
        }

        board[i][j] = ch;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st; //to avoid duplicate answers
        
        for(int k = 0; k < words.size(); k++){
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(words[k][0] == board[i][j] && DFS(i, j, words[k].substr(1), board))
                        st.insert(words[k]);
                }
            }
        }

        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};
