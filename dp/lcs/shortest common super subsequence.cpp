#include <bits/stdc++.h>
using namespace std;

    int n, m;
        string str1, str2;
        vector<vector<int>> dp;
        
        //lcs memoization method..
        int lcs(int i, int j) {
            if (i == n || j == m) return 0;
            if (dp[i][j] != -1) return dp[i][j];
    
            if (str1[i] == str2[j]) {
                return dp[i][j] = 1 + lcs(i + 1, j + 1);
            } else {
                return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
            }
        }
        
        //memoization method..
        int t[501][501];
        int solve(int i, int j) {
            if (i == n) return m - j;
            if (j == m) return n - i;

            if (t[i][j] != -1) return t[i][j];

            if (str1[i] == str2[j]) {
                return t[i][j]=1 + solve(i + 1, j + 1);
            } else {
                return t[i][j]=1 + min(solve(i + 1, j), solve(i, j + 1));
            }
        }   

        //tabulation method..
        int helper(int i, int j) {
            for(int i=0;i<=n;i++) t[i][0]=i;
            for(int j=0;j<=m;j++) t[0][j]=j;
            for(int i=1;i<=n;i++){if(n==0 || m==0) return m+n;
                for(int j=1;j<=m;j++){
                    if(str1[i-1]==str2[j-1]){
                        t[i][j]=1 + t[i-1][j-1]; 
                    }else{
                        t[i][j]=1 + min(t[i-1][j],t[i][j-1]);
                    }       
                }
            }
            return t[n][m];        
        }   
    
        int shortestCommonSupersequence(string s1, string s2) {
            str1 = s1;
            str2 = s2;
            n = str1.size();
            m = str2.size();
            dp.assign(n + 1, vector<int>(m + 1, -1));
    
            int lcsLength = lcs(0, 0);
            return n + m - lcsLength; // Length of SCS = len(s1) + len(s2) - len(LCS)
        }
    
        int main() {
        string s1 = "abac";
        string s2 = "cab";
    
        cout << shortestCommonSupersequence(s1, s2) << endl; // Output: 5
        return 0;
    }