pair<int, int> najbliziElementi(vector<int> niz)
{
    sort(niz.begin(), niz.end());

    int najmanjaRazlika = a[1] - a[0];
    pair <int, int> resenje = {a[0], a[1]};

    for (int i = 2; i < niz.size(); i++) {
        if (a[i] - a[i - 1] < najmanjaRazlika) {
            najmanjaRazlika = a[i] - a[i - 1];
            resenje = {a[i - 1], a[i]};
        }
    }

    return resenje;
}