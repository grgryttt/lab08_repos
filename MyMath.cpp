#include <algorithm>
#include "MyMath.h"

using namespace std;

size_t FindPair(const string& s, const size_t pos)
{
    size_t a = s.find("aa", pos);   // позиція першого "aa" або npos
    size_t b = s.find("bb", pos);   // позиція першого "bb" або npos
    size_t c = s.find("cc", pos);   // позиція першого "cc" або npos

    return min({ a, b, c });        // npos - найбільше значення, тому min дає найранішу пару
}

bool HasPair(const string& s)
{
    return FindPair(s) != string::npos;
}

string Change(const string& s)
{
    string res;                     // результат
    size_t pos = 0;                 // початок ще не опрацьованої частини
    size_t t;                       // позиція знайденої пари

    while ((t = FindPair(s, pos)) != string::npos)
    {
        res.append(s, pos, t - pos); // символи перед парою
        res += "***";                // пара -> "***"
        pos = t + 2;                 // продовжуємо одразу після пари
    }
    res.append(s, pos, string::npos); // решта рядка

    return res;
}
