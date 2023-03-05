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
  // konstraktor dari classnya yang akan memberi nilai head, dan tail menjadi -1 karena isinya masih kosong 
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
  // jika queue masih kosong maka index first akan diset ke 0
  if (this->head == -1) 
  {
    this->head = 0;
  }
  // dan index lastnya akan dimajukan 1 nomor kedepan
  array[++this->tail] = value; 
}
void Queue::deQueue()
{
  // jika queue tidak kosong maka index first akan majukan 1 nomor
  if (this->tail != -1) 
  {
    this->head++;
  }
}

void Queue::display()
{
  // diloop dari index head ke firstnya dan di tampilkan masing masing
  for (int i = this->head; i <= this->tail; i++) 
  {
    cout << array[i] << " ";
  }
  cout << endl;
}
// kenapa hanya fungsi ini yang tidak memiliki <tipe data> Queue:: <nama fungsi>? karena hanya fungsi ini yanhg bukan bagian dari class Queue
void inputAneh(Queue *queue, Queue *mainQueue){
  // jika index head nya tidak sampai melewati nilai dari index lastnya (nilai index head akan selalu maju jika di deQueue)
  if (mainQueue->head <= mainQueue->tail) 
  {
    // jika nilai dari antrian utamanya atau nilai yang mau dimasukan itu berurut atau lebih besar dari nilai sebelumnya maka
    if (mainQueue->array[mainQueue->head] > queue->array[queue->tail]) 
    {
      // nilainya akan dimasukan kedalam queue
      queue->enQueue(mainQueue->array[mainQueue->head]);
      // dan queue utamanya akan di deQueue karena nilainya telah diambil
      mainQueue->deQueue();                              
    }
  }
}
int main()
{
  Queue mainQueue; 
  int N;           
  cout << "Masukan Jumlah N : ";
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int Xi;
    cout << "Masukan Nilai X" << i + 1 << " : ";
    cin >> Xi;
    // masing masing nilai akan dimasukan sementara kedalam queue utama
    mainQueue.enQueue(Xi); 
  }
  // deklarasikan 3 antrian yang akan menampung nilai yang berurut
  Queue antrian[3]; 

  // masing masing antrian akan menerima input
  for (int i = 0; i < 3; i++) 
  {
    // jika antrian [i] masih kosong maka akan diisi dulu agar mempunyai nilai awal dan bisa dibandingkan diatas
    if (antrian[i].tail == -1) 
    {
      antrian[i].enQueue(mainQueue.array[mainQueue.head]);
      // setiap kali menginputkan nilai dari queue utamanya maka queue utamanya juga akan didequeue
      mainQueue.deQueue(); 
    }
    while (mainQueue.array[mainQueue.head] > antrian[i].array[antrian[i].tail] && (mainQueue.head <= mainQueue.tail)) // dan diloop selama nilai yang mau diinput ke dalam antrian [i] lebih besar daripada value akhir dari antrian[i] dan selama index headnya tidak melebihi index tailnya maka antrian[i] akan di enque terus
    {
      inputAneh(&antrian[i], &mainQueue);
    }
  }
  // dicek ulang lagi, terkadang ada angka yang tersisa di queue utama namun masih bisa masuk ke salah satu antrian [i]
  {
  for (int i = 0; i < 3; i++) 
    inputAneh(&antrian[i], &mainQueue);
  }
  // sebagai index
  int i = 0; 

// selama headnya tidak melebihi tailnya (index) atau yang artinya masih ada nilai di dalam queue utamanya maka nilai yang ada di dalam antrian 1,2,3 akan dihapus dimulai dari yang paling kecil
  while (mainQueue.head < mainQueue.tail) 
  {
    // nested if ini untuk case antrian [i]
    if (antrian[i].array[antrian[i].head] > antrian[i + 1].array[antrian[i + 1].head]) 
    {
      if (antrian[i].array[antrian[i].head] > antrian[i + 2].array[antrian[i + 2].head])
      {
        if (antrian[i + 1].array[antrian[i + 1].head] > antrian[i + 2].array[antrian[i + 2].head])
        {
          antrian[i + 2].deQueue();
          mainQueue.deQueue();
        }
        else
        {
          antrian[i + 1].deQueue();
          mainQueue.deQueue();
        }
      }
      else
      {
        antrian[i].deQueue();
        mainQueue.deQueue();
      }
    }
    // nested else if ini untuk case antrian [i+1]
    else if (antrian[i + 1].array[antrian[i + 1].head] > antrian[i + 2].array[antrian[i + 2].head] && antrian[i + 2].head != antrian[i + 2].tail + 1) 
    {
      if (antrian[i + 1].array[antrian[i + 1].head] > antrian[i].array[antrian[i].head])
      {
        if (antrian[i + 2].array[antrian[i + 2].head] > antrian[i].array[antrian[i].head])
        {
          antrian[i].deQueue();
          mainQueue.deQueue();
        }
        else
        {
          antrian[i + 2].deQueue();
          mainQueue.deQueue();
        }
      }
      else
      {
        antrian[i + 1].deQueue();
        mainQueue.deQueue();
      }
    }
    // nested else if ini untuk case antrian [i+2]
    else if (antrian[i + 2].array[antrian[i + 2].head] > antrian[i].array[antrian[i].head]) 
    {
      if (antrian[i + 2].array[antrian[i + 2].head] > antrian[i + 1].array[antrian[i + 1].head])
      {
        if (antrian[i].array[antrian[i].head] > antrian[i + 1].array[antrian[i + 1].head])
        {
          antrian[i + 1].deQueue();
          mainQueue.deQueue();
        }
        else
        {
          antrian[i].deQueue();
          mainQueue.deQueue();
        }
      }
      else
      {
        antrian[i + 2].deQueue();
        mainQueue.deQueue();
      }
    }
    // kondisi jika ada yang sama nilai terkecilnya
    if (antrian[i + 1].array[antrian[i + 1].head] > antrian[i].array[antrian[i].head] && antrian[i + 2].head > antrian[i + 2].tail)
    {
      antrian[i].deQueue();
    }
    else if (antrian[i + 1].array[antrian[i + 1].head] > antrian[i + 2].array[antrian[2].head] && antrian[i].head > antrian[i].tail)
    {
      antrian[i + 2].deQueue();
    }
  }
  // print data yang sudah di olah sesuai arahan soal
  cout << "Data Telah di proses!\n"; 
  for (int i = 0; i < 3; i++)
  {
    cout << "Antrian ke-" << i + 1 << ":\n";
    antrian[i].display();
  }
  return 0;
}5