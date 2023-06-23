#include<bits/stdc++.h>

using namespace std;

struct sub1{
	int p, q;
	sub1(int p, int q){
		this->p = p;
		this->q = q;
	}
	
	bool check(int x){
		vector<int> cnt(10,0);
		while (x){
			cnt[x%10]++;
			x /= 10;
		}
		bool has1 = 0, has2 = 0, has3 = 0;
		for (int i = 0; i < 10; i++){
			if (cnt[i]%4==1){
				if (has1||has3) return false;
				else has1 = true;
			} else if (cnt[i]%4==2){
				if (has2||has3) return false;
				else has2 = true;
			} else if (cnt[i]%4==3) if (has3||has1||has2) return false; else has3 = true; 
				
		}
		return true;
	}
	
	void solve(){
		int res = 0;
//		cout << check(11) << "\n";
		for (int i = p; i <= q; i++) if (check(i)){
			res++;
		}
		cout << res << "\n";
	}
};
int dp[20][(1<<20)+5][2][2], cnt[10];
struct sub2{
	string p, q;
	sub2(string p, string q){
		this->p = p;
		this->q = q;
	}
	const int mod = 1e9+7;

	int calc(string x){
		memset(dp,0,sizeof(dp));
		int n = x.length();
		x = "#" + x;
		dp[0][0][0][0] = 1;
		for (int i = 1; i <= n; i++) for (int bigger = 0; bigger < 2; bigger++) for (int has0 = 0; has0 < 2; has0++){
//			for (int cnt1 = 0; cnt1 < 10; cnt1++) for (int cnt2 = 0; cnt2 < 10; cnt2++) for (int cnt4 = 0; cnt4 < 10; cnt4++){
//				if (cnt4) dp[i][cnt1+1][cnt2][cnt4-1] += dp[i-1][cnt1][cnt2][cnt4];
//				if (cnt2) dp[i][cnt1+1][cnt2-1][]
//			}
			for (int mask = 0; mask < (1<<20); mask++){
				if (dp[i-1][mask][bigger][has0]==0) continue;
				for (int i = 0; i < 10; i++) cnt[i] = ((mask>>(2*i))&3);
				for (int digit = 0; digit < 10; digit++){
					if (!bigger&&digit>x[i]-'0') break;
					
						
					int ncnt = (cnt[digit]+1)%4;
					int nmask = (mask|(3<<(digit*2)))^(3<<(digit*2));
					nmask = nmask^(ncnt<<(digit*2));
					
					
					int nhas0 = has0||digit;
					if (nhas0==false){ //chua dien
						nmask = (nmask|3)^3;	
					}

//					cout << digit << " " << bitset<20>(mask) << " " << bitset<20>(nmask)  << " is writen" << nhas0 << "\n";
					
										
					(dp[i][nmask][bigger||x[i]-'0'>digit][has0||digit] += dp[i-1][mask][bigger][has0])%=mod;
				}
			}
		}
		int res = 0;
		for (int bigger = 0; bigger < 2; bigger++) for (int mask = 0; mask < (1<<20); mask++){
			for (int i = 0; i < 10; i++) cnt[i] = ((mask>>(2*i))&3);
			bool ok = true, has1 = 0, has2 = 0, has3 = 0;
			for (int i = 0; i < 10; i++){
				if (cnt[i]%4==1) if (has1||has3) ok = false; else has1 = true;
				else if (cnt[i]%4==2) if (has2||has3) ok = false; else has2 = true;
				else if (cnt[i]%4==3) if (has3||has2||has1) ok = false; else has3 = true;
			}
			if (!ok) continue;
			(res += dp[n][mask][bigger][1])%=mod;
		}
//		cout << res;
		return res;
	}
	
	bool check(string x){
		memset(cnt,0,sizeof(cnt));
		for (char c: x){
			cnt[c-'0']++;
		}
		bool has1 = 0, has2 = 0, has3 = 0;
		for (int i = 0; i < 10; i++){
			if (cnt[i]%4==1) if (has1||has3) return 0; else has1 = true;
			else if (cnt[i]%4==2) if (has2||has3) return 0; else has2 = true;
			else if (cnt[i]%4==3) if (has3||has2||has1) return 0; else has3 = true;
		}
		return true;
	}
	
	void solve(){
		cout << (calc(q)-calc(p)+check(p)+mod)%mod;
	}
	
};

int main(){
	string p, q;
	cin >> p >> q;
//	cout << p << "-" << q << "\n";
	if (q.length()<=5){
		sub1 x = sub1(stoi(p),stoi(q));
		x.solve();
		return 0;
	} else if (q.length()<=18){
		sub2 x = sub2(p,q);
		x.solve();
		return 0;	
	}
	
	
	return 0;
}
