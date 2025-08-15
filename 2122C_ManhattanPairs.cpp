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
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        priority_queue<pair<ll,ll>> x;
        priority_queue<pair<ll,ll>> y;
        foo(i,0,n){
            ll a,b;
            cin>>a>>b;
            x.push({a,i+1});
            y.push({b,i+1});
        }
        map<ll,ll> Xl,Xr,Yl,Yr;
        foo(i,0,n){
            if(i<(n/2)){
                Xr[x.top().second]=x.top().first;
                Yr[y.top().second]=y.top().first;
            }
            else{
                Xl[x.top().second]=x.top().first;
                Yl[y.top().second]=y.top().first;
            }
            x.pop();
            y.pop();
        }
        vector<ll> A,B,C,D;
        for(auto it = Xl.begin(); it!=Xl.end();++it){
            if(Yl.find(it->first)!=Yl.end()){
                A.pb(it->first);
            }
            else{
                B.pb(it->first);
            }
        }
        for(auto it=Xr.begin();it!=Xr.end();++it){
            if(Yl.find(it->first)!=Yl.end()){
                C.pb(it->first);
            }
            else{
                D.pb(it->first);
            }
        }
        foo(i,0,A.size()){
            cout<<A[i]<<" "<<D[i]<<endl;
        }
        foo(i,0,B.size()){
            cout<<B[i]<<" "<<C[i]<<endl;
        }
    }
}