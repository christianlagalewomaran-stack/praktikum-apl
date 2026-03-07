#include <iostream>
#include <string>
using namespace std;

struct Login {
    string username;
    string password;
};

struct Tim {
    string nama;
    string deskripsi;
    string prestasi;
    string pemain;
    string staff;
};

int main() {

    Login akun = {"tian","058"};

    string user, pass;
    int kesempatan = 3;

    cout<<"Selamat datang di program silahkan login untuk verifikasi diri anda"<<endl;

    while(kesempatan > 0){

        cout<<"Masukkan username: ";
        getline(cin, user);
        cout<<"Masukkan password: ";
        getline(cin, pass);

        if(user == akun.username && pass == akun.password){
            cout<<"Berhasil login"<<endl;
            break;
        }else{
            kesempatan--;
            if(kesempatan > 0){
                cout<<"Login gagal, coba lagi"<<endl;
                cout<<"Sisa kesempatan: "<<kesempatan<<endl<<endl;
            }else{
                cout<<"Kesempatan habis, keluar dari program"<<endl;
                return 0;
            }
        }
    }

    Tim tim[12];

    tim[0] = {"G2",
        "G2 Esports adalah organisasi esports profesional dari Berlin, Jerman",
        "Juara 2019 Mid-Season Invitational",
        "BrokenBlade SkewMond Caps HansSama Labrov",
        "Coach Dylan Falco"};

    tim[1] = {"Fnatic",
        "Fnatic adalah organisasi esports profesional asal Inggris yang didirikan tahun 2004",
        "Juara Riot Season 1 Championship",
        "Empyros Razork Vladi Upset Lospa",
        "Coach GrabbZ"};

    int jumlahTim = 2;
    int menu;

    do{

        cout<<"\n===== MENU PROGRAM ====="<<endl;
        cout<<"1. Tambah Tim Partisipan baru"<<endl;
        cout<<"2. Lihat Data Tim"<<endl;
        cout<<"3. Perbarui Data Tim"<<endl;
        cout<<"4. Keluarkan Tim partisipan"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih : ";
        cin>>menu;

        switch(menu){

        case 1:

            if(jumlahTim >= 12){
                cout<<"Tim partisipan penuh"<<endl;
            }else{

                string namaBaru;
                bool sudahAda = false;

                cout<<"Masukkan nama tim baru : ";
                cin>>namaBaru;

                for(int i=0;i<jumlahTim;i++){
                    if(namaBaru == tim[i].nama){
                        sudahAda = true;
                        break;
                    }
                }

                if(sudahAda){
                    cout<<"Tim sudah ada, gagal menambahkan"<<endl;
                }else{

                    tim[jumlahTim].nama = namaBaru;
                    cin.ignore();

                    cout<<"Deskripsi : ";
                    getline(cin,tim[jumlahTim].deskripsi);

                    cout<<"Prestasi : ";
                    getline(cin,tim[jumlahTim].prestasi);

                    cout<<"Pemain : ";
                    getline(cin,tim[jumlahTim].pemain);

                    cout<<"Staff : ";
                    getline(cin,tim[jumlahTim].staff);

                    jumlahTim++;

                    cout<<"Tim berhasil ditambahkan"<<endl;
                }
            }
            break;

        case 2:

            if(jumlahTim == 0){
                cout<<"Tidak ada data tim"<<endl;
            }else{

                cout<<"\nDaftar Tim"<<endl;

                for(int i=0;i<jumlahTim;i++){
                    cout<<i+1<<". "<<tim[i].nama<<endl;
                }

                int pilihTim;

                cout<<"Pilih tim : ";
                cin>>pilihTim;

                if(pilihTim < 1 || pilihTim > jumlahTim){
                    cout<<"Tim tidak ada"<<endl;
                }else{

                    int lihat;

                    cout<<"\n1. Deskripsi"<<endl;
                    cout<<"2. Prestasi"<<endl;
                    cout<<"3. Pemain dan Staff"<<endl;
                    cout<<"Pilih : ";
                    cin>>lihat;

                    switch(lihat){

                    case 1:
                        cout<<"Deskripsi : "<<tim[pilihTim-1].deskripsi<<endl;
                        break;

                    case 2:
                        cout<<"Prestasi : "<<tim[pilihTim-1].prestasi<<endl;
                        break;

                    case 3:
                        cout<<"Pemain : "<<tim[pilihTim-1].pemain<<endl;
                        cout<<"Staff : "<<tim[pilihTim-1].staff<<endl;
                        break;

                    default:
                        cout<<"Data tidak ada"<<endl;
                    }
                }
            }
            break;

        case 3:

            cout<<"\nDaftar Tim"<<endl;

            for(int i=0;i<jumlahTim;i++){
                cout<<i+1<<". "<<tim[i].nama<<endl;
            }

            int pilihTim;

            cout<<"Pilih tim yang ingin diupdate : ";
            cin>>pilihTim;

            if(pilihTim < 1 || pilihTim > jumlahTim){
                cout<<"Tim tidak ada"<<endl;
            }else{

                int edit;

                cout<<"\n1. Deskripsi"<<endl;
                cout<<"2. Prestasi"<<endl;
                cout<<"3. Pemain"<<endl;
                cout<<"4. Staff"<<endl;
                cout<<"Pilih data : ";
                cin>>edit;
                cin.ignore();

                switch(edit){

                case 1:
                    cout<<"Deskripsi baru : ";
                    getline(cin,tim[pilihTim-1].deskripsi);
                    cout<<"Data berhasil diupdate"<<endl;
                    break;

                case 2:
                    cout<<"Prestasi baru : ";
                    getline(cin,tim[pilihTim-1].prestasi);
                    cout<<"Data berhasil diupdate"<<endl;
                    break;

                case 3:
                    cout<<"Pemain baru : ";
                    getline(cin,tim[pilihTim-1].pemain);
                    cout<<"Data berhasil diupdate"<<endl;
                    break;

                case 4:
                    cout<<"Staff baru : ";
                    getline(cin,tim[pilihTim-1].staff);
                    cout<<"Data berhasil diupdate"<<endl;
                    break;

                default:
                    cout<<"Data tidak ada"<<endl;
                }
            }

            break;

        case 4:

            cout<<"\nDaftar Tim"<<endl;

            for(int i=0;i<jumlahTim;i++){
                cout<<i+1<<". "<<tim[i].nama<<endl;
            }

            int hapus;

            cout<<"Pilih tim yang ingin dihapus : ";
            cin>>hapus;

            if(hapus < 1 || hapus > jumlahTim){
                cout<<"Tim tidak ada"<<endl;
            }else{

                for(int i=hapus-1;i<jumlahTim-1;i++){
                    tim[i] = tim[i+1];
                }

                jumlahTim--;

                cout<<"Tim berhasil dihapus"<<endl;
            }

            break;

        case 5:
        cout<<"Keluar dari program"<<endl;
        break;
            default:
            cout << "pilihan tidak valid pilih ulang" << endl;

        }

    }while(menu != 5);

    cout<<"Program selesai"<<endl;

}