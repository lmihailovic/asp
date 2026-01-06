struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

ListNode* zameniParove(ListNode* glava)
{
    if (glava == NULL || glava->sledeci == NULL)
        return glava;

    ListNode* prethodni = NULL;
    ListNode* trenutni = glava;
    ListNode* sledeci = glava->sledeci;

    glava = glava->sledeci;

    // TO DO: objasniti slikovitoi i korak po korak donji kod

    while (sledeci) {
        if (prethodni)                          // ako prethodni postoji...
            prethodni->sledeci = sledeci;       // ...sledeci od prethodnog pokazuje na sledeci

        trenutni->sledeci = sledeci->sledeci;   // sledeci postaje cvor nakon sledeceg
        sledeci->sledeci = trenutni;            // cvor nakon sledeceg postaje trenutni

        prethodni = trenutni;                   // prethodni postaje trenutni
        trenutni = trenutni->sledeci;           // trenutni postaje sledeci

        if (trenutni)
            return glava;

        sledeci = trenutni->sledeci;
    }

    return glava;
}