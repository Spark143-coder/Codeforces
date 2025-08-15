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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n,m,v;
        cin>>n>>m>>v;
        vll arr(n);
        takeArray(arr,n);
        vll prefixSum(n,0);
        foo(i,0,n){
            if(i > 0){
                prefixSum[i]=prefixSum[i-1]+arr[i];
            }
            else prefixSum[0]+=arr[i];
        }
        vll v1(m+1,n);
        v1[0]=-1;
        ll curr=0;
        ll index=1;
        foo(i,0,n){
            curr+=arr[i];
            if(curr >= v){
                v1[index]=i;
                index++;
                if(index > m)break;
                curr=0;
            }
        }
        vll v2(m+1,-1);
        v2[0]=n;
        index=1;curr=0;
        foo3(i,n,0){
            curr+=arr[i];
            if(curr >= v){
                v2[index]=i;
                index++;
                if(index > m)break;
                curr=0;
            }
        }
        ll ans = -1;
        foo(i,0,m+1){
            if(v1[i] < n && v2[m-i] >= 0){
                ll l = v1[i];
                ll r = v2[m-i];
                if(l < r){
                    if(l==r-1){
                        ans=(ll)fmax(0,ans);
                    }
                    else{
                        if(l >= 0 && r > 0)ans=(ll)fmax(ans,prefixSum[r-1]-prefixSum[l]);
                        else if(r==0) ans=(ll)fmax(ans,0);
                        else if(l==-1){
                            ans = (ll)fmax(ans,prefixSum[r-1]);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}