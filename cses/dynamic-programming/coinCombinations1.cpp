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
- dp(i) = no.of ways of making sum==i using given coins.
- Ans = dp(X). 
- dp(i) = dp(i-c1) + dp(i-c2) + ... + dp(i-cn)
- dp(0) = 1
- T(n) = O(n.X)
- S(n) = O(x)
*/

int find(int n, int i, const vector<int>& c, int* dp) {
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    for(int j=0;j<n;++j){
        if(c[j] <= i){
            int ans1 = find(n, i - c[j], c, dp);
            if(dp[i]==-1) dp[i] = 0;
            dp[i] = (dp[i] + ans1)%MOD;
        }
    }
    return dp[i];
}
//top to bottom approach
void method1(int n, int x, vector<int> c) {
    int* dp = new int[x+1];
    rep(i,0,x+1)
        dp[i] = -1;
    
    int tot = find(n,x,c,dp);
    cout<<tot<<'\n';
}

//bottom to top approach
void method2(int n, int x, vector<int> c) {
    int dp[x+1];
    dp[0]=1;
    rep(i,1,x+1){
        dp[i] = 0;
        for(int coin_val : c){
            if(coin_val <= i)
                dp[i] = (dp[i] + dp[i-coin_val])% MOD;
        }
    }
    cout<<dp[x]<<'\n';
}

int main() {
    IOS;
    int T = 1;
    //cin >> T;
    rep(i, 1, T + 1) {
        int n,x;
        cin>>n>>x;
        vector<int> c(n);
        rep(i,0,n) cin>>c[i]; 
        //method1(n,x,c);
        method2(n,x,c);
    }
    return 0;
}
