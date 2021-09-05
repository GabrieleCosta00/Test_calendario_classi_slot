//
// Created by Gabriele on 05/09/2021.
//

#ifndef TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H
#define TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H

#define n_slot 6

#include <vector>
#include "slot.h"



class giorno{

private:

    vector <slot> _fasce_orarie;
    vector <string> _id_cds_inseriti;
    vector <int> _anni_inseriti;

public:

    giorno();
    bool set_id_esame_nel_giorno(const string &id_esame, const vector <string> &id_cds, const int anno,
                                 const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral);
    void print_cal_giorno();

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H