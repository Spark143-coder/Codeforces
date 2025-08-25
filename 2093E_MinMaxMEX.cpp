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
        vll arr(n);
        takeArray(arr,n);
        vll freq(n,0);
        foo(i,0,n){
            if(arr[i]<n)freq[arr[i]]++;
        }
        set<ll> possible;
        foo(i,0,n){
            if(freq[i] >= k)possible.insert(i);
            else break;
        }
        if(possible.empty()){
            cout<<0<<"\n";continue;
        }
        ll s = 0,e=possible.size()-1,ans=0;
        while(s <= e){
            ll m = (s+e)/2;
            set<ll> found;
            ll num = 0;
            foo(i,0,n){
                if(arr[i]<=m)found.insert(arr[i]);
                if(found.size() == m+1){
                    num++;
                    found.clear();
                }
            }
            if(num >= k){
                ans=m;
                s = m+1;
            }
            else e = m-1;
        }
        cout<<ans+1<<"\n";
    }
}