#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vs vector<set<long long>>
#define umli unordered_map<long long , int>
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define foo(i, v, n) for (ll i = v; i < n; i++)
#define foo3(k, m, o) for (ll k = m - 1; k >=o; k--)
#define ll long long
#define pb push_back
const long long MOD = 998244353;
const ll N = 2e5 + 5;

vvl jump[N+1];

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

vector<ll> sieve(ll n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){
            res.push_back(p);
        }
    }
    return res;
}

void takeArray(vll &arr,ll n){
    foo(i,0,n){
        cin>>arr[i];
    }
}

void printArray(vll &arr,ll n){
    foo(i,0,n){
        if(i < n-1)cout<<arr[i]<<" ";
        else cout<<arr[i]<<endl;
    }
}

ll binex(ll a , ll b , ll mod){
	a %= mod;

	ll result = 1;
	b = b % (MOD-1);
	while(b > 0)
	{
		if(b%2 == 1)
			result = (result%mod * a%mod)%mod ;
		a = (a%mod*a%mod)%mod;
		b = b/2;
	}
	return result;
}


ll modinv(ll a, ll p){
	return (binex(a , p-2 , p) );
}

long long modMultiply(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

ll DP(ll i,vll &dp,ll m){
    if(i > m)return 1;
    if(dp[i]!=-1)return dp[i];
    ll value = 0;
    for(auto next: jump[i]){
        ll r = next[0];
        ll p = next[1];
        ll q = next[2];
        ll val = 1;
        val*=modinv(q-p,MOD);
        val%=MOD;
        val*=p;
        val%=MOD;
        value = ((value%MOD)+(modMultiply(val,DP(r+1,dp,m),MOD))%MOD);
    }
    dp[i]=value;
    return value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll dp(m+1,-1);
    ll ans = 1;
    foo(i,0,n){
        ll l,r,p,q;
        cin>>l>>r>>p>>q;
        jump[l].push_back({r,p,q});
        ans *= (q-p);
        ans%=MOD;
        ans*=modinv(q,MOD);
        ans%=MOD;
    }
    cout<<(modMultiply(ans,DP(1,dp,m),MOD))%MOD<<"\n";
}