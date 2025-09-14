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
const long long MOD = 1e9 + 7;
const ll N = 1e6 + 5;
const ll longMax = 9223372036854775807;

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

void takeArray(vll &arr,ll n){
    foo(i,0,n){
        cin>>arr[i];
    }
}

void printArray(vll &arr,ll n){
    foo(i,0,n){
        if(i < n-1)cout<<arr[i]<<" ";
        else cout<<arr[i]<<"\n";
    }
}

vector<ll> sieve(int n) {
    vector<bool> prime(n + 1, true);
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> res;
    for (ll p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

ll modpow(ll a ,ll b ) {
    ll res = 1 ;
    a %= MOD;
    while ( b > 0 ) {
    if ( b & 1 ) res = ( res * a ) % MOD;
    a = ( a * a ) % MOD;
    b >>= 1 ;
    }
    return res ;
}

ll modinv(ll q){
    return modpow(q,MOD-2);
}

long long modMultiply(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

void func(vll &arr, vll &result){
    ll n = arr.size();
    stack<ll> temp;
    foo(i,0,n){
        while(!temp.empty() && arr[i] > arr[temp.top()]){
            temp.pop();
        }
        if(!temp.empty()){
            result[i]=temp.top();
        }
        temp.push(i);
    }
    return;
}

void fun(vll &a, vll &b,vll &result){
    ll n = a.size();
    if(b.size()!=a.size())return;
    vll indices;
    foo(i,0,n){
        ll position = -1;
        ll low = 0,high = indices.size()-1;
        while(low<=high){
            ll mid = (low+high)/2;
            if(a[indices[mid]] >= b[i]){
                position = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        if(position!=-1)result[i]=indices[position];
        while(!indices.empty() && a[indices.back()] <= a[i])indices.pop_back();
        indices.pb(i);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    while(testcases--){
        ll n;
        cin>>n;
        vll a(n),b(n);
        takeArray(a,n);
        takeArray(b,n);
        ll sum = 0;
        vll result(n,-1);
        func(a,result);
        vll result2(n,-1);
        fun(a,b,result2);
        foo(i,0,n){
            if(a[i]==b[i]){
                sum+=(i+1)*(n-i);
            }
            else{
                sum+=(min(result[i]+1,result2[i]+1)*(n-i));
            }
        }
        cout<<sum<<endl;
    }
}