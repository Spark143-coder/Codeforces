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
const ll N = 1e5 + 5;
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
    
int main(){
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        takeArray(arr,n);
        foo(i,0,n){
            if(arr[i]<=k)arr[i]=1;
            else arr[i]=-1;
        }
        vll p(n),s(n);
        p[0]=arr[0];
        s[n-1]=arr[n-1];
        foo(i,1,n){
            p[i]=p[i-1]+arr[i];
            s[n-1-i]=s[n-i]+arr[n-1-i];
        }
        ll right = n;
        foo(i,0,n-2){
            if(p[i] >=0){
                right=i;break;
            }
        }
        ll left = -1;
        foo3(i,n,2){
            if(s[i] >=0){
                left=i;
                break;
            }
        }
        bool yes=false;
        if(right + 1 < left)yes=true;
        vll pos;
        foo(i,0,n-1){
            if(p[i] >= 0)pos.pb(p[i]);
        }
        if(pos.size() >=3)yes=true;
        else if(pos.size()==2 && !(pos[0]==1 && pos[1]==0))yes=true;
        pos.clear();
        foo3(i,n,1){
            if(s[i] >= 0)pos.pb(s[i]);
        }
        if(pos.size() >= 3)yes=true;
        else if(pos.size()==2 && !(pos[0]==1 && pos[1]==0))yes=true;
        if(yes)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}