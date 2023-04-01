#include<stdio.h>
#include<math.h>
int main(){
	//i-moriin dugaar
	//j baganii dugaar
	//n- moriin too
	//m- baganii too
    int i,j,n,m,r,s;
    float golelement;
    printf(" moriin too n = ");
    scanf("%d",&n);
    printf("baganii too m = ");
    scanf("%d",&m);
    
	float A[n][m+1], B[n][m+1];
	
    printf("Matrixiin mor baganii tohiroh elementuudee oruulna uu:\n");
    for(i=0; i<n; i++){
        for(j=0; j<(m+1); j++){
            printf("A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        } 
    }
    
    printf("Husnegt 1\n");
    for(i=0;i<n;i++){
    	for(j=0;j<m+1;j++){
    		printf("%.4f\t",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nB husnegted utgaa hadgalaw\n\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<m+1;j++){
			B[i][j]=A[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m+1;j++){
			printf("%.4f\t",B[i][j]);
		}
		printf("\n");
	}
	
	if(n>=m){
		int k=-1;
		for(r=0;r<n;r++){
			
			for(s=k+1;s<m+1;s++){
				
				if(A[r][s]!=0){
					golelement=A[r][s];
					
					printf(" \n---> golelemenet = %.4f\n",golelement);
				
					for(i=0;i<n;i++){
						for(j=0;j<m+1;j++){
							if(i==r){
								if(j==s){
									A[i][j]=1/B[i][j];	
								}
								if(j!=s){
									A[r][j]=B[r][j]/golelement;
								}
							}
							if(j==s){
								if(i==r){
								}
								else{
									A[i][j]=-B[i][j]/golelement;	
								}	
							}
							if(j!=s&&i!=r){
								A[i][j]=B[i][j]-B[r][j]*B[i][s]/golelement;
							}
						}
					}
					s=m+1;
				}
				else{
					
				}
			}
			for(i=0;i<n;i++){
				for(j=0;j<m+1;j++){
					B[i][j]=A[i][j];
				}
			}
			printf("\nhusnegt %d\n",r+2);
			
			for(i=0;i<n;i++){
				for(j=r+1;j<m+1;j++){
					printf("%.4f\t",B[i][j]);
				}
				printf("\n");
			}
			k=k+1;
			for(i=0;i<n;i++){
				int p = 0;
				for(j=0;j<m+1;j++){
					if(B[i][j]==0){
						p++;
					}
				}
				if(p==m){
					printf("niitsgui\n");
				}
				if(p==m+1){
					printf("bodlogo togsgolgui olon shiidtei bn\n");
				}
			}
			int q=0;
			for(j=0;j<m+1;j++){
				for(i=0;i<n;i++){
					if(B[i][j]==0){
						q++;
					}
				}
				if(q==n){
					printf("shiidggui\n");
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=n;j<m+1;j++){
				printf("x1 = %.4f\n",B[i][j]);
			}
			printf("\n");
		}
	}
	
	if(n<m){
		int k=-1;
		for(r=0;r<n;r++){
			
			for(s=k+1;s<m+1;s++){
				
				if(A[r][s]!=0){
					golelement=A[r][s];
					
					printf(" \n--->> golelement = %.4f\n",golelement);
					
					for(i=0;i<n;i++){
						for(j=0;j<m+1;j++){
							if(i==r){
								if(j==s){
									A[i][j]=1/B[i][j];	
								}
								if(j!=s){
									A[r][j]=B[r][j]/golelement;
								}
							}
							if(j==s){
								if(i==r){
								}
								else{
									A[i][j]=-B[i][j]/golelement;	
								}	
							}
							if(j!=s&&i!=r){
								A[i][j]=B[i][j]-B[r][j]*B[i][s]/golelement;
							}
						}
					}
					s=m+1;
				}
			}
			for(i=0;i<n;i++){
				for(j=0;j<m+1;j++){
					B[i][j]=A[i][j];
				}
			}
			printf("\nhusnegt %d\n",r+2);
			
			for(i=0;i<n;i++){
				for(j=r+1;j<m+1;j++){
					printf("%.4f\t",B[i][j]);
				}
				printf("\n");
			}
			k=k+1;
			for(i=0;i<n;i++){
				int p=0;
				for(j=0;j<m+1;j++){
					if(B[i][j]==0){
						p++;
					}
				}
				if(p==m-1){
					printf("niitsgui\n");
				}
				if(p==m+1){
					printf("bodlogo togsgolgui olon shiidtei bn\n");
				}
				
				if(n==2&&m==3){
					for(i=0;i<n;i++){
						for(j=m-1;j<m;j++){
							printf("x[%d] = %.4f * x3 + %.4f\n",i+1,B[i][j],B[i][j+1]);
						}
						printf("\n");
					}
				}
			}
			
			for(j=0;j<m+1;j++){
				int q=0;
				for(i=0;i<n;i++){
					if(B[i][j]==0){
						q++;
					}
				}
				if(q==n-1){
					printf("niitsgui\n");
				}
				if(q==n){
					printf("shiidgui\n");
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=3;j<m;j++){
				printf("x[%d] = %.4f * x4 + %.4f\n",i+1,B[i][j],B[i][j+1]);
			}
			printf("\n");
		}
	}
	return 0;
}
