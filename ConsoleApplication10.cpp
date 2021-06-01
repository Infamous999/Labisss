#include <windows.h>
#include <iostream>
using namespace std;

void prob(int i)
{
    for (int k = 0; k < i; k++)
        cout << ' ';
}

void zvezd(int i)
{
    for (int k = 0; k < i; k++)
        cout << '*'; 
}

void clear(int i)
{
    for (int k = 0; k < i; k++)
        cout << endl;
}

int main()
{
    /* Без анимации
****   *    * *     *
*      *  *   **    *
***    * *    * *   *
*      *  *   *  *  *
*      *    * *    **
                                                    */

    for (int i = 1; i < 4; i++)
    {
        
        zvezd(4 * i);
        prob(3 * i);
        zvezd(1 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(1 * i);
        zvezd(1 * i);
        prob(5 * i);
        zvezd(1 * i);
        prob(3 * i);

        

        cout << endl;

       
        zvezd(1 * i);
        prob(6 * i);
        zvezd(1 * i);
        prob(2 * i);
        zvezd(1 * i);
        prob(3 * i);
        zvezd(1 * i);
        prob(0 * i);
        zvezd(1 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(2 * i);
        
       

        cout << endl;

       
        zvezd(3 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(1 * i);
        zvezd(1 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(1 * i);
        zvezd(1 * i);
        prob(3 * i);
        zvezd(1 * i);
        prob(2 * i);
        

        cout << endl;

       
        zvezd(1 * i);
        prob(6 * i);
        zvezd(1 * i);
        prob(2 * i);
        zvezd(1 * i);
        prob(3 * i);
        zvezd(1 * i);
        prob(2 * i);
        zvezd(1 * i);
        prob(2 * i);
        zvezd(1 * i);
        prob(2 * i);
       
        

        cout << endl;

        
        zvezd(1 * i);
        prob(6 * i);
        zvezd(1 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(1 * i);
        zvezd(1 * i);
        prob(4 * i);
        zvezd(1 * i);
        prob(0 * i);
        zvezd(1 * i);
        prob(2 * i);

       
        

        cout << endl;

        clear(19);
        Sleep(900);
    }

    system("pause");
    return 0;
}