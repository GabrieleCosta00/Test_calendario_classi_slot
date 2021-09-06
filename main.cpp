
#include "calendario.h"

int main() {

    calendario cal1;
    vector <string> esami {"000000","000011", "000022"};
    int n_es_paralleli[3] = {1, 2, 3};
    vector <vector <string>> cds{{"cds1"}, {"cds1", "cds3"}, {"cds4", "cds5", "cds6"}};
    vector <vector <string>> anni{{"a2"}, {"a2", "a2"}, {"a1", "a1", "a1"}};
    vector <vector <string>> semestri{{"s1"}, {"s2", "s2"}, {"s1", "s1", "s1"}};
    int n_slot_necessari[3] = {3, 1, 2};
    vector <vector <string>> prof_esami{{"Mario", "Paolo", "Giovanni"}, {"Gabriele", "Marcello", "Simone", "Giorgio"},
                                        {"Luca1", "Luca2", "Luca3", "Luca4", "Luca5", "Luca6"}};

    for (int i=0; i < esami.size(); i++)
    {
        if (!cal1.set_id_esame_nel_calendario(esami[i], cds[i], anni[i], n_slot_necessari[i], prof_esami[i],
                                                   n_es_paralleli[i], semestri[i]))
        {
            cout<<"Qualcosa e' andato storto!"<<endl;
        }
    }

    cal1.print_calendario();

}