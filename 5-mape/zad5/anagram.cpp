bool jeAnagram(string s, string t)
{
    unordered_map<char, int> mapa;

    if (s.size() != t.size())   // anagrami ne mogu imati razlicit broj slova
        return false;

    for (char slovo : s)
        mapa[slovo] += 1;

    for (char slovo : t)
        mapa[slovo] -= 1;

    for (auto slovo : mapa)
        if (slovo.second != 0)  // ako nije 0, znaci da se slovo ne nalazi u oba stringa isto broj puta
            return false;

    return true;
}
