class Solution {
public:
    #define ll long long
    const int mod=1e9+7;
        int dp[60][60][60];
    
    ll solve(int m,int n,int mx,int i,int j){
        if(mx<0)return 0;
        if(i>=m || j>=n||i<0||j<0){
            return 1;
        }
        if(dp[i][j][mx]!=-1)return dp[i][j][mx];


        ll a=solve(m,n,mx-1,i+1,j)%mod;
        ll b=solve(m,n,mx-1,i-1,j)%mod;
        ll c=solve(m,n,mx-1,i,j+1)%mod;
        ll d=solve(m,n,mx-1,i,j-1)%mod;
        return dp[i][j][mx]=(((a+b)%mod+c)%mod+d)%mod;
    }
    ll findPaths(int m, int n, int mx, int i, int j) {
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=mx;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(m,n,mx,i,j);
    }
};