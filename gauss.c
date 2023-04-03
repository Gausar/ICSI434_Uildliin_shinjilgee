#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void print_array(int n, int m, bool *b, double **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] || j == m - 1) printf("%f ", a[i][j]);
        }
        printf("\n");
    }   
}

void huvirgalt(int n, int m, int r, int s, double **a) {
    double b[n][m];
    b[r][s] = - 1 / a[r][s];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == r) {
                b[r][j] = (-a[r][j] / a[r][s]);
            }
            else if (j == s) {
                b[i][s] = a[i][s] / a[r][s];
            }
            else {
                b[i][j] = (a[i][j] * a[r][s] - a[i][s] * a[r][j]) / a[r][s];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

int main() {
    int n, m;

    printf("Heden system oruulah ve?\n");
    scanf("%d", &n);

    printf("Heden huvisagchtai ve?\n");
    scanf("%d", &m);

    m++;

    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(m * sizeof(double));
    }

    bool *bagana = (bool *)malloc(m * sizeof(bool));
    int mur[n];

    printf("Husnegt oruulna uu\n");
    for (int i = 0; i < n; i++) {
        mur[i] = -1;    
        for (int j = 0; j < m; j++) {
            bagana[j] = true;
            scanf("%lf", &a[i][j]);
        }
    }
    bagana[m - 1] = false;

    printf("1-r husnegt:\n");
    print_array(n, m, bagana, a);
    
    int f = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bagana[j] && a[i][j] != 0) {
                huvirgalt(n, m, i, j, a);
                bagana[j] = false;
                mur[i] = j;
                break;
            }
        }
        if (mur[i] == -1 && a[i][m - 1] != 0) {
            printf("Etssiin hariu: Niitsgui\n");
            f = 0;
            break;
        }
        printf("%d-r husnegt:\n", i + 2); 
        print_array(n, m, bagana, a);
    }
    if (f == 1) {
        printf("Etssiin hariu : ");
        for(int i=0; i < n; i++){
            if(mur[i] != -1){
                printf("\nx%d = ",mur[i]+1);
                int k=0;
                for(int j=0; j<m; j++){
                    if(bagana[j] == true && a[i][j] != 0){
                        if(a[i][j] > 0 && k != 0){
                            printf("+");
                        }
                        k = 1;
                        printf("%lf*x%d", a[i][j], j+1);
                    }
                    else if(j == m - 1){
                        if(a[i][j] > 0 && k!=0){
                            printf("+");
                        }
                        k = 1;
                        printf("%f", a[i][j]);
                    }
               
                }
            }
        }
    }
    free(a);
    return 0;
}