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
const ll longMax = 9223372036854775807;
const ll longMin = -9223372036854775807;
    
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
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    while(testcases--){
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<0<<endl;continue;
        }
        vector<set<ll>> adj(n+1);
        foo(i,0,n-1){
            ll a,b;
            cin>>a>>b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        queue<ll> leaf;
        foo(i,1,n+1){
            if(adj[i].size()==1){
                leaf.push(i);
            }
        }
        vll vis(n+1,0);
        foo(i,0,k){
            ll size = leaf.size();
            if(size <=0)break;
            foo(j,0,size){
                ll u = leaf.front();
                ll v = *adj[u].begin();
                adj[v].erase(u);
                adj[u].erase(v);
                vis[u]=1;
                if(adj[v].size() == 1){
                    leaf.push(v);
                }
                leaf.pop();
            }
        }
        ll count=0;
        foo(i,1,n+1){
            if(!vis[i])count++;
        }
        cout<<count<<endl;
    }
}