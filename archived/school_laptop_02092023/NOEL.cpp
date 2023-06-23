#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, last;
vector<int> a;
bool inLeft[100005];
multiset<int> s, t;

void xoa(int i){
	inLeft[i] = true;
	if (s.size()==1){
		s.clear();
		return;
	}
	if (a[i]==*s.begin()){
		auto it = s.find(a[i]);
		auto it1 = it; it1++;
		t.erase(t.find(*it1-*it));
		s.erase(it);
		return;
	}
	if (a[i]==*s.rbegin()){
		auto it = s.find(a[i]);
		auto it0 = it; it0--;
		t.erase(t.find(*it-*it0));
		s.erase(it);
		return;
	}
	auto it = s.find(a[i]);
	auto it0 = it; it0--;
	auto it1 = it; it1++;
	t.erase(t.find(*it1-*it));
	t.erase(t.find(*it-*it0));
	t.insert(*it1-*it0);
	s.erase(it);
}
bool check(){
	if (!t.size()) return true;
	return (*t.begin()==*t.rbegin());
}
void kq(){
	int sz = 0;
	for (int i = 0; i < n; i++) if (inLeft[i]) sz++;
	cout << sz << "\n";
	for (int i = 0; i < n; i++) if (inLeft[i]) cout << a[i] << " "; cout << "\n";
	cout << n-sz << "\n";
	for (int i = 0; i < n; i++) if (!inLeft[i]) cout << a[i] << " "; cout << "\n";
}

bool startWith(int x, int y){
	memset(inLeft,0,sizeof(inLeft));
	s.clear(); t.clear();
	for (int i = 0; i < n; i++) s.insert(a[i]);
	for (int i = 0; i < n-1; i++) t.insert(a[i+1]-a[i]);
	xoa(x); xoa(y);
	last = a[y];
	for (int i = 0; i < n; i++) if (!inLeft[i]){
		if (check()){
			kq();
			return 1;
		}
		if (a[i]-last==a[y]-a[x]) xoa(i), last = a[i];
	} 
	if (check()){
		kq();
		return 1;
	}
	return 0;
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	
	if (n==2){
		cout << "1\n" << a[0] << "\n1\n" << a[1] << "\n";
		return 0;
	} else if (startWith(0,1)) return 0;
	else if (startWith(1,2)) return 0;
	else if (startWith(0,2)) return 0;
	cout << -1 << endl;
	
	
	return 0;
}



//void xoa(int i){
//	for (auto x: s) cout << x << " "; cout << endl;
//	for (auto x: t) cout << x << " "; cout << "find " << i << endl;
//	inLeft[i] = true;
//	if (s.size()==1){
//		s.erase(a[i]);
//		return;
//	}
//	if (a[i]==*s.begin()){
//		s.erase(s.find(a[i]));
//		t.erase(t.find(a[i+1]-a[i]));
//		return;
//	}
//	if (a[i]==*s.rbegin()){
//		s.erase(s.find(a[i]));
//		t.erase(t.find(a[i]-a[i-1]));
//		return;
//	}
//	s.erase(s.find(a[i]));
//	t.erase(t.find(a[i+1]-a[i]));
//	t.erase(t.find(a[i]-a[i-1]));
//	t.insert(a[i+1]-a[i-1]);
//}


