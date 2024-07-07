#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 1e5+5;
const int T = sqrt(maxN);
int n, m, a, b, c, x[maxN], pref[maxN], suff[maxN], prefx[maxN], suffx[maxN];
vector<int> edge[maxN];
void solve(){
	cin >> n >> m >> a >> b >> c;
	for (int i = 1; i <= n; i++) cin >> x[i];
	vector<ii> el;
	set<ii> es(el.begin(),el.end());
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		if (u>v) swap(u,v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		el.push_back({u,v});
		if (es.count({u,v})) continue;
		es.insert({u,v});
		pref[v]++;
		suff[u]++;
	} 
	for (int i = 2; i <= n; i++) pref[i] += pref[i-1];
	for (int i = n-1; i >= 1; i--) suff[i] += suff[i+1];
	for (int i = 1; i <= n; i++){
		sort(edge[i].begin(),edge[i].end());
	}
	long long sum3 = 0;
	for (auto it: el){
		int u = it.first, v = it.second;
		if (edge[u].size()<edge[v].size()) swap(u,v);
		for (int t: edge[v]){
			int ut1 = u, ut2 = t;
			if (ut1>ut2) swap(ut1,ut2);
			if (es.count({ut1,ut2})){
				int x1 = u, x2 = v, x3 = t;
				if (x1>x2) swap(x1,x2);
				if (x2>x3) swap(x2,x3);
				if (x1>x2) swap(x1,x2);
				sum3 += x[x1]*a + x[x2]*b + x[x3]*c;
//				cout << arr[0] << " " << arr[1] << " " << arr[2] << " = " << x[arr[0]]*a + x[arr[1]]*b + x[arr[2]]*c<< "\n";
			}
		}
	}
//	cout << sum3 << " = sum3\n";
	sum3 /= 3;
	
	long long sum2 = 0;
	for (int i = 1; i <= n; i++){
		vector<int> v1, v2;
		for (int x: edge[i]){
			if (x>i) v2.push_back(x);
			else v1.push_back(x);
		}	
		
		long long sumtmp = (v1.size()?x[v1[0]]:0);
		for (int j = 1; j < v1.size(); j++){
			int u = v1[j];
			sum2 += 1ll*sumtmp*a + x[u]*j*b + x[i]*j*c;
			sumtmp += x[u];
		}
		
		sumtmp = (v2.size()?x[v2[0]]:0);
		for (int j = 1; j < v2.size(); j++){
			int u = v2[j];
			sum2 += x[i]*j*a + 1ll*sumtmp*b + x[u]*j*c;
			sumtmp += x[u];
		}
		
		for (int u: v1) sum2 += 1ll*x[u]*v2.size()*a;
		for (int u: v2) sum2 += 1ll*x[u]*v1.size()*c;
		sum2 += 1ll*x[i]*v1.size()*v2.size()*b;
	}
	sum2 -= sum3*3;
//	cout << sum2 << " two\n";
	
	long long sum1 = 0;
//	for (int i = 1; i <= n; i++){
//		sum1b += (m-pref[i]-suff[i]); //1ll*(m-pref[i]-suff[i])*x[i];
//	}
	for (int i = 1; i <= n; i++) prefx[i] = prefx[i-1]+x[i];
	for (auto it: el){
		int u = it.first, v = it.second;
		sum1 += 1ll*prefx[u-1]*a+1ll*x[u]*(u-1)*b+1ll*x[v]*(u-1)*c;
		sum1 += 1ll*x[u]*(v-u-1)*a+1ll*(prefx[v-1]-prefx[u])*b+1ll*x[v]*(v-u-1)*c;
		sum1 += 1ll*x[u]*(n-v)*a+1ll*x[v]*(n-v)*b+1ll*(prefx[n]-prefx[v])*c;
//		for (int t = 1; t <= n; t++){
//			if ((es.count({t,u})||es.count({u,t}))) continue;
//			if ((es.count({t,v})||es.count({v,t}))) continue;
//			cout << u << " " << t << " " << v << "\n";
//		}
	}
	sum1 -= sum2*2 + sum3*3;
	
	long long sum0 = 0;
	for (int i = 2; i < n; i++){
		sum0 += 1ll*prefx[i-1]*(n-i)*a;
		sum0 += 1ll*(prefx[n]-prefx[i])*(i-1)*c;
		sum0 += 1ll*x[i]*(n-i)*(i-1)*b;
	}
	sum0 -= sum1 + sum2 + sum3;
//	cout << sum0 - sum1 - sum2 - sum3<< "\n";
	
//	sum1 -= 2*sum2 + 3*sum3;
//	cout << sum1 << "\n";
//	for (int i = 1; i <= n; i++){
//		for (int j = i+1; j <= n; j++){
//			for (int k = j+1; k <= n; k++){
//				int cnt = 0;
//				cnt += es.count({i,j})||es.count({j,i});
//				cnt += es.count({k,j})||es.count({j,k});
//				cnt += es.count({i,k})||es.count({k,i});
//				cout << cnt << "\n";
//			}
//		}
//	}
	cout << sum0 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}


