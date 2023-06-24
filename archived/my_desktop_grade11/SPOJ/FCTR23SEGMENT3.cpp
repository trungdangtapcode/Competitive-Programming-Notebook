#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> getUsefulSegments(vector<pii> &seg) {
    int n = seg.size();

    sort(seg.begin(), seg.end());

    vector<pii> useful;
    useful.push_back(seg[0]);

    for(int i = 1; i < n; ++i)
        if (seg[i].second > useful.back().second)
            useful.push_back(seg[i]);
	
	n = useful.size();
	//for(int u = 0; u < n; ++u) cout <<" {" << useful[u].first << "," << useful[u].second << "} "; cout << endl;
//	int j = 0;
//	for(int i = 0; i < n; ++i) {
//        while (j < n && useful[j].first <= useful[i].second+1)
//            useful[i+1] = useful[j], ++j;    
//	}
	vector <pii> useful1;
	vector <long long int> aR;
	for (int i = 0; i < n; ++i) aR.push_back(useful[i].second);
	
	for (int i = 0; i < n; ++i){
		int BS = lower_bound(aR.begin(),aR.end(),useful[i].first)-aR.begin();
		while (useful1.size()>BS+1){
			//cout << i << " " << BS << endl;
			useful1.pop_back();
		}
		useful1.push_back(useful[i]);
	}
	
    return useful1;
}

vector<int> getJumpTable(vector<pii> &seg) {
    int n = seg.size();

    vector<int> f(n);
    int j = 0;

    for(int i = 0; i < n; ++i) {
        while (j < n && seg[j].first <= seg[i].second+1)
            ++j;
        f[i] = j-1;
    }

    return f;
}

int getFirstSegmentIndex(vector<pii> &seg, int x) {
    int n = seg.size();

    int lo = 0, hi = n-1, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (seg[mid].first <= x) {
            res = mid;
            lo = mid+1;
        } else
            hi = mid-1;
    }

    return res;
}

int Solve(vector<pii> &seg, vector<vector<int> > &nxt, int a, int b) {
    int k = nxt.size()-1, n = nxt[0].size();

    int ind = getFirstSegmentIndex(seg, a);
    if (ind == -1)
        return ind;
    if (seg[ind].second >= b)
        return 1;

    int ans = 1;
    for(int i = k; i >= 0; --i) {
        int nxtInd = nxt[i][ind];
        if (seg[nxtInd].second < b) {
            ind = nxtInd;
            ans += 1<<i;
        }
    }

    for(int i = 0; i < k; ++i) {
        int nxtInd = nxt[i][ind];
        if (seg[nxtInd].second >= b)
            return ans + 1<<i;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pii> seg(n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &seg[i].first, &seg[i].second);

    seg = getUsefulSegments(seg);
    n = seg.size();

    int k = log2(n);
    vector<vector<int> > nxt(k+1, vector<int>(n, -1));

    nxt[0] = getJumpTable(seg);
    for(int i = 1; i <= k; ++i)
        for(int u = 0; u < n; ++u)
            nxt[i][u] = nxt[i-1][nxt[i-1][u]];

	
	//for(int u = 0; u < n; ++u) cout <<" {" << seg[u].first << "," << seg[u].second << "} "; cout << endl;
//	for(int i = 0; i <= k; ++i){
//        for(int u = 0; u < n; ++u) cout << nxt[i][u] << " ";
//		cout << endl;
//	}
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", Solve(seg, nxt, a, b));
    }

    return 0;
}
