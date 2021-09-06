//
// Created by Gabriele on 06/09/2021.
//

#include "calendario.h"
#include <iostream>

using namespace std;

calendario::calendario() {

    giorni.resize(n_giorni);

}

bool calendario::set_id_esame_nel_calendario(const string &id_esame, const vector<string> &id_cds, const int anno,
                                             const int n_slot_necessari, const vector<string> &id_professori,
                                             int n_vers_paral)
{

    int inserisco_nel_giorno = 0;

    while(inserisco_nel_giorno < n_giorni)
    {
        if(!giorni[inserisco_nel_giorno].set_id_esame_nel_giorno(id_esame, id_cds, anno, n_slot_necessari, id_professori, n_vers_paral))
        {
            inserisco_nel_giorno ++;
        }
        else
        {
            return true;
        }
    }

    cout<<"Esame "<<id_esame<<" non inserito nel calendario!"<<endl;
    return false;

}

void calendario::print_calendario() {

    for(int i=0; i < n_giorni; i++)
    {
        cout<<"Giorno "<<i+1<<": "<<endl;
        cout<<"\t";
        giorni[i].print_cal_giorno();
        cout<<endl;
    }

}