#include <bits/stdc++.h>
using namespace std;
struct cay{
	int sum1;
	int sum2;
	long long int d;
	int loai;
};
bool myfunc(cay a, cay b){
	if (a.d==b.d) return a.loai<b.loai; else return a.d<b.d;
}
int main() {
	//neu cac cay ko cung vi tri
	int n, a, b;
	cay *t = new cay[300000];
	cin >> n >> a >> b;
	t[0].d = 0; t[0].loai = 0; 
	for (int i = 1; i <= n; i++){
		cin >> t[i].d >> t[i].loai;
	}
	sort(t,t+n+1,myfunc);
	t[0].sum1 = 0; t[0].sum2 = 0;
	for (int i = 1; i <= n; i++){
		t[i].sum1 = t[i-1].sum1 + (t[i].loai==1);
		t[i].sum2 = t[i-1].sum2 + (t[i].loai==2);
	}
	//for (int i = 0; i <= n; i++){
	//	cout << t[i].d << " " << t[i].loai << " " << t[i].sum1 << " " << t[i].sum2 << endl;
	//}
	long long int result = 1e15;
	int j = 1;
	for (int i = 1; i <= n; i++){
		while (t[i].sum1-t[j-1].sum1>=a&&t[i].sum2-t[j-1].sum2>=b){
			result = min(result,t[i].d - t[j].d);
			j++;
		}
		//cout << i << " " << j << endl;
	}
	if (result == 1e15) cout << -1; else cout << result;
	return 0;
}
