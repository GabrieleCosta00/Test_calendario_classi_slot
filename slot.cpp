//
// Created by Gabriele on 01/09/2021.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "slot.h"

using namespace std;

bool slot::set_id_esame_nello_slot(const string &id_esame, const vector<string> &id_professori, int n_vers_parall) {

    vector<string>::iterator it;

    if ((_id_esami.size() + n_vers_parall) > n_max_es_in_slot)
    {
        cout<<endl<<"Massima capienza dello slot raggiunta! (esame "<<id_esame<<")"<<endl;
        return false;

    } else {

        for(int j=0; j < id_professori.size(); j++)
        {
            it = find(_id_professori.begin(), _id_professori.end(), id_professori[j]);
            if (it != _id_professori.end())
            {
                cout << "Professore già impegnato con un altro esame!" << endl;
                return false;
            }
        }
        for(int j=0; j < id_professori.size(); j++)
        {
            _id_professori.push_back(id_professori[j]);
        }
        for(int k=0; k < n_vers_parall; k++)
        {
            _id_esami.push_back(id_esame);
        }
    }
    return true;
}

const vector<string> &slot::get_id_esami_dallo_slot() const {
    return _id_esami;
}

void slot::print_professori() {
    cout<<endl<<"Professori: ";
    for(auto & i : _id_professori)
    {
        cout<<i<<" ";
    }
}

void slot::print_id_esami() {
    cout<<endl<<"ID esami: ";
    for(auto & i : _id_esami)
    {
        cout<<i<<" ";
    }

}

slot::slot() {

}
