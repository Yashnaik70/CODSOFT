#include <iostream>
using namespace std;

class ARITHMETIC
{
private:
    float output;
    char Operator;

public:
    void Output(float Number1, float Number2)
    {
        // TAKING THE ARITHMETIC OPERATOR...
        cout << "\n\n\t\tENTER THE ARITHMETIC OPERATOR (+ , - , * , / ) : ";
        cin >> Operator;
        // SWITCHING THE OPERATOR..
        switch (Operator)
        {
        case '+':
            cout << "\n\t\t==========================================";
            cout << "\n\t\tTHE ADDITION OF TWO NUMBERS ----";
            output = Number1 + Number2;
            cout << "\n\n\t\t " << Number1 << "\t" << Operator << "\t" << Number2 << "\t"
                 << "="
                 << "\t" << output;
            cout << "\n\t\t==========================================";
            break;
        case '-':
            cout << "\n\t\t==========================================";
            cout << "\n\t\tTHE SUBSTRACTION OF TWO NUMBERS ----";
            output = Number1 - Number2;
            cout << "\n\n\t\t " << Number1 << "\t" << Operator << "\t" << Number2 << "\t"
                 << "="
                 << "\t" << output;
            cout << "\n\t\t==========================================";
            break;
        case '*':
            cout << "\n\t\t==========================================";
            cout << "\n\t\tTHE MULTIPLICATION OF TWO NUMBERS ----";
            output = Number1 * Number2;
            cout << "\n\n\t\t " << Number1 << "\t" << Operator << "\t" << Number2 << "\t"
                 << "="
                 << "\t" << output;
            cout << "\n\t\t==========================================";
            break;
        case '/':
            cout << "\n\t\t==========================================";
            if (Number2 == 0)
            {
                cout << "\n\t\tCAN NOT DIVIDE BY ZERO ( 0 )..";
                cout << "\n\t\t==========================================";
            }
            else
            {
                cout << "\n\t\tTHE DIVISION OF TWO NUMBERS ----";
                output = Number1 / Number2;
                cout << "\n\n\t\t " << Number1 << "\t" << Operator << "\t" << Number2 << "\t"
                     << "="
                     << "\t" << output;
                cout << "\n\t\t==========================================";
            }
            break;
        default:
            cout << "\n\t\t INVALID CHOICE...!";
            break;
        }
    }
};

int main()
{
    do
    {
        ARITHMETIC A;
        float Number1, Number2;
        // TAKING THE TWO NUMBERS AS A FROM THE USER
        cout << "\n\t\t-------Simple Calculator-------";
        cout << "\n\t\t===============================";
        cout << "\n\t\tENTER THE FIRST NUMBER  :";
        cin >> Number1;
        cout << "\n\t\tENTER THE SECOND NUMBER :";
        cin >> Number2;
        // FUNCTION CALL.
        A.Output(Number1, Number2);
    } while (true);
    return 0;
}
