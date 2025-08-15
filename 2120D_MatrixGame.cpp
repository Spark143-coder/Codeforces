#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define umli unordered_map<long long , int>
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define foo(i, v, n) for (ll i = v; i < n; i++)
#define foo3(k, m, o) for (ll k = m - 1; k >=o; k--)
#define ll long long
#define pb push_back
const long long MOD = 1e9 + 7;
const ll N = 1e9 + 5;
    
bool isPowerOfTwo(ll n) { return n > 0 && (n & (n - 1)) == 0; }
bool isPrime(long long n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
    
ll modpower(ll a ,ll b){
    ll r=1;
    a %=MOD;
    while(b > 0){
        if(b & 1)r = (r * a) % MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return r;
}
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll rows = ((((a-1)%MOD)*(k))%MOD + 1)%MOD;
        ll cols=1;
        foo(i,0,a){
            cols*= (rows-i)%MOD;
            cols%=MOD;
            cols=(cols*(modpower((a-i),MOD-2))%MOD)%MOD;
        }
        cols = (cols *(b-1))%MOD;
        cols = (cols * k) %MOD;
        cols = (cols + 1)%MOD;
        cols%=MOD;
        cout<<rows<<" "<<cols<<endl;
    }
}