#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (n%2){
			cout << -1 << "\n";
			continue;
		}
		int dem = 0;
		for (int i = 0; i < n; i += 2){
			if (a[i]==-1&&a[i+1]==1||a[i]==1&&a[i+1]==-1){
				dem+=2;
			} else {
				dem++;
			}
		} 
		cout << dem << "\n";
		for (int i = 0; i < n; i += 2){
			if (a[i]+a[i+1]==0){
				cout << i +1<< " " << i +1<< "\n" << i+1 +1<< " " << i+1 +1<< "\n";
			} else {
				cout << i +1<< " " << i+1 +1<< "\n";
			}
		} 
	}
	
	return 0;
}



/*
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i%2) a[i] = -a[i];
			sum += a[i];
		}
		vector<ii> res;
		int st = 0;
		bool ok = false;
		if (sum%2==0&&sum%4!=0&&n%2==0) sum -= 2*(a[n-1]), ok = true; 
		for (int i = 1; i < n-1; i+=2){
			if (abs(sum-2*(a[i]+a[i+1]))<abs(sum)){
				if (st<=i-1) res.push_back({st,i-1});
				res.push_back({i,i+1});
				st = i+2;
				sum -= 2*(a[i]+a[i+1]);
			}
		}
		if (ok){
			if (st<=n-2) res.push_back({st,n-2});
			res.push_back({n-1,n-1});
		} else if (st<=n-1) res.push_back({st,n-1});
		
		if (sum==0){
			cout << res.size() << "\n";
			for (auto it: res)
				cout << it.first+1 << " " << it.second+1 << "\n";
		} else cout << "-1\n";
	}
	
	return 0;
}

*/
