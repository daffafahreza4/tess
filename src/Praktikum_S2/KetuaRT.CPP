#include <iostream>
using namespace std;
int main() {
    int n, UMax, UMin, usia = -1;
    int ketua[n];
    cin >> n;
    cin >> usia;
    cin >> UMin;
    
    for (int i = 0; i < n; i++){
        cin >> ketua[i];
    }
    
    for (int i = 0; i < n; i++){
        if (ketua[i] >= usia && ketua[i] <= UMin){
            if(ketua[i] >= usia ){
            usia = ketua[i];
            }    
        }   
    }
    cout << usia;
    return 0;
}