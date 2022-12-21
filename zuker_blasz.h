void zuker_blasz(){
      int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
 int lb, ub, lbp, ubp, lb2, ub2;
 register int lbv, ubv;
/* Start of CLooG code */


for (int w0 = max(-1, floord(-N + 2, 6)); w0 <= floord(N - 1, 6); w0 += 1) {
  #pragma omp parallel for shared(w0)
  for (int h0 = max(w0 - (N + 5) / 6 + 1, -((N + 3) / 6)); h0 <= min(0, w0); h0 += 1) {
    for (int t0 = max(0, 2 * w0); t0 <= min(min(min(2 * w0 + 3, 2 * w0 - 2 * h0 + 1), (N - 1) / 3), 2 * h0 + (N + 1) / 3 + 1); t0 += 1) {
      for (int i1 = max(max(max(max(-N + 2, -6 * w0 + 6 * h0 - 4), 6 * h0), -6 * w0 + 6 * h0 + 3 * t0 - 5), -N + 3 * t0 + 1); i1 <= min(min(0, 6 * h0 + 5), -6 * w0 + 6 * h0 + 3 * t0 + 2); i1 += 1) {
        for (int i2 = max(max(6 * w0 - 6 * h0, 3 * t0 - i1), -i1 + 1); i2 <= min(min(N - 1, 6 * w0 - 6 * h0 + 5), 3 * t0 - i1 + 2); i2 += 1) {
          {
            for (int i3 = -i1 + 1; i3 < i2; i3 += 1) {
              for (int i5 = i3 + 1; i5 < min(i2, i1 + i2 + i3 - 2); i5 += 1) {
                V[-i1][i2] = (((V[i3][i5] + EFL[-i1][i2]) < V[-i1][i2]) ? (V[i3][i5] + EFL[-i1][i2]) : V[-i1][i2]);
              }
              if (i2 >= i3 + 2) {
                V[-i1][i2] = (((W[-i1 + 1][i3] + W[i3 + 1][i2 - 1]) < V[-i1][i2]) ? (W[-i1 + 1][i3] + W[i3 + 1][i2 - 1]) : V[-i1][i2]);
              }
              W[-i1][i2] += ((((W[-i1][i3] < W[i3 + 1][i2]) ? W[-i1][i3] : W[i3 + 1][i2]) < W[-i1][i2]) ? ((W[-i1][i3] < W[i3 + 1][i2]) ? W[-i1][i3] : W[i3 + 1][i2]) : W[-i1][i2]);
            }
            V[-i1][i2] = ((((V[-i1 + 1][i2 - 1] < EHF[-i1][i2]) ? V[-i1 + 1][i2 - 1] : EHF[-i1][i2]) < V[-i1][i2]) ? ((V[-i1 + 1][i2 - 1] < EHF[-i1][i2]) ? V[-i1 + 1][i2 - 1] : EHF[-i1][i2]) : V[-i1][i2]);
          }
          W[-i1][i2] = ((((((W[-i1 + 1][i2] < W[-i1][i2 - 1]) ? W[-i1 + 1][i2] : W[-i1][i2 - 1]) < V[-i1][i2]) ? ((W[-i1 + 1][i2] < W[-i1][i2 - 1]) ? W[-i1 + 1][i2] : W[-i1][i2 - 1]) : V[-i1][i2]) < W[-i1][i2]) ? ((((W[-i1 + 1][i2] < W[-i1][i2 - 1]) ? W[-i1 + 1][i2] : W[-i1][i2 - 1]) < V[-i1][i2]) ? ((W[-i1 + 1][i2] < W[-i1][i2 - 1]) ? W[-i1 + 1][i2] : W[-i1][i2 - 1]) : V[-i1][i2]) : W[-i1][i2]);
        }
      }
    }
  }
}

}
