#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

static void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}


static void Roll(int dice) { // actually rolling
    int numoftimes;
    int num;
    int blegh;
    int total = 0;
    cout << "This is D" << dice << endl;
    cout << "How many dice do you want to roll\n";
    cin >> numoftimes;

    for (int i = 0; i < numoftimes; ++i) {
        
        random_device rd; // Non-deterministic seed source
        mt19937 gen(rd()); // Mersenne Twister engine

        // Create a distribution
        uniform_int_distribution<int> dist(1, dice); // Range 1 to 4

        // Generate random numbers
        num = dist(gen);

        cout << "Your roll is: " << num << endl;
        total = total + num;
    };
    if (numoftimes > 1) {
        cout << "Your total is : " << total << endl;
    };
    cout << "Do you want to roll agian?\n(1)Yes\n(2)No\n";
    cin >> blegh;
    
    if (blegh == 1) {

    }
    else {
        exit(2);
    };
    
}


int main() { // just the main menu.
    while (true) {
        ClearScreen();
        int huh;
        cout << "(1) D4\n" << "(2) D6\n" << "(3) D8\n" << "(4) D10\n" << "(5) D12\n" << "(6) D20\n" << "(7) D100\n" << "(8) Exit";
        cout << endl;
        cin >> huh;
        ClearScreen();
        switch (huh)
        {
        case 1:
            Roll(4);
            break;
        case 2:
            Roll(6);
            break;
        case 3:
            Roll(8);
            break;
        case 4:
            Roll(10);
            break;
        case 5:
            Roll(12);
            break;
        case 6:
            Roll(20);
            break;
        case 7:
            Roll(100);
            break;

        case 8:
            ClearScreen();
            cout << "Are you sure?\nYes(1)\nNo(2)\n";
            cin >> huh;
            if (huh == 1) {
                exit(1);
            }
            else { break; }
        default:
            break;
        };
        

    }
    
    return 0;
} 
