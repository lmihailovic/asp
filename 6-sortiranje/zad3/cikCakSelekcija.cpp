vector<int> cikCakSelekcija(vector<int> niz)
{
    sort(niz.begin(), niz.end());
    vector<int> resenje;

    int levo = 0;
    int desno = niz.size() - 1;

    for (int i = 0; i < niz.size(); i++) {
        if (i % 2 == 0) {
            resenje[levo] = niz[i];
            levo += 1;
        } else {
            resenje[desno] = niz[i];
            desno -= 1;
        }
    }

    return resenje;
}