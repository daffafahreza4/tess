#include <iostream>
using namespace std;

void kali(int *a, int *b, int *c){
	*a=*a*2;
	*b=*b*2;
	*c=*c*2;
}

int main (){
    int a, b, c;

    cout << "Masukan nilai a : ";
    cin >> a;
    cout << "Masukan nilai b : ";
    cin >> b;
    cout << "Masukan nilai c : ";
    cin >> c;
    
    kali (&a, &b, &c);

    cout << "Nilai a setelah diubah : " << a << endl;
    cout << "Nilai b setelah diubah : " << b << endl;
    cout << "Nilai c setelah diubah : " << c << endl;
}