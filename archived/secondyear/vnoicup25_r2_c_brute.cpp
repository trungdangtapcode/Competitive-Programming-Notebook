#include<bits/stdc++.h>
using namespace std;

//brute force
void solve() {
	string s;
	cin >> s;
    queue<string> q;
    unordered_set<string> visited;
    
    q.push(s);
    visited.insert(s);
    
    int minLen = s.length();
    
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        
        minLen = min(minLen, (int)curr.length());
        
        // Try ptp -> ap
        for (int i = 0; i <= (int)curr.length() - 3; i++) {
            if (curr.substr(i, 3) == "ptp") {
                string next = curr.substr(0, i) + "ap" + curr.substr(i + 3);
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        
        // Try ap -> ptp
        if (curr.length() <= s.length() + 5) {
            for (int i = 0; i <= (int)curr.length() - 2; i++) {
                if (curr.substr(i, 2) == "ap") {
                    string next = curr.substr(0, i) + "ptp" + curr.substr(i + 2);
                    if (visited.find(next) == visited.end() && next.length() <= s.length() + 10) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
    }
    cout <<  minLen << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    int t;
    cin >> t;
    while (t--)
    solve();
    
    return 0;
}

