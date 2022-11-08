class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();

        //if k > 1 then we can swap any character to any place so eventually the 
        //lexicographically smallest string will be sorted one
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        } else {
            //if k == 1 then we just find a string that is lexicographically smaller
            //this can be done as follow:
            //append entre string at the end and find the minimu substring which will
            //be lexicographically smaller to present one
            string minStr = s;
            s += s;
            for(int i = 1; i < n; i++)
                minStr = min(minStr, s.substr(i, n));

            return minStr;
        }
        
    }
};
