//
// Created by Gabriele on 06/09/2021.
//

#ifndef TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H
#define TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H

#define n_giorni 7

#include <vector>
#include "giorno.h"

class calendario {

private:

    vector <giorno> giorni;

public:

    calendario();
    bool set_id_esame_nel_calendario(const string &id_esame, const vector <string> &id_cds, const int anno,
                                     const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral);
    void print_calendario();

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H
