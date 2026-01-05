struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

ListNode* okreniListu(ListNode* glava)
{
    ListNode* trenutni = glava; // glava liste
    ListNode* prosli = NULL;    // pokazivac za prethodni element
    ListNode* sledeci = NULL;   // pokazivac na sledeci elemenet

    while (trenutni) {          // prolazak kroz listu (dokle god trenutni nije NULL)

        sledeci = trenutni->sledeci;    // pamtimo sledeci element koji moramo da posetimo
        trenutni->sledeci = prosli;     // trenutni element stavljamo da pokazuje na prethodni
        prosli = trenutni;              // trenutni postaje prethodni za sledeci prolaz petlje
        trenutni = sledeci;             // pomeramo se na sledeci element
    }

    glava = prosli;
    return glava;
}