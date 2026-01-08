struct ListNode
{
    int vrednost;
    struct ListNode *sledeci;
};

ListNode* particije(ListNode* glava, int x)
{
    ListNode* leviStart = NULL;
    ListNode* desniStart = NULL;
    ListNode* leviTrenutni = NULL;
    ListNode* desniTrenutni = NULL;
    ListNode* trenutni = glava;

    while (trenutni) {

        // pamtimo sledeci cvor koji treba da posetimo
        ListNode* sledeci = trenutni->sledeci;

        if (trenutni->vrednost < x) {
            if (leviStart == NULL) {    // ako je leva lista prazna...
                leviStart = trenutni;   // ...postavljamo joj glavu
                leviTrenutni = leviStart;
                leviTrenutni->sledeci = NULL;
            } else {                    // ako nije prazna, samo postavljamo vrednost sledeceg cvora leve liste
                leviTrenutni->sledeci = trenutni;
                leviTrenutni = leviTrenutni->sledeci;
                leviTrenutni->sledeci = NULL;
            }
        } else {
            if (desniStart == NULL) {   // ako je desna lista prazna...
                desniStart = trenutni;  // ...postavljamo joj glavu
                desniTrenutni = desniStart;
                desniTrenutni->sledeci = NULL;
            } else {                    // ako nije prazna, samo postavljamo vrednost sledeceg cvora desne liste
                desniTrenutni->sledeci = trenutni;
                desniTrenutni = desniTrenutni->sledeci;
                desniTrenutni->sledeci = NULL;
            }
        }

        trenutni = sledeci;
    }

    // ako leva lista nije prazna,
    // spajamo je sa desnom listom,
    // i postavljamo glavu na pocetak leve liste
    if (leviStart) {
        glava = leviStart;
        leviTrenutni->sledeci = desniStart;
    } else {    // inace postavljamo glavu na pocetak desne liste
        glava = desniStart;
    }

    return glava;
}
