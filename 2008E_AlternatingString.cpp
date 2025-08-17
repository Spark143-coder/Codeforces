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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vll f1(26,0),f2(26,0);
        foo(i,0,n){
            if(i%2==0)f1[s[i]-97]++;
            else f2[s[i]-97]++;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        if(n%2==0){
            ll num1 = f1[25];
            ll num2 = f2[25];
            cout<<(n-num1-num2)<<endl;
        }
        else{
            if(n==1 || n==3){
                cout<<1<<endl;continue;
            }
            vvl oddPrefix(n);
            vvl evenPrefix(n);
            foo(i,0,26){
                oddPrefix[0].pb(0);
                evenPrefix[0].pb(0);
            }
            foo(i,0,n){
                if(i==0){
                    oddPrefix[i][s[i]-97]++;
                }
                else if(i%2==0){
                    oddPrefix[i]=oddPrefix[i-1];
                    oddPrefix[i][s[i]-97]++;
                    evenPrefix[i]=evenPrefix[i-1];
                }
                else{
                    evenPrefix[i]=evenPrefix[i-1];
                    evenPrefix[i][s[i]-97]++;
                    oddPrefix[i]=oddPrefix[i-1];
                }
            }
            vvl oddSuffix(n),evenSuffix(n);
            foo(i,0,26){
                oddSuffix[n-1].pb(0);
                evenSuffix[n-1].pb(0);
            }
            foo3(i,n,0){
                if(i==n-1){
                    oddSuffix[i][s[i]-97]++;
                }
                else if(i%2==0){
                    oddSuffix[i]=oddSuffix[i+1];
                    oddSuffix[i][s[i]-97]++;
                    evenSuffix[i]=evenSuffix[i+1];
                }
                else{
                    evenSuffix[i]=evenSuffix[i+1];
                    evenSuffix[i][s[i]-97]++;
                    oddSuffix[i]=oddSuffix[i+1];
                }
            }
            ll operations = longMax;
            foo(i,0,n){
                if(i==0){
                    ll num1=longMin,num2=longMin;
                    foo(j,0,26){
                        num1 = (ll)fmax(num1,oddSuffix[1][j]);
                        num2 = (ll)fmax(num2,evenSuffix[1][j]);
                    }
                    operations = (ll)fmin(n-1-num1-num2,operations);
                }
                else if(i==n-1){
                    ll num1=longMin,num2=longMin;
                    foo(j,0,26){
                        num1 = (ll)fmax(num1,oddPrefix[n-2][j]);
                        num2 = (ll)fmax(num2,evenPrefix[n-2][j]);
                    }
                    operations = (ll)fmin(n-1-num1-num2,operations);
                }
                else{
                    ll num1=longMin,num2=longMin;
                    foo(j,0,26){
                        ll temp1 = oddPrefix[i-1][j] + evenSuffix[i+1][j];
                        ll temp2 = evenPrefix[i-1][j] + oddSuffix[i+1][j];
                        num1 = (ll)fmax(num1,temp1);
                        num2 = (ll)fmax(num2,temp2);
                    }
                    operations = (ll)fmin(n-1-num1-num2,operations);
                }
            }
            cout<<operations+1<<endl;
        }
    }
}