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
        ll n,m,k;
        cin>>n>>m>>k;
        vector<string> mine(n);
        foo(i,0,n){
            cin>>mine[i];
        }
        vvl matrix(n,vll(m,0));
        foo(i,0,n){
            foo(j,0,m){
                if(mine[i][j]=='g')matrix[i][j]++;
            }
        }
        vvl psum(n,vll(m,0));
        foo(i,0,n){
            foo(j,0,m){
                psum[i][j] = matrix[i][j];
                if(i > 0)psum[i][j]+=psum[i-1][j];
                if(j > 0)psum[i][j]+=psum[i][j-1];
                if(i>0 && j>0)psum[i][j]-=psum[i-1][j-1];
            }
        }
        ll maxGold = psum[n-1][m-1];
        ll rem = maxGold;
        foo(i,0,n){
            foo(j,0,m){
                if(mine[i][j]=='.'){
                    ll a = min((i+k-1),n-1);
                    ll b = min((j+k-1),m-1);
                    ll c = (ll)fmax((i-k),-1);
                    ll d = (ll)fmax((j-k),-1);
                    ll temp=0;
                    temp+=psum[a][b];
                    if(c >= 0)temp-=psum[c][b];
                    if(d >= 0)temp-=psum[a][d];
                    if(c >=0 && d>=0)temp+=psum[c][d];
                    rem=(ll)fmin(rem,temp);
                }
            }
        }
        cout<<maxGold-rem<<endl;
    }
}