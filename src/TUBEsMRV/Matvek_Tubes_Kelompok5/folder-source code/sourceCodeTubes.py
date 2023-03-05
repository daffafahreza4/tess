import numpy as np

# deklarasi fungsi-fungsi

def show_SPL(matriks, row, column, variable):
    # tujuan : menampilkan SPL dari inputan user
    for i in range(row): 
        status = False
        for j in range(column):
            if j < column-1:
                # jika nilai suku = 0, maka tidak tampil
                if matriks[i][j] != 0:
                    if status == True:
                        # otomatis memilih keluaran plus atau minus pada console
                        if matriks[i][j] > 0:
                            print(" +", end="")
                        else:
                            print(" ", end="")
                    print(" {}{}".format(matriks[i][j], variable[j]), end="")
                    status = True
            else:
                if status == True:
                    print(" =", matriks[i][j])



def show_matriks(matriks, row, column):
    # tujuan : menampilkan Matriks dari inputan user
    for i in range(row):
        print(" [", end="")
        for j in range(column):
            # jika bukan 0, maka setiap matriks akan disederhanakan menjadi hanya 2 angka dibelakang koma
            if matriks[i][j] != 0:
                matriks[i][j] = round(matriks[i][j], 2)
            # jika bagian hasil atau perulangan kolom terakhir, maka tampil garis augmented
            if j == column-1:
                print(" |", end="")
            # keluarin nilai matriks
            print(" {}".format(matriks[i][j]), end="")
        print(" ]")


def gauss(matriks, row, column, i=0, z=0):
    # tujuan : memproses matriks dengan metode eleminasi gauss
    # jika i dan z sesuai dengan syarat posisi matriks
    if i < row:
        if z < column-1:
            # jika nilai suku matriks = 0, maka sorting dengan yang memiliki angka
            if matriks[i][z] == 0:
                for j in range(i+1, row):
                    # jika angka atau bukan nol, maka "tukar"
                    if matriks[j][z] != 0:
                        for k in range(column):
                            # "tukar" = seluruh baris matriks 1 dengan yang lain
                            matriks[i][k], matriks[j][k] = matriks[j][k], matriks[i][k]
                        # menampilkan info proses sistem penukaran
                        print("="*50)
                        print("R{} =><= R{}".format(i+1, j+1))
                        show_matriks(matriks, row, column)

                        break
            # setelah sorting, jika suku matriks != 0, maka "cek satu" dan "buat satu"
            if matriks[i][z] != 0:
                # jika matriks tidak 1, maka "eliminasi jadi satu"
                if matriks[i][z] != 1:
                    # "eliminasi jadi satu"
                    temp = matriks[i][z]
                    for j in range(z, column):
                        matriks[i][j] /= temp
                    # manmpilkan info sistem eliminasi jadi satu
                    print("="*50)
                    print("R{} / {}".format(i+1, temp))
                    show_matriks(matriks, row, column)
                # "buat satu" -> membuat hanya ada satu nilai dalam satu kolom
                for j in range(i+1, row):
                    if matriks[j][z] != 0:
                        # jika matriks tidak nol, maka lakukan eliminasi dengan matriks yang bernilai awal 1
                        temp = matriks[j][z] / matriks[i][z]
                        for k in range(z, column):
                            matriks[j][k] = matriks[j][k] - \
                                (temp * matriks[i][k])
                        # menampilkan info sistem eliminasi agar satu nilai dalam satu kolom
                        print("="*50)
                        print("R{}".format(j+1), end="")
                        if temp > 0:
                            print(" - ", end="")
                        else:
                            print(" + ", end="")
                            temp *= -1
                        print("{}R{}".format(temp, i+1))
                        show_matriks(matriks, row, column)
                # jika proses "sorting", eliminasi "jadi satu" dan "buat satu" selesai,
                # maka panggil function "gauss" kembali dengan nilai i yang bertambah
                i += 1
                gauss(matriks, row, column, i, z)
            else:
                # jika matriks = 0, maka panggil function "gauss" dengan nilai z bertambah
                z += 1
                gauss(matriks, row, column, i, z)


def gauss_jordan(matriks, row, column, variable):
    # tujuan : melakukan proses jordan saja pada konsep eliminasi gauss-jordan
    # dibawah ini proses pengecekan apakah dia solusi unik, banyak dan tidak ada solusi
    unik = False

    for i in range(row):
        fill_status = True
        result_status = False
        for j in range(column):
            if j < column-1:
                if matriks[i][j] == 0 and fill_status == True:
                    fill_status = True
                else:
                    fill_status = False
            else:
                if matriks[i][j] == 0:
                    result_status = True
                else:
                    result_status = False
        # jika isi baris matriks bernilai 0 dan hasil baris matriks bernilai !0, maka tidak ada solusi
        if fill_status == True and result_status == False:
            print("="*50)
            print("*="+"Tidak Ada Solusi".center(48)+"=*")
            print("="*50)
            return
        # jika isi baris matriks bernilai !0 dan hasil baris matriks bernilai 0, maka banyak solusi
        elif fill_status == True and result_status == True:
            solusi = "Banyak Solusi"
            break
        # jika bukan (tidak ada solusi dan banyak solusi), maka solusi unik
        else:
            solusi = "Solusi Unik"
            unik = True

    if unik == True or (fill_status == True and result_status == True):
        # perulangan dimulai dari paling bawah (cek yang bawah terlebih dahulu)
        for i in range(row-1, -1, -1):
            for j in range(column-1):
                # jika nilai matriks !0, maka eliminasi matriks diatasnya yang sejajar
                if matriks[i][j] != 0:
                    for k in range(i-1, -1, -1):
                        # proses eliminasi matriks diatasnya yang sejajar
                        if matriks[k][j] != 0:
                            temp = matriks[k][j] / matriks[i][j]
                            for l in range(j, column):
                                matriks[k][l] -= (temp * matriks[i][l])
                            # menampilkan info sistem eliminasi yang dilakukan
                            print("="*50)
                            print("R{}".format(k+1), end="")
                            if temp > 0:
                                print(" - ", end="")
                            else:
                                print(" + ", end="")
                                temp *= -1
                            print("{}R{}".format(temp, i+1))
                            show_matriks(matriks, row, column)
                    break
        print("="*50)
        print("*="+solusi.center(48)+"=*")
        print("="*50)
        # setelah eliminasi "gauss jordan", maka mengeluarkan hasil dari setiap variabel
        for i in range(row):
            cek = False
            for j in range(column):
                if matriks[i][j] != 0 and j < column-1:
                    if cek == True:
                        print(" +", end="")
                    print(" {}".format(variable[j]), end="")
                    cek = True
            if cek == True:
                print(" = {}".format(matriks[i][j]))
    print("="*50)


print("="*52)
print("*="+"Tubes Martriks dan Ruang Vektor".center(48)+"=*")
print("*="+(48*"*").center(48)+"=*")
print("*="+"Anggota Kelompok".center(48)+"=*")
print("*="+(48*"*").center(48)+"=*")
print("*="+"Nama : Ahmad Fadillah ".center(48)+"=*")
print("*="+"NIM  : 121140173".center(48)+"=*")
print("*="+"Nama : Muhammad Daffa Fahreza".center(48)+"*")
print("*="+"NIM  : 121140178".center(48)+"=*")
print("*="+"Nama : Ghulwan Shihabuddin".center(48)+"=*")
print("*="+"NIM  : 121140164".center(48)+"=*")
print("*="+"Nama : Varell Anthonio".center(48)+"=*")
print("*="+"NIM  : 121140122".center(48)+"=*")
print("="*52)
# sebagai nilai awal agar bisa masuk ke while
user_option = "0"

while user_option != "2":
    print("*="+"Pilihan menu untuk penyelesaian (1-2)".center(48)+"=*")
    print("="*52)
    print("*="+"1.Mencari Solusi Sistem Persamaan Linear Matriks".ljust(48)+"=*")
    print("*="+"2.Keluar".ljust(48)+"*")
    print("="*52)
    user_option = input("Input Pilihan (1-2) : ")
    print("="*52)
    status_matriks = False
    # jika pilihan mencari SPL dan Matriks
    if user_option == "1":
        print("*="+"Pilihan menu untuk penyelesaian (1-3)".center(48)+"=*")
        print("="*52)
        print("*="+"1.input manual".ljust(48)+"=*")
        print("*="+"2.input file".ljust(48)+"=*")
        print("="*52)
        user_option_type = input("Input Pilihan (1-2) : ")
        print("="*52)
        if user_option_type == "1":
            # tampung input baris dan kolom SPL atau Matriks
            print("*="+"Masukkan Jumlah Baris Dan Kolom".ljust(48)+"=*")
            print("="*52)
            row = int(input("Baris : "))
            column = int(input("Kolom : "))
            print("="*52)
            column += 1
            # inisialisasi isi variabel dengan format x1,x2,x3 dan seterusnya
            variable = ["x{}".format(i+1) for i in range(column-1)]
            # inisialisasi matriks kosong sebesar baris kali kolom dengan method di numpy
            matriks = np.zeros((row, column))
            # menginputkan nilai dari tiap suku SPL atau Matriks
            for i in range(row):
                for j in range(column):
                    # jika bukan bagian hasil
                    if j < column-1:
                        # print perintah masukkan menggunakan "nama variabel"
                        print(" {} : ".format(variable[j]), end="")
                    else:
                        # print perintah masukkan untuk hasil, karena perulangan kolom yang terakhir
                        print(" Hasil {} : ".format(i+1), end="")
                    # inputan ditampung kedalam matriks dengan tipe masukan float
                    matriks[i][j] = float(input())
                    # jika bagian akhir perulangan,
                    if j == column-1:
                        print("="*52)
            status_matriks = True
        elif user_option_type == "2":
            path = ['C:/Users/ernik/Downloads/Matvek_Tubes_Kelompok5/folder-test/', ""]
            print("="*52)
            print("*="+"List nama file: ".center(48)+"=*")
            print("*="+"1. input-file-1.txt".center(48)+"=*")
            print("*="+"2. input-file-2.txt".center(48)+"=*")
            print("*="+"3. input-file-3.txt".center(48)+"=*")
            print("="*52)
            temp_input = str(input('Masukan nama file : '))
            print("*"*52)
            if temp_input != "":
                path[1]= temp_input
            full_path = ''.join(path)
            if temp_input == "input-file-1.txt" or temp_input == "input-file-2.txt" or temp_input == "input-file-3.txt":
                matriks = np.loadtxt(full_path, dtype = float, delimiter = ' ')
                [row, column] = matriks.shape
                variable = ["x{}".format(i+1) for i in range(column-1)]
                status_matriks = True
            else:
                print("="*52)
                print("=*"+"Harap masukan nama file yang sesuai dengan list diatas!".ljust(48)+"*=")
                print("="*52)
        if status_matriks == True:
            print("*="+"Sistem Persamaan Linear".center(48)+"*=")
            print("*"*52)
            show_SPL(matriks, row, column, variable)
            print("="*52)
            print("*="+"Matriks Augmented".center(48)+"*=")
            print("="*52)
            # panggil function "tampilMatriks"
            show_matriks(matriks, row, column)
            print("="*52)
            print("*="+"Proses Eliminasi Gauss".center(48)+"*=")
            print("="*52)
            # panggil function "gauss"
            gauss(matriks, row, column)
            print("="*52)
            print("*="+"Proses Eliminasi Gauss Jordan".center(48)+"=*")
            print("="*52)
            # panggil function "gauss_jordan"
            gauss_jordan(matriks, row, column, variable)

    elif user_option != "2":
        print("*="+"Inputan Salah!".center(48)+"=*")