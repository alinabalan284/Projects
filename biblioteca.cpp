#include <iostream>
#include <string>
#include<vector>

using namespace std;

int status[1000];

struct Carte{
    int cod_identificare;
    string nume;
    string autor;
    int an_publicatie;
    bool imprumutata;
};

struct Pers{
    string numePers;
    int id_carteIMP;

};


void ListCarti(Carte c[], const int k){
    //Carte carte[n];
    cout << "Cartile din biblioteca sunt: ";
    for (int i=0; i < k; i++){
        cout << c[i].nume << ", " ;
    }
    cout << '\n';
}

void ElimCarte (Carte c[], int k) {
    int idElim;
    int index;
    cout << "Introduceti codul de identificare al cartii pe care doriti sa o eliminati!" << endl;
    cin >> idElim;
    for (int i = 0; i < k ; i++) {
        if (c[i].cod_identificare == idElim )
            int index = i;
        //break;
    if(index != -1){
       // k = k - 1;
        for (int i = index; i < k - 1; i++) {
            //c[i].cod_identificare.size() = c[i].cod_identificare.size() - 1;
            // n = n - 1;
            c[i] = c[i + 1];
            i--;
            k--;

        }}
    }
}

/*void ListInfoCarte(Carte c[], const int k){
    int idListInfo;
    cout << "Introduceti codul de identificare al cartii careia doriti a-i afla informatiile!" << endl;
    cin >> idListInfo;
    for (int i = 0; i < k; i++) {
        if (idListInfo == c[i].cod_identificare){
            cout << "Numele cartii: " << c[i].nume << endl;
            cout << "Autorul cartii: " << c[i].autor << endl;
            cout << "Anul publicatiei: " << c[i].an_publicatie << endl;
            if(c[i].imprumutata == 0){
                cout << "Status: Imprumutata." << endl;
            } else if(c[i].imprumutata == 1){
                cout << "Status: Neimprumutata." << endl;
            }
            break;
        }
    }

}*/

    void Imprumut(Pers a[], Carte c[], int idCimp, int k){
    int i, found;
    for(int i = 0; i < k; i++){}
    cout << "Introduceti numele persoanei ce doreste a imprumuta o carte!" << endl;
    cin.ignore();

    getline(cin, a[i].numePers);
    cout << "Introduceti codul de identificare al cartii pe care vreti sa o imprumutati!" << endl;
    cin >> a[i].id_carteIMP;

    if (c[i].cod_identificare == a[i].id_carteIMP){
        found = 1;

        if(found == 1){
        c[i].imprumutata == 1;
        cout << "Carte imprumutata cu succes!" << endl;
    }
    }
}


int main() {
    int optiune;

    cout << "Meniu" << endl;
    cout << "1. Adaugarea unei carti in biblioteca" << endl;
    cout << "2. Listarea tuturor cartilor din biblioteca" << endl;
    cout << "3. Eliminarea unei carti din biblioteca" << endl;
    cout << "4. Imprumutul unei carti de catre o persoana " << endl;
    cout << "5. Listarea informatiilor despre o carte" << endl;
    cout << "6. Listarea informatiilor despre o persoana" << endl;
    //cout << "7. Iesire " << endl;
    //cout << "Introduceti numarul corespunzator optiunii alese!" << endl;
    //cin >> optiune;

    int n = 0;
    Carte *carte;
    cout << "Introduceti numarul de carti pe care doriti sa-l contina biblioteca!"<< endl;
    cin >> n;
    carte = new Carte[n];
    int *idArray;
    idArray = new int[n];
    Pers status[1000];

    Pers idIMP[100];
    Pers persoanaIMP[100];


    while(1) {
        cout << "Introduceti numarul corespunzator optiunii alese!" << endl;
        cin >> optiune;
        switch (optiune) {
            case (1): {
                // do {
                int k = n;
                cout << "Introduceti detaliile cartii pe care doriti sa o adaugati!" << endl;
                for (int i = 0; i < k; i++) {
                    cout << "Codul de identificare al cartii numarul " << i + 1 << " este:" << endl;
                    cin >> carte[i].cod_identificare;
                    cin.ignore();

                    cout << "Numele cartii este:" << endl;
                    getline(cin, carte[i].nume);

                    cout << "Autorul cartii este:" << endl;
                    getline(cin, carte[i].autor);


                    cout << "Anul de publicatie este:" << endl;
                    cin >> carte[i].an_publicatie;
                }

                break;
            }

            case (2):
                ListCarti(carte, n);
                break;
            case (3):
                ElimCarte(carte, n);
                break;
            case (4): {
                int idCimp;
                Imprumut(persoanaIMP, carte, idCimp, n);
            }
                break;

            case (5): {
                //ListInfoCarte(carte, n);
                int idListInfo;
                int found;
                cout << "Introduceti codul de identificare al cartii careia doriti a-i afla informatiile!" << endl;
                cin >> idListInfo;
                for (int i = 0; i < n; i++) {
                    if (idListInfo == carte[i].cod_identificare) {
                        cout << "Numele cartii: " << carte[i].nume << endl;
                        cout << "Autorul cartii: " << carte[i].autor << endl;
                        cout << "Anul publicatiei: " << carte[i].an_publicatie << endl;

                        if (carte[i].cod_identificare == persoanaIMP[i].id_carteIMP)
                            found = 1;

                            if (found == 1)
                                carte[i].imprumutata == 1;

                                if (carte[i].imprumutata == 1) {
                                    cout << "Status: Imprumutata." << endl;
                                } else if (carte[i].imprumutata == 0) {
                                    cout << "Status: Neimprumutata." << endl;
                                }
                               // break;
                    }}
                }break;


            }

        }

    return 0;
}
