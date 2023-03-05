#include<iostream>
using namespace std;

struct pembeli{
    string nama;
    string tanggalLahir;
    int nik;
};

int main(){
    int pilihan;
    string destinasi;
    long biaya, total;
    biaya=0; total=0;

    cout << "\t\t\t\tPROGRAM AGEN TRAVEL\n\n";

tujuan:
    cout << "Pilih destinasi perjalanan anda :" << endl;
    string A[5]={"Sabang","Jakarta","Jogja","Bali","Raja Ampat"};
        for(int i=0; i<5; i++){
            cout << i+1 << ". " << A[i] << endl;
        }
        cout << "Masukkan Pilihan : ";
            cin >> pilihan;
            switch(pilihan){
                case 1:
                    biaya=1000000;
                    destinasi=A[0];
                    break;
                case 2:
                    biaya=450000;
                    destinasi=A[1];
                    break;
                case 3:
                    biaya=700000;
                    destinasi=A[2];
                    break;
                case 4:
                    biaya=2300000;
                    destinasi=A[3];
                    break;
                case 5:
                    biaya=4000000;
                    destinasi=A[4];
                    break;
                default:
                    cout << "Pilihan tidak ditemukan\n";
                    goto tujuan;
            }
cout << "------------------------------------" << endl;
kendaraan:
    cout << "\nPilih pilihan tiket perjalanan anda :" << endl;
    string transportasi;
    string B[3]={"Bis","Kereta Api","Pesawat"};
        for(int i=0; i<3; i++){
            cout << i+1 << ". " << B[i] << endl;
        }
   		cout << "Masukkan Pilihan : ";
            cin >> pilihan;
            switch(pilihan){
                case 1:
                    transportasi=B[0];
                    break;
                case 2:
                    biaya+=200000;
                    transportasi=B[1];
                    break;
                case 3:
                    biaya+=500000;
                    transportasi=B[2];
                    break;
                default:
                    cout << "Pilihan tidak ditemukan\n";
                    goto kendaraan;
            }
 cout << "------------------------------------" << endl;   
kelas:
    cout << "\nPilih kelas kursi yang anda inginkan :" << endl;
    string kursi;
    string C[3]={"Ekonomi","Bisnis","Eksekutif"};
        for(int i=0; i<3; i++){
            cout << i+1 << ". " << C[i] << endl;
        }
    	cout << "Masukkan Pilihan : ";
            cin >> pilihan;
            switch(pilihan){
                case 1:
                    kursi=C[0];
                    break;
                case 2:
                    biaya+=250000;
                    kursi=C[1];
                    break;
                case 3:
                    biaya+=600000;
                    kursi=C[2];
                    break;
                default:
                    cout << "Pilihan tidak ditemukan\n";
                    goto kelas;
            }
cout << "------------------------------------" << endl;
waktu:
    cout << "\nPilih tanggal Keberangkatan" << endl;
        string tanggal;
        cin.ignore();
        getline(cin, tanggal);
cout << "------------------------------------" << endl;
tiket:
    cout << "Berapa jumlah tiket yang anda inginkan : ";
        int jumlah;
        cin >> jumlah;
        total = biaya*jumlah;
        data:
        pembeli data[jumlah];
            for(int i=0; i<jumlah; i++){
                cout << "\nMasukkan Nama Penumpang "<< i+1 << " : ";
                cin.ignore();
                getline(cin, data[i].nama);
                
                cout << "Masukkan Tanggal Lahir penumpang " << i+1 << " : ";
                getline(cin, data[i].tanggalLahir);
                
                cout << "Masukkan NIK Penumpang " << i+1 << " : ";
                cin >> data[i].nik;
            }
cout << "------------------------------------" << endl;
cek:
    cout << "\nMohon Cek Kembali Pesanan Anda";
    cout << "\nDestinasi Anda\t: " << destinasi;
    cout << "\nTransportasi Anda\t: " << transportasi;
    cout << "\nJenis Kursi Anda\t: " << kursi;
    cout << "\nTanggal Keberangkatan Anda\t: " << tanggal;
    cout << "\nData Penumpang :";
        for(int i=0; i<jumlah; i++){
            cout << "\n\tNama Penumpang " << i+1 << " \t: " << data[i].nama;
            cout << "\n\tTanggal Lahir Penumpang " << i+1 << " \t: " << data[i].tanggalLahir;
            cout << "\n\tNIK Penumpang " << i+1 << " \t: " << data[i].nik;
        }
    cout << "\nHarga Tiket\t: Rp. " << biaya;
    cout << "\nTotal Rp. " << total;

cout << " TERIMA KASIH TELAH MENGGUNAKAN TRAVELOLA";
return 0;
}
