struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};


ListNode* obrisiTrenutniCvor(ListNode* glava, ListNode* prethodni, ListNode* trenutni, ListNode* sledeci)
{
    if (prethodni == NULL)  // ako je trenutni cvor glava, ne moze da ima prethodni...
        glava = sledeci;    // ...time je nova glava sledeci cvor
    else
        prethodni->sledeci = sledeci;   // "preskacemo" trenutni cvor
    // free(trenutni)       // rucno oslobadjamo memoriju za trenutni i obrisani cvor
    return glava;           // vracamo glavu na listu
}

ListNode* ukloniDuplikate(ListNode* glava)
{
    ListNode* prethodni = NULL;
    ListNode* trenutni = glava;
    ListNode* sledeci = NULL;

    bool jesuIsti = false;  // oznacava da li su dva uzastopna cvora isti

    while (trenutni) {
        sledeci = trenutni->sledeci;

        // ako su trenutni i sledeci cvor isti, brisemo trenutni
        if (sledeci && trenutni->vrednost == sledeci->vrednost) {
            jesuIsti = true;
            glava = obrisiTrenutniCvor(glava, prethodni, trenutni, sledeci);
        } else if (jesuIsti) {

            // ako su prethodna dva cvora bili jednaki, onda je trenutni cvor
            // poslednji preostali duplikat, te i njega brisemo
            jesuIsti = false;
            glava = obrisiTrenutniCvor(glava, prethodni, trenutni, sledeci);
        } else {
            jesuIsti = false;
            prethodni = trenutni;
        }
        trenutni = sledeci;
    }

    return glava;
}