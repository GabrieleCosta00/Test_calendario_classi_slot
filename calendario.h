
#ifndef TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H
#define TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H

#include "sessione.h"

class calendario {

private:

    vector<sessione> _sessioni;

public:

    calendario();

    bool set_id_esame_nel_calendario(const string &id_esame, const vector<string> &id_cds, const vector<string> &anno,
                                     const int n_slot_necessari, const vector<string> &id_professori, int n_vers_paral,
                                     const vector<string> &semestre_dell_esame);

    void print_calendario();

};


#endif //TEST_CALENDARIO_CLASSI_SLOT_CALENDARIO_H