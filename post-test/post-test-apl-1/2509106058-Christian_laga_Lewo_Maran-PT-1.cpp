#include <iostream>
using namespace std;

int main(){
    int kesempatan = 3;
    string password;
    string nama;
    string menu;
    int nilai;
    int jam;
    int menit;
    int detik;

    while (kesempatan > 0){
        cout <<"masukkan username: "; 
        getline (cin, nama);
        cout <<"masukkan password: ";
        getline (cin, password);
        if (nama == "tian" && password == "058") {
            cout << "berhasil login" << endl;
            break;
        }
        else {
            kesempatan -= 1;
            if(kesempatan > 0) {
                cout << "gagal login coba lagi" << endl;
            }
            else {
                cout << "keluar dari program";
                return 0;
            }
        }
    }
    while (true) {
        cout << "selamat datang di program konversi waktu\n"
                "silahkan pilih menu konversi\n";
        cout << "1.Jam -> Menit dan Detik\n"
                "2.Menit -> Jam dan Detik\n"
                "3.Detik -> Jam dan Menit\n"
                "4.Keluar\n"
                "masukkan nomor menu konversi untuk memilih: ";
        cin >> menu;
        if (menu == "1"){
            cout << "masukkan nilai waktu dalan jam yang ingin dikonversi: ";
            cin >> jam;
            int jam_menit = jam * 60;
            int jam_detik = jam * 3600;
            cout << jam_menit << "\n" << jam_detik << endl;
        }
        else if (menu == "2"){
            cout << "masukkan nilai waktu dalam menit yang ingin dikonversi: ";
            cin >> menit;
            double menit_jam = menit / 60.0;
            int menit_detik = menit * 60;
            cout << menit_jam << "\n" << menit_detik << endl;
        }
        else if (menu == "3"){
            cout << "masukkan nilai waktu dalam detik yang ingin dikonversi: ";
            cin >> detik;
            double detik_jam = detik / 3600.0;
            double detik_menit = detik / 60.0;
            cout << detik_jam << "\n" << detik_menit << endl;
        }
        else if (menu == "4"){
            cout << "program selesai" << endl;
            break;
        }
        else {
            cout << "pilihan tidak tersedia, silahkan pilih ulang" << endl;
        }
            }
        return 0;
}