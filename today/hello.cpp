#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
#define N 2
ll mod;
struct mat {
  ll mar[N][N];
};
mat a, b, init;
mat res = {1, 0, 0, 1};
mat mul(mat a1, mat b1) {
  int i, j, l;
  mat c1;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      c1.mar[i][j] = 0;
      for (l = 0; l < N; l++) {
        c1.mar[i][j] = c1.mar[i][j] + a1.mar[i][l] * b1.mar[l][j] % (mod - 1);
        c1.mar[i][j] %= (mod - 1);
      }
    }
  }
  return c1;
}
mat er_fun(mat e, int x) {
  mat tp;
  tp = e;
  e = res;
  while (x) {
    if (x & 1) e = mul(e, tp);
    tp = mul(tp, tp);
    x >>= 1;
  }
  return e;
}
ll quick_mod(ll aa, ll bb) {
  ll ans = 1;

  while (bb) {
    aa %= mod;
    if (bb & 1) {
      ans = ans * aa % mod;
    }
    bb >>= 1;
    aa = aa * aa;
  }
  return ans;
}
int main() {
  int t;
  int n, aa, bb;
  ll anum, bnum;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%d%d%d", &aa, &bb, &mod, &n);

    if (n == 1) {
      printf("Case #%d: %lld\n", i, aa % mod);
      continue;
    }

    init.mar[0][0] = 1;
    init.mar[0][1] = 1;
    init.mar[1][0] = 1;
    init.mar[1][1] = 0;
    a = init;

    b = er_fun(a, n - 2);
    bnum = b.mar[0][0];
    anum = b.mar[1][0];

    anum = quick_mod((ll)aa, anum);
    bnum = quick_mod((ll)bb, bnum);

    printf("Case #%d: %lld\n", i, anum * bnum % mod);
  }
}
