class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int n  = n1.size();
        int m = n2.size();
        
        int ans = 0 ;

        int t[n + 1][m + 1];
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                if (i == 0 || j == 0){
                    t[i][j] = 0;
                }    
            }
        }
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1; j<=m ; j++){
                if(n1[i-1] == n2[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                    ans = max(t[i][j], ans);
                }else{
                    t[i][j] = 0;
                }
            }
        }

        return ans;

    }
};
