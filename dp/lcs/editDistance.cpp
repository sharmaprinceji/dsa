    #include <bits/stdc++.h>
    using namespace std;

    int m,n;
    int dp[501][501];
    int solve(string &word1,int i,string &word2,int j){
       if(j==n){
        return m-i;
       } //no of deletion opertaion

       if(i==m){
         return n-j;
       } //no of insertion operation;
       
       if(dp[i][j]!=-1) return dp[i][j];

       if(word1[i]==word2[j]){
          return dp[i][j]=solve(word1,i+1,word2,j+1);
       }
       else{
         int insertion=1+solve(word1,i,word2,j+1);
         int deletion=1+solve(word1,i+1,word2,j);
         int replace=1+solve(word1,i+1,word2,j+1);

         return dp[i][j]=min({insertion,deletion,replace});
       }
    }
    int minDistance(string word1, string word2) {
       m=word1.size();
       n=word2.size();
       memset(dp,-1,sizeof(dp));
       return solve(word1,0,word2,0); 
    }

    int main(){
        string word1 = "horse";
        string word2 = "ros";
        cout << "Minimum Edit Distance: " << minDistance(word1, word2) << endl; // Output: 3
        return 0;
    }