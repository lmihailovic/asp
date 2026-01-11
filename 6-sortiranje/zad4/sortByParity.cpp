vector<int> sortByParity(vector<int> niz)
{
    int indeksParnih = 0;
    int indeksNeparnih = 1;

    int n = niz.size();

    while (indeksParnih < n && indeksNeparnih < n) {
        // ako parni indeks ima parnu vrednost, idemo na sledeci parni
        while (niz[indeksParnih] % 2 == 0 && indeksNeparnih < n)
            indeksParnih += 2;

        // ako neparni indeks ima neparnu vrednost, idemo na sledeci neparni
        while (niz[indeksNeparnih] % 2 != 0 && indeksParnih < n)
            indeksNeparnih += 2;

        // ako je neki indeks prekoracio velicinu niza, prekidamo petlju
        if (indeksParnih > n || indeksNeparnih > n)
            break;

        // zamenimo vrednosti na parnom i neparnom indeksu
        // jer ako smo ovde stigli, ocito neki nije na svom mestu
        swap(niz[indeksParnih], niz[indeksNeparnih]);
    }

    return niz;
}