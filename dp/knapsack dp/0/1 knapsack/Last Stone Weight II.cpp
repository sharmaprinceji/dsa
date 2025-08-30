#include <bits/stdc++.h>
using namespace std;

 int total;
    int n;
    vector<int> stones;
    vector<vector<int>> memo;

    // return true if subset sum 'curr' is possible starting from index i
    bool solve(int i, int curr) {
        if (curr < 0) return false;
        if (i == n) return (curr == 0);

        if (memo[i][curr] != -1) return memo[i][curr];

        // Choice: take this stone or skip it
        bool take = false;
        if (curr >= stones[i]) {
            take = solve(i + 1, curr - stones[i]);
        }
        bool notTake = solve(i + 1, curr);

        return memo[i][curr] = (take || notTake);
    }

    int lastStoneWeightII(vector<int>& arr) {
        stones = arr;
        n = stones.size();
        total = accumulate(stones.begin(), stones.end(), 0);
        int half = total / 2;

        memo.assign(n + 1, vector<int>(half + 1, -1));

        // Find the largest j (≤ total/2) that is achievable
        int best = 0;
        for (int j = half; j >= 0; --j) {
            if (solve(0, j)) {
                best = j;
                break;
            }
        }
        return total - 2 * best;
    }

    int main() {
    vector<int> stones1 = {2,7,4,1,8,1};
    vector<int> stones2 = {31,26,33,21,40};

    cout << lastStoneWeightII(stones1) << endl; // Output: 1
    cout << lastStoneWeightII(stones2) << endl; // Output: 5
    return 0;
}
