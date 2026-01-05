struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

ListNode* ukloniDuplikate(ListNode* glava)
{
    ListNode* trenutni = glava;
    // ListNode* tmp;           // potreban ako rucno oslobadjamo memoriju...
                                // ...bitno za jezike bez garbage collector-a...
                                // ...kao sto je C++, inace bi doslo do memory leak-a

    // prolazimo kroz sve cvorove liste
    while (trenutni) {

        // dokle god trenutni i sledeci imaju istu vrednost, brisemo sledeci
        while (trenutni->sledeci &&
                trenutni->vrednost == trenutni->sledeci->vrednost) {
            // tmp = trenutni->sledeci;                     // privremeni pokazivac pokazuje na sledeci cvor
            trenutni->sledeci = trenutni->sledeci->sledeci; // "preskacemo" naredni cvor tj. duplikat
            // free(tmp);                                   // rucno oslobadjamo memoriju
        }

        trenutni = trenutni->sledeci;   // prelazimo na sledeci cvor liste
    }

    return glava;
}