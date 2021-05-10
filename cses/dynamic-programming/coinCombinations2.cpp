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
- dp(i,j) = no.of valid ways of making sum==j using first ith coins.
- Ans = dp(n,x). 
- dp(i,j) = dp(i-1,j) + dp(i,j-c[i]); we exclude that coin with no effect on sum, we include that coin with reduced sum
- dp(i,0) = 1
- T(n) = O(n.X); X= (v1+v2+v3+...+vn)/n
- S(n) = O(n)
*/

int find(int i, int x, const vector<int>& c, int** dp) {    
    if(dp[i][x]>-1) return dp[i][x];

    int option1 = (i<=1)? 0 : ( (dp[i-1][x]>-1) ? dp[i-1][x] : find(i-1,x,c,dp) ); //excluding that coin 
    int option2 =  (c[i]>x)? 0 : ( (dp[i][x-c[i]]>-1) ? dp[i][x-c[i]] : find(i,x-c[i],c,dp) ); //including that coin 
    
    if(option1>0) dp[i-1][x] = option1; 
    if(option2>0) dp[i][x-c[i]] = option2;
    
    int ans = (option1 + option2)%MOD;
    dp[i][x] = ans;
    return ans;
}

//top to bottom approach
void method1(int n, int x, vector<int> c) {
    int** dp = new int*[n+1];
    rep(i,0,n+1) {
        dp[i] = new int[x+1];
        rep(j,0,x+1) {
            dp[i][j] = -1;
        }
    }
 
    //if sum==0, there is 1 way by selecting no coin
    rep(i,1,n+1){
        dp[i][0] = 1;
    }
    // no coins left
    rep(i,0,x+1){
        dp[0][i] = 0;
    }
    cout<<find(n,x,c,dp)<<'\n';
    rep(i,0,n) delete [] dp[i];
    delete [] dp;
}

//bottom to top approach
void method2(int n, int x, vector<int> c) {
    int dp[n+1][x+1];
    rep(i,1,n+1){
        for(int sum=0;sum<=x;++sum){
            if(sum==0) dp[i][sum]=1;
            else {
                int option1 = (i==1) ? 0 : dp[i-1][sum]; //excluding that coin & if one one coin is left we have to take it
                int option2 =  (c[i]>sum) ? 0 : dp[i][sum-c[i]]; //including that coin & checking if sum<=c[i]
                dp[i][sum] = (option1 + option2)%MOD;
            }
        }
    }
    cout<<dp[n][x]<<'\n';
}

int main() {
    IOS;
    int T = 1;
    //cin >> T;
    rep(i, 1, T + 1) {
        int n,x;
        cin>>n>>x;
        vector<int> c(n+1);
        rep(i,1,n+1) cin>>c[i]; 
        //method1(n,x,c);
        method2(n,x,c);
    }
    return 0;
}
