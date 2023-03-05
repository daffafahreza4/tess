#include <iostream>
using namespace std;

#define maxsize 100 
// menggunakan class untuk mengimplementasikan stack
class Queue 
{
// di set ke public supaya bisa diakses
//deklarasikan semua fungsi yang digunakan
public:                             
    int head, tail, array[maxsize]; 
    Queue()                        
    {
        head = -1;
        tail = -1;
    }
    void enQueue(int value); 
    void deQueue();          
    void display();          
};

void Queue::enQueue(int value)
{
    // buat kosndisi dimana jika queue masih kosong maka index first akan diset ke 0
    if (this->head == -1) 
    {
        this->head = 0;
    }
    // index lastnya akan diincrementkan 1 nomor kedepan
    array[++this->tail] = value; 
}
void Queue::deQueue()
{
    // jika queue tidak kosong maka index first akan diincrementkan 1 nomor
    if (this->tail != -1) 
    {
        this->head++;
    }
}
void Queue::display()
{
    // melakukan loop dari index head ke firstnya dan di tampilkan masing masing
    for (int i = this->head; i <= this->tail; i++) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue mainQueue; 
    int max, N;      
    cout << "Masukan Jumlah Queue: ";
    cin >> max;
    cout << "Masukan Jumlah N: ";
    cin >> N;
    // inputkan semua nilai sementara ke dalam mainQueue
    for (int i = 0; i < max; i++) 
    {
        int x;
        cout << "Masukan Queue ke-" << i + 1 << ": ";
        cin >> x;
        mainQueue.enQueue(x);
    }
    
    Queue queue[N];             
    for (int i = 0; i < N; i++) 
    {
        // setiap queue bagian ini memiliki maksimal index yang didapat dari hasil maksimal index queue utama dibagi jumlah queue bagian
        for (int j = 0; j < max / N; j++) 
        {
            // nilai yang diinputkan berasal dari queue utama
            // dan queue utamanya didequeue karena nilainya sudah diambil
            queue[i].enQueue(mainQueue.array[mainQueue.head]); 
            mainQueue.deQueue();                               
        }
    }
    // tampiljan semua queue bagian
    for (int i = 0; i < N; i++) 
    {
        cout << "Queue ke-" << i + 1 << " :\n";
        queue[i].display();
    }
}