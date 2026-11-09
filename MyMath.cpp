#include <cstring>
#include "MyMath.h"

using namespace std;

const char* FindPair(const char* s)
{
    const char* a = strstr(s, "aa");   // вказівник на перше "aa"
    const char* b = strstr(s, "bb");   // вказівник на перше "bb"
    const char* c = strstr(s, "cc");   // вказівник на перше "cc"
    const char* first = nullptr;       // найраніша з знайдених пар

    if (a != nullptr)
        first = a;
    if (b != nullptr && (first == nullptr || b < first))
        first = b;
    if (c != nullptr && (first == nullptr || c < first))
        first = c;

    return first;
}

bool HasPair(const char* s)
{
    return FindPair(s) != nullptr;
}

char* Change(const char* s)
{
    // кожні 2 символи пари дають 3 зірочки, тому результат не довший за 3/2 від s
    size_t size = strlen(s) * 3 / 2 + 1;
    char* res = new char[size];
    res[0] = '\0';

    const char* p = s;                 // початок ще не опрацьованої частини
    const char* t;                     // початок знайденої пари

    while ((t = FindPair(p)) != nullptr)
    {
        strncat_s(res, size, p, t - p); // символи перед парою
        strcat_s(res, size, "***");     // пара -> "***"
        p = t + 2;                      // продовжуємо одразу після пари
    }
    strcat_s(res, size, p);             // решта рядка

    return res;
}
