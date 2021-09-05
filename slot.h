//
// Created by Gabriele on 01/09/2021.
//

#ifndef PROVA_CLAENDARIO_CON_CLASSI_SLOT_H
#define PROVA_CLAENDARIO_CON_CLASSI_SLOT_H

#define n_max_es_in_slot 4

#include <vector>
#include <string>

using namespace std;


class slot{

private:

    vector <string> _id_esami;
    vector <string> _id_professori;

public:

    slot();
    bool set_id_esame_nello_slot(const string &id_esame, const vector <string> &id_professori, int n_vers_paral);
    const vector<string> &get_id_esami_dallo_slot() const;
    void print_professori();
    void print_id_esami();





};


#endif //PROVA_CLAENDARIO_CON_CLASSI_SLOT_H
