//my approach
class Solution {
public:
    string makeGood(string s) {
        int i = 1;
        
        while(s.length() && i < s.length()){
            if(isupper(s[i])){
                if(islower(s[i-1]) && s[i] == toupper(s[i-1])){
                    s.erase(i-1, 2);
                    i=1;
                }
                else i++;
            } else if(islower(s[i])){
                if(isupper(s[i-1]) && s[i] == tolower(s[i-1])){
                    s.erase(i-1, 2);
                    i = 1;
                }
                else i++;
            }
        }

        return s;
    }
};

//approach I liked
class Solution {
public:
    string makeGood(string s) {
        string ans;

        for(int i = 0; i < s.length(); i++){
            if(ans.empty() || abs(s[i] - ans.back()) != 32)
                ans.push_back(s[i]);
            else    
                ans.pop_back();
        }

        return ans;
    }
};



