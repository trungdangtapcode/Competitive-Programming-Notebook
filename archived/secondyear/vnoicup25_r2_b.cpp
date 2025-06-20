#include<bits/stdc++.h>

using namespace std;


int n, m, target_i, target_j;
vector<vector<char>> conveyor() {
	// greedy: 
	// interior cells point directly toward the target cell to guide movement inward
	// Adjacent cells around the target are adjusted to point directly into it
	// ensuring every object can eventually reach the target
    int ti = target_i - 1;
    int tj = target_j - 1;

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (r == ti && c == tj) continue;

            bool on_border = (r == 0 || r == n - 1 || c == 0 || c == m - 1);
            if (on_border) {
                if (r == 0) {
                    grid[r][c] = (c < m - 1) ? '>' : 'v';
                } else if (c == m - 1) {
                    grid[r][c] = (r < n - 1) ? 'v' : '<';
                } else if (r == n - 1) {
                    grid[r][c] = (c > 0) ? '<' : '^';
                } else { // c = 0
                    grid[r][c] = (r > 0) ? '^' : '>';
                }
            } else {
                if (r < ti)
                    grid[r][c] = 'v';
                else if (r > ti)
                    grid[r][c] = '^';
                else if (c < tj)
                    grid[r][c] = '>';
                else
                    grid[r][c] = '<';
            }
        }
    }

	bool on_border = (ti == 0 || ti == n - 1 || tj == 0 || tj == m - 1);
	if (!on_border){
		grid[0][1] = 'v';
	}
	
//    if (ti > 0)
//        grid[ti - 1][tj] = 'v';
//    if (ti < n - 1)
//        grid[ti + 1][tj] = '^';
//    if (tj > 0)
//        grid[ti][tj - 1] = '>';
//    if (tj < m - 1)
//        grid[ti][tj + 1] = '<';

    return grid;
}

void solve() {
    cin >> n >> m >> target_i >> target_j;
    vector<vector<char>> result = conveyor();
    
    for (const auto& row : result) {
        for (char c : row) cout << c;
        cout << '\n';
    }
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

