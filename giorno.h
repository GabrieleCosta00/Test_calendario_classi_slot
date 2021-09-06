
#ifndef TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H
#define TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H

#define n_slot 6

#include "slot.h"


class giorno{

private:

    vector <slot> _fasce_orarie;
    vector <string> _id_cds_inseriti;
    vector <string> _anni_inseriti;

public:

    giorno();
    bool set_id_esame_nel_giorno(const string &id_esame, const vector <string> &id_cds, const vector <string> &anno,
                                 const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral);
    void print_cal_giorno();
    vector<string> &get_id_cds_inseriti();
    vector<string> &get_anni_inseriti();

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_GIORNO_H