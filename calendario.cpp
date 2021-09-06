
#include "calendario.h"

calendario::calendario() {

    giorni.resize(n_giorni);

}

bool calendario::set_id_esame_nel_calendario(const string &id_esame, const vector <string> &id_cds,
                                             const vector <string> &anno, const int n_slot_necessari,
                                             const vector<string> &id_professori, int n_vers_paral)
{

    int inserisco_nel_giorno = 0;
    bool trovato_cds_anno;
    vector <string>::iterator it_oggi;
    vector <string>::iterator it_ieri;
    vector <string>::iterator it_domani;

    while(inserisco_nel_giorno < n_giorni)
    {
        trovato_cds_anno = false;
        for(int i=0; i < id_cds.size(); i++)
        {
            it_oggi = find_cds_anno(giorni[inserisco_nel_giorno].get_id_cds_inseriti().begin(),
                                    giorni[inserisco_nel_giorno].get_id_cds_inseriti().end(),
                                    giorni[inserisco_nel_giorno].get_anni_inseriti().begin(),
                                    id_cds[i], anno[i]);

            if(inserisco_nel_giorno != 0)
            {
                it_ieri = find_cds_anno(giorni[inserisco_nel_giorno-1].get_id_cds_inseriti().begin(),
                                        giorni[inserisco_nel_giorno-1].get_id_cds_inseriti().end(),
                                        giorni[inserisco_nel_giorno-1].get_anni_inseriti().begin(),
                                        id_cds[i], anno[i]);
            }
            else
            {
                it_ieri = giorni[inserisco_nel_giorno-1].get_id_cds_inseriti().end();
            }

            if(inserisco_nel_giorno != (n_giorni - 2))
            {
                it_domani = find_cds_anno(giorni[inserisco_nel_giorno+1].get_id_cds_inseriti().begin(),
                                          giorni[inserisco_nel_giorno+1].get_id_cds_inseriti().end(),
                                          giorni[inserisco_nel_giorno+1].get_anni_inseriti().begin(),
                                          id_cds[i], anno[i]);
            }
            else
            {
                it_domani = giorni[inserisco_nel_giorno+1].get_id_cds_inseriti().end();
            }

            if((it_oggi != giorni[inserisco_nel_giorno].get_id_cds_inseriti().end()) ||
               (it_ieri != giorni[inserisco_nel_giorno-1].get_id_cds_inseriti().end()) ||
               (it_domani != giorni[inserisco_nel_giorno+1].get_id_cds_inseriti().end()))
            {
                trovato_cds_anno = true;
            }
        }
        if(!trovato_cds_anno)
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
        else
        {
            inserisco_nel_giorno ++;
            cout<<endl<<"Esame "<<id_esame<<" spostato di un giorno!"<<endl;
        }
    }

    cout<<endl<<"Esame "<<id_esame<<" non inserito nel calendario!"<<endl;
    return false;

}



void calendario::print_calendario() {

    for(int i=0; i < n_giorni; i++)
    {
        cout<<endl<<"Giorno "<<i+1<<": "<<endl;
        cout<<"\t";
        giorni[i].print_cal_giorno();
        cout<<endl;
    }

}

template<class InputIterator, class T>
InputIterator
calendario::find_cds_anno(InputIterator first_cds, InputIterator last_cds, InputIterator first_anno, const T& cds,
                          const T& anno) {
    while (first_cds!=last_cds) {
        if ((*first_cds==cds) && (*first_anno==anno)) return first_cds;
        ++first_cds;
        ++first_anno;
    }
    return last_cds;
}