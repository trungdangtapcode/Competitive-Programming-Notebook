#include <bits/stdc++.h>

using namespace std;
string a, b;
//vector <char> va, vb;
//int sa[1000005], sb =0;
int nxt[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;
	nxt[0] = -1;
	for(int i = 1; i < b.length(); i++) {
        int j = nxt[i-1];
        while(j >= 0 && b[j+1] != b[i]) j = nxt[j];
        if(b[j+1] == b[i]){
        	nxt[i] = j+1;
		} else {
			nxt[i] = -1;
		}
    }
	//for(int i = 0; i <= 30; ++i) cout << nxt[i] << " " ;
	int j = -1;
    for(int i = 0; i <a.length() ; i++) {
        while (j >= 0 && b[j+1] != a[i]) j = nxt[j];
        if (b[j+1] == a[i]) j++;
 
        if (j+1>=b.length()) { // Het xau s
            printf("%d ", i - j + 1);
            j = nxt[j];
        }
    }
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//string a, b;
//int sa[1000005], sb =0;
//
//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> a >> b;
//	a = " " + a;
//	sa[0] = 0;
//	for (int i = 1; i <= a.length(); i++) sa[i] = sa[i-1] + (a[i]-'a');
//	for (int i = 0; i < b.length(); i++) sb += (b[i]-'a');
//	for (int i = 1; i <= a.length()-b.length()+1; i++){
//		if (sa[i+b.length()-1]-sa[i-1]==sb) if (b==a.substr(i,b.length())) cout << i << " ";
//	}
//	
//	return 0;
//}




//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6;
//char s[N+1], t[N+1];
//int next[N];
//
//int main() {
//    scanf("%s%s", t, s);
//    next[0] = -1;
//    for(int i = 1; s[i]; ++i) {
//        int j = next[i-1];
//        while(j >= 0 && s[j+1] != s[i]) j = next[j];
//        if(s[j+1] == s[i]) ++j;
//        next[i] = j;
//    }
//    for (int i = 0; i <= 30; i++) printf("%d ", next[i]); printf("\n");
//    for(int i = 0, j = -1; t[i]; ++i) {
//        while(j >= 0 && t[i] != s[j+1]) j = next[j];
//        if(t[i] == s[j+1]) ++j;
//        printf("%d %d\n",i,j);
//        if(s[j+1] == 0) {
//            printf("%d \n", i - j + 1);
//            j = next[j];
//        }
//    }
//    printf("\n");
//    return 0;
//}
