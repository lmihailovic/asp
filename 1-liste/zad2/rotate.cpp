struct ListNode
{
    int val;
    struct ListNode *sledeci;
};

int duzinaListe(ListNode* glava)
{
    int duzina = 0;

    ListNode* trenutni = glava;

    // TO DO: da li je bolje oduzeti 1 na kraju petlje ili imati ovaj if unutar petlje da ne bi brojali i null??
    while (trenutni) {
        duzina += 1;                    // dodajemo 1 za svaki cvor liste
        if (trenutni->sledeci == NULL)  // ako je trenutni poslednji element...
            break;                      // ...zavrsavamo sa brojanjem duzine

        trenutni = trenutni->sledeci;
    }

    return duzina;
}

ListNode* rotirajDesno(ListNode* glava, int k)
{
    if (glava == NULL)      // ako je lista prazna, nemamo sta da rotiramo
        return glava;

    int duzinaListe = duzinaListe(glava);

    if (k > duzinaListe)    // ako je k veci od duzine liste, racunamo moduo...
        k %= duzinaListe;   // ... tj. ostatak pri celobrojnom deljenju sa duzinom liste

    if (k == 0)             // ako je k=0, rotiramo za 0 => ne rotiramo
        return glava;

    ListNode* trenutni = glava;
    int brojac = 1;

    // prolazimo kroz listu dok ne dodjemo do k-tog elementa
    while (brojac < k && trenutni) {
        brojac += 1;
        trenutni = trenutni->sledeci;
    }

    ListNode* ktiCvor = trenutni;   // pamtimo k-ti čvor

    // nastavljamo kroz listu sve do poslednjeg elementa
    while (trenutni->sledeci != NULL)
        trenutni = trenutni->sledeci;

    trenutni->sledeci = glava;      // poslednji element sada pokazuje na glavu liste
    glava = ktiCvor->sledeci;       // glava je sada k+1 cvor

    ktiCvor->sledeci = NULL;        // postavljamo poslednji element liste da pokazuje...
                                    // ...na NULL umesto na glavu
    return glava;
}