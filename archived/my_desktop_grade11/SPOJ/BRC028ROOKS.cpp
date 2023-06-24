//Lai tap: Greed + DP

#include <bits/stdc++.h>

using namespace std;
string s;
int a, nxt, num, res[8], k = 2, mmin;
bool checked[8], isHaveAns;
map<vector<int>, int> ans;
vector<int> cnt(8);
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t >> k;
	while (t--){	
//		memset(cnt,0,sizeof(cnt));
//		cnt.resize(8); //for map
		for (int i = 0; i < 8; i++) cnt[i] = 0; 
		memset(res,0,sizeof(res)); //but memset is faster
		isHaveAns = true;
		cin >> s;
		for (int i = 0; i < 8; i++) a = s[i]-'1', cnt[a]++;
		
		if (ans.count(cnt)){ //da tinh (kha giong DP)
			cout << ans[cnt] <<'\n';
			continue;
		}
		
		for (int i = 0; i < 8; i++){
			memset(checked,false,sizeof(checked));
			nxt = i; num = 0;
			while (!checked[nxt]){
//				cout << i << " " << nxt << " = " << num << endl;
				checked[nxt] = true;
				num += cnt[nxt]-1;
				res[i] += abs(num);
				nxt = (nxt+k)%8;
			}
			isHaveAns &= (num==0);
//			cout << t <<". "<< num << endl;
		}
		
		memset(checked,false,sizeof(checked));
		for (int i = 0; i < 8; i++) if (!checked[i]){
			mmin = 1e7; nxt = i; 
			while (!checked[nxt]){
				checked[nxt] = true;
				mmin = min(mmin,res[nxt]);
				nxt = (nxt+k)%8;
			}
			ans[cnt] += mmin;
		}
		if (!isHaveAns) ans[cnt] = -1;
		cout << ans[cnt] << '\n';
	}
	return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//string s;
//int cnt[8], a, nxt, num, res[8], k = 2, mmin;
//bool checked[8], visited[8], isHaveAns;
//int main(){
//	
//	cin >> s;
//	for (int i = 0; i < 8; i++) a = s[i]-'1', cnt[a]++;
////	memset(checked,-1,sizeof(checked));
//	memset(visited,false,sizeof(visited));
//	for (int i = 0; i < 8; i++){
//		memset(checked,false,sizeof(checked));
//		nxt = i; num = 0;
//		while (!checked[nxt]){
////			cout << i << " " << nxt << endl;
//			checked[nxt] = visited[nxt] = true;
//			num += cnt[nxt]-1;
//			res[i] += abs(num);
//			nxt = (nxt+k)%8;
//		}
//	}
//	
//	memset(checked,false,sizeof(checked));
//	for (int i = 0; i < 8; i++) if (!checked[i]){
//		mmin = 1e7; nxt = i; 
//		while (!checked[nxt]){
//			checked[nxt] = true;
//			mmin = min(mmin,res[nxt]);
//			nxt = (nxt+k)%8;
//		}
//		ans += mmin;
//	}
////	for (int i = 0; i < 8; i++) cout << "res = " << res[i] << endl;
//	isHaveAns = true;
//	for (int i = 0; i < 8; i++) isHaveAns &= visited[i];
//	cout << (isHaveAns?ans:-1) << '\n';
//	
//	return 0;
//}
