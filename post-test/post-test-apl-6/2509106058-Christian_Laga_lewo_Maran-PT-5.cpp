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
    int ranking;
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
            cout<<"Berhasil login"<<endl;
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

    cin.ignore();
    cout<<"Masukkan nama tim baru : ";
    getline(cin,namaBaru);
    
    for(int i=0;i<jumlahTim;i++){
        if(namaBaru == tim[i].nama){
            sudahAda = true;
            break;
        }
    }

    if(sudahAda){
        cout<<"Tim sudah ada, gagal menambahkan"<<endl;
        return;
    }

    tim[jumlahTim].nama = namaBaru;

    int rankingBaru;
    bool rankingAda;

    do{
        rankingAda = false;

        cout<<"Ranking (angka) : ";
        cin>>rankingBaru;

        for(int i=0;i<jumlahTim;i++){
            if(rankingBaru == tim[i].ranking){
                rankingAda = true;
                cout<<"Ranking sudah digunakan! Masukkan ranking lain.\n";
                break;
        }
    }

    }while(rankingAda);

    tim[jumlahTim].ranking = rankingBaru;
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

void lihatTim(Tim *tim, int jumlahTim){

    if(jumlahTim == 0){
        cout<<"Tidak ada tim partisipan"<<endl;
        return;
    }

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<" (Ranking: "<<tim[i].ranking<<")"<<endl;
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

void updateTim(Tim *tim, int *jumlahTim){

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<*jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int pilihTim;

    cout<<"Pilih tim yang ingin diupdate : ";
    cin>>pilihTim;

    if(pilihTim < 1 || pilihTim > *jumlahTim){
        cout<<"Tim tidak ada"<<endl;
        return;
    }

    int edit;

    cout<<"\n1. Deskripsi"<<endl;
    cout<<"2. Prestasi"<<endl;
    cout<<"3. Pemain"<<endl;
    cout<<"4. Staff"<<endl;
    cout<<"5. Ranking"<<endl;
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

    case 5:{
        int rankingBaru;
        bool rankingAda;

        do{
            rankingAda = false;

            cout<<"Ranking baru : ";
            cin>>rankingBaru;

            for(int i=0;i<*jumlahTim;i++){
                if(i != pilihTim-1 && rankingBaru == tim[i].ranking){
                    rankingAda = true;
                    cout<<"Ranking sudah digunakan! Masukkan ranking lain.\n";
                    break;
                }
            }

        }while(rankingAda);

        tim[pilihTim-1].ranking = rankingBaru;
        break;
    }

    default:
        cout<<"Data tidak ada"<<endl;
        return;
    }

    cout<<"Data berhasil diupdate"<<endl;
}

void hapusTim(Tim *tim, int *jumlahTim){

    cout<<"\nDaftar Tim"<<endl;

    for(int i=0;i<*jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int hapus;

    cout<<"Pilih tim yang ingin dihapus : ";
    cin>>hapus;

    if(hapus < 1 || hapus > *jumlahTim){
        cout<<"Tim tidak ada"<<endl;
        return;
    }

    for(int i=hapus-1;i<*jumlahTim-1;i++){
        tim[i] = tim[i+1];
    }

    (*jumlahTim)--;

    cout<<"Tim berhasil dihapus"<<endl;
}

void sortNamaDesc_Selection(Tim *tim, int jumlahTim){
    for(int i=0;i<jumlahTim-1;i++){
        int maxIndex = i;
        for(int j=i+1;j<jumlahTim;j++){
            if(tim[j].nama > tim[maxIndex].nama){
                maxIndex = j;
            }
        }
        swap(tim[i], tim[maxIndex]);
    }
    cout<<"Sorting Nama Descending (Selection Sort) berhasil"<<endl;
}

void sortRankingAsc_Bubble(Tim *tim, int jumlahTim){
    for(int i=0;i<jumlahTim-1;i++){
        for(int j=0;j<jumlahTim-i-1;j++){
            if(tim[j].ranking > tim[j+1].ranking){
                swap(tim[j], tim[j+1]);
            }
        }
    }
    cout<<"Sorting Ranking Ascending (Bubble Sort) berhasil"<<endl;
}

void sortRankingDesc_Insertion(Tim *tim, int jumlahTim){
    for(int i=1;i<jumlahTim;i++){
        Tim key = tim[i];
        int j = i - 1;

        while(j >= 0 && tim[j].ranking < key.ranking){
            tim[j+1] = tim[j];
            j--;
        }
        tim[j+1] = key;
    }
    cout<<"Sorting Ranking Descending (Insertion Sort) berhasil"<<endl;
}

int linearSearchNama(Tim *tim, int jumlahTim, string key){
    for(int i=0;i<jumlahTim;i++){
        if(tim[i].nama == key){
            return i;
        }
    }
    return -1;
}

int binarySearchRanking(Tim *tim, int jumlahTim, int key){
    int left = 0, right = jumlahTim - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(tim[mid].ranking == key){
            return mid;
        }else if(tim[mid].ranking < key){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
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
    "Coach Dylan Falco",
    1};

    tim[1] = {"Fnatic",
    "Fnatic adalah organisasi esports profesional asal Inggris",
    "Juara Riot Season 1 Championship",
    "Empyros Razork Vladi Upset Lospa",
    "Coach GrabbZ",
    7};

    tim[2] = {"Karmine Corp",
    "Karmine Corp (sebelumnya dikenal sebagai Kameto Corp ) adalah organisasi Prancis yang saat ini bermain di LEC",
    "Runner up 2025 First Stand Tournament",
    "Canna Yike kyeahoo Caliste Busio",
    "Coach Reapered",
    2};

    tim[3] = {"Natus Vincere",
    "Natus Vincere (Latin: ""lahir untuk menang"", sering disingkat sebagai NAVI) adalah organisasi esports multi-game terkemuka dari Ukraina",
    "Peringkat 5-6 LEC 2026 Versus",
    "Maynter Rhilech Poby SamD Parus",
    "Coach TheRock7",
    6};

    int jumlahTim = 4;
    int menu;

    do{

        cout<<"\n===== MENU PROGRAM ====="<<endl;
        cout<<"1. Tambah Tim"<<endl;
        cout<<"2. Lihat Data Tim"<<endl;
        cout<<"3. Update Data Tim"<<endl;
        cout<<"4. Hapus Tim"<<endl;
        cout<<"5. Sorting Nama (Desc - Selection Sort)"<<endl;
        cout<<"6. Sorting Ranking (Asc - Bubble Sort)"<<endl;
        cout<<"7. Sorting Ranking (Desc - Insertion Sort)"<<endl;
        cout<<"8. Cari Nama Tim (Linear Search)"<<endl;
        cout<<"9. Cari Ranking Tim (Binary Search)"<<endl;
        cout<<"10. Keluar"<<endl;
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
            updateTim(tim, &jumlahTim);
            break;

        case 4:
            hapusTim(tim, &jumlahTim);
            break;

        case 5:
            sortNamaDesc_Selection(tim, jumlahTim);
            break;

        case 6:
            sortRankingAsc_Bubble(tim, jumlahTim);
            break;

        case 7:
            sortRankingDesc_Insertion(tim, jumlahTim);
            break;

        case 8:{
            cin.ignore();
            string namaCari;
            cout<<"Masukkan nama tim : ";
            getline(cin,namaCari);

            int index = linearSearchNama(tim, jumlahTim, namaCari);

            if(index != -1){
                cout<<"Tim ditemukan!\n";
                cout<<"Nama : "<<tim[index].nama<<endl;
                cout<<"Ranking : "<<tim[index].ranking<<endl;
            }else{
                cout<<"Tim tidak ditemukan"<<endl;
            }
            break;
        }

        case 9:{
            int rankCari;
            cout<<"Masukkan ranking : ";
            cin>>rankCari;

            sortRankingAsc_Bubble(tim, jumlahTim);

            int index = binarySearchRanking(tim, jumlahTim, rankCari);

            if(index != -1){
                cout<<"Tim ditemukan!\n";
                cout<<"Nama : "<<tim[index].nama<<endl;
                cout<<"Ranking : "<<tim[index].ranking<<endl;
            }else{
                cout<<"Tim tidak ditemukan"<<endl;
            }
            break;
        }

        case 10:
            cout<<"Keluar dari program"<<endl;
            break;

        default:
            cout<<"Pilihan tidak valid"<<endl;
        }

    }while(menu != 10);

    cout<<"Program selesai"<<endl;
}