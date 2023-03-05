#include <iostream>
using namespace std;
#define maksIndex 100
// menggunakan class untuk mengimpelemtasikan stack
class Stack           
{
//mendeklarasikan fungsi-fungsi yang digunakan
public:
    int top;               
    char array[maksIndex]; 
    Stack()                
    {
        top = -1;
    }
    void push(char Charstr);       
    void pop();                    
    void reverseDisplay();         
    void filterAneh(char Charstr); 
};
void Stack::push(char Charstr)
{
    // membuat kosndisi jika stack belum penuh
    if (this->top < maksIndex) 
    {
        // masukan nilai kedalam stack dan index top akan bertambah 1
        array[++this->top] = Charstr; 
    }
}
void Stack::pop()
{
    // index top akan decrement sebanyak 1
    array[this->top--]; 
}
void Stack::filterAneh(char Charstr)
{
    // memanggil fungsi push untuk memasukan char
    if (Charstr >= '0' && Charstr <= '9')
    {
        push(Charstr);
    }
    // jika ada _ (underscore) setelah inputan angka makahapus angka tsb 
    else if (Charstr == '_') 
    {
        pop(); // pop stack
    }
}
// menampilkan stack dari top
void Stack::reverseDisplay()
{
    for (int i = this->top; i >= 0; i--) 
    {
        cout << array[i];
    }
    cout << endl;
}
int main()
{
    //mendeklarasikan banyak Kasus dari stack dan deklarasiarray dari classnya sesuai jumlah kasus
    int banyakKasus;
    cout << "Masukan Jumlah Kasus (0 <= Kasus <= 50) : ";
    cin >> banyakKasus;
    Stack stack[banyakKasus]; 
    for (int i = 0; i < banyakKasus; i++)
    {
        cout << "Masukan String Aneh : ";
        string str;
        cin >> str;
        // melakukan nested dan filter agar menerima inputan angka saja
        for (int j = 0; j < str.size(); j++) 
        {
            stack[i].filterAneh(str[j]);
        }
    }
    // Menampilkan output
    for (int i = 0; i < banyakKasus; i++)
    {
        stack[i].reverseDisplay();
    }
    return 0;
}