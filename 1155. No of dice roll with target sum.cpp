class Solution {
public:
    int dp[50][1010];
    const int mod=1e9+7;
    int solve(int n,int k,int t){
        if(t<0)return 0;
        if(n==0 && t==0)return 1;
        if(n==0 && t!=0)return 0;

        if(dp[n][t]!=-1)return dp[n][t];
        int ans=0;
        for(int j=1;j<=k;j++){
        int a=solve(n-1,k,t-j)%mod;
        ans=(ans%mod+a%mod)%mod;
        }
        return dp[n][t]= ans;
    }
    int numRollsToTarget(int n, int k, int t) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,t);
    }
};
