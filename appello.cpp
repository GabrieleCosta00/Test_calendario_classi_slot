
#include "appello.h"

appello::appello(const int quale_appello) {

    _quale_appello = quale_appello;
    if (_quale_appello == 1) {
        _giorni.resize(n_giorni_appello_1);
    } else {
        _giorni.resize(n_giorni_appello_2);
    }

}

bool
appello::set_id_esame_nell_appello(const string &id_esame, const vector<string> &id_cds, const vector<string> &anno,
                                   const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral) {

    int inserisco_nel_giorno = 0;

    while (inserisco_nel_giorno < _giorni.size()) {
        if ((!trovato_cds_anno(id_cds, anno, inserisco_nel_giorno)) &&
            (prof_disponibili(id_professori, inserisco_nel_giorno))) {
            if (!_giorni[inserisco_nel_giorno].set_id_esame_nel_giorno(id_esame, id_cds, anno, n_slot_necessari,
                                                                       id_professori, n_vers_paral)) {
                inserisco_nel_giorno++;
            } else {
                return true;
            }
        } else {
            inserisco_nel_giorno++;
//            cout<<endl<<"Esame "<<id_esame<<" spostato di un giorno!"<<endl;
        }
    }

    return false;

}

bool
appello::trovato_cds_anno(const vector<string> &id_cds, const vector<string> &anno, const int inserisco_nel_giorno) {

    bool trovato = false;
    vector<string>::iterator it_oggi;
    vector<string>::iterator it_ieri;
    vector<string>::iterator it_domani;

    for (int i = 0; i < id_cds.size(); i++) {
        it_oggi = find_cds_anno(_giorni[inserisco_nel_giorno].get_id_cds_inseriti().begin(),
                                _giorni[inserisco_nel_giorno].get_id_cds_inseriti().end(),
                                _giorni[inserisco_nel_giorno].get_anni_inseriti().begin(),
                                id_cds[i], anno[i]);

        if (inserisco_nel_giorno != 0) {
            it_ieri = find_cds_anno(_giorni[inserisco_nel_giorno - 1].get_id_cds_inseriti().begin(),
                                    _giorni[inserisco_nel_giorno - 1].get_id_cds_inseriti().end(),
                                    _giorni[inserisco_nel_giorno - 1].get_anni_inseriti().begin(),
                                    id_cds[i], anno[i]);
        } else {
            it_ieri = _giorni[inserisco_nel_giorno - 1].get_id_cds_inseriti().end();
        }

        if (inserisco_nel_giorno != (_giorni.size() - 2)) {
            it_domani = find_cds_anno(_giorni[inserisco_nel_giorno + 1].get_id_cds_inseriti().begin(),
                                      _giorni[inserisco_nel_giorno + 1].get_id_cds_inseriti().end(),
                                      _giorni[inserisco_nel_giorno + 1].get_anni_inseriti().begin(),
                                      id_cds[i], anno[i]);
        } else {
            it_domani = _giorni[inserisco_nel_giorno + 1].get_id_cds_inseriti().end();
        }

        if ((it_oggi != _giorni[inserisco_nel_giorno].get_id_cds_inseriti().end()) ||
            (it_ieri != _giorni[inserisco_nel_giorno - 1].get_id_cds_inseriti().end()) ||
            (it_domani != _giorni[inserisco_nel_giorno + 1].get_id_cds_inseriti().end())) {
            trovato = true;
        }
    }
    return trovato;
}

template<class InputIterator, class T>
InputIterator
appello::find_cds_anno(InputIterator first_cds, InputIterator last_cds, InputIterator first_anno, const T &cds,
                       const T &anno) {
    while (first_cds != last_cds) {
        if ((*first_cds == cds) && (*first_anno == anno)) return first_cds;
        ++first_cds;
        ++first_anno;
    }
    return last_cds;
}

void appello::print_appello() {

    for (int i = 0; i < _giorni.size(); i++) {
        cout << endl << "Giorno " << i + 1 << ": " << endl;
        cout << "\t";
        _giorni[i].print_giorno();
        cout << endl;
    }

}

const int appello::get_quale_appello() const {
    return _quale_appello;
}

bool appello::prof_disponibili(const vector<string> &id_professori, const int inserisco_nel_giorno) {

    /*for(int i=0; i < id_professori.size(); i++)
    {
        for(int j=0; j < id_professori[i].get_indisponibilita.size(); j++)
        {
            // se inserisco_nel_giorno è dentro indisponibilità allora return false
        }
    }*/
    return true;
}