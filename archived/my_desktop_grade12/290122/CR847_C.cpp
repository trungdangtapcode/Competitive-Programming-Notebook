#include<bits/stdc++.h>

using namespace std;
int n, pt[2005], b[2005], tmp[2005];
int main(){
	int t; cin >>t;
	while (t--){
		cin >> n;
		for (int i = 1; i<= n; i++) pt[i] = 0;
		for (int i = 1, a; i<= n-1; i++){
			cin >> a;
			pt[a] = i;
		}
		int piv = -1, res = 0;
		for (int i = 1; i<= n; i++) if (pt[i]==0) piv = i;
		for (int i = 1; i <= n-1; i++){
			for (int j = 1; j < n; j++) cin >> b[j];
			for (int j = 1; j < n; j++) if (b[j]==piv){
				res = max(res,pt[b[j-1]]);
//				cout << b[j-1] << "hehe\n";
				break;
			}
		}
		memset(tmp,0,sizeof(tmp));
//		cout << "res = " << res << " at pivot " << piv << '\n';
//		pt[piv] = res+1;
		for (int i = 1; i <= n; i++){
			tmp[pt[i]] = i;
//			cout << pt[i] << "= ";
		}
//		for (int i = 1; i <= res; i++) cout << tmp[i] << " ";
//		cout << piv << " ";
//		for (int i = res+1; i < n; i++) cout << tmp[i] << " ";
		for (int i = 1; i<= res; i++) cout << tmp[i] <<" ";
		cout << piv << " ";
		for (int i = res+1; i < n; i++) cout << tmp[i] << " ";
		cout << "\n";
	}
	return 0;
}
