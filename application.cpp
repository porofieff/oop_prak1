#include "application.h"
#include <iostream>
#include "number.h"
#include "array.h"

using namespace std;

Application::Application()
{

}

int Application::exec()
{
    int ch;
    Array arr;

    while(true)
    {
        ch = menu();
        switch(ch)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter elements" << endl;
                cin >> arr;
                break;
            case 2:
                cout << "Arifmetic avarage - " << arr.calculate_arefmetic_avarage() << endl;
                cout << "Standatd deviation - " << arr.calculate_square() << endl;
                break;
            case 3:
                cout << "1 - Descending" << endl;
                cout << "2 - Ascending" << endl;
                int reverse;
                cin>>reverse;
                if (reverse == 1)
                    arr.qsort(0, arr.sizeo(), false);
                else
                    arr.qsort(0, arr.sizeo(), true);
                break;
            case 4:
                cout << "Input new size" << endl << "> ";
                int num;
                cin >> num;
                arr.change_size(num);
                break;
            case 5:
                cout << "Input index" << endl << "> ";
                int index;
                number elem;
                cin >> index;
                cout << "Input new value" << endl << "> ";
                cin >> elem;
                arr.change_element(index, elem);
                break;
            case 6:
                cout<<arr;
                break;
            default:
                break;
        }
    }
}

int Application::menu()
{
    int ch;

    cout << "1 - Enter value" << endl;
    cout << "2 - Deviation calculation" << endl;
    cout << "3 - Sort the array" << endl;
    cout << "4 - Change array lenth" << endl;
    cout << "5 - Change specific element" << endl;
    cout << "6 - Print array" << endl;
    cout << "0 - Exit" << endl << "> ";

    cin >> ch;
    return ch;
}
