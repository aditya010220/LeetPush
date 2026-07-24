class Solution {
public:
    int solve(string &word1, string &word2, int i, int j,
              vector<vector<int>> &dp) {

        // word1 is exhausted
        if (i == word1.size()) {
            return word2.size() - j;
        }

        // word2 is exhausted
        if (j == word2.size()) {
            return word1.size() - i;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters are same
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);
        }

        // Insert
        int insert = solve(word1, word2, i, j + 1, dp);

        // Delete
        int deleteChar = solve(word1, word2, i + 1, j, dp);

        // Replace
        int replace = solve(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min({insert, deleteChar, replace});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(word1, word2, 0, 0, dp);
    }
};