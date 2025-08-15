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
    cin >>testcases;
    while(testcases--){
        ll n,k;
        cin>>n>>k;
        vll arr(n,0);
        double check = log2((double)k);
        if(check > n-1){
            cout<<-1<<endl;
        }
        else {
            k--;
            string s;
            foo(i,0,n-1){
                s+="0";
            }
            foo(i,0,n-1){
                if(k%2==1){
                    s[n-2-i]='1';
                }
                k = k/2;
            }
            ll num = 1;
            ll start = 0;
            ll end = n-1;
            foo(i,0,n-1){
                if(s[i]=='1'){
                    arr[end]=num;
                    num++;
                    end--;
                }
                else {
                    arr[start]=num;
                    num++;
                    start++;
                }
            }
            if(start==end)arr[start]=num;
            foo(i,0,n){
                if(i==n-1)cout<<arr[i]<<endl;
                else cout<<arr[i]<<" ";
            }
        }
    }
}