vector<int> zajednickiElementi(vector<int> niz1, vector<int> niz2)
{
    vector<int> zajednicki;

    sort(niz1.begin(), niz1.end());
    sort(niz2.begin(), niz2.end());

    int brojac1 = 0;
    int brojac2 = 0;

    int najskorijeDodati = -1;

    while (brojac1 < niz1.size()
        && brojac2 < niz2.size()
        && najskorijeDodati != niz1[brojac1]) {

        if (niz1[brojac1] == niz2[brojac2]) {
            zajednicki.push_back(niz1[brojac1]);
            najskorijeDodati = niz1[brojac1];   // pamtimo najskorije dodati
                                                // da ga ne bi dodali opet kao duplikat
            brojac1 += 1;
            brojac2 += 1;
        } else if (niz1[brojac1] < niz2[brojac2])
            brojac1 += 1;
        else
            brojac2 += 1;
    }

    return zajednicki;
}