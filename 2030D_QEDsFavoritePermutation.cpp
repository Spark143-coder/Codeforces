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
        ll n,q;
        cin>>n>>q;
        vll arr(n);
        takeArray(arr,n);
        string s;
        cin>>s;
        ll maximum = INT32_MIN;
        vll maxArray(n);
        foo(i,0,n){
            maximum = (ll)fmax(maximum,arr[i]);
            maxArray[i]=maximum;
        }
        ll problems=0;
        foo(i,0,n-1){
            if(s[i]=='L' && s[i+1]=='R'){
                if(maxArray[i] > i+1){
                    problems++;
                }
            }
        }
        while(q--){
            ll index;
            cin>>index;
            index--;
            if(s[index]=='L'){
                if(index < n-1 && s[index+1]=='R' && maxArray[index] > index+1){
                    problems--;
                }
                if(index > 0 && s[index-1]=='L' && maxArray[index-1] > index){
                    problems++;
                }
            }
            if(s[index]=='R'){
                if(index > 0 && s[index-1]=='L' && maxArray[index-1] > index){
                    problems--;
                }
                if(index < n-1 && s[index+1]=='R' && maxArray[index] > index+1){
                    problems++;
                }
            }
            (s[index]=='L')?(s[index]='R'):(s[index]='L');
            if(problems > 0)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}