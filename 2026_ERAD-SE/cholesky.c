for (k = 0; k < N; k++) {
  |\color{dpotrfcolor}\textbf{DPOTRF}|(RW,A[k][k]);
  for (i = k+1; i < N; i++)
    |\color{dtrsmcolor}\textbf{DTRSM}|(RW,A[i][k], R,A[k][k]);
  for (i = k+1; i < N; i++) {
    |\color{dsyrkcolor}\textbf{DSYRK}|(RW,A[i][i], R,A[i][k]);
    for (j = k+1; j < i; j++)
      |\color{dgemmcolor}\textbf{DGEMM}|(RW,A[i][j],
	     R,A[i][k], R,A[j][k]);
  }
}
