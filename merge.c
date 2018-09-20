//mergesort
#include <stdio.h>
#include <time.h>
void merge_sort(int a[],int p,int r);
void merge(int a[],int p,int q,int r);
void vector(int a[],int n);
   
 
void merge_sort(int a[],int p,int r){
  int q;
  if(p<r){
       q=(p+r)/2;
       merge_sort(a,p,q);
       merge_sort(a,q+1,r);
       merge(a,p,q,r);
       }
  }
   
 //prueba
void merge(int a[],int p,int q,int r){
     int n1,n2,i,j,k;
     int infinito=1000000000;
     n1=q-p+1;
     n2=r-q;    
     int L[n1],R[n2];
     for(i=1;i<=n1;i++)
         L[i]=a[p+i-1];
     for(j=1;j<=n2;j++)
         R[j]=a[q+j];
     L[n1+1]=infinito;
     R[n2+1]=infinito;
     i=1;
     j=1;
     for(k=p;k<=r;k++){
         if(L[i]<=R[j]){
            a[k]=L[i];
            i=i+1;
            }
         else{
            a[k]=R[j];
            j=j+1;
            }
            
       }
  }   



void vector(int a[],int n){
    int i,opcion,ordenamiento,j,k,aux;
    char c;
    printf("desea dar los valores(1) o que el programa los genere(2)?:\n");
   scanf("%d",&opcion);
      if(opcion==1){
          for(i=1;i<=n;i++)
              scanf("%d",&a[i]);
         while(c!='\n')
              scanf("%c",&c);
            }
      else if(opcion==2){
             printf("desea que sea el ordenamiento sea ascendente(1), descendente(2)? por defecto aleatorio\n");
             srand(time(NULL));
             for(i=1;i<=n;i++)
                a[i]=rand()%1000000;
             scanf("%d",&ordenamiento);
             if(ordenamiento==1){
                  for(j=2;j<=n;j++){
                      k=j;
                      aux=a[j];
                      while(k>0 && aux<a[k-1]){
                          a[k]=a[k-1];
                          k--;       
                         }
                   a[k]=aux;
                   }                 
                  }
              else if(ordenamiento==2){
                    for(j=1;j<=n;j++){
                       for(k=1;k<n;k++){
                           if(a[k]<a[k+1]){
                              aux=a[k];
                              a[k]=a[k+1];
                              a[k+1]=aux;
                            }
                         }
                       }

             }
              else 
                  printf("\n");
           }
      
       else
          printf("\n");
        
      }

      
void main(){
    float total,inicio, final;
    int i,n,j;
    printf("tamaño de vector:");
    scanf("%d",&n);
    int A[n];
    vector(A,n);
    //for(j=1;j<=n;j++)
      // printf("%d ",A[j]);
    printf("\n");
    inicio=clock();
    merge_sort(A,1,n);
    final=clock();
    //for(i=1;i<=n;i++)
      //  printf("%d ",A[i]);
    total=(final-inicio)/(double) CLOCKS_PER_SEC;
    printf("\ntiempo total:%.1f us\n",total*1000000);
      }      
        
