struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

ListNode* spojiListe(ListNode* lista1, ListNode* lista2)
{
    // ako imamo samo jednu listu za spajanje, vracamo nju posto je ne spajamo ni sa cim
    if (lista1 == NULL)
        return lista2;
    if (lista2 == NULL)
        return lista1;

    ListNode* glava = NULL; // glava nove spojene liste
    ListNode* tmp = NULL;

    while (lista1 && lista2) {
        if (lista1->vrednost <= lista2->vrednost) { // vrednost iz liste 1 ide pre vrednosti iz liste 2
            if (glava == NULL) {                    // ako je glava NULL, onda je prvi cvor liste 1 glava nove liste
                glava = lista1;
                tmp = lista1;                       // "vezujemo" tmp da preko njega punimo novu spojenu listu
            } else {
                tmp->sledeci = lista1;
                tmp = tmp->sledeci;
            }
            lista1 = lista1->sledeci;
        } else {
            if (glava == NULL) {                    // ako je glava NULL, onda je prvi cvor liste 2 glava nove liste
                glava = lista2;
                tmp = lista2;                       // "vezujemo" tmp da preko njega punimo novu spojenu listu
            } else {
                tmp->sledeci = lista2;
                tmp = tmp->sledeci;
            }
            lista2 = lista2->sledeci;
        }
    }

    while (lista1) {
        tmp->sledeci = lista1;
        tmp = tmp->sledeci;
        lista1 = lista1->sledeci;
    }

    while (lista2) {
        tmp->sledeci = lista2;
        tmp = tmp->sledeci;
        lista2 = lista2->sledeci;
    }

    return glava;
}