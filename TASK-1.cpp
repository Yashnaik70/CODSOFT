#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

class Guessnumber
{
    int userguees;

public:

    void userinput()
    {
    
        cout << "\n\t\tENTER YOUR NUMBER BETWEEN( 1 TO 100 ) : ";
        cin >> userguees;
    }
    void output(int random)
    {
        userinput();
        if (userguees > random)
        {
            cout << "\n\t\t...OOps Gussed Number is Too High !!!\n";
        }
        else if (userguees < random)
        {
            cout << "\n\t\t...OOps Gussed Number is Too Low !!!\n";
        }
        else
        {
            cout << "\n\t\t...Congratulation !!,\n\t\tYour Gussed Number is Correct\n";
        }
    }
};

int main()
{
    Guessnumber G;
    cout<<"\n\t\t------GUESS THE NUMBER------\n";
    do
    {
        srand(time(0));
        int random = (rand() % 100) + 1;
        // cout << "Random Number Is ( for example ):" << random;
        G.output(random);
    } while (true);
    return 0;
}