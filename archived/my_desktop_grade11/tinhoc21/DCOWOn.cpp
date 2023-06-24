#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,a[200000],b[1005];
    cin>>n;
    for (ll i=1;i<=1000;i++)
        b[i] = 0; 
    
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    
    ll s=0;
    for (ll i=1;i<=1000;i++)
        s+=b[i]*(b[i]-1)/2;
    cout<<s;
    return 0;
}
