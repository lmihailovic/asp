struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

bool jePalindrom(ListNode* glava)
{
    int duzina = 0;
    ListNode* tmp = glava;

    while (tmp) {
        tmp = tmp->sledeci;
        duzina += 1;
    }

    tmp = glava;

    // pomeramo pokazivac do polovine liste
    // duzina+1 obezbedjuje da za neparne duzine odemo na gornju celobrojnu vrednost
    for (int i = 0; i < (duzina + 1) / 2; i++)
        tmp = tmp->sledeci;

    // okrecemo drugu polovinu liste
    ListNode* glava2 = okreniListu(tmp);    // prvi zadatak

    // prolazimo kroz obe polovine liste
    while (glava && glava2) {

        // ako se u nekom trenutku vrednosti na istoj poziciji razlikuju
        if (glava->vrednost != glava2->vrednost)
            return false;

        glava = glava->sledeci;
        glava2 = glava2->sledeci;
    }
    return true;
}