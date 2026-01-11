int najmanjeRazlicitih(vector<int> niz, int k)
{
    sort(niz.begin(), niz.end());

    vector<int> brojPojavljivanja;  // broj pojavljivanja svakog broja u nizu
    int pojavljivanjeBroja = 1;     // svaki broj se pojavljuje bar jednom

    for (int i = 1; i < niz.size(); i++) {
        if (niz[i] != niz[i - 1]) {
            brojPojavljivanja.push_back(pojavljivanjeBroja);
            pojavljivanjeBroja = 0;
        }
        pojavljivanjeBroja += 1;
    }

    // dodajemo poslednji broj ako je isti kao pretposlednji
    brojPojavljivanja.push_back(pojavljivanjeBroja);

    sort(brojPojavljivanja.begin(), brojPojavljivanja.end());

    // brojac za niz sa brojem pojavljivanja svakog elementa niza
    int i = 0;

    while (k > 0 && i < brojPojavljivanja.size()) {
        // smanjujemo k za koliko puta se pojavljuju brojevi
        // u nizu, pocevsi od najredjih brojeva
        k -= brojPojavljivanja[i];

        if (k >= 0) // ako jos uvek mozemo da brisemo brojeve iz niza
            i += 1; // idemo na sledeci broj pojavljivanja nekog elementa niza
    }

    // vracamo broj jedinstvenih elementa koje ne mozemo da obrisemo sa K brisanja
    return brojPojavljivanja.size() - i;
}