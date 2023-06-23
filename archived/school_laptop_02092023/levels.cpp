#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ                     int main()
#define ll                      long long
#define ii                           pair<int, int>
#define ld                      long double
#define fi                      first
#define se                      second
#define endl                    '\n'
#define pb                      push_back

#define OK                      cout << "ok\n";
#define all(a)                  a.begin(), a.end()
#define rall(a)                 a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int v, lv;
    string s, slv = "...", ans;
    cin >> v >> s;

    lv = 1;
    if(v <= 1600) lv = 3;
        else if(v <= 1900) lv = 2;

    for(auto it : s) slv[it - 49] = '*';

    switch(lv)
    {
        case 1: {
            if(slv[0] == '*') ans += "1\n";
            if(slv[1] == '*') ans += "2*\n";
            if(slv[2] == '*') ans += "3*\n";
            break;
        }

        case 2: {
            if(slv[0] == '*') ans += "1\n";
            if(slv[1] == '*') ans += "2\n";
            if(slv[2] == '*') ans += "3*\n";
            break;
        }

        case 3: {
            if(slv[0] == '*') ans += "1\n";
            if(slv[1] == '*') ans += "2\n";
            if(slv[2] == '*') ans += "3\n";
            break;
        }
    }

    cout << ans;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
