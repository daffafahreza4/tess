#include <iostream>
using namespace std;

void tukar(int *a, int *b){

int tmp;
tmp = *a;
*a = *b;
*b = tmp;}

    int main (){
        int a,b,n=9;
        int nim[n]={1,2,1,1,4,0,1,7,8};
        int idx;
        for (int i=n-1;i>0;i--){
            idx=0;
            for (int j=1;j<=i;j++){
                if (nim[j]<nim[idx]){
                    idx=j;
                }
            }
            tukar (&nim[i],&nim[idx]);
        }
        cout<<endl<<"Setelah Pengurutan Menurun : ";
        for (int i=0;i<n;i++){
            cout<<nim[i]<<" ";
        }
    }