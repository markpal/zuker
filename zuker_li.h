void zuker_li()
{
int i,j,k,m;
int diag,row,col;


for(diag=2; diag<=N-1; diag++)
#pragma omp parallel for shared(diag) private(col, row, k, m)
   for(row=0; row<=N-diag-1; row++){
      col = diag+row;
         for(k=row; k<col; k++){
               for(m=k+1; m <col; m++)
                        if(k-row + col - m > 2){
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
                                                                
                                                                




}








