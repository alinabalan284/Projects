#include <iostream>
#include <string>
#include <vector>

using namespace std;


class MagazinPlinException {
public:
    MagazinPlinException(){};

    string getMessage() {
        return "Magazinul este plin!\n\n";
    }
};

class ProdusInexistentException {
private:
    int id;
public:
    ProdusInexistentException(int id){
        this->id=id;
    };

    string getMessage() {
        return "Produsul cu id-ul: " + to_string(id) + " nu a fost gasit!\n\n";
    }
};

class Produs {
private:
    int id;
    string nume;
    double pret;

public:
    Produs() {
        this->id = 0;
        this->nume = "";
        this->pret = 0;
    }

    Produs(int id, string nume, double pret){
        this->id = id;
        this->nume = nume;
        this->pret = pret;
    }

    void setId(int id) {
        this->id = id;
    }

    void setNume(string nume) {
        this->nume = nume;
    }

    void setPret(double pret) {
        this->pret = pret;
    }

    int getId() {
        return id;
    }

    string getNume() {
        return nume;
    }

    double getPret() {
        return pret;
    }

    virtual void scrieProdus() {
        cout << "id: " << this->getId();
        cout << ", nume: " << this->getNume();
        cout << ", pret: " << this->getPret();

    }


    virtual void citesteProdus() {
        cout << "Id: ";
        cin >> id;
        cout << "Nume: ";
        cin.ignore();
        getline(cin,nume);
        cout << "Pret: ";
        cin >> pret;
    }
};

class Frigider : public Produs {
private:
    int volum;
    bool areCongelator;

public:
    Frigider() : Produs() {
        this->volum = 0;
        this->areCongelator = false;
    }

    Frigider(int id, string nume, double pret, int volum, bool areCongelator) : Produs(id, nume, pret) {
        this->volum = volum;
        this->areCongelator = areCongelator;
    }

    void setVolum(int volum) {
        this->volum = volum;
    }

    void setAreCongelator(bool areCongelator) {
        this->areCongelator = areCongelator;
    }

    int getVolum() {
        return volum;
    }

    bool getAreCongelator() {
        return areCongelator;
    }

    void scrieProdus() {
        cout << "Frigider: { ";
        Produs::scrieProdus();
        cout << ", volum: " << this->getVolum();
        cout << ", areCongelator: ";
        if(this->getAreCongelator())
            cout << "da";
        else
            cout << "nu";
        cout << " }" << endl;
    }

    void citesteProdus() {
        cout << "Introduceti datele pentru frigider: " << endl;
        Produs::citesteProdus();
        cout << "Volum: ";
        cin >> volum;
        cout << "Are Congelator (Introduceti '0' sau '1'): ";
        cin >> areCongelator;
        cout << endl;
    }
};

class MasinaDeSpalat : public Produs{
private:
    int rotatiiPeMinut;
    string clasaEnergetica;

public:
    MasinaDeSpalat() : Produs() {
        this->rotatiiPeMinut = 0;
        this->clasaEnergetica = "";
    }

    MasinaDeSpalat(int id, string nume, double pret, int rotatiiPeMinut, string clasaEnergetica) : Produs(id, nume, pret){
        this->rotatiiPeMinut = rotatiiPeMinut;
        this->clasaEnergetica = clasaEnergetica;
    }

    void setRotatiiPeMinut(int rotatiiPeMinut) {
        this->rotatiiPeMinut = rotatiiPeMinut;
    }

    void setClasaEnergetica(string clasaEnergetica) {
        this->clasaEnergetica = clasaEnergetica;
    }

    int getRotatiiPeMinut() {
        return rotatiiPeMinut;
    }

    string getClasaEnergetica() {
        return clasaEnergetica;
    }

    void scrieProdus()  {
        cout << "Masina De Spalat: { ";
        Produs::scrieProdus();
        cout << ", rotatiiPeMinut: " << this->getRotatiiPeMinut();
        cout << ", clasaEnergetica: " << this->getClasaEnergetica();
        cout << " }" << endl;
    };

    void citesteProdus()  {
        cout << "Introduceti datele pentru masina de spalat: " << endl;
        Produs::citesteProdus();
        cout << "Rotatii Pe Minut: ";
        cin >> rotatiiPeMinut;
        cout << "Clasa Energetica: ";
        cin.ignore();
        getline(cin,clasaEnergetica);
        cout << endl;
    }
};

class Magazin {
private:
    int nrProduse;
    vector<Produs*> produse;

public:
    Magazin(int nrProduse){
        this->nrProduse = nrProduse;
    }

    void adaugaProdus(Produs* produs) {
        try {
            if(produse.size() >= nrProduse) {
                throw MagazinPlinException();
            }
            produse.push_back(produs);
            cout << "Produsul a fost adaugat cu succes!" << endl << endl;
        } catch (MagazinPlinException& exception) {
            cout << exception.getMessage();
        }
    }

    void eliminaProdus(int idProdus) {
        try {
            bool gasit = false;
            for (int i = 0; i < produse.size(); i++) {
                if (idProdus == produse[i]->getId()) {
                    gasit = true;
                    Produs *produs = produse[i];
                    produse.erase(produse.begin() + i);
                    delete produs;
                    break;
                }
            }
            if (!gasit) {
                throw ProdusInexistentException(idProdus);
            }
            cout << "Produsul a fost eliminat cu succes" << endl << endl;
        } catch (ProdusInexistentException exception) {
            cout << exception.getMessage();
        }

    }

    Produs* cautaProdus(int idProdus) {
        try {
            for (int i = 0; i < produse.size(); i++) {
                if (idProdus == produse[i]->getId()) {
                    return produse[i];
                }
            }
            throw ProdusInexistentException(idProdus);

        } catch (ProdusInexistentException exception) {
            cout << exception.getMessage();
            return nullptr;
        }
    }

    void scrieProduse() {
        int size = produse.size();
        cout<<"Produsele din magazin sunt: "<<endl;
        for(int i = 0; i < nrProduse; i++) {
            if(i < size) {
                produse[i]->scrieProdus();
            } else {
                cout << "NULL" << endl;
            }
        }
        cout << endl;
    }

    int numaraMasiniDeSpalat() {
        int nrMs = 0;
        int size = produse.size();
        for(int i = 0; i < size; i++) {
            if(dynamic_cast<MasinaDeSpalat*>(produse[i]))
                nrMs++;
        }
        return nrMs;
    }

    Produs* operator [](int idProdus) {
        return cautaProdus(idProdus);
    }
};

int main() {
    cout << "Introduceti numarul de produse din magazin: ";
    int nrProduse;
    cin >> nrProduse;
    Magazin magazin(nrProduse);
    cout << endl;

    char optiune;
    do {
        cout << "Meniu Magazin:" << endl;
        cout << "- A - Adauga produs" << endl;
        cout << "- E - Elimina produs" << endl;
        cout << "- C - Cauta produs" << endl;
        cout << "- N - Numara masina de spalat" << endl;
        cout << "- L - Scrie produse" << endl;
        cout << "- X - Iesire "<< endl << endl;

        cout << "Introduceti optiunea dorita: ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 'A' : {

                Produs* produs;
                string tipAparat;
                cout << "Introduceti tipul de produs pe care doriti sa il adaugati in magazin ('frigider' sau 'masina de spalat'): ";
                cin.ignore();
                getline(cin,tipAparat);
                cout << endl;
                if(tipAparat == "frigider") {
                    produs = new Frigider;
                } else if(tipAparat == "masina de spalat") {
                    produs = new MasinaDeSpalat;
                } else {
                    cout << "Tip produs inexistent!" << endl << endl;
                    break;
                }
                produs->citesteProdus();
                magazin.adaugaProdus(produs);
                break;
            }
            case 'E' : {
                int idProdus;
                cout << "Introduceti id-ul produsului pe care doriti sa il eliminati: ";
                cin >> idProdus;
                cout << endl;
                magazin.eliminaProdus(idProdus);
                break;
            }
            case 'C' : {
                int idProdus;
                cout << "Introduceti id-ul produsului pe care il cautati: ";
                cin >> idProdus;
                cout << endl;
                Produs* produs = magazin[idProdus];
                if(produs != nullptr) {
                    produs->scrieProdus();
                    cout << endl;
                }
                break;
            }
            case 'N' : {
                cout << "Numarul de masini de spalat din magazin este: " << magazin.numaraMasiniDeSpalat() << endl << endl;
                break;
            }
            case 'L' : {
                magazin.scrieProduse();
                break;
            }
            case 'X' : {
                break;
            }
            default: {
                cout << "Optiunea nu a fost recunoscuta!" << endl << endl;
                break;
            }
        }
    } while (optiune != 'X');

    return 0;
}
