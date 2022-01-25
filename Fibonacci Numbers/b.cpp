#include <bits/stdc++.h>
using namespace std;


#define ll long long int

ll Sum(ll n){
    ll a = 1;
    ll b = 1;
    ll Sum = 0;
    while (b<=n){
        if (b&1);
        else
            Sum+=b;
        tie(a,b) = make_tuple(b,a+b);
    }
    return Sum;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<Sum(n)<<"\n";
    }  
    return 0;
}
