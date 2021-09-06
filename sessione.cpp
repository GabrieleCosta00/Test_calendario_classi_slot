
#include "sessione.h"

sessione::sessione(const string &quale_sessione) {

    _quale_sessione = quale_sessione;
    if (_quale_sessione != "s3") {
        _appelli.emplace_back(1);
        _appelli.emplace_back(2);
    } else {
        _appelli.emplace_back(2);
    }

}

bool sessione::set_id_esame_nella_sessione(const string &id_esame, const vector<string> &id_cds,
                                           const vector<string> &anno, const int n_slot_necessari,
                                           const vector<string> &id_professori, int n_vers_paral,
                                           const vector<string> &semestre_dell_esame) {
    vector<bool> inserito_nell_appello(_appelli.size());
    for (auto &&j: inserito_nell_appello) {
        j = true;
    }

    for (int i = 0; i < _appelli.size(); i++) {
        if (_appelli[i].get_quale_appello() == 2) {
            if (!_appelli[i].set_id_esame_nell_appello(id_esame, id_cds, anno, n_slot_necessari, id_professori,
                                                       n_vers_paral)) {
//                cout<<endl<<"Esame "<<id_esame<<" non inserito nell'appello "<<i+1<<" della sessione "<<_quale_sessione<<"!"<<endl;
                inserito_nell_appello[i] = false;
            }
        } else {
            if ((_quale_sessione == semestre_dell_esame[0]) && (_quale_sessione != "s3")) {
                if (!_appelli[i].set_id_esame_nell_appello(id_esame, id_cds, anno, n_slot_necessari, id_professori,
                                                           n_vers_paral)) {
//                    cout<<endl<<"Esame "<<id_esame<<" non inserito nell'appello "<<i+1<<" della sessione "<<_quale_sessione<<"!"<<endl;
                    inserito_nell_appello[i] = false;
                }
            }
        }
    }

    bool all_false = true;
    for (auto &&k: inserito_nell_appello) {
        if (k)
            all_false = false;
    }

    if (all_false)
        return false;
    else
        return true;
}

void sessione::print_sessione() {

    for (int i = 0; i < _appelli.size(); i++) {
        cout << endl << "Appello " << i + 1 << ": " << endl;
        cout << "\t";
        _appelli[i].print_appello();
        cout << endl;
    }

}