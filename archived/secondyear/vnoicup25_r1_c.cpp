#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> shares(n + 1, 0);         // Current shares for each shareholder
    vector<ll> last_total_v(n + 1, 0);   // Cumulative v at last update/withdrawal
    vector<ll> balance(n + 1, 0);        // Current balance
    ll total_v = 0;                      // Cumulative sum of v from type 2 events
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int p;
            ll x;
            cin >> p >> x;
            // Update balance with shares * (v accumulated since last update)
            ll delta = ((total_v - last_total_v[p] + MOD) % MOD) * (shares[p] % MOD) % MOD;
            balance[p] = (balance[p] + delta) % MOD;
            // Update shares
            shares[p] += x;
            // Record current total_v
            last_total_v[p] = total_v;
        } 
        else if (type == 2) {
            ll v;
            cin >> v;
            total_v = (total_v + v) % MOD;
        } 
        else if (type == 3) {
            int p;
            cin >> p;
            // Update balance before withdrawal
            ll delta = ((total_v - last_total_v[p] + MOD) % MOD) * (shares[p] % MOD) % MOD;
            balance[p] = (balance[p] + delta) % MOD;
            // Output withdrawn amount
            cout << balance[p] << endl;
            // Reset balance
            balance[p] = 0;
            // Update last_total_v to current total_v
            last_total_v[p] = total_v;
        }
    }
    
    return 0;
}
