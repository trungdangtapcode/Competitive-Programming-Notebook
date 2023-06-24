#include <bits/stdc++.h>

using namespace std;
int n, f[10000005], cnt[10000005];
long long int m;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i] = i;
	
	for (int i = 2; i*i <= n; i++){ //https://oj.vnoi.info/problem/bedao_m08_pairs/editorial
		for (int j = i*i; j <= n; j += i*i)  { //1 lo k khong de k lo 1
			f[j] = (j/(i*i));
		}
		//f[i] += f[i-1];
	}
//	for (int i = 1; i <= n; i++) cnt[f[i]]++;
//	int l = 1, r = n;
//	long long int res = 0;
//	while (l < r){
//		if (l*r<=m) {
//			res += cnt[f[l]]-1;
//			cnt[f[l]]--;
//			l++;
//		} else {
//			cnt[f[r]]--;
//			r--;
//		}
//	}
	//for (int i = 0; i < 10; i++) cout << f[i] << " "; cout << endl;
	memset(cnt,0,sizeof(cnt));
	long long int res = 0;
	int j = 0; //cnt[f[0]]++;
	for (int i = 1; i <= n; i++){
		while (j < i-1 && (long long int)i*j <= m) j++, cnt[f[j]]++;
		while ((long long int)i*j > m) cnt[f[j]]--, j--;
		//cout << i << " " << j << endl;
		//cout << i << " " << cnt[f[i]] << endl;
		res += (long long int)cnt[f[i]];//cnt[j][f[i]]
	}
	cout << res;
	return 0;
}
