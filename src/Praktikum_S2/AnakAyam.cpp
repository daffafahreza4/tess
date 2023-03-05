#include <iostream>
using namespace std;


int main() {
    int n, x = 1;
    cout << "Masukan pengulangan yang diinginkan : ";
    cin >> n;
    
    for(int i = 0; i<n ;i++){
        if(i == 0){
            cout<<"Tek kotek kotek kotek anak ayam turun "<< x<< endl;
        }else{
            cout<<"Tek koteks kotek kotek belah diri jadinya "<< x<< endl;
            cout<<"Tek kotek kotek kotek anak ayam turun "<< x<< endl;
        }
        x = x*2;
    }
    cout<<"Mati satu tinggal induknya";
    return 0;
}