class Solution {
public:
    #define ll long long
    const int mod=1e9+7;
    ll solve(int m,int n,int mx,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n||i<0||j<0){
            if(mx>=0)return 1;
            else return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];


        ll a=solve(m,n,mx-1,i+1,j,dp)%mod;
        ll b=solve(m,n,mx-1,i-1,j,dp)%mod;
        ll c=solve(m,n,mx-1,i,j+1,dp)%mod;
        ll d=solve(m,n,mx-1,i,j-1,dp)%mod;
        return dp[i][j]=(((a+b)%mod+c)%mod+d)%mod;
    }
    ll findPaths(int m, int n, int mx, int i, int j) {
        vector<vector<int>>dp(4000,vector<int>(4000,-1));
        return solve(m,n,mx,i,j,dp);
    }
};