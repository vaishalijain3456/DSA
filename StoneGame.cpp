class Solution {
public:
    int dp[50001][2];
    int M = 3;
    int dfs(int idx, int n, vector<int> &piles, int person){
        if (idx>=n){
            return 0;
        }
        if (dp[idx][person]!=-1){
            return dp[idx][person];
        }
        
        int s = 0;
        int res;
        if (person==0){
            res = INT_MIN;
        } else {
            res = INT_MAX;
        }
        for (int x = 1; x<=min(M, n-idx); x++){
            s += piles[idx+x-1]; // since started from 1;
            if (person==0){
                res = max(res, s+dfs(idx+x, n, piles, 1));
            } else {
                res = min(res, dfs(idx+x, n, piles, 0));
            }
        }
        return dp[idx][person]=res;
    }
    string stoneGameIII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int total = accumulate(piles.begin(), piles.end(), 0); 
        int alice =  dfs(0, piles.size(), piles, 0);
        int bob = total-alice;
        int res = alice-bob;
        if (res > 0)
            return "Alice";
        else if (res < 0)
            return "Bob";
        else
            return "Tie";
        
    }
};
