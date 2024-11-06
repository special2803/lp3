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


int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n - 2);

}
void solve(){
    //code goes here 
    int n; cin >> n;
    // int temp; cin >> temp;
    for(int i = 0 ; i <= n ; i ++)
    cout << fib(i) << " ";
    cout <<endl;
    int a = 0;
    int b = 1;
    cout << a << " "<< b << " ";
    for(int i = 2 ; i <=n ; i ++){
        // cout << a+b << " ";
        int c = a + b;

        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    //  testcase() 
        solve();

    return 0;
}
