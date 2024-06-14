#include<bits/stdc++.h>

using namespace std;
#define int long long
string s;
int f[16][9*14+1][9*14][2];
main(){
	cin >> s;
	int res = 0;
	for (int sum = 1; sum <= 9*14; sum++){
		memset(f,0,sizeof(f));
		f[0][0][0][0] = 1;
		for (int pos = 0; pos < s.length(); pos++){
			for (int sum_digit = 0; sum_digit <= sum; sum_digit++){
				for (int rem = 0; rem < sum; rem++){
					for (int smaller = 0; smaller < 2; smaller++){
						for (int digit = 0; digit <= 9; digit++){
//							if (pos==1&&sum_digit==1&&rem==1&&smaller==1) cout << "hi\n";
							if (smaller==0&&digit>s[pos]-'0') continue;
							if (sum_digit+digit>sum) continue;
							f[pos+1][sum_digit+digit][(10*rem+digit)%sum][smaller||(digit<s[pos]-'0')] += f[pos][sum_digit][rem][smaller];
						}
					}
				}
			}
		}
//		if (sum==3){
//			cout << f[1][1][1][1]  << " " << f[2][3][0][1] << "\n";
//		}
//		cout << sum << ". " << f[1][sum][0][0] << " " << f[1][sum][0][1] << "\n";
		res += f[s.length()][sum][0][0] + f[s.length()][sum][0][1];
	}
	cout << res << "\n";
	
	
	return 0;
}
