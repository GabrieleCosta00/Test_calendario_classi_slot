
#ifndef TEST_CALENDARIO_CLASSI_SLOT_APPELLO_H
#define TEST_CALENDARIO_CLASSI_SLOT_APPELLO_H

#include "giorno.h"


class appello {

private:

    vector <giorno> _giorni;
    int _quale_appello;

public:

    appello(const int quale_appello);
    bool set_id_esame_nell_appello(const string &id_esame, const vector <string> &id_cds, const vector <string> &anno,
                                   const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral);
    bool trovato_cds_anno(const vector <string> &id_cds, const vector <string> &anno, const int inserisco_nel_giorno);
    void print_appello();
    const int get_quale_appello() const;

    template<class InputIterator, class T>
    InputIterator find_cds_anno (InputIterator first_cds, InputIterator last_cds, InputIterator first_anno, const T& cds, const T& anno);

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_APPELLO_H