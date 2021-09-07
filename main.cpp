/*Per i corsi spenti è sufficiente inserirli come di pertinenza del semestre 3 (s3). In questo modo vengono gestiti
opportunamente: risultano inseriti solo nei secondi appelli e nella sessione autunnale
La gestione delle indisponibilità dei professori è impostata, ma commentata*/


#include "Genera_esami.h"

int main() {

    Genera_esami cal1;
    vector<vector<string>> esami{{"000000", "000033"},
                                 {"000011"},
                                 {"000022"},
                                 {"000033", "000000"}};
    vector<int> n_esami_raggruppati{2, 1, 1, 2};
    vector<vector<int>> n_es_paralleli{{1, 1},
                                       {2},
                                       {3},
                                       {1, 1}};
    vector<vector<vector<string>>> cds{{{"cds1"}, {"cds7"}},
                                       {{"cds1", "cds3"}},
                                       {{"cds4", "cds5", "cds6"}},
                                       {{"cds7"}, {"cds1"}}};
    vector<vector<string>> anni{{"a2", "a2"},
                                {"a2"},
                                {"a1"},
                                {"a2", "a2"}};
    vector<string> semestri{"s1", "s2", "s1", "s1"};
    vector<vector<int>> n_slot_necessari{{3, 3},
                                         {1},
                                         {2},
                                         {3, 3}};
    vector<vector<vector<string>>> prof_esami{{{"Mario",    "Paolo",    "Giovanni"}, {"Sandro1", "Sandro2"}},
                                              {{"Gabriele", "Marcello", "Simone", "Giorgio"}},
                                              {{"Luca1",    "Luca2",    "Luca3",  "Luca4", "Luca5", "Luca6"}},
                                              {{"Sandro1",  "Sandro2"},              {"Mario",   "Paolo", "Giovanni"}}};

    for (int i = 0; i < esami.size(); i++) {
        if (!cal1.set_id_esame_nel_calendario(n_esami_raggruppati[i], esami[i], cds[i], anni[i], n_slot_necessari[i],
                                              prof_esami[i],
                                              n_es_paralleli[i], semestri[i])) {
//            cout<<endl<<"Qualcosa e' andato storto!"<<endl;
        }
    }

    cal1.print_calendar();

}