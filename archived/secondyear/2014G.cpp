#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxN = 2e5+5;
int n, m, k, a[maxN], d[maxN];
int ntest =0;
void solve(){
	ntest++;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> d[i] >> a[i];
	}
	int res = 0;
	deque<iii> dq; 
	//first avaiable future day not filled in a segment
	//day, {amount left, count of next consecutive zero filled}
	for (int i = n; i >= 1; i--){
		int r = d[i]+k-1;
		while (dq.size()&&dq.front().first>r) dq.pop_front();
		int cnt = (i==n?1e9:d[i+1]-d[i]-1);
		dq.push_back({d[i],{m,cnt}});
		int cur = a[i];
		while (cur&&dq.size()){
			int d = dq.back().first;
			int amount = dq.back().second.first;
			int cnt = dq.back().second.second;
			dq.pop_back();
			cnt = min(cnt,r-d);
//			cout << i << ". cur = " << cur
//				<< " cnt = " << cnt
//				<< " amount = " << amount
//				<< " d = " << d << "\n"; 
			if (amount<=cur){
				cur -= amount;
				int nxt = min(cnt,cur/m);
				cnt -= nxt;
				cur -= nxt*m;
				res += 1+nxt;
//				cout << " + " << 1+nxt << '\n';
				if (cnt){
					dq.push_back({d+nxt+1,{m-cur,cnt-1}});
					cur = 0;
					break;
				} 
			} else {
				dq.push_back({d,{amount-cur,cnt}});
				cur = 0;
				break;	
			}
		}		
	}
	cout << res << "\n";
//	exit(0);
}
//solution 2 => divide based on event
//a segment same avaiable milk (stored in deque) will be
//easily calculated in amortized O(n)

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

