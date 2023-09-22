class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int k=0;
        for(int i = 0 ; i<m && k<=n ; i++) {
            if(t[i] == s[k]){
                k++;
            }
        }
        if(k == n){
            return true;
        }
        return false;
    }
};
