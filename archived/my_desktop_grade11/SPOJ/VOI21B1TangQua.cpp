#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int d;

int solve(vector<int> a, vector<int> b){
	//a, b -> n, bs(val,pos) -> b (lower_bound)
	//tmp -> dec sort -> push to vb
	//LIS vb
	int n = a.size();
	vector<ii> bs(b.size());
	vector<int> vb;
	for (int i = 0; i < b.size(); i++){ //b -> bs
		bs[i].first = b[i];
		bs[i].second = i;
	}
	sort(bs.begin(),bs.end());
	sort(b.begin(),b.end());
	for (int i = 0; i < n; i++){
		vector<int> tmp; //cong vao vb
		int pos = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
		 
		int j = pos-1;
		while (j>=0&&abs(bs[j].first-a[i])<=d) tmp.push_back(bs[j].second),j--;
		j = pos;
		while (j<b.size()&&abs(bs[j].first-a[i])<=d) tmp.push_back(bs[j].second), j++;
		
		sort(tmp.begin(),tmp.end(),[](int a, int b){return a>b;});
		for (int it: tmp) vb.push_back(it);
	}
	int m = vb.size();
	vector<int> lis(m+1,1e6);
	lis[0] = -1e6;
	for (int i = 0; i < m; i++){
		int pos = lower_bound(lis.begin(),lis.end(),vb[i])-lis.begin();
		lis[pos] = vb[i];
	}
	for (int i = m; i >= 1; i--){
		if (lis[i]<1e6){ //lis[i] > -1e6
			return i;
		}
	}
	return -1;
}

int main(){
//	d = 1;
//	cout << solve({1,5,3,7},{2,8,6,4});
	int n; cin >> n >> d;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	
	int res = 0;
	for (int i = 0; i < 2*n-1; i++){
//		cout << i << ": \n";
		vector<int> sa, sb;
		for (int j = 0; j <= i; j++) sa.push_back(a[j]);
		for (int j = i+1; j < 2*n; j++) sb.push_back(a[j]);
//		for (int it: sa) cout << it << " "; cout << endl;
//		for (int it: sb) cout << it << " "; cout << endl;
		res = max(res,solve(sa,sb));
	}
	cout << res;
	
	return 0;
}

/* j4f

int solve(vector<int> a, vector<int> b){
	//a, b -> n, bs(val,pos) -> b (lower_bound)
	//tmp -> dec sort -> push to vb
	//LIS vb
//	for (auto it: b) cout << it << " "; cout << endl;
	int n = a.size();
	vector<ii> bs(b.size());
	vector<int> vb;
	for (int i = 0; i < b.size(); i++){ //b -> bs
		bs[i].first = b[i];
		bs[i].second = i;
	}
	sort(bs.begin(),bs.end());
//	for (int i = 0; i < b.size(); i++) b[i] = bs[i].first; //bs -> b
	sort(b.begin(),b.end());
	for (int i = 0; i < n; i++){
		vector<int> tmp; //cong vao vb
		int pos = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
		 
		int j = pos-1;
		while (j>=0&&abs(bs[j].first-a[i])<=d) tmp.push_back(bs[j].second),j--;
		j = pos;
		while (j<n&&abs(bs[j].first-a[i])<=d) tmp.push_back(bs[j].second), j++;
		
		sort(tmp.begin(),tmp.end(),[](int a, int b){return a>b;});
		cout << a[i] << ": ";
		for (int it: tmp) vb.push_back(it), cout << it << " "; cout << endl;
	}
//	for (int it: vb) cout << it << " "; cout << endl;
	int m = vb.size();
	vector<int> lis(m+1,1e6);
	lis[0] = -1e6;
	for (int i = 0; i < m; i++){
		int pos = lower_bound(lis.begin(),lis.end(),vb[i])-lis.begin();
		lis[pos] = vb[i];
//		for (int it: lis) cout << it << " "; cout << endl;
	}
	for (int i = m; i >= 1; i--){
		if (lis[i]<1e6){ //lis[i] > -1e6
			return i;
		}
	}
*/
