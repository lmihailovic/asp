vector<int> twoSum(vector<int>& niz, int target)
{
    // [key: value] nam je sada
    // [vrednost: indeks]
    unordered_map<int, int> mapa;

    // klasicna for petlja, jer nam treba indeks 'i'
    for (int i = 0; i < niz.size(); i++) {

        auto drugiSabirak = mapa.find(target - niz[i]); // trazimo da li postoji drugi sabirak
                                                        // tako da je niz[i] + drugiSabirak == target

        if (drugiSabirak != mapa.end())                 // ::find() vraca ::map.end() ako ne nadje element
            return {drugiSabirak->first, i};

        mapa[niz[i]] = i;
    }

    return {0, 0};
}