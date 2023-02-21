#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

void prentaToflu(char *pf,  int radir, int dalkar) {
    for (int i = 0; i < radir; i++) {
        for (int j = 0; j < dalkar; j++) {
            cout << *pf << "  ";
            pf++;
        }
        cout << "\n";
    }
}

void prentaFjoldaStafa(int *pf, int lengdLista) {
    int counter = 0;
    for (int i = 0; i < lengdLista; i++) {
        cout << char(65 + i) << ":" << *pf++ << "\t";
        counter++;
        if (counter == 7) {
            cout << "\n";
            counter = 0;
        }
    }
    cout << "\n";
}

void SynaAlgengasta(int *pf, int lengdLista) {
    char algengustu[26] = {'A'};
    char *Apf = algengustu;
    int *BUpf = pf;

    /*
    tekinn kóði frá https://stackoverflow.com/questions/7719978/finding-max-value-in-an-array til þess að finna hæsta value í lista.
    Breytti kóðanum smá til þess að passa við það sem ég vildi að það gerði
    Gat gert þetta sjálfur en vildi checkea hvort það væri max_value fall í c++
    */

    int highNum = 0; // Bý til breytu sem á að geyma hæsta gildið í listanum
    for (int m = 0 ; m < lengdLista; m++) { // fer í gegnum listann
        if (*pf >= highNum) { // og ef næsta númerið í listanum er jafnt eða hærri en current hæsta númerið þá skipti ég því út
            highNum = *pf;
        }
        pf++;
    }

    pf = BUpf;
    int lengdAlgengustu = 0;
    for (int k = 0; k < lengdLista; k++) {
        if (*pf == highNum) {
            algengustu[lengdAlgengustu] = 'A' + k;
            lengdAlgengustu++;
        }
        pf++;
    }
    
    if (lengdAlgengustu >= 3) {
        for (int o = 0; o < (lengdAlgengustu - 2); o++) {
            cout << *Apf << ", ";
            Apf++;
        }
        cout << *Apf << " og ";
        Apf++;
        cout << *Apf;
    }
    else if (lengdAlgengustu == 2) {
        cout << *Apf++ << " og " << *Apf++;
    }
    else {
        cout << *Apf;
    }
    cout << " kom oftast upp eða " << highNum << " sinnum\n";
    
}

void SynaMinnstu(int *pf, int lengdLista) {
    char algengustu[26] = {'A'};
    char *Apf = algengustu;
    int *BUpf = pf;

    /*
    tekinn kóði frá https://stackoverflow.com/questions/7719978/finding-max-value-in-an-array til þess að finna hæsta value í lista.
    Breytti kóðanum smá til þess að passa við það sem ég vildi að það gerði
    Gat gert þetta sjálfur en vildi checkea hvort það væri max_value fall í c++
    */

    int lowNum = 101; // Bý til breytu sem á að geyma hæsta gildið í listanum
    for (int m = 0 ; m < lengdLista; m++) { // fer í gegnum listann
        if (*pf <= lowNum) { // og ef næsta númerið í listanum er jafnt eða hærri en current hæsta númerið þá skipti ég því út
            lowNum = *pf;
        }
        pf++;
    }

    pf = BUpf;
    int lengdAlgengustu = 0;
    for (int k = 0; k < lengdLista; k++) {
        if (*pf == lowNum) {
            algengustu[lengdAlgengustu] = 'A' + k;
            lengdAlgengustu++;
        }
        pf++;
    }
    
    if (lengdAlgengustu >= 3) {
        for (int o = 0; o < (lengdAlgengustu - 2); o++) {
            cout << *Apf << ", ";
            Apf++;
        }
        cout << *Apf << " og ";
        Apf++;
        cout << *Apf;
    }
    else if (lengdAlgengustu == 2) {
        cout << *Apf++ << " og " << *Apf++;
    }
    else {
        cout << *Apf;
    }
    cout << " kom sjaldnast upp eða " << lowNum << " sinnum\n";
    
}


int main() {
    std::srand(std::time(0));
    char tafla[10][10] = {{0}};
    char *pf = tafla[0];
    int fjoldiStafa[26] = {0};
    int *FSpf = fjoldiStafa;

    int fjoldiStakaIYtraFylki = sizeof(tafla) / sizeof(tafla[0]);
    int fjoldiStakaIInnraFylki = sizeof(tafla[0]) / sizeof(tafla[0][0]);

    for (int i = 0; i < fjoldiStakaIYtraFylki; i++) {
        for (int j = 0; j < fjoldiStakaIInnraFylki; j++) {
            int randTala = (std::rand() % 26);
            tafla[i][j] = 'A' + randTala;
            fjoldiStafa[randTala]++;
        }
    }

    int val;

    do {
        cout << "1. Sýna stafatöfluna\n2. Sýna fjölda af hverjum staf\n3. Sýna stafinn sem er algengastur\n4. Sýna stafinn sem er sjaldgæfastur\n0. Hætta\n";
        cout << "Veldu núna: ";
        cin >> val;
        cout << "\n";

        switch(val){
            case 0:
                cout << "Takk fyrir\n";
                break;
            case 1:
                prentaToflu(pf, sizeof(tafla) / sizeof(tafla[0]), sizeof(tafla[0]) / sizeof(tafla[0][0]));
                break;
            case 2:
                prentaFjoldaStafa(FSpf, (sizeof(fjoldiStafa) / sizeof(fjoldiStafa[0])));
                break;
            case 3:
                SynaAlgengasta(FSpf, (sizeof(fjoldiStafa) / sizeof(fjoldiStafa[0])));
                break;
            case 4:
                SynaMinnstu(FSpf, (sizeof(fjoldiStafa) / sizeof(fjoldiStafa[0])));
                break;
            default:
                cout << "Rangt Innslegið. Reyndur Aftur.\n";
                break;
        }

        cout << "\n";

    } while (val != 0);

    return 0;
}