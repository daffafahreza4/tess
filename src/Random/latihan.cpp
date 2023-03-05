#include <iostream>
using namespace std;

struct mahasiswa{
        int nim;
        string nama;   
        string matkul;
        int sks;
        string hurufmutu;
        float mutunilai;
        
    };
    
    int main()
    
    {   int n, cari;
        cout<<"Jumlah Mahasiswa : ";
        cin>>n;
        cout<<"\n";
        mahasiswa x[n];
        
        for (int i=0;i<n;i++){
            cout<<"Data Mahasiswa ke-"<<i+1<<"\n";
            cout<<"NIM\t\t : ";
            cin>>x[i].nim;
            cout<<"Nama\t\t : ";
            cin.ignore();
            getline(cin,x[i].nama);
            cout<<"Nama Mata Kuliah : ";
            getline(cin,x[i].matkul);
            cout<<"SKS\t\t : ";
            cin>>x[i].sks;
            cout<<"Huruf Mutu\t : ";
            cin>>x[i].hurufmutu;
            if (x[i].hurufmutu=="A"){
                x[i].mutunilai=4*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="AB"){
                x[i].mutunilai=3.5*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="B"){
                x[i].mutunilai=3*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="BC"){
                x[i].mutunilai=2.5*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="C"){
                x[i].mutunilai=2*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="D"){
                x[i].mutunilai=1*x[i].sks;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            else if (x[i].hurufmutu=="E"){
                x[i].mutunilai=0;
                cout<<"Nilai KSM\t : "<<x[i].mutunilai;
            }
            cout<<"\n\n";
    }
    
    	for(int i=0; i<n; i++){
    		for(int j=i+1; j<n; j++){
    		if(x[i].nim == x[j].nim){
    			x[i].sks += x[j].sks;
    			x[i].mutunilai += x[j].mutunilai;
			}
		}
	}
    cout<<"NIM yang akan dicari : ";
    cin>>cari;
    
     for (int i=0;i<n;i++){
    		if(cari==x[i].nim){
    			cout<<"NIM ditemukan atas nama "<<x[i].nama<<" dengan NR = "<<x[i].mutunilai/x[i].sks;
    			break;
		}
			  else if (cari!=x[i].nim and n==(i+1)){
                cout<<"NIM tidak dtemukan";
            }
	}
   
   }
