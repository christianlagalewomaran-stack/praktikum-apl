#include <iostream>
#include <string>
#include <stdexcept>
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

        try{
            if(user != akun.username || pass != akun.password){
                throw runtime_error("Login gagal!");
            }

            cout<<"Berhasil login"<<endl;
            return true;

        }catch(const runtime_error& e){
            kesempatan--;
            cout<<"Error: "<<e.what()<<endl;

            if(kesempatan > 0){
                cout<<"Sisa kesempatan : "<<kesempatan<<endl;
            }else{
                cout<<"Kesempatan habis"<<endl;
            }
        }
    }
    return false;
}

void tambahTim(Tim tim[], int &jumlahTim){
    if(jumlahTim >= 12){
        cout<<"Tim penuh"<<endl;
        return;
    }

    string namaBaru;
    bool sudahAda = false;

    cin.ignore();
    cout<<"Masukkan nama tim : ";
    getline(cin,namaBaru);

    for(int i=0;i<jumlahTim;i++){
        if(namaBaru == tim[i].nama){
            sudahAda = true;
            break;
        }
    }

    if(sudahAda){
        cout<<"Tim sudah ada"<<endl;
        return;
    }

    tim[jumlahTim].nama = namaBaru;

    int rankingBaru;
    bool ulang;

    do{
        ulang = false;
        try{
            cout<<"Ranking : ";
            cin>>rankingBaru;

            if(cin.fail()){
                throw invalid_argument("Ranking harus angka!");
            }

            for(int i=0;i<jumlahTim;i++){
                if(rankingBaru == tim[i].ranking){
                    throw runtime_error("Ranking sudah digunakan!");
                }
            }

        }catch(const exception& e){
            cout<<"Error: "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            ulang = true;
        }

    }while(ulang);

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
    cout<<"Berhasil tambah tim"<<endl;
}

void lihatTim(Tim *tim, int jumlahTim){
    if(jumlahTim == 0){
        cout<<"Tidak ada tim"<<endl;
        return;
    }

    cout<<"\nDaftar Tim"<<endl;
    for(int i=0;i<jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<" (Ranking "<<tim[i].ranking<<")"<<endl;
    }

    int pilihTim;

    try{
        cout<<"Pilih tim : ";
        cin>>pilihTim;

        if(cin.fail()) throw invalid_argument("Harus angka!");
        if(pilihTim < 1 || pilihTim > jumlahTim) throw runtime_error("Tim tidak ada!");

    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        return;
    }

    int lihat;
    try{
        cout<<"1.Deskripsi\n2.Prestasi\n3.Pemain & Staff\nPilih: ";
        cin>>lihat;

        if(cin.fail()) throw invalid_argument("Harus angka!");

    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        return;
    }

    switch(lihat){
        case 1: cout<<tim[pilihTim-1].deskripsi<<endl; break;
        case 2: cout<<tim[pilihTim-1].prestasi<<endl; break;
        case 3:
            cout<<"Pemain: "<<tim[pilihTim-1].pemain<<endl;
            cout<<"Staff: "<<tim[pilihTim-1].staff<<endl;
            break;
        default: cout<<"Menu tidak ada"<<endl;
    }
}

void updateTim(Tim *tim, int *jumlahTim){
    cout<<"\nDaftar Tim"<<endl;
    for(int i=0;i<*jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int pilihTim;

    try{
        cout<<"Pilih tim : ";
        cin>>pilihTim;

        if(cin.fail()) throw invalid_argument("Harus angka!");
        if(pilihTim < 1 || pilihTim > *jumlahTim) throw runtime_error("Tim tidak ada!");

    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        return;
    }

    int edit;
    cout<<"1.Deskripsi\n2.Prestasi\n3.Pemain\n4.Staff\n5.Ranking\nPilih: ";
    cin>>edit;
    cin.ignore();

    switch(edit){
        case 1: cout<<"Deskripsi baru: "; getline(cin,tim[pilihTim-1].deskripsi); break;
        case 2: cout<<"Prestasi baru: "; getline(cin,tim[pilihTim-1].prestasi); break;
        case 3: cout<<"Pemain baru: "; getline(cin,tim[pilihTim-1].pemain); break;
        case 4: cout<<"Staff baru: "; getline(cin,tim[pilihTim-1].staff); break;

        case 5:{
            int rankingBaru;
            bool ulang;

            do{
                ulang = false;
                try{
                    cout<<"Ranking baru: ";
                    cin>>rankingBaru;

                    if(cin.fail()) throw invalid_argument("Harus angka!");

                    for(int i=0;i<*jumlahTim;i++){
                        if(i != pilihTim-1 && rankingBaru == tim[i].ranking){
                            throw runtime_error("Ranking sudah digunakan!");
                        }
                    }

                }catch(const exception& e){
                    cout<<"Error: "<<e.what()<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    ulang = true;
                }

            }while(ulang);

            tim[pilihTim-1].ranking = rankingBaru;
            break;
        }

        default:
            cout<<"Menu tidak ada"<<endl;
            return;
    }

    cout<<"Update berhasil"<<endl;
}

void hapusTim(Tim *tim, int *jumlahTim){
    cout<<"\nDaftar Tim"<<endl;
    for(int i=0;i<*jumlahTim;i++){
        cout<<i+1<<". "<<tim[i].nama<<endl;
    }

    int hapus;

    try{
        cout<<"Pilih tim : ";
        cin>>hapus;

        if(cin.fail()) throw invalid_argument("Harus angka!");
        if(hapus < 1 || hapus > *jumlahTim) throw runtime_error("Tim tidak ada!");

    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        return;
    }

    for(int i=hapus-1;i<*jumlahTim-1;i++){
        tim[i] = tim[i+1];
    }

    (*jumlahTim)--;
    cout<<"Berhasil hapus"<<endl;
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
    cout<<"Sorting nama berhasil"<<endl;
}

void sortRankingAsc_Bubble(Tim *tim, int jumlahTim){
    for(int i=0;i<jumlahTim-1;i++){
        for(int j=0;j<jumlahTim-i-1;j++){
            if(tim[j].ranking > tim[j+1].ranking){
                swap(tim[j], tim[j+1]);
            }
        }
    }
    cout<<"Sorting ranking ASC berhasil"<<endl;
}

void sortRankingDesc_Insertion(Tim *tim, int jumlahTim){
    for(int i=1;i<jumlahTim;i++){
        Tim key = tim[i];
        int j = i-1;

        while(j>=0 && tim[j].ranking < key.ranking){
            tim[j+1] = tim[j];
            j--;
        }
        tim[j+1] = key;
    }
    cout<<"Sorting ranking DESC berhasil"<<endl;
}

int linearSearchNama(Tim *tim, int jumlahTim, string key){
    for(int i=0;i<jumlahTim;i++){
        if(tim[i].nama == key) return i;
    }
    return -1;
}

int binarySearchRanking(Tim *tim, int jumlahTim, int key){
    int left = 0, right = jumlahTim-1;

    while(left <= right){
        int mid = (left + right)/2;

        if(tim[mid].ranking == key) return mid;
        else if(tim[mid].ranking < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    Login akun = {"tian","058"};

    if(!login(akun)) return 0;

    Tim tim[12] = {
        {"G2","","","","",1},
        {"Fnatic","","","","",7},
        {"Karmine Corp","","","","",2},
        {"Natus Vincere","","","","",6}
    };

    int jumlahTim = 4;
    int menu;

    do{
        cout<<"\n===== MENU ====="<<endl;
        cout<<"1.Tambah\n2.Lihat\n3.Update\n4.Hapus\n5.Sort Nama\n6.Sort Rank ASC\n7.Sort Rank DESC\n8.Cari Nama\n9.Cari Rank\n10.Keluar\nPilih: ";

        try{
            cin>>menu;

            if(cin.fail()) throw invalid_argument("Harus angka!");
            if(menu < 1 || menu > 10) throw runtime_error("Menu tidak valid!");

        }catch(const exception& e){
            cout<<"Error: "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }

        switch(menu){
            case 1: tambahTim(tim, jumlahTim); break;
            case 2: lihatTim(tim, jumlahTim); break;
            case 3: updateTim(tim, &jumlahTim); break;
            case 4: hapusTim(tim, &jumlahTim); break;
            case 5: sortNamaDesc_Selection(tim, jumlahTim); break;
            case 6: sortRankingAsc_Bubble(tim, jumlahTim); break;
            case 7: sortRankingDesc_Insertion(tim, jumlahTim); break;

            case 8:{
                cin.ignore();
                string cari;
                cout<<"Nama tim: ";
                getline(cin,cari);

                int idx = linearSearchNama(tim,jumlahTim,cari);
                if(idx != -1) cout<<"Ditemukan: "<<tim[idx].nama<<endl;
                else cout<<"Tidak ditemukan"<<endl;
                break;
            }

            case 9:{
                int rank;
                try{
                    cout<<"Ranking: ";
                    cin>>rank;

                    if(cin.fail()) throw invalid_argument("Harus angka!");

                }catch(const exception& e){
                    cout<<"Error: "<<e.what()<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    break;
                }

                sortRankingAsc_Bubble(tim,jumlahTim);
                int idx = binarySearchRanking(tim,jumlahTim,rank);

                if(idx != -1) cout<<"Ditemukan: "<<tim[idx].nama<<endl;
                else cout<<"Tidak ditemukan"<<endl;
                break;
            }
        }

    }while(menu != 10);

    cout<<"Program selesai"<<endl;
}