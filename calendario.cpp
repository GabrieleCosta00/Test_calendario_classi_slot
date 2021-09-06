
#include "calendario.h"

calendario::calendario() {

    _sessioni.emplace_back("s1");
    _sessioni.emplace_back("s2");
    _sessioni.emplace_back("s3");

}

bool calendario::set_id_esame_nel_calendario(const string &id_esame, const vector<string> &id_cds,
                                             const vector<string> &anno, const int n_slot_necessari,
                                             const vector<string> &id_professori, int n_vers_paral,
                                             const vector<string> &semestre_dell_esame) {

    for (int i = 0; i < _sessioni.size(); i++) {
        if (!_sessioni[i].set_id_esame_nella_sessione(id_esame, id_cds, anno, n_slot_necessari, id_professori,
                                                      n_vers_paral,
                                                      semestre_dell_esame)) {
//            cout<<endl<<"Esame "<<id_esame<<" non inserito nella sessione "<<i+1<<"!"<<endl;
        }
    }

}

void calendario::print_calendario() {

    cout << endl << "Calendario: " << endl << endl;
    for (int i = 0; i < _sessioni.size(); i++) {
        cout << endl << "\tSessione " << i + 1 << ": " << endl << endl;
        _sessioni[i].print_sessione();
    }

}