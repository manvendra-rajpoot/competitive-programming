#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define sz(c) c.size()
#define all(v) (v).begin(), (v).end()
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/*
- dp(i) = no.of valid ways of throwing dice such that sum==i.
- Ans is: dp(n). 
- dp(i) = dp(i-1) + dp(i-2) + ... + dp(i-6)
- dp(0) = 1
- dp(-ve) = not valid, avoid it
- S(n) = O(n)
- T(n) = O(n)
*/

ll find(ll n, vector<ll>& dp) {
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]>-1) return dp[n];
    ll ans=0;
    for(int i=1;i<7;++i){
        ans = (ans + find(n-i,dp))%MOD;
    }
    dp[n] = ans;
    return dp[n];
}

//top to bottom approach
void method1() {
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    dp[0] = 1;
    cout<<find(n,dp)<<'\n';
}

//bottom to top approach
void method2() {
    int n;
    cin>>n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    rep(i,1,n+1){
        for(int x=1;x<7;++x){
            if(x>i)break;
            dp[i] = (dp[i]+dp[i-x])%MOD;
        }
    }
    cout<<dp[n]<<'\n';
}

int main() {
    IOS;
    int T = 1;
    //cin >> T;
    rep(i, 1, T + 1) {
        method1();
        //method2();
    }
    return 0;
}
