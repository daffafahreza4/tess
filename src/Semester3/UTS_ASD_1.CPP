#include <iostream>
using namespace std;

struct mahasiswa {
    int nim;
    string nama, prodi, jenjang;
    float ipk;
}mhs;

int main (){
    mhs;

    for (i=0, i<n, i++){
    cin >> n;
    cout << "Masukkan NIM : ";
    cin >> mhs.nim;
    cout <<"Masukkan nama: ";
    cin.ignore();
    getline (cin, mhs.nama);
    cout <<"Masukkan Program Studi: ";
    cin.ignore();
    getline (cin, mhs.prodi);
    cout <<"Masukkan Jenjang: ";
    cin >> mhs.jenjang;
    cout <<"Masukkan IPK: ";
    cin >> mhs.ipk;

    cout << "NIM: "<< mhs.nim << endl;
    cout << "Nama: "<< mhs.nama << endl;
    cout << "Program Studi: "<< mhs.prodi << endl;
    cout << "Jenjang: "<< mhs.jenjang << endl;
    cout << "IPK : "<< mhs.ipk << endl;

    }
    
    
    

    
};
