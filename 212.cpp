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


//optimized using Trie

class Solution {
    struct TrieNode{
        string word;
        TrieNode* children[26];
    };
    
    TrieNode* root;
    
    void formTrie(vector<string>& words){
        root = new TrieNode();
        for(auto it : words){
            TrieNode* cur = root;
            for(auto c : it){
                if(!cur->children[c-'a'])
                    cur->children[c-'a'] = new TrieNode();
                cur = cur->children[c-'a'];
            }

            cur->word = it;
        }
    }

    void DFS(int i, int j, vector<vector<char>>& board, vector<string>& ans, int rows, int cols, TrieNode* r){
        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == '$' || !r->children[board[i][j] - 'a'])
            return;
        
        r = r->children[board[i][j] - 'a'];

        if(r->word.size() > 0){
            ans.push_back(r->word);
            r->word = "";
        }

        char ch = board[i][j];
        board[i][j] = '$';

        DFS(i-1, j, board, ans, rows, cols, r);
        DFS(i+1, j, board, ans, rows, cols, r);
        DFS(i, j-1, board, ans, rows, cols, r);
        DFS(i, j+1, board, ans, rows, cols, r);

        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size(), cols = board[0].size();
        formTrie(words);
        vector<string> ans;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                DFS(i, j, board, ans, rows, cols, root);
            }
        }

        return ans;
    }
};

