//cleanup by Jaehyun Park

#include <stdio.h>
#include <bits/stdc++.h>
#define PROBNAME "cleanup"
#define min(a, b) (((a)<(b))?(a):(b))
#define sqr(x) ((x)*(x))
using namespace std;
int N, M;
int P[40001];
int last_occurrence[40001];
int min_index[201], min_index_size;
int d[40001];
void INPUT() {
    int i;
    cin >> N >> M;
    for (i = 1; i <= N; i++)
        cin >> P[i];
    P[0] = -1;
}

void PROCESS() {
    int i, j, k;
    for (i = 1; i <= M; i++)
        last_occurrence[i] = -1;
    for (min_index_size=1; sqr(min_index_size) <= N; min_index_size++);
    min_index_size--;
    min_index[0]=1;
    for(i=1;i<=N;i++) {
        k = last_occurrence[P[i]];
        for (j = 0; j <= min_index_size && min_index[j]-1 != k; j++)
            ;
        for(j--; j >= 0; j--)
            min_index[j+1]=min_index[j];
        min_index[0] = i + 1;
        d[i] = i;
        for (j = 1; j <= min_index_size; j++)
            d[i] = min(d[i], d[min_index[j]-1] + sqr (j));
        last_occurrence[P[i]] = i;
    }
}

void OUTPUT() {
    cout << d[N];
}



int main() {
    INPUT ();
    PROCESS ();
    OUTPUT ();
    //CLOSE_FILES ();
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int n, m;
//vector<int> a;
//int f[40001];
//int min_index[201], min_index_size;
//int d[40001];
//
//
//void solve() {
//    int i, j, k;
//    for (i = 1; i <= m; i++)
//        f[i] = -1;
//        
//    min_index_size = sqrt(n);
//    //min_index_size--;
//    min_index[0]=1;
//    for(i=0;i<n;i++) {
//        k = f[a[i]];
//        for (j = 0; j <= min_index_size && min_index[j]-1 != k; j++);
//        for(j--; j >= 0; j--)
//            min_index[j+1]=min_index[j];
//        min_index[0] = i + 1;
//        d[i] = i;
//        for (j = 1; j <= min_index_size; j++)
//            d[i] = min(d[i], d[min_index[j]-1] + j*j);
//        f[a[i]] = i;
//    }
//}
//
//
//int main() {
//    cin >> n >> m;
//    //a.push_back(-1);
//    for (int i = 0; i < n; i++) {
//		int x; 
//		cin >> x;
//		a.push_back(x);
//    }
//	solve ();
//    cout << d[n];
//    return 0;
//}
