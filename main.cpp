#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

void aggiungiLibro (int opzione, int& num, string titolo[], string autore[], int anno[], string categoria[]);
void cercaLibro (int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]);
void ordinatiPerAutore(int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]);
void stampatiPerCategoria (int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]);

int main () {
    int opzione;
    int num = 0;
    string titolo[1000]={};
    string autore[1000]={};
    int anno[1000]={};
    string categoria[1000]={};
    bool exit = true;

    while (exit) {
        system("clear");
        cout<<"1 --> Aggiungi libro"<<endl<<"2 --> Cerca libro"<<endl<<"3 --> Stampa libri ordinati per autore"<<endl<<"4 --> Stampa libri per categoria"<<endl<<"5 --> Esci"<<endl;
        cout<<"Scegli l'opzione: ";
        cin>>opzione;

        if (opzione==1) {
            system("clear");
            aggiungiLibro (opzione, num, titolo, autore, anno, categoria);
        } else if (opzione==2) {
            system("clear");
            cercaLibro (opzione, num, titolo, autore, anno, categoria);
            } else if (opzione==3) {
                system("clear");
                ordinatiPerAutore (opzione, num, titolo, autore, anno, categoria);
            } else if (opzione==4) {
                system("clear");
                stampatiPerCategoria (opzione, num, titolo, autore, anno, categoria);
            } else if (opzione==5) exit = false;
    }

    return 0;
}

void aggiungiLibro (int opzione, int& num, string titolo[], string autore[], int anno[], string categoria[]) {
    if (opzione==1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Inserisci il titolo del libro: ";
        getline(cin, titolo[num]);
        cout<<"Inserisci l'autore del libro: ";
        getline(cin, autore[num]);
        cout<<"Inserisci l'anno di pubblicazione del libro: ";
        cin>>anno[num];
        cout<<"Inserisci in che categoria si trova il libro: ";
        cin>>categoria[num];
        num++;
        system("clear");
        cout<<"Libro aggiunto!"<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

void cercaLibro (int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]) {
    if (opzione==2) {

    bool notFound = true;
    string parolaDaCercare;
    cout<<"Inserisci il titolo del libro che vuoi cercare: ";
    cin>>parolaDaCercare;

    for (int i = 0; i <= num; i++) {
        if (parolaDaCercare==titolo[i]) {
            system("clear");
            cout<<"Titolo: "<<titolo[i]<<", Autore: "<<autore[i]<<", Anno: "<<anno[i]<<", Categoria: "<<categoria[i]<<endl;
            notFound = false;
            break;
        }
    }
    
    if (notFound) cout<<"Il titolo del libro non è stato trovato"<<endl;
    
    }
    this_thread::sleep_for(chrono::seconds(2));
}

void ordinatiPerAutore(int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]) {
    if (opzione == 3) {

        string titoloOrdinato[1000];
        string autoreOrdinato[1000];
        int annoOrdinato[1000];
        string categoriaOrdinata[1000];

        for (int i = 0; i < num; i++) {
            titoloOrdinato[i] = titolo[i];
            autoreOrdinato[i] = autore[i];
            annoOrdinato[i] = anno[i];
            categoriaOrdinata[i] = categoria[i];
        }

        for (int i = 0; i < num - 1; i++) {
            for (int j = i + 1; j < num; j++) {
                if (autoreOrdinato[i] > autoreOrdinato[j]) {
                    swap(autoreOrdinato[i], autoreOrdinato[j]);
                    swap(titoloOrdinato[i], titoloOrdinato[j]);
                    swap(annoOrdinato[i], annoOrdinato[j]);
                    swap(categoriaOrdinata[i], categoriaOrdinata[j]);
                }
            }
        }

        cout<<"\nLibri ordinati per autore\n";
        for (int i = 0; i < num; i++) {
            cout<<"Titolo: "<<titoloOrdinato[i]<<", Autore: "<<autoreOrdinato[i]<<", Anno: "<<annoOrdinato[i]<<", Categoria: "<<categoriaOrdinata[i]<<endl;
        }
        this_thread::sleep_for(chrono::seconds(5));
    }
}

void stampatiPerCategoria (int opzione, int num, string titolo[], string autore[], int anno[], string categoria[]) {    
    if (opzione==4) {
        int firstCount = 0;
        string firstCountCategory[1000];
        cout<<"----- Ecco le categorie che ci sono -----"<<endl;

        for (int i = 0; i < num; i++) {
            bool foundCategory = false;
            for (int k = 0; k < firstCount; k++) {
                if (categoria[i]==firstCountCategory[k]) {
                    foundCategory = true;
                    break;
                }
            }

            if (!foundCategory) {
                firstCountCategory[firstCount] = categoria[i];
                firstCount++;
            }
        }
        
        for (int i = 0; i < firstCount; i++) {
            cout<<firstCountCategory[i]<<endl;
        }

        string categoriaInput;
        bool notFound = true;
        cout<<"Inserisci la categoria che vuoi stampare: ";
        cin>>categoriaInput;

        for (int i = 0; i < num; i++) {
            if (categoria[i]==categoriaInput) {
                cout<<"Titolo: "<<titolo[i]<<", Autore: "<<autore[i]<<", Anno: "<<anno[i]<<", Categoria: "<<categoria[i]<<endl;
                notFound = false;
            }
        }

        if (notFound) cout<<"Non esiste la categoria che stavi cercando"<<endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}