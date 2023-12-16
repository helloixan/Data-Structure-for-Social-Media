#ifndef SOSMED_H_INCLUDED
#define SOSMED_H_INCLUDED
#include <iostream>
#define NIL NULL
#define first(L) L.first
#define last(L) L.last
#define next(p) p->next
#define info(p) p->info
#define relation(p) p->relation
#define nextNet(p) p->nextNet

using namespace std;
struct netizen {
    string nama, id, status, noHP;
};
struct group {
    string title, desc;
    int Nmember, maxMember;
};
typedef group infotypeGroup;
typedef netizen infotypeNetizen;
typedef struct elmGroup *adrGroup;
typedef struct elmNetizen *adrNetizen;
typedef struct Relation *adrRelation;

struct elmGroup {
    infotypeGroup info;
    adrGroup next;
    adrRelation relation;
};
struct elmNetizen {
    infotypeNetizen info;
    adrNetizen next;
};
struct Relation {
    adrRelation next;
    adrNetizen nextNet;
};

struct ListGroup {
    adrGroup first;
    adrGroup last;
};
struct ListNetizen {
    adrNetizen first;
};

// Primitif Function dan Procedure
void createListGroup(ListGroup &LG);
void createListNetizen(ListNetizen &LN);
adrGroup createElmGroup(infotypeGroup X);
adrNetizen createElmNetizen(infotypeNetizen X);
adrRelation createElmRelasi(adrNetizen Netizen);
void addGroup(ListGroup &LG, adrGroup P);
void deleteGroup(ListGroup &LG, adrGroup &P);
void addNetizen(ListNetizen &LN, adrNetizen P);
void addMember(adrGroup &Group, adrNetizen N);
void deleteNetizen(ListNetizen &LN, adrNetizen &P);
void disalokasiRel(adrRelation Relasi);
void deleteFirstRel(adrGroup &Group, adrRelation &Rel);
void deleteAfterRel(adrGroup &Group, adrRelation &Rel, adrRelation Prec);
void deleteLastRel(adrGroup &Group, adrRelation &Rel);

// Non Primitif
void removeMember(adrGroup &Grup, adrNetizen Netizen);
void showAll(ListGroup LG);
void showGroup(adrGroup Group);
void showMember(adrGroup Group);
void descNetizen(adrNetizen Net);
void showAllNetizen(ListNetizen LN);
bool isMember(adrGroup Grup, adrNetizen Netizen);
adrGroup findGroupbyTitle(ListGroup LG, string title);
adrNetizen findNetizen(ListNetizen LN, string id);
void maxGroupMember(ListGroup LG);
void minGroupMember (ListGroup LG);
int selectMenu();
void welcome();
#endif // SOSMED_H_INCLUDED
