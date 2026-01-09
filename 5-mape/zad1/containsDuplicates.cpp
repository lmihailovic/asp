bool sadrziDuplikate(vector<int>& niz)
{
    // inicijalizujemo praznu mapu...
    // sa kljucem int, i vrednoscu bool za svaki kljuc
    unordered_map<int, bool> mapa;

    // ekvivalentno petlji: foreach element in niz (od verzije C++ 11)
    for (const int element : niz) { // const => obecavamo da ne menjamo element unutar vektora
        if (mapa[element])          // ako za kljuc "element" imamo vrednost true,
            return true;            // znaci da smo vec videli taj element => duplikat

        mapa[element] = true;   // prvi put vidimo ovaj element => dodajemo ga u mapu
    }
    return false;
}