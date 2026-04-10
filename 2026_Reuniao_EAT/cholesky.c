for (k = 0; k < N; k++) {
   |\color{dpotrfcolor}\textbf{DPOTRF}|(|\underline{RW}|, A[k][k]);
   for (i = k+1; i < N; i++)
     |\color{dtrsmcolor}\textbf{DTRSM}|(|\underline{RW}|, A[i][k], |\underline{R}|, A[k][k]);
   for (i = k+1; i < N; i++) {
     |\color{dsyrkcolor}\textbf{DSYRK}|(|\underline{RW}|, A[i][i], |\underline{R}|, A[i][k]);
     for (j = k+1; j < i; j++)
        |\color{dgemmcolor}\textbf{DGEMM}|(|\underline{RW}|, A[i][j], |\underline{R}|, A[i][k],
                           |\underline{R}|, A[j][k]);
   }
}
