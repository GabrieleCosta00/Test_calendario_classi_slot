#include <iostream>
#include "slot.h"
#include <vector>
#include <string>

using namespace std;


int main() {

    slot s1;
    vector <string> esami{"000000","000011", "000022"};
    int n_es_paralleli[3];
    n_es_paralleli[0]=1;
    n_es_paralleli[1]=2;
    n_es_paralleli[2]=3;
    vector <vector <string>> prof_es_inf{{"Mario", "Paolo", "Giovanni"},{"Gabriele", "Marcello", "Simone", "Giorgio"},
                                         {"Luca1", "Luca2", "Luca3", "Luca4", "Luca5", "Luca6"}};

    for (int i=0; i < esami.size(); i++)
    {
        if (s1.set_id_esame_nello_slot(esami[i], prof_es_inf[i], n_es_paralleli[i]))
        {
            s1.print_id_esami();
            s1.print_professori();
        }
        else
        {
            cout<<"Qualcosa e' andato storto!"<<endl;
        }
    }



    return 0;
}
