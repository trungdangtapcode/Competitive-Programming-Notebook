#include<bits/stdc++.h>

using namespace std;
typedef pair<char,int> ci;
ci rmq[1000005][20];
int n;
string s;

int findPos(int l, int r){
	int h = __lg(r-l+1);
	return -max(rmq[l][h],rmq[r-(1<<h)+1][h]).second;
}

int main(){
    cin >> s >> n;
    
    for (int i = 0; i < s.length(); i++) rmq[i][0] = {s[i],-i};
    for (int i = 1; i < 20; i++){
    	for (int j = 0; j < (int)s.length()-(1<<i)+1; j++) rmq[j][i] = max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	}
    
    for (int i = s.length()-n, p = 0; i > 0; i--){
        int cur = findPos(p,s.length()-i);
        cout << s[cur];
        p = cur + 1;
    }
    
    return 0;
}
