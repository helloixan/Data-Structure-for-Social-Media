#include "sosialmedia.h"

int main()
{
    ListGroup LG;
    ListNetizen LN;
    adrNetizen netizen;
    adrGroup group;
    adrRelation member;
    infotypeNetizen dataNetizen;
    infotypeGroup dataGroup;
    int banyakData;
    string namaGroup, id;
//    group grup;
//    netizen Netizen;


    welcome();
    createListGroup(LG);
    createListNetizen(LN);

    //hardcode
//    grup.title = "GDSC";
//    grup.admin = "tidak ada";
//    grup.maxMember = 100;
//    addGroup(LG, createElmGroup(grup));
//
//    Netizen.id = "Iksan09";
//    Netizen.nama = "Iksan";
//    Netizen.noHP = "082384739857";
//    Netizen.status = "JFKJAD";
//    N = createElmNetizen(Netizen);
//    addNetizen(LN, N);


    int inputMenu = selectMenu();
    while (inputMenu != 0){
            switch(inputMenu){
                case 1: {
                cout << "=== MENAMBAHKAN NETIZEN ===" << endl;
                cout << endl;

                cout << "masukan banyaknya data: ";
                cin >> banyakData;

                for(int i = 1; i <= banyakData; i++){
                    cout << "Netizen ke-" << i << endl;
                    cout << "masukan ID: ";
                    cin >> dataNetizen.id;

                    cout << "masukan NAMA: ";
                    cin >> dataNetizen.nama;

                    cout << "masukan no hp: ";
                    cin >> dataNetizen.noHP;

                    cout << "masukan status: ";
                    cin >> dataNetizen.status;

                    netizen = createElmNetizen(dataNetizen);
                    addNetizen(LN, netizen);
                }
                break;
            }
                case 2: {
                cout << "=== MENAMBAHKAN GROUP ===" << endl;
                cout << endl;

                cout << "masukan banyaknya Grup: ";
                cin >> banyakData;

                for(int i = 1; i <= banyakData; i++){
                    cout << "masukan title: ";
                    cin >> dataGroup.title;

                    cout << "masukan deskripsi group: ";
                    cin >> dataGroup.desc;

                    cout << "masukan maksimal member: ";
                    cin >> dataGroup.maxMember;
                    group = createElmGroup(dataGroup);
                    addGroup(LG, group);
                }
                break;
            }
                case 3: {
                cout << "=== MENAMBAHKAN MEMBER KE GROUP ===" << endl;
                cout << endl;
                cout << "Nama Group : ";
                cin >> namaGroup;
                group = findGroupbyTitle(LG, namaGroup);
                while (group == NIL && namaGroup != "cancel") {
                    cout << "Group tidak ada, masukan nama grup yang valid! atau 'cancel' untuk membatalkan." << endl;
                    cout << "Nama Group : ";
                    cin >> namaGroup;
                    group = findGroupbyTitle(LG, namaGroup);
                }
                cout << "Group " << namaGroup << " dipilih" << endl;
                cout << "Banyaknya member yang ingin ditambahkan : ";
                cin >> banyakData;
                int i = 1;
                id = "notcancel";
                while (i <= banyakData && id != "cancel"){
                    cout << "member ke-" << i << endl;
                    cout << "masukan ID netizen: ";
                    cin >> id;
                    netizen = findNetizen(LN, id);
                    if (netizen == NIL) {
                        cout << "ID tersebut tidak ditemukan, harap memasukan ID yang valid! atau 'cancel' untuk membatalkan." << endl;
                    } else if (isMember(group, netizen)) {
                        cout << info(netizen).nama << " sudah menjadi member di grup " << info(group).title << endl;
                    } else {
                        addMember(group, netizen);
                        i++;
                    }
                }
                break;
            }
                case 4: {
                cout << "=== REMOVE MEMBER DARI GROUP ===" << endl;
                cout << endl;

                cout << "masukan nama group: ";
                cin >> namaGroup;
                group = findGroupbyTitle(LG, namaGroup);
                id = "notcancel";
                while (group == NIL && namaGroup != "cancel") {
                    cout << "Group tidak ada, masukan nama grup yang valid! atau 'cancel' untuk membatalkan." << endl;
                    cout << "Nama Group : ";
                    cin >> namaGroup;
                    group = findGroupbyTitle(LG, namaGroup);
                }

                if (info(group).Nmember != 0) {
                    cout << "Group " << namaGroup << " dipilih" << endl;
                    cout << "Banyaknya member yang ingin dikeluarkan : ";
                    cin >> banyakData;
                    int i = 1;
                    while (i <= banyakData && id != "cancel"){
                        cout << "member ke-" << i << endl;
                        cout << "masukan ID netizen: ";
                        cin >> id;
                        netizen = findNetizen(LN, id);
                        if (netizen == NIL) {
                            cout << "ID tersebut tidak ditemukan pada grup, harap memasukan ID yang valid! atau 'cancel' untuk membatalkan." << endl;
                        } else {
                            removeMember(group, netizen);
                            i++;
                        }
                    }
                } else {
                    cout << "Tidak ada member di Grup " << namaGroup << endl;
                }
                break;
            }
                case 5: {
                cout << "=== MENCARI GROUP ===" << endl;
                cout << endl;

                cout << "masukan nama group: ";
                cin >> namaGroup;

                group = findGroupbyTitle(LG, namaGroup);
                if (group != NIL){
                    cout << "Group Ditemukan!" << endl;
                    showGroup(group);
                    cout << endl;
                } else {
                    cout << "Group tidak tersedia" << endl;
                }
                break;
            }
                case 6: {
                cout << "=== MENCARI NETIZEN ===" << endl;
                cout << endl;

                cout << "Masukan ID Netizen: ";
                cin >> id;

                netizen = findNetizen(LN, id);
                if (netizen != NIL){
                    descNetizen(netizen);
                } else {
                    cout << "ID tersebut tidak ditemukan!" << endl;
                }

                break;
            }
                case 7: {
                cout << "=== DELETE GROUP ===" << endl << endl;

                cout << "Menghapus grup urutan pertama" << endl;

                deleteGroup(LG, group);
                // mengeluarkan seluruh member dari grup
                member = relation(group);
                while (member != NIL) {
                    netizen = nextNet(member);
                    removeMember(group, netizen);
                    member = relation(group);
                }
                cout << "Grup " << info(group).title << " Berhasil dihapus" << endl;
                break;
            }
                case 8: {
                cout << "=== DELETE NETIZEN ===" << endl << endl;

                cout << "menghapus netizen terakhir" << endl;
                deleteNetizen(LN, netizen);
                // menghapus seluruh relasi dengan netizen
                group = first(LG);
                while (group != NIL) {
                    if (isMember(group, netizen)) {
                        removeMember(group, netizen);
                    }
                    group = next(group);
                }
                cout << "Akun tersebut telah dihapus" << endl;
                break;
            }
                case 9: {
                cout << "=== MENAMPILKAN GROUP DENGAN ANGGOTA TERBANYAK & TERKECIL ===" << endl;
                cout << "MINIMUM GROUP: " << endl;
                minGroupMember(LG);
                cout << "MAKSIMAL GROUP: " << endl;
                maxGroupMember(LG);
                break;
            }
                case 10: {
                cout << "=== MENAMPILKAN KESELURUHAN GRUP ===" << endl;
                showAll(LG);
                break;
            }
                case 11: {
                cout << "=== MENAMPILKAN KESELURUHAN NETIZEN ===" << endl;
                showAllNetizen(LN);
                break;
            }
        }
        cout << endl;
        inputMenu = selectMenu();
    }

    cout << "=== TERIMAKASIH ===" << endl;
    return 0;
}
