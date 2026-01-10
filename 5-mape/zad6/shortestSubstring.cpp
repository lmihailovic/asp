string najmanjiPodstring(string s, string t)
{
    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    int duzinaT = t.size();
    int duzinaS = s.size();

    // leva i desna granica naseg podstringa
    int levo = 0;
    int desno = 0;

    int iskorisceniKarakteri = 0;

    int pocetakResenja = 0;
    int krajResenja = 0;

    for (char slovo : t)
        mapT[slovo] = 1;

    while (desno < duzinaS) {

        // ako nismo iskoristili sve karaktere u stringu T
        if (iskorisceniKarakteri < duzinaT) {

            char trenKar = s[desno];
            mapS[trenKar] += 1;

            // ako novi uhvaceni karakter pripada stringu T
            // i ako ga nas substring ne sadrzi makar
            // onoliko puta koliko se on nalazi u T
            if (mapS[trenKar] <= mapT[trenKar])
                iskorisceniKarakteri += 1;

            // povecavamo nas substring za jedan karakter dalje
            desno += 1;
        } else {
            // ako je trenutni substring manji od najmanjeg validnog,
            // to je onda novo resenje
            if (desno - levo < krajResenja - pocetakResenja || krajResenja == 0) {
                pocetakResenja = levo;
                krajResenja = desno;
            }

            char trenKar = s[levo];

            // karakter koji nam treba iz T nam ispada iz opsega
            // i zato smanjujemo njegovo pojavljivanje u mapi
            if (mapS[trenKar] == mapT[trenKar])
                iskorisceniKarakteri -= 1;

            // karakter ispada iz opsega naseg substringa
            mapS[trenKar] -= 1;
            levo += 1;
        }
    }


    // posto je desna granica dosla do kraja stringa S,
    // sada pomeramo levu granicu dokle god imamo validan substring

    // dokle god koristimo sve karaktere u stringu T
    while (iskorisceniKarakteri == duzinaT) {
        if (desno - levo < krajResenja - pocetakResenja || krajResenja == 0) {
            pocetakResenja = levo;
            krajResenja = desno;
        }

        char trenKar = s[levo];

        // karakter koji nam treba iz T nam ispada iz opsega
        if (mapS[trenKar] == mapT[trenKar])
            iskorisceniKarakteri -= 1;

        // karakter ispada iz opsega naseg substringa
        mapS[trenKar] -= 1;
        levo += 1;
    }

    return s.substr(pocetakResenja, krajResenja - pocetakResenja);
}