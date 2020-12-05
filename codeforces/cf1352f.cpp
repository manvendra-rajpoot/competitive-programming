/*Problem Link - https://codeforces.com/contest/1352/problem/F*/
#include<bits/stdc++.h>
using namespace std;
typedef  long long                 ll;
typedef  unsigned long long       llu;
typedef  long double              ldo;
typedef  vector <ll>              vll;
typedef  vector <string>          vss;
typedef  vector <pair <ll,ll>>   vpll; 
typedef  vector <vector <ll>>    vvll;
typedef  set <ll>                 sll;
typedef  set <string>             sss;
typedef  unordered_map <ll,ll>   umll;//insert,find,erase in O(1) 
typedef  map <ll,ll>              mll;//insert,find,erase in O(logN)
typedef  map <string,ll>         msll;
typedef  map <char,ll>           mcll;
typedef  map <ll,string>         mlls;
typedef  priority_queue<ll>      pqll;
const    ll  mod       =   1000000007;
const    ldo pi        =  2*asin(1.0); //3.14159 
const    int INF       =   0x3f3f3f3f; //1061109567
const    ll  LL_INF    = 0x3f3f3f3f3f3f3f3f;       //4557430888798830399
const    ll  MAXN      = numeric_limits<ll>::max();//9223372036854775807
const    ll  MINN      =   -1*(1e9+1); //-1000000001
#define  endl          '\n'
#define  sz(c)         (ll)c.size()
#define  fr            first 
#define  sc            second
#define  pb            push_back
#define  mp            make_pair
#define  all(v)        (v).begin(),(v).end()
#define  rep(i,a,n)    for(ll i=a;i<n;i++)
#define  bs_a(arr,i,n,x) binary_search(arr+i,arr+n,x)/*return bool 1/0 */
#define  lb_a(arr,i,n,x) lower_bound(arr+i,arr+n,x)-arr/*return pointer of that 1st index*/
#define  up_a(arr,i,n,x) upper_bound(arr+i,arr+n,x)-arr/*return pointer of next index*/
#define  bs_v(vec,x)     binary_search(vec.begin(),vec.end(),x)
#define  lb_v(vec,x)     lower_bound(vec.begin(),vec.end(),x)-vec.begin()
#define  up_v(vec,x)     upper_bound(vec.begin(),vec.end(),x)-vec.begin()
#define  gcdll(x,y)    __gcd(x,y)
#define  lcmll(x,y)    (x*y)/gcdll(x,y)
#define  swapll(x,y)   swap(x,y)/*x & y can be vector,arr,numbers*/
#define  IOS           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
class Solution{
    public:
    
    void SolutionFunc(){
        ll a,b,c;cin>>a>>b>>c;
        string s="";
        if(a==0 && b==0){
            rep(i,0,c+1)s.pb('1');
        }
        else{
            rep(i,0,a+1)s.pb('0');
            ll x=b;
            if(x%2==0)x--;
            rep(i,0,x){
                if(i%2==0)s.pb('1');
                else s.pb('0');
            }
            rep(i,0,c)s.pb('1');
            if(b%2==0 && b>0)s.pb('0');
        }
        cout<<s<<'\n';
    }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
  IOS;

  Solution obj;
  ll T=1;
  cin>>T;
  rep(i,0,T){
    //cout<<"Case #"<<i+1<<": ";
    obj.SolutionFunc();
  }  
  return(0);
} 