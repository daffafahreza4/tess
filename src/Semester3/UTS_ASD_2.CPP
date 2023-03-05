#include <iostream>
using namespace std;

string aneh(int x){
    if ( x <= 0)
        return "0";
    else if ( x == 1)
        return "1";
    else 
        return aneh (x-1) + aneh (x/2);

}

int main (){
    cout << aneh (10);
}