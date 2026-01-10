int podelaCokoladica(vector<int> paketi, int k)
{
    int n = paketi.size();

    sort(paketi.begin(), paketi.end());

    int najmanjaRazlika = -1;
    int levo = 0;
    int desno = k - 1;

    while (levo < desno) {
        // najveca razlika ce uvek biti izmedju prvog i poslednjeg paketa u opsegu
        // zato nas i ona jedino interesuje,
        // tj. gde je razlika izmedju pocetka i kraja opsega najmanja
        najmanjaRazlika = min(najmanjaRazlika, paketi[desno] - paketi[levo]);

        // pomeramo opseg
        levo += 1;
        desno += 1;
    }

    return najmanjaRazlika;
}