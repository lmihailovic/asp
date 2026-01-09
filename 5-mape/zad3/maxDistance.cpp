int najveceRastojanje(vector<int>& niz)
{
    unordered_map<int, int> mapa;
    int najveceRastojanje = -1;

    for (int i = 0; i < niz.size(); i++) {
        if (mapa.find(niz[i]) != mapa.end())    // ako mapa vec sadrzi element sa tim kljucem...
            // onda vrati max od vec najveceg rastojanja, i rastojanja pozicije trenutnog elementa
            // sa pozicijom prvog pojavljvanja njegove vrednosti u nizu
            najveceRastojanje = max(najveceRastojanje, i - mapa[niz[i]]);
        else
            mapa[niz[i]] = i;
    }

    return najveceRastojanje;
}