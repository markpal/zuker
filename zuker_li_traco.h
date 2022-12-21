void zuker_li_traco()
{
int i,j,k,m,a;
int diag,row,col;
int c0, c1, c4, c10, c12;
a=0;
for( c0 = 1; c0 < 2 * N - 2; c0 += 1)
  #pragma omp parallel for shared(c0) private(c1, c4, c10, c12)
  for( c1 = c0 / 2 + 1; c1 <= min(N - 1, c0); c1 += 1) {
    for( c4 = -c0 + c1; c4 < -1; c4 += 1) {
      for( c12 = max(N + 2 * c0 - 3 * c1 + c4 - 28, N + c0 - 2 * c1 + c4 + 1); c12 < min(N + c0 - 2 * c1, N + 2 * c0 - 3 * c1 + c4 - 1); c12 += 1){
        V[(N-c1-1)][(N+c0-2*c1)] = MIN(V[(N+c0-2*c1+c4)][c12] + EFL[(N-c1-1)][(N+c0-2*c1)], V[(N-c1-1)][(N+c0-2*c1)]);
//a++;
}
      V[(N-c1-1)][(N+c0-2*c1)] = MIN(W[(N-c1-1)+1][(N+c0-2*c1+c4)] + Wp[(N+c0-2*c1)-1][(N+c0-2*c1+c4)+1], V[(N-c1-1)][(N+c0-2*c1)]);
//a++;
    }
    for( c10 = N - c1; c10 < N + c0 - 2 * c1; c10 += 1) {
      W[(N-c1-1)][(N+c0-2*c1)] += MIN ( MIN(W[(N-c1-1)][c10], Wp[(N+c0-2*c1)][c10+1]), W[(N-c1-1)][(N+c0-2*c1)]);
//a++;
      Wp[(N+c0-2*c1)][(N-c1-1)] = W[(N-c1-1)][(N+c0-2*c1)];
    }
    V[(N-c1-1)][(N+c0-2*c1)] = MIN( MIN (V[(N-c1-1)+1][(N+c0-2*c1)-1], EHF[(N-c1-1)][(N+c0-2*c1)]), V[(N-c1-1)][(N+c0-2*c1)]);
    W[(N-c1-1)][(N+c0-2*c1)] = MIN( MIN ( MIN ( W[(N-c1-1)+1][(N+c0-2*c1)], W[(N-c1-1)][(N+c0-2*c1)-1]), V[(N-c1-1)][(N+c0-2*c1)]), W[(N-c1-1)][(N+c0-2*c1)]);
    Wp[(N+c0-2*c1)][(N-c1-1)] = W[(N-c1-1)][(N+c0-2*c1)];
//a++; a++;
  }

//printf("%i", a);


/*
for(diag=2; diag<=N-1; diag++)
#pragma omp parallel for
   for(row=0; row<=N-diag-1; row++){
      col = diag+row;
         for(k=row; k<col; k++){
               for(m=k+1; m <col; m++)
                        if(k-row + col - m > 2 && k-row + col - m < 30){
                                   V[row][col] = MIN(V[k][m] + EFL[row][col], V[row][col]);
                                          }
                                                 W[row][col] += MIN ( MIN(W[row][k], W[col][k+1]), W[row][col]);
                                                    if(k < col-1){
                                                         V[row][col] = MIN(W[row+1][k] + W[col-1][k+1], V[row][col]);
                                        }
                                                            }
                                                             V[row][col] = MIN( MIN (V[row+1][col-1], EHF[row][col]), V[row][col]);
                                                              W[row][col] = MIN( MIN ( MIN ( W[row+1][col], W[row][col-1]), V[row][col]), W[row][col]);
                                                               W[col][row] = W[row][col];
                                                                }


*/



}








