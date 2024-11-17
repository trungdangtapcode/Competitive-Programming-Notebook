#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 666666 + 10;
const int mod = 998244353;

int n, q, a[N];

int prv[N];
int cnt[2*N];
typedef pair<int,int> ii;
ii add(ii a, ii b){
    int x = a.second+b.second;
    if (x>=mod) x-= mod;
    if (a.first==b.first) return {a.first,x};
    return max(a,b);
}
ii sub(ii a, ii b){
    assert(a.first>=b.first);
    int x = a.second-b.second;
    if (x<0) x += mod;
    if (a.first==b.first) return {a.first,x};
    return a;
}
ii f[N];

void solve(){
    vector<int> comp;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        comp.push_back(a[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int i=1;i<=n;i++){
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
    }
    for (int i = 1; i <= n; i++) cnt[a[i]] =0;

    for(int l=1,i=1;i<=n;i++){
        cnt[a[i]]++;
        while(cnt[a[i]] == 2){
            cnt[a[l]]--;
            ++l;
        }
        prv[i] = l;
    }

    while (q--){
        int k;
        cin >> k;
        f[0] = {0,1};
        ii current = {0,0};
        int ll = 1, rr = 0;
        for (int i = 1; i <= n; i++){
            int l = prv[i], r = i-k+1;
            //cout << i << " " << l << " " << r << "\n";
            if (l<=r){
                while (rr<r){
                    rr++;
                    current = add(current,f[rr-1]);
                }
                while (ll<l){
                    current = sub(current,f[ll-1]);
                    ll++;
                }
            }
            f[i] = f[i-1];
            if (l<=r) f[i] = add(f[i],{current.first+1,current.second});
        }
        cout << f[n].first << " " << f[n].second << "\n";
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void solve(){
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

