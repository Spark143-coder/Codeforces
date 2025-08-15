#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
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
    cin>>testcases;
    while (testcases--)
    {
        string  a,b;
        cin>>a;
        cin>>b;
        ll positions=0;
        foo(i,0,a.size()){
            if(a[i]==b[i])positions+=2;
            else {
                if(a[i]==b[i]-1 || (a[i]=='9' && b[i]=='0')){
                    positions++;
                    if(i<a.size()-1 && (a[i+1]!='9' || b[i+1]!='0'))break;
                }
                else break;
            }
        }
        cout<<positions<<endl;
    }
}