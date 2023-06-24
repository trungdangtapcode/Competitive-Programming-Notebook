#include<bits/stdc++.h>

using namespace std;
typedef complex<double> Complex;
int n, bit = 1<<18;;
int rev[300005];
const int T = 5e4;
const double PI = atan(1)*4;

void get_rev(){
    for (int i = 0; i < bit; i++){
        rev[i] = rev[i/2]/2|(bit/2)*(i&1);
    }
}

void FFT(Complex *a, int op){
    for (int i = 0; i < bit; i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int mid = 1; mid < bit; mid <<= 1){
        Complex wn(cos(PI/mid),op*sin(PI/mid));
        for (int j = 0; j < bit; j += mid<<1){
            Complex w(1,0);
            for (int k = 0; k < mid; k++, w *= wn){
                Complex x = a[j+k], y = w*a[j+k+mid];
                a[j+k] = x + y; a[j+k+mid] = x - y;
            }
        }
    }
    if (op==-1){
        for (int i = 0; i < bit; i++) a[i] /= bit;
    }
}