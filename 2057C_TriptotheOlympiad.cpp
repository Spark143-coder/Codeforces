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

string decToBinary(int n) {
    string bin = "";
    while (n > 0) {
        // checking the mod
        int bit = n%2;
        bin.push_back('0' + bit);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    while(testcases--){
        ll l,r;
        cin>>l>>r;
        if(r-l==2){
            cout<<l<<" "<<l+1<<" "<<r<<endl;
        }
        else{
            string s = decToBinary(l);
            string p = decToBinary(r);
            if(s.length()==p.length()){
                ll index = -1;
                ll sum = 0;
                foo(i,0,s.length()){
                    if(s[i]!=p[i]){index=i;break;}
                    if(s[i]=='1')sum+=(pow(2,s.length()-1-i));
                }
                ll a = sum + (ll)pow(2,s.length()-1-index);
                ll b = sum + (ll)(pow(2,s.length()-1-index)-1);
                ll c;
                if(a < r){
                    c = a+1;
                }
                else c = b-1;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
            else {
                ll a = (ll)pow(2,p.length()-1);
                ll b = a-1;
                ll c;
                if(a < r){
                    c = a+1;
                }
                else c = b-1;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }
}