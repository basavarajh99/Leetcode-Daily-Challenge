class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '6'){
                s[i] = '9';
                if(stoi(s) > num){
                    num = stoi(s);
                    s[i] = '6';
                }  
            }
        }

        return num;
    }
};
