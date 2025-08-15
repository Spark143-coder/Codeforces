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
ll testcases;
cin >> testcases;
while(testcases--){
    ll n,m;
    cin>>n>>m;
    vll a(n),b(m);
    foo(i,0,n)cin>>a[i];
    foo(i,0,m)cin>>b[i];
    ll bIndex = 0;
    foo(i,0,n){
        if(bIndex < m && a[i] >= b[bIndex]){
            bIndex++;
        }
    }
    if(bIndex >= m){
        cout<<0<<endl;
    }
    else {
        vll p(m,INT32_MAX);
        bIndex = 0;
        foo(i,0,n){
            if(bIndex < m && a[i] >= b[bIndex]){
                p[bIndex]=i;bIndex++;
            }
        }
        vll s(m,INT32_MIN);
        bIndex = m-1;
        foo3(i,n,0){
            if(bIndex >= 0 && a[i] >= b[bIndex]){
                s[bIndex]=i;bIndex--;
            }
        }
        if(m == 1){
            cout<<b[0]<<endl;
        }
        else {
            ll ans = INT32_MAX;
            foo(i,0,m){
                if(i == 0){
                    if(i+1 < m && s[i+1] >= 0){
                        ans = (ll)fmin(ans,b[i]);
                    }
                }
                else if(i == m-1){
                    if(i-1 >= 0 && p[i-1] < n){
                        ans = (ll)fmin(ans,b[i]);
                    }
                }
                else {
                    if(p[i-1] < s[i+1]){
                        ans = (ll)fmin(ans,b[i]);
                    }
                }
            }
            if(ans == INT32_MAX){
                cout<<-1<<endl;
            }
            else {
                cout<<ans<<endl;
            }
        }
    }
    }
}