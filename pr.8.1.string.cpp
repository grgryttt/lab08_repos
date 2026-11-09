#include <iostream>
#include <string>
#include "MyMath.h"

using namespace std;

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (HasPair(str))
        cout << "String contains a pair of 'aa' or 'bb' or 'cc'" << endl;
    else
        cout << "String does not contain a pair of 'aa' or 'bb' or 'cc'" << endl;

    string dest = Change(str);

    cout << "Modified string: " << dest << endl;

    return 0;
}
