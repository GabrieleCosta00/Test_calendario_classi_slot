
#ifndef TEST_CALENDARIO_CLASSI_SLOT_SESSIONE_H
#define TEST_CALENDARIO_CLASSI_SLOT_SESSIONE_H

#include "appello.h"


class sessione {

private:

    vector<appello> _appelli;
    string _quale_sessione;

public:

    sessione(const string &quale_sessione);

    bool set_id_esame_nella_sessione(const string &id_esame, const vector<string> &id_cds, const vector<string> &anno,
                                     const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral,
                                     const vector<string> &semestre_dell_esame);

    void print_sessione();

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_SESSIONE_H