#include <iostream>
using namespace std;    
#include <vector>
#include <string>
#include <algorithm>

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i = n, j = m;
        string res = "";

        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                res.push_back(str1[i-1]);
                i--; j--;
            } else if (dp[i-1][j] < dp[i][j-1]) {
                res.push_back(str1[i-1]);
                i--;
            } else {
                res.push_back(str2[j-1]);
                j--;
            }
        }

        while (i > 0) {
            res.push_back(str1[i-1]);
            i--;
        }

        while (j > 0) {
            res.push_back(str2[j-1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int main() {
        string str1 = "abac";
        string str2 = "cab";
        cout << "Shortest Common Supersequence: " << shortestCommonSupersequence(str1, str2) << endl; // Output: "cabac"
        return 0;
    }