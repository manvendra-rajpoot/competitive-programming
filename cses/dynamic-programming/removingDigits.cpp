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
- dp(i) = min. step to go from i to 0.
- Ans is: dp(n). 
- dp(i) = 1+ min(dp(n-di)); di is i-th digit 
- dp(0) = 0
- S(n) = O(n)
- T(n) = O(n.X); X=number of digits
*/

int find(int i, int* dp) {
    if(i==0)return 0;
    if(dp[i]>-1) return dp[i];
    int temp = i, minSteps = INT_MAX;
    while(temp!=0){
        int di = temp%10;
        temp/=10;
        if(di==0) continue; //deadlock condition
        minSteps = min(minSteps, 1+ find(i-di,dp));
    }
    dp[i] = minSteps;
    return dp[i];
}

//top to bottom approach
void method1(int n) {
    int* dp = new int[n+1];
    rep(i,0,n+1) dp[i]=-1;
    int ans = find(n, dp);
    delete [] dp;
    cout<<ans<<'\n';
}

//bottom to top approach
void method2(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    rep(i,1,n+1){
        int temp = i;
        int minSteps = INT_MAX;
        while(temp!=0){
            int di = temp%10;
            temp/=10;
            if(di==0) continue; //deadlock condition
            minSteps = min(minSteps, 1+ dp[i-di]);
        }
        dp[i] = minSteps;
    }
    
    cout<<dp[n]<<'\n';
}

int main() {
    IOS;
    int T = 1;
    //cin >> T;
    rep(i, 1, T + 1) {
        int n;
        cin>>n;

        method1(n);
        //method2(n);
    }
    return 0;
}
