#include<bits/stdc++.h>

using namespace std;
const int N = 6e5+5;
int spf[N], resr[N], n, m, a[N], nxt[N], b[N];
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<ii> vec[N];
map<int,int> mp, mprime;
multiset<int> ms;


bool checkPrime(int p){
	for (int i = 2; i*i <= p; i++){
		if (p%i==0) return false;
	}
	return true;
}
int findNext(int x){
	return (nxt[x]==x?x:nxt[x]=findNext(nxt[x]));
}
bool hop(int u, int v){
//	assert();
	if (u>v) swap(u, v);
	u = findNext(u), v = findNext(v);
	if (u==v) return false;
//	cout << u << " " << v << "\n";
//	cout << "nxt[" << u << "] = " << v << "\n"; 
	nxt[u] = v;
	return true;
}
int largestPrime(int x){
	int c = sqrt(x)+1;
	assert(c<=N-5);
	for (int i = N-6; i >= 2; i--) if (spf[i]==i){
		if (x%i==0) return i;
	}
	assert(false);
	return -1;
}

void solve(){
	for (int i = 2; i <= N-5; i++) if (!spf[i]){
		for (int j = i; j <= N-5; j+=i) if (!spf[j]){
			spf[j] = i;
		}
	}
	for (int i = 1; i <= N-5; i++) nxt[i] = i, b[i] = 1e9;
	
	cin >> n >> m;
	int tmp = m;
	for (int j = 2; j*j <= tmp; j++){
		if (tmp%j==0){
			int cnt = 0;
			while (tmp%j==0) tmp /= j, cnt++;
//			cout << 0 << ": " << j << "^" << cnt << "\n";
			mprime[j] = cnt;
			mp[j] = cnt;
			ms.insert(cnt);
		}
	}
	if (tmp>1){
		ms.insert(1);
//		cout << 0 << ": " << tmp << "^" << 1 << "\n";
		mprime[tmp] = 1, mp[tmp] = 1;
	}
//	if (checkPrime(tmp)){
//		mprime[tmp] = 1;
//		mp[tmp] = 1;
//		ms.insert(1);
//	} else while (tmp>1){
//		if (tmp>=N-5){
//			int p = largestPrime(tmp);
//			tmp /= p;
//			mprime[p] = 1;
//			mp[p] = 1;
//		}
//		cout << tmp << "\n";
//		return;
//		int p = spf[tmp];
//		int cnt = 0;
//		while (tmp%p==0) cnt++, tmp/=p;
//		mprime[p] = cnt;
//		mp[p] = cnt;
//		ms.insert(cnt);
//	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int tmp = a[i];
		for (auto it: mprime){
			int p = it.first;
			if (tmp%p==0){
				int cnt = 0;
				while (tmp%p==0) cnt++, tmp/=p;
				vec[i].push_back({p, cnt});
			}
		}
//		for (int j = 2; j*j <= tmp; j++){
//			if (tmp%j==0){
//				int cnt = 0;
//				while (tmp%j==0) tmp /= j, cnt++;
//				if (mprime.count(j)) vec[i].push_back({j, cnt});
////				cout << i << ": " << j << "^" << cnt << "\n";
//			}
//		}
//		if (tmp>1){
//			if (mprime.count(tmp)) vec[i].push_back({tmp,1});
////			cout << i << ": " << tmp << "^" << 1 << "\n";
//		}
//		if (checkPrime(tmp)){
//			if (mprime.count(tmp)) vec[i].push_back({tmp, 1});
//		} else while (tmp>1){
//			if (tmp>=N-5){
//				int p = largestPrime(tmp);
//				tmp /= p;
//				if (mprime.count(p)) vec[i].push_back({p, 1});
//			}
//			int p = spf[tmp];
//			int cnt = 0;
//			while (tmp%p==0) cnt++, tmp/=p;
//			if (mprime.count(p)) vec[i].push_back({p, cnt});
//		}
	}
	int r = 0;
	auto mpbackup = mp;
	auto msbackup = ms;
	vector<iii> seg;
	for (int i = 1; i <= n; i++){
		while (r<n&&*ms.rbegin()>0){
			r++;
			for (auto it: vec[r]){
				int cnt = it.second, p = it.first;
				int mppold = mp[p];
				mp[p] -= cnt;
				ms.erase(ms.find(mppold));
				ms.insert(mp[p]);
			}
		}
//		cout << i << " " << *ms.rbegin() << "\n";
//		for (auto it: mp) cout << "mp[" << it.first << "] = " << it.second<< "; "; cout << '\n';
		if (*ms.rbegin()<=0){
			resr[i] = r;
			seg.push_back({r-i+1, {i, r}});
//			cout << i << " -> " << resr[i] << "\n";
		}
		for (auto it: vec[i]){
			int cnt = it.second, p = it.first;
			int mppold = mp[p];
			mp[p] += cnt;
			ms.erase(ms.find(mppold));
			ms.insert(mp[p]);
		}
	}
	r = 0;
	mp = mpbackup, ms = msbackup;
	for (int i = 1; i <= n; i++){
		while (r<n&&*ms.rbegin()>0){
			r++;
			for (auto it: vec[n-r+1]){
				int cnt = it.second, p = it.first;
				int mppold = mp[p];
				mp[p] -= cnt;
				ms.erase(ms.find(mppold));
				ms.insert(mp[p]);
			}
		}
//		cout << i << " " << *ms.rbegin() << "\n";
//		for (auto it: mp) cout << "mp[" << it.first << "] = " << it.second<< "; "; cout << '\n';
		if (*ms.rbegin()<=0){
//			resr[i] = r;
			seg.push_back({r-i+1, {n-r+1, n-i+1}});
//			cout << i << " -> " << resr[i] << "\n";
		}
		for (auto it: vec[n-i+1]){
			int cnt = it.second, p = it.first;
			int mppold = mp[p];
			mp[p] += cnt;
			ms.erase(ms.find(mppold));
			ms.insert(mp[p]);
		}
	}
//	return;
	sort(seg.begin(), seg.end());
	for (auto it: seg){
		int w = it.first, l = it.second.first, r = it.second.second;
		int pos = findNext(l);
//		cout << l << " " << r << " " << w << "  lrw\n";
		while (pos<=r){
			b[pos] = min(b[pos], w);
//			int jmp = findNext(pos)+1;
//			if (jmp<=r){
////				cout << "hop\n";
//				hop(pos,jmp);
//			}
//			cout << pos << " -> " << jmp << " " << nxt[4] << "\n";
//			return;
//			pos=jmp;
			nxt[pos] = findNext(pos+1);
			pos = findNext(pos);
		}
	}
	for (int i = 1; i <= n; i++){
		int u = findNext(i);
//		cout << i << " " << u << " " << b[u] << " iubu\n";
	}
	for (int i = 1; i <= n; i++){
	    cout << (b[i]==1e9?-1:b[i]) << " ";
	}
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

