class Solution {
public:

    string shortestSuperstring(vector<string>& words) {

        int cost[12][12] = {0};
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                cost[i][j] = helper(words[i], words[j]);
                cost[j][i] = helper(words[j], words[i]);
            }
        }

        int dp[1<<12][12] = {0};
        int path[1<<12][12] = {0};
        
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) > 0) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = words[j].size();
                    } else {
                        dp[i][j] = INT_MAX;
                        for (int k = 0; k < n; ++k) {
                            if ((prev & (1 << k)) && dp[prev][k] + cost[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + cost[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
            }
        }

        int last = -1, len = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dp[(1<<n)-1][i] < len) {
                len = dp[(1<<n)-1][i];
                last = i;
            }
        }

        int cur = (1 << n) - 1;
        stack<int> stk;
        while (cur > 0) {
            stk.push(last);
            int tmp = cur;
            cur -= (1 << last);
            last = path[tmp][last];
        }

        int pre = stk.top();
        stk.pop();
        string res = words[pre];
        while (!stk.empty()) {
            int j = stk.top();
            stk.pop();
            res += words[j].substr(words[j].size() - cost[pre][j]);
            pre = j;
        }
        return res;
    }

    int helper(string &s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        for (int i = 0; i < n1; ++i) {
            int j = i, k = 0;
            while (j < n1 && k < n2 && s1[j] == s2[k]) {
                j++;
                k++;
            }
            if (k == n2) return 0;
            if (j == n1) return n2 - k;
        }
        return n2;
    }

};
