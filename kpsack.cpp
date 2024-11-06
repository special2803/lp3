#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define pb              push_back
#define mp              make_pair
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define sz(x)           int((x).size())
#define trav(a, x)      for (auto &a : x)
#define testcase()      int t; cin >> t; while (t--)
#define yes             cout << "YES" << '\n'
#define no              cout << "NO" << '\n'
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define repin(i,a,b)    for(int i=a;i>b;i--)
#define int             long long



// Typedefs for common types
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;

// Maths
ll fact(ll n)          { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll nPr(ll n, ll r)     { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r)     { return fact(n) / (fact(r) * fact(n - r)); }
ll gcd(ll a, ll b)     { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b)     { return (a * b) / gcd(a, b);}
ll mypow(ll a, ll b)   { ll ans = 1; while(b){ if (b&1) ans = (ans*a) ; b /= 2; a = (a*a); } return ans; }
bool isPrime(ll n)     { if(n <= 1) return false; for(ll i = 2; i <= sqrt(n); i++) if(n % i == 0) return false; return true; }


// Input and output functions
template <class T> void re(T &x) { cin >> x; }
template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }

template <class T> void pr(const T &x) { cout << x << " "; }
template <class T> void ps(const T &x) { pr(x); cout << '\n'; }

int helper(int ind, vi &wt, vi &profit, int w, vvi& dp){
    if(ind <0 || w == 0) return 0;
    if(dp[ind][w] !=-1) return dp[ind][w];

    int nottake = helper(ind - 1, wt, profit, w,dp);
    int take = (wt[ind] > w) ? 0 : profit[ind] + helper(ind - 1, wt, profit, w - wt[ind], dp);
    
    return dp[ind][w] = max(take, nottake);

}
void solve(){
    //code goes here 
    int n = 0;
    int profit[] = {1,2,3};
    int weight[] = {1,2,3};
    int W = 0;
    // int W = 8;
    // cout << helper(n - 1, wt, pro)
    vvi dp(n, vi(W + 1, -1));

    vector<int> wt(weight , weight + n);
    vector<int> proft(profit, profit + n);
    // cout << helper(n - 1, wt, proft, W, dp) << endl;

    vvi k(n + 1, vi(W+1));

        for(int i = 0 ; i < n; i ++){
            for(int w = 0; w <= W; w++){
                k[i+1][w] = (wt[i] > w) ? k[i][w] : max(k[i][w], proft[i] + k[i][w - wt[i]]);
            }
        }
    cout << k[n][W]<<endl;



    // for(const auto & row : dp){
    //     for(const auto& item : row){
    //         cout << item << " ";
    //     }
    //     cout << endl;qwertyuiopasdfghjklzxv
    // }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    //  testcase() 
        solve();

    return 0;
}
