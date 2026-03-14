#include <iostream>
#include <string>
using namespace std;

struct Login{
    string username;
    string password;
};

struct Tim{
    string nama;
    string deskripsi;
    string prestasi;
    string pemain;
    string staff;
};

bool login(Login akun){

    string user, pass;
    int kesempatan = 3;

    cout<<"Selamat datang di program silahkan login untuk verifikasi diri anda"<<endl;

    while(kesempatan > 0){

        cout<<"Masukkan username : ";
        getline(cin,user);
        cout<<"Masukkan password : ";
        getline(cin,pass);

        if(user == akun.username && pass == akun.password){
            cout<<"berhasil login"<<endl;
            return true;
        }

        kesempatan--;

        if(kesempatan > 0){
            cout<<"Login gagal, coba lagi"<<endl;
            cout<<"Sisa kesempatan : "<<kesempatan<<endl;
        }else{
            cout<<"Kesempatan habis, keluar dari program"<<endl;
        }

    }

    return false;
}

void tambahTim(Tim tim[], int &jumlahTim){

    if(jumlahTim >= 12){
        cout<<"Tim partisipan penuh"<<endl;
        return;
    }

    string namaBaru;
    bool sudahAda = false;

    cout<<"Masukkan nama tim baru : ";
    cin>>namaBaru;

    for(int i=0;i<jumlahTim;i++){
        if(namaBaru == tim[i].nama){
            sudahAda = true;
        }
    }

    if(sudahAda){
        cout<<"Tim sudah ada, gagal menambahkan"<<endl;
        return;
    }

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

void lihatTim(Tim tim[], int jumlahTim){

    if(jumlahTim == 0){
        cout<<"Tidak ada tim partisipan"<<endl;
        return;
    }

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int pilihTim;

    cout<<"Pilih tim : ";
    cin>>pilihTim;

    if(pilihTim < 1 || pilihTim > jumlahTim){
        cout<<"Tim tidak tersedia"<<endl;
        return;
    }

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
        cout<<"Data tim tidak tersedia"<<endl;
    }

}

void updateTim(Tim tim[], int jumlahTim){

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int pilihTim;

    cout<<"Pilih tim yang ingin diupdate : ";
    cin>>pilihTim;

    if(pilihTim < 1 || pilihTim > jumlahTim){
        cout<<"Tim tidak ada"<<endl;
        return;
    }

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
        break;

    case 2:
        cout<<"Prestasi baru : ";
        getline(cin,tim[pilihTim-1].prestasi);
        break;

    case 3:
        cout<<"Pemain baru : ";
        getline(cin,tim[pilihTim-1].pemain);
        break;

    case 4:
        cout<<"Staff baru : ";
        getline(cin,tim[pilihTim-1].staff);
        break;

    default:
        cout<<"Data tidak ada"<<endl;
        return;
    }

    cout<<"Data berhasil diupdate"<<endl;

}

void hapusTim(Tim tim[], int &jumlahTim){

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int hapus;

    cout<<"Pilih tim yang ingin dihapus : ";
    cin>>hapus;

    if(hapus < 1 || hapus > jumlahTim){
        cout<<"Tim tidak ada"<<endl;
        return;
    }

    for(int i=hapus-1;i<jumlahTim-1;i++){
        tim[i] = tim[i+1];
    }

    jumlahTim--;

    cout<<"Tim berhasil dihapus"<<endl;

}

int main(){

    Login akun = {"tian","058"};

    if(!login(akun)){
        return 0;
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
        cout<<"1. Tambah Tim"<<endl;
        cout<<"2. Lihat Data Tim"<<endl;
        cout<<"3. Update Data Tim"<<endl;
        cout<<"4. Hapus Tim"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih : ";
        cin>>menu;

        switch(menu){

        case 1:
            tambahTim(tim, jumlahTim);
            break;

        case 2:
            lihatTim(tim, jumlahTim);
            break;

        case 3:
            updateTim(tim, jumlahTim);
            break;

        case 4:
            hapusTim(tim, jumlahTim);
            break;

        case 5:
            cout<<"Keluar dari program"<<endl;
            break;

        default:
            cout<<"Pilihan tidak valid"<<endl;

        }

    }while(menu != 5);

    cout<<"Program selesai"<<endl;

}

