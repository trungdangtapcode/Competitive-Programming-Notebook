#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    int q;
    cin >> q;
    for (int game = 0; game < q; game++) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> prefix_u(n + 1, 0);
        vector<int> prefix_i(n + 1, 0);
        bool found = false;
        for (int i = 1; i <= n; i++) {
            prefix_u[i] = prefix_u[i - 1] + (s[i - 1] == 'U' ? 1 : 0);
            prefix_i[i] = prefix_i[i - 1] + (s[i - 1] == 'I' ? 1 : 0);
            if ((prefix_i[i] >= 1 && prefix_u[i] >= 2 * prefix_i[i]) || 
                (prefix_u[i] >= 1 && prefix_i[i] >= 2 * prefix_u[i])) {
                cout << "YES" << endl;
                cout << 1 << " " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
