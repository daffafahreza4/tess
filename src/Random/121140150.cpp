//KevinSimorangkir
//RC
//121140150

#include<iostream>

using namespace std;

//Tugas IV RC ASD

/*
   1. Berdasarkan Video Rekaman Kelas RD di Pertemuan ke 4 di waktu video 1:41:58,
      Pak Eko menjelaskan mengenai sebuah parameter terkait Pointer Hapus (*hapus)
      yang mana digunakan mengambil sebuah data berupa nilai - nilai yang terdapat
      pada list tersebut yang akan dihapus
    
   2. Berdasarkan Video Rekaman Kelas RD di Pertemuan ke 4 di waktu video 1:59:05 
      Pak Eko menjelaskan tentang variabel predTemp, dan temp pada DeleteLast, 
      temp akan menjadi first dengan data yang sama sedangkan predTemp akan diset 
      NULL, setelah itu ditelusuri dimana letak last selama tidak ditemukan NULL maka 
      akan terus ditelusuri setelah itu alamat setelahnya akan masuk ke predTemp. Jika 
      temp sama dengan alamat awal, maka dilakukan deleteFirst, jika tidak sama maka 
      lakukan deleteAfter yang mana dimasukkan parameternya yakni predTemp.

   3. Program Single Linked List :
 | | | | | | | | | | |
    | | | | | | | | | | |
    v v v v v v v v v v v 
*/

struct singleLinkedList
{
    //komponen / member
    int bilangan;

    singleLinkedList *next;

};

singleLinkedList *head, *tail, *cur, *newNode, *del, *before;


class singleLinkedList_Class
{
    public:

    //create Single Linked List
    void createSingleLinked_List (int bilangan)
    {
        head = new singleLinkedList();
        head->bilangan = bilangan;
        head->next = NULL;
        tail = head;
    }

    //menghitung banyak list
    int countSingleLinked_List ()
    {
        cur = head;
        int sum = 0;
        while (cur != NULL)
        {
            sum++;
            cur = cur->next;
        }
        return sum;
    }

    //addFirst single linked list
    void addFirst (int bilangan)
    {
        newNode = new singleLinkedList();
        newNode->bilangan = bilangan;
        newNode->next = head;
        head = newNode;
    }

    //addMid single linked list
    void addMid (int bilangan, int position)
    {
        if (position < 1 || position > countSingleLinked_List())
        {
            cout << "Posisi diluar Jangkauan" << endl;
        }
        else if (position == 1)
        { 
        cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            newNode = new singleLinkedList();
            newNode->bilangan = bilangan;
            //trasversing
            cur = head;
            int num = 1;
            while (num < position - 1)
            {
                cur = cur->next;
                num++;
            }

            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    //addLast single linked list
    void addLast (int bilangan)
    {
        newNode = new singleLinkedList();
        newNode->bilangan = bilangan;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }


    //removeFirst
    void deleteFirst ()
    {
        del = head;
        head = head->next;
        delete del;
    }

    //removeMiddle
    void deleteMid (int position)
    {
        if (position < 1 || position > countSingleLinked_List())
        {
            cout << "Posisi diluar Jangkauan" << endl;
        }
        else if (position == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            int num = 1;
            cur = head;
            while (num <= position)
            {
                if (num == position - 1)
                {
                    before = cur;
                }
                if (num == position)
                {
                    del = cur;
                }
                cur = cur->next;
                num++;
            }
            before->next = cur;
            delete del;
        }
    }

    //removeLast
    void deleteLast ()
    {
        del = tail;
        cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        tail = cur;
        tail->next = NULL;
        delete del;
    }

    //changeFirst
    void changeFirst (int bilangan)
    {
        newNode->bilangan = bilangan;
    }

    //changeMid
    void changeMid (int bilangan, int position)
    {
        if (position < 1 || position > countSingleLinked_List())
        {
            cout << "Posisi diluar Jangkauan" << endl;
        }
        else if (position == 1 || position == countSingleLinked_List())
        {  
            cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            cur = head;
            int num = 1;
            while (num < position)
            {
                cur = cur->next;
                num++;
            }
            cur->bilangan = bilangan;
        }
    }

    //changeLast
    void changeLast (int bilangan, int tB)
    {
        tail->bilangan = bilangan;
    }

    //print Single Linked List
    void printSingleLinked_List ()
    {
        cout << "Jumlah data ada : " << countSingleLinked_List() << endl;
        cur = head;
        while (cur != NULL)
        {
            cout << cur->bilangan << " | ";
            cur = cur->next;
        }
    }
};

singleLinkedList_Class bilanganBulat;

int main()
{
    bilanganBulat.createSingleLinked_List(4);
    bilanganBulat.addFirst(1);
    bilanganBulat.addLast(5);
    bilanganBulat.addMid(2,2);
    bilanganBulat.addMid(3,3);
    bilanganBulat.deleteMid(2);
    bilanganBulat.printSingleLinked_List();

    return 0;
}