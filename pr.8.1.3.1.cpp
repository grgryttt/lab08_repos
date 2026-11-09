

#include <iostream>
#include "MyMath.h"

using namespace std;

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (HasPair(str))
        cout << "String contains a pair of 'aa' or 'bb' or 'cc'" << endl;
    else
        cout << "String does not contain a pair of 'aa' or 'bb' or 'cc'" << endl;

    char* dest = Change(str);

    cout << "Modified string: " << dest << endl;

    delete[] dest;

    return 0;
}

