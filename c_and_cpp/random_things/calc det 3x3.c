#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

int **mat, i, j, det=0;

mat = (int **) malloc(3 * sizeof(int *));
for(i=0; i<3; i++)
    mat[i] = (int *) malloc(3 * sizeof(int));

for(i=0; i<3; i++)
for(j=0; j<3; j++)
scanf("%d", &mat[i][j]);

det+= (mat[2][0]*mat[0][1]*mat[1][2]);
det+= (mat[0][0]*mat[1][1]*mat[2][2]);
det+= (mat[1][0]*mat[2][1]*mat[0][2]);
det-= (mat[2][2]*mat[0][1]*mat[1][0]);
det-= (mat[0][2]*mat[1][1]*mat[2][0]);
det-= (mat[1][2]*mat[2][1]*mat[0][0]);

printf("Det = %d", det);

for(i=0; i<3; i++)
    free(mat[i]);
free(mat);


return 0;
}