#include "sosialmedia.h"

// PRIMITIF
void createListGroup(ListGroup &LG){
    first(LG) = NIL;
    last(LG) = NIL;
};

void createListNetizen(ListNetizen &LN){
    first(LN) = NIL;
};

adrRelation createElmRelasi(adrNetizen Netizen){
    adrRelation relasi = new Relation;
    next(relasi) = NIL;
    nextNet(relasi) = Netizen;
    return(relasi);
}

adrGroup createElmGroup(infotypeGroup X){
    adrGroup P = new elmGroup;
    info(P) = X;
    info(P).Nmember = 0;
    next(P) = NIL;
    prev(P) = NIL;
    relation(P) = NIL;
    return P;
};

adrNetizen createElmNetizen(infotypeNetizen X){
    adrNetizen P = new elmNetizen;
    info(P) = X;
    next(P) = NIL;
    return P;
};

void addGroup(ListGroup &LG, adrGroup P){
    // Menambah grup baru pada list, insert last
    if (first(LG) == NIL) {
        first(LG) = P;
    } else {
        adrGroup Q = first(LG);
        while (next(Q) != NIL) {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
    cout << "Group Berhasil Ditambahkan!" << endl;
};

void deleteGroup(ListGroup &LG, adrGroup &P){
    // Menghapus grup berdasarkan posisinya serta mengeluarkan seluruh member dari grup
    if (P == first(LG)){
        deleteFirstGroup(LG, P);
    } else if (P == last(LG)) {
        deleteLastGroup(LG, P);
    } else {
        adrGroup PreG = first(LG);
        while (next(PreG) != P) {
            PreG = next(PreG);
        }
        deleteAfterGroup(LG, P, PreG);
    }
};

void deleteFirstGroup(ListGroup &LG, adrGroup &P){
    // menghapus grup pada lIST MENGGUNAKAN delete first
    if (first(LG) == NIL) {
        cout << "Tidak ada Grup yang tersedia" << endl;
    } else if (next(first(LG)) == NIL) {
        // hapus member yang ada di grup
        P = first(LG);
        next(P) = NIL;
        first(LG) = NIL;
    } else {
        // hapus member yang ada di grup
        P = first(LG);
        first(LG) = next(P);
        next(P) = NIL;
    }
};

void deleteLastGroup(ListGroup &LG, adrGroup &P){
    // menghapus grup pada lIST MENGGUNAKAN delete last
    if (first(LG) == NIL) {
        cout << "Tidak ada Grup yang tersedia" << endl;
    } else if (next(first(LG)) == NIL) {
        // hapus member yang ada di grup
        P = first(LG);
        next(P) = NIL;
        first(LG) = NIL;
    } else {
        // hapus member yang ada di grup
        P = last(LG);
        last(LG) = prev(P);
        prev(P) = NIL;
        next(last(LG)) = NIL;
    }
};

void deleteAfterGroup(ListGroup &LG, adrGroup &P, adrGroup Prec){
    // menghapus grup pada lIST MENGGUNAKAN delete after
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NIL;
    prev(P) = NIL;
};

void addNetizen(ListNetizen &LN, adrNetizen P){
    // menambah netizen baru pada list (insert first)
    if (first(LN) == NIL) {
        first(LN) = P;
    } else {
        next(P) = first(LN);
        first(LN) = P;
    }
};

void deleteNetizen(ListNetizen &LN, adrNetizen &P){
    // Menghapus netizen berdasarkan letaknya
    if (P == first(LN)) {
        deleteFirstNetizen(LN, P);
    } else if (next(P) = NIL) {
        deleteLastNetizen(LN, P);
    } else {
        adrNetizen PreN = first(LN);
        while (next(PreN) != P) {
            PreN = next(PreN);
        }
        deleteAfterNetizen(LN, P, PreN);
    }
};

void deleteLastNetizen(ListNetizen &LN, adrNetizen &P){
    // menghapus netizen dari list, delete last
    if (first(LN) == NIL) {
        cout << "Tidak ada netizen" << endl;
    } else {
        adrNetizen Q = first(LN);
        P = next(Q);
        while (next(P) != NIL) {
            Q = next(Q);
            P = next(P);
        }
        next(Q) = NIL;
    }
};

void deleteFirstNetizen(ListNetizen &LN, adrNetizen &P){
    // menghapus netizen dari list, delete last
    if (first(LN) == NIL) {
        cout << "Tidak ada netizen" << endl;
    } else if (next(first(LN)) == NIL) {
        // hapus member yang ada di grup
        P = first(LN);
        next(P) = NIL;
        first(LN) = NIL;
    } else {
        // hapus member yang ada di grup
        P = first(LN);
        first(LN) = next(P);
        next(P) = NIL;
    }
};

void deleteAfterNetizen(ListNetizen &LN, adrNetizen &P, adrNetizen Prec){
    // menghapus grup pada lIST MENGGUNAKAN delete after
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NIL;
};

// NON-PRIMITIF
void addMember(adrGroup &Group, adrNetizen N){
    // insert first
    if(info(Group).Nmember == info(Group).maxMember){
        cout << "Grup penuh, harap untuk mengeluarkan member terlebih dahulu." << endl;
    } else {
        adrRelation Relasi = createElmRelasi(N);
        if (relation(Group) == NIL) {
            relation(Group) = Relasi;
        } else {
            next(Relasi) = relation(Group);
            relation(Group) = Relasi;
        }
        info(Group).Nmember++;
        cout << info(nextNet(Relasi)).nama << " Berhasil ditambahkan ke Grup" << endl;
    }
};

void deleteFirstRel(adrGroup &Group, adrRelation &Rel){
    if (relation(Group) == NIL) {
        cout << "Tidak ada member pada grup" << endl;
    } else if (next(relation(Group)) == NIL){
        Rel = relation(Group);
        relation(Group) = NIL;
    } else {
        Rel = relation(Group);
        relation(Group) = next(Rel);
        next(Rel) = NIL;
    }
}

void deleteLastRel(adrGroup &Group, adrRelation &Rel){
    if (relation(Group) == NIL) {
        cout << "Tidak ada member pada grup" << endl;
    } else {
        adrRelation PrecRelasi = relation(Group);
        adrRelation Relasi = next(PrecRelasi);
        while (next(Relasi) != NIL) {
            PrecRelasi = Relasi;
            Relasi = next(Relasi);
        }
        Rel = Relasi;
        next(PrecRelasi) = NIL;
    }
}

void deleteAfterRel(adrGroup &Group, adrRelation &Rel, adrRelation Prec){
    if (relation(Group) == NIL) {
        cout << "Tidak ada member pada grup" << endl;
    } else {
        Rel = next(Prec);
        next(Prec) = next(Rel);
        next(Rel) = NIL;
    }
};

void disalokasiRel(adrRelation Relasi){
    delete Relasi;
}


void removeMember(adrGroup &Grup, adrNetizen Netizen){
    // Mengeluarkan member dari grup
    adrRelation tempRelation;
    adrRelation Relasi = relation(Grup);
    while (nextNet(Relasi) != Netizen) {
        Relasi = next(Relasi);
    }
    if (Relasi == relation(Grup)) {
        deleteFirstRel(Grup, tempRelation);
    } else if (next(Relasi) == NIL) {
        deleteLastRel(Grup, tempRelation);
    } else {
        adrRelation Prec = relation(Grup);
        while (next(Prec) != Relasi) {
            Prec = next(Prec);
        }
        deleteAfterRel(Grup, tempRelation, Prec);
    }
    cout << info(nextNet(tempRelation)).nama << " berhasil dikeluarkan dari grup " << info(Grup).title << endl;
    disalokasiRel(tempRelation);
    info(Grup).Nmember -= 1;
};

void showGroup(adrGroup Group){
    cout << "Nama Grup: " << info(Group).title << endl;
    cout << "deskripsi grup: " << info(Group).desc << endl;
    cout << "Jumlah member saat ini: " << info(Group).Nmember << endl;
    cout << "maksimal member: " << info(Group).maxMember << endl;
    showMember(Group);
}

void showAll(ListGroup LG){
    // Menampilkan semua grup beserta membernya
    adrGroup Grup = first(LG);
    if (Grup == NIL) {
        cout << "Belum ada Grup yang dibentuk" << endl;
    } else {
        int i = 1;
        while (Grup != NIL) {
            showGroup(Grup);
            cout << endl;
            Grup = next(Grup);
            i++;
        }
    }
};

void showMember(adrGroup Group){
    adrRelation Relasi = relation(Group);
    if (Relasi == NIL) {
        cout << "Tidak ada member di group " << info(Group).title << endl;
    } else {
        cout << "Berikut member yang ada pada group " << info(Group).title << endl;
        int i = 0;
        while (Relasi != NIL) {
            i++;
            cout << i << ". " << info(nextNet(Relasi)).nama << endl;
            Relasi = next(Relasi);
        }
    }
};

bool isMember(adrGroup Grup, adrNetizen Netizen){
    adrRelation Relasi = relation(Grup);
    while (Relasi != NIL) {
        if (nextNet(Relasi) == Netizen) {
            return true;
        }
        Relasi = next(Relasi);
    }
    return false;
};

void descNetizen(adrNetizen Net){
    cout << "ID: " << info(Net).nama << endl;
    cout << "Nama: " << info(Net).nama << endl;
    cout << "No HP: " << info(Net).noHP << endl;
    cout << "Status: " << info(Net).status << endl;
};

void showAllNetizen(ListNetizen LN){
    adrNetizen Net = first(LN);
    if (Net == NIL) {
        cout << "Belum ada akun yang dibuat" << endl;
    } else {
        int i = 1;
        while (Net != NIL) {
            cout << "Netizen ke-" << i << endl;
            descNetizen(Net);
            Net = next(Net);
            i++;
        }
    }
};

adrGroup findGroupbyTitle(ListGroup LG, string title){
    // Mencari dan menampilkan grup tertentu

    adrGroup Grup = first(LG);
    while (Grup != NIL){
        if (info(Grup).title == title) {
            return Grup;
        }
        Grup = next(Grup);
    }
    return NIL;

};

adrNetizen findNetizen(ListNetizen LN, string id){
    // mencari dan menampilkan netizen tertentu
    adrNetizen Netizen = first(LN);
    while (Netizen != NIL) {
        if (info(Netizen).id == id) {
            return Netizen;
        }
        Netizen = next(Netizen);
    }

    return NIL;

};

void maxGroupMember(ListGroup LG){
    // mencari grup dengan member terbanyak

    adrGroup Grup = first(LG);
    adrGroup Grup_Member_Terbanyak = NIL;
    int maxMember = 0;
    while (Grup != NIL) {
        if (info(Grup).Nmember > maxMember) {
            maxMember = info(Grup).Nmember;
            Grup_Member_Terbanyak = Grup;
        }
        Grup = next(Grup);
    };
    if (Grup_Member_Terbanyak == NIL) {
        cout << "Tidak ada Group tersedia" << endl;
    } else {
        cout << "Grup dengan member terbanyak adalah " << info(Grup_Member_Terbanyak).title << " dengan jumlah member " << info(Grup_Member_Terbanyak).Nmember << endl;
    }
}


void minGroupMember(ListGroup LG){
    // mencari grup dengan member paling sedikit

    adrGroup Grup = first(LG);
    adrGroup Grup_Member_Terkecil = Grup;
    int minMember = info(Grup).Nmember;
    while (Grup != NIL) {
        if (info(Grup).Nmember < minMember) {
            minMember = info(Grup).Nmember;
            Grup_Member_Terkecil = Grup;
        }
        Grup = next(Grup);
    }

    if (Grup_Member_Terkecil == NIL) {
        cout << "Tidak ada Group tersedia" << endl;
    } else {
        cout << "Grup dengan member paling sedikit adalah " << info(Grup_Member_Terkecil).title << " dengan jumlah member " << info(Grup_Member_Terkecil).Nmember << endl;
    }
}


int selectMenu(){
        cout << "===== MENU =====" << endl;
    cout << "Tekan 0 untuk keluar" << endl;
    cout << "Tekan 1 untuk menambahkan netizen baru" << endl;
    cout << "Tekan 2 untuk menambahkan grup baru" << endl;
    cout << "Tekan 3 untuk menambahkan member ke grup" << endl;
    cout << "Tekan 4 untuk mengeluarkan member dari grup" << endl;
    cout << "Tekan 5 untuk mencari grup" << endl;
    cout << "Tekan 6 untuk mencari netizen" << endl;
    cout << "Tekan 7 untuk menghapus grup" << endl;
    cout << "Tekan 8 untuk menghapus netizen" << endl;
    cout << "Tekan 9 untuk melihat grup dengan member terbanyak dan terkecil" << endl;
    cout << "Tekan 10 untuk melihat keseluruhan grup yang tersedia" << endl;
    cout << "Tekan 11 untuk melihat keseluruhan netizen yang tersedia" << endl;
    cout << "pilih menu : ";

    int input = 0;
    cin >> input;
    cout << endl;
    return input;
}

void welcome(){
    cout << "=========== SOCIAL MEDIA ============" << endl;
    cout << "|  Selamat datang di social media!  |" << endl;
    cout << "|              by                   |" << endl;
    cout << "|       Iksan Oktav Risandy         |" << endl;
    cout << "|    M Rafif Aryasatya Purnomo      |" << endl;
    cout << "=====================================" << endl;
    cout << "\nKetik apapun untuk melanjutkan" << endl;
    string apapun;
    cin >> apapun;
};
