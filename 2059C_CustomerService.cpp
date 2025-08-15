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
        ll n;
        cin>>n;
        vvl matrix(n,vll(n));
        foo(i,0,n)foo(j,0,n)cin>>matrix[i][j];
        vll num(n,0);
        foo(i,0,n){
            foo3(j,n,0){
                if(matrix[i][j]!=1)break;
                else num[i]++;
            }
        }
        sort(num.begin(),num.end());
        ll ans=1;
        ll mini=1;
        foo(i,1,n){
            if(num[i] >= mini){
                mini++;ans++;
            }
        }
        cout<<ans<<endl;
    }
}