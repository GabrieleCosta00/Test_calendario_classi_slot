
#include "giorno.h"

giorno::giorno() {

    _fasce_orarie.resize(n_slot);

}

bool giorno::set_id_esame_nel_giorno(const string &id_esame, const vector<string> &id_cds, const vector<string> &anno,
                                     const int n_slot_necessari, const vector<string> &id_professori,
                                     int n_vers_paral) {

    bool esame_inserito = true;
    int inserisco_nello_slot = 0;

    while ((inserisco_nello_slot + n_slot_necessari - 1) < n_slot) {
        for (int i = 0; (i < n_slot_necessari) && esame_inserito; i++) {
            if (!_fasce_orarie[i + inserisco_nello_slot].set_id_esame_nello_slot(id_esame, id_professori,
                                                                                 n_vers_paral)) {
                esame_inserito = false;
            }
        }

        if (esame_inserito) {
            for (int j = 0; j < n_vers_paral; j++) {
                _id_cds_inseriti.push_back(id_cds[j]);
                _anni_inseriti.push_back(anno[j]);
            }

            return true;
        } else {
            inserisco_nello_slot++;
            esame_inserito = true;
        }
    }

//    cout<<endl<<"Esame "<<id_esame<<" non inserito nel giorno!"<<endl;
    return false;

}

void giorno::print_giorno() {

    cout << endl << "------------------------------------------------------------------" << endl;

    for (int i = 0; i < n_slot; i++) {
        cout << endl << "Slot " << i + 1 << ": " << endl;
        cout << "\t";
        _fasce_orarie[i].print_id_esami();
        cout << "\t";
        _fasce_orarie[i].print_professori();
        cout << endl;
    }

    cout << endl << "------------------------------------------------------------------" << endl;

}

vector<string> &giorno::get_id_cds_inseriti() {
    return _id_cds_inseriti;
}

vector<string> &giorno::get_anni_inseriti() {
    return _anni_inseriti;
}