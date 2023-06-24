#include<bits/stdc++.h>

using namespace std;
int n, r, s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s >> r;
		int mmax = s-r;
//		vector<int> res;
//		res.push_back(mmax);
//		int d = r/mmax, rm = r%mmax;
		cout << mmax << " "; n--;
		while (2*n<r){ //r<=2*n
			while (r-mmax<n-1) mmax--; //r>=n
			if (mmax==0) break;
			cout << mmax << " ";
			r-=mmax;
			n--;
		}
		int a = r-n, b = n-a;
		for (int i = 0; i < a; i++) cout << 2 << " ";
		for (int i = 0; i < b; i++) cout << 1 << " ";
		cout << "\n";
	}
}
