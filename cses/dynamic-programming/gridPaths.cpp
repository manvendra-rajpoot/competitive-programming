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
- dp(i,j) = no.of valid path from cell(i,j) to cell(n-1,n-1).
- Ans is: dp(0,0). 
- dp(i,j) = dp(i,j+1) + dp(i+1,j)
- dp(n-1,n-1) = 1
- S(n) = O(n^2)
- T(n) = O(n^2)
*/

int find(int i, int j, int n, int** dp) {
    if(i>=n || j>=n)return 0;
    if(dp[i][j]>-1) return dp[i][j];
    dp[i][j] = (find(i+1,j,n,dp) + find(i,j+1,n,dp))%MOD;
    return dp[i][j];
}

//top to bottom approach
void method1(int n, vector<vector<char>>& g) {
    int** dp = new int*[n];
    rep(i,0,n){
        dp[i] = new int[n];
        rep(j,0,n){
            dp[i][j]=-1;
            if(g[i][j]=='*') dp[i][j]=0;
        }
    }
    if(g[n-1][n-1]!='*') dp[n-1][n-1]=1;
    
    int ans = find(0,0,n,dp);
    rep(i,0,n)delete [] dp[i];
    delete [] dp;
    cout<<ans<<'\n';
}

//bottom to top approach
void method2(int n, vector<vector<char>>& g) {
    int dp[n][n];
    for(int i=n-1;i>-1;--i){
        for(int j=n-1;j>-1;--j){
            if(i==n-1&&j==n-1){
                dp[i][j]=1;
            }
            else {
                int option1 = (i+1>=n)? 0 : dp[i+1][j];
                int option2 = (j+1>=n)? 0 : dp[i][j+1];
                dp[i][j] = (option1+option2)%MOD;
            }
            if(g[i][j]=='*') dp[i][j]=0;
        }
    }
    cout<<dp[0][0]<<'\n';
}

int main() {
    IOS;
    int T = 1;
    //cin >> T;
    rep(i, 1, T + 1) {
        int n;
        cin>>n;
        vector<vector<char>> grid(n);
        rep(i,0,n){
            grid[i] = vector<char>(n);
            rep(j,0,n){
                cin>>grid[i][j];
            }
        }

        method1(n,grid);
        //method2(n,grid);
    }
    return 0;
}
