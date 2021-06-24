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
- dp(i,x) = max number of page that I can buy from first i books using x amount of money 
- Ans = dp(n,x). 
- dp(i,x) = max( dp(i-1,x) + (pages[i]+dp(i,x-cost[i])) )
- dp(0,x) = 0, dp(i,0) = 0
- S(n) = O(n.x)
- T(n) = O(n.x)
*/

int find(int i, int x, const vector<int> &cost, const vector<int> &pages, int** dp) {
    if(dp[i][x]>-1) return dp[i][x];

    int opt1 = (i<=1)? 0 : find(i-1,x,cost,pages,dp);
    int opt2 = (cost[i]>x)? 0 : pages[i]+ ((i<=1)? 0 :find(i-1,x-cost[i],cost,pages,dp));
    dp[i][x] = max(opt1, opt2);
    return dp[i][x];
}

//top to bottom approach
void method1(int n, int x, const vector<int> &cost, const vector<int> &pages) {
    int** dp = new int*[n+1];
    rep(i,0,n){
        dp[i] = new int[x+1];
        rep(j,0,n){
            dp[i][j]=-1;
        }
    }   
    rep(i,0,x+1) dp[0][i] = 0;
    rep(i,0,n+1) dp[i][0] = 0;

    int ans = find(n,x,cost,pages,dp);

    rep(i,0,n+1)delete [] dp[i];
    delete [] dp;
    cout<<ans<<'\n';
}

//bottom to top approach
void method2(int n, int x, const vector<int> &cost, const vector<int> &pages) {
    int dp[n+1][x+1];
    for(int book=0;book<=n;++book){
        for(int amt=0;amt<=x;++amt){
            if(amt==0 || book==0) dp[book][amt]=0; //no money no book can be bought or if no book no pages
            else {
                int opt1 = (book<=1)? 0 : dp[book-1][amt];
                int opt2 = (cost[book]>amt)? 0 : pages[book]+dp[book-1][amt-cost[book]];
                dp[book][amt] = max(opt1, opt2);
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
        int n, x;
        cin>>n>>x;
        vector<int> cost(n+1), pages(n+1);
        rep(i,1,n+1) cin>>cost[i];
        rep(i,1,n+1) cin>>pages[i];
        
        method2(n, x, cost, pages);
        //method1(n, x, cost, pages);
    }
    return 0;
}
