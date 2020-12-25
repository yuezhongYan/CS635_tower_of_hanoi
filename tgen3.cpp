#include <iostream>
using namespace std;

int main()
{
    char t1, t2;    // input is a char
    
    cout << "Tower from: "; cin >> t1;
    cout << "Tower to  : "; cin >> t2;
    
    char *t[] = {   (char *)"AAAAAAAAAA", 
                    (char *)"BBBBBBBBBB", 
                    (char *)"CCCCCCCCCC"
                };
    
    cout << t1 << ' ' << t2 << ' ' << endl;
    cout << t[3 - (t1 - 'A') - (t2 - 'A')];

    return 0;
}
