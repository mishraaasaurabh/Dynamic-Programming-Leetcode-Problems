#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
#define int long long
int solve(vector<int>&v,int sum,int i){
    int n=v.size();
    if(i==n){return sum;}
    if(sum>=v[i]){return sum;}
    else{
        return max(solve(v,sum+v[i],i+1),solve(v,sum,i+1));
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>v={6,13,9,19};
    sort(v.begin(),v.end());
    cout<<solve(v,0,0);
    
}