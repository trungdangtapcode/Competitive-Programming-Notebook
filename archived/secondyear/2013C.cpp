#include<bits/stdc++.h>

using namespace std;
int n;
int ask(deque<int> d){
	string s;
	while (d.size()){
		s += d.front()+'0';
		d.pop_front();
	}	
	cout << "? " << s << endl;
	int tmp; cin >> tmp;
	return tmp;
}
void ans(deque<int> d){
	string s;
	while (d.size()){
		s += d.front()+'0';
		d.pop_front();
	}
	cout << "! " << s << endl;
	return; 
}

void solve(){
	cin >> n;
	deque<int> d;
	cout << "? 0" << endl;
	int tmp; cin >> tmp;
	if (tmp==0){
		cout << "! ";
		for (int i = 1; i<= n; i++) cout << "1";
		cout << endl;
		return;
	} else if (n==1){
		cout << "! 0" << endl;
		return;
	}
	d.push_back(0);
	bool check = 0;
	for (int i = 2; i <= n; i++){
		if (check){
			d.push_front(0);
			if (ask(d)){
				if (i==n){ 
					ans(d);
					return;
				}
				continue;
			}
			d.pop_front();
			d.push_front(1);
			if (i==n){
//				cout << "hi" << d.size() << endl;
				ans(d);
				return;
			}
			if (ask(d)){
				continue;
			}
			assert(0);
		}
		d.push_back(0);
		if (ask(d)){
			if (i==n){ 
				ans(d);
				return;
			}
			continue;
		}
		d.pop_back();
		d.push_back(1);
		if (ask(d)){
			if (i==n){
				ans(d);
				return;
			}
			continue;
		}
		d.pop_back();
		check = 1;
		i--;
	}
	assert(0);
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	#ifdef JESSIE
//	freopen("input.txt","r",stdin);
//	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

