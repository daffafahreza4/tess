#include <iostream>
using namespace std;

int main(){
    int M[3][4]={{1,2,3,4},{5,6,7,8},{9,8,7,6}};
    int MTranspose[3][4];
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            MTranspose[j][i] = M[i][j];
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout << MTranspose[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}





