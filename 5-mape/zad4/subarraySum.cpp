int podnizoviSuma(vector<int>& niz, int k)
{
    unordered_map<int, int> mapa;
    int brojPodnizova = 0;
    int suma = 0;
    mapa[0] = 1;    // postoji prefiksna suma 0 - tj. prazan podniz

    for (int i = 0; i < niz.size(); i++) {
        suma += niz[i];
        brojPodnizova += mapa[suma - k];    // nece vratiti 0 ako vec imamo podnizove cija suma je K
        mapa[suma]++;
    }


    return brojPodnizova;
}