#include <iostream>
#include <conio.h>
#include <fstream>
#include <cmath>
using namespace std;
// Basic Structures
const int gridSize = 5;
char board[gridSize][gridSize] = {};
// Function Prototypes
void initial();
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
void check(char);
bool checkInput(int, int);
void displayBoard();
void populateBoard();
void typeCasting(string address);
void store();
void loadGame();
// Variable Declaration
int addressI = -1,
    addressCol = -1;
bool checkRowsV, checkColoumsV, checkDiagonalV;
int gridSize1;
char option;
int draw = 0;

main()
{
    string address;
    char ch;
    system("cls");
    initial();

    // Game Start
    system("cls");
    displayBoard();
    for (int i = 0; i < (gridSize1 * gridSize1) - 1; i++)
    {
        store();
        ch = '0';
        cout << "Player 0 turn ";
        cin >> address;
        system("cls");
        typeCasting(address);
        // cout << addressI << endl
        //      << addressCol << endl;
        while (!checkInput(addressI, addressCol))
        {
            displayBoard();
            cout << "Enter Valid Option..." << endl;
            cout << "Player 0 turn ";
            cin >> address;
            system("cls");
            typeCasting(address);
        }
        board[addressI][addressCol] = '0';
        check(ch);
        displayBoard();
        draw++;
        if (checkRowsV || checkColoumsV || checkDiagonalV)
        {
            cout << "\t\t\t\t\t\tWinner is player 0";
            break;
        }
        if (draw == gridSize1 * gridSize1)
        {
            cout << "\t\t\t\t\t\tMatch Tied Between Both players" << endl;
            break;
        }
        cout << "Player X turn ";
        cin >> address;
        ch = 'X';
        system("cls");
        typeCasting(address);
        // cout << addressI << endl
        //      << addressCol << endl;
        while (!checkInput(addressI, addressCol))
        {
            displayBoard();
            cout << "Enter Valid Option..." << endl;
            cout << "Player X turn ";
            cin >> address;
            ch = 'X';
            system("cls");
            typeCasting(address);
        }
        board[addressI][addressCol] = 'X';
        check(ch);
        displayBoard();
        draw++;
        if (checkRowsV || checkColoumsV || checkDiagonalV)
        {
            cout << "\t\t\t\t\t\tWinner is player X";
            break;
        }
        if (draw == gridSize1 * gridSize1)
        {
            cout << "\t\t\t\t\t\tMatch Tied Between Both players" << endl;
        }
    }
}
void initial()
{
    cout << "\n\n\t\t\t\t\t\tTIC TAC TOE\n\n\n";
    cout << "Load Previous Game (Y/N) :- ";
    cin >> option;
    while (option != 'Y' || option != 'N')
    {
        if (option == 'Y')
        {
            loadGame();
            break;
        }
        else if (option == 'N')
        {
            cout << "Let's Start New Game..." << endl
                 << "Enter Grid Size (5 or 3) :- ";
            cin >> gridSize1;
            populateBoard();
            break;
        }
        else
        {
            cout << "Choose Right Option" << endl;
            cin >> option;
        }
    }
}
void check(char ch)
{
    checkRowsV = checkRows(ch);
    checkColoumsV = checkColumns(ch);
    checkDiagonalV = checkDiagonals(ch);
}
void populateBoard()
{
    for (int i = 0; i < gridSize1; i++)
    {
        for (int j = 0; j < gridSize1; j++)
        {
            board[i][j] = '-';
        }
    }
}
bool checkInput(int row, int col)
{
    if (gridSize1 == 5 && row >= 0 && row <= 4 && col >= 0 && col <= 4 && board[row][col] == '-')
    {
        return true;
    }
    else if (gridSize1 == 3 && row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void displayBoard()
{
    char x;
    cout << "\t\t\t\t      ";
    if (gridSize1 == 5)
    {
        cout << "0      "
             << "     "
             << "1      "
             << "     "
             << "2      "
             << "     "
             << "3      "
             << "     "
             << "4"
             << "\t"
             << endl;
    }
    else
    {
        cout << "0      "
             << "     "
             << "1      "
             << "     "
             << "2      "
             << "\t"
             << endl;
    }
    cout << "\t\t\t\t ";
    for (int i = 0; i < gridSize1 * 12; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < gridSize1; i++)
    {
        x = i + 65;
        cout << "\t\t\t" << x << "\t|     ";
        for (int j = 0; j < gridSize1; j++)
        {
            cout << board[i][j] << "     |     ";
        }
        if (i < gridSize1 - 1)
        {
            cout << endl;
        }
        else
        {
            cout << "\n";
        }
    }
    cout << "\t\t\t\t ";
    for (int i = 0; i < gridSize1 * 12; i++)
    {
        cout << "-";
    }
    cout << endl;
}
bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < gridSize1; row++)
    {
        count = 0;
        for (int col = 0; col < gridSize1; col++)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize1)
        {
            return true;
        }
    }
    return false;
}
bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < gridSize1; col++)
    {
        count = 0;
        for (int row = 0; row < gridSize1; row++)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize1)
        {
            return true;
        }
    }
    return false;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < gridSize1; idx++)
    {
        if (board[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize1)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < gridSize1; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize1)
    {
        return 1;
    }
    return 0;
}
void typeCasting(string address)
{
    if (address[0] == 'A')
    {
        addressI = 0;
    }
    else if (address[0] == 'B')
    {
        addressI = 1;
    }
    else if (address[0] == 'C')
    {
        addressI = 2;
    }
    else if (address[0] == 'D')
    {
        addressI = 3;
    }
    else if (address[0] == 'E')
    {
        addressI = 4;
    }
    else
    {
        addressI = -1;
    }
    if (address[1] == '0')
    {
        addressCol = 0;
    }
    else if (address[1] == '1')
    {
        addressCol = 1;
    }
    else if (address[1] == '2')
    {
        addressCol = 2;
    }
    else if (address[1] == '3')
    {
        addressCol = 3;
    }
    else if (address[1] == '4')
    {
        addressCol = 4;
    }
    else
    {
        addressCol = -1;
    }
}
void store()
{
    fstream file, file1;
    file1.open("board.txt", ios::out);
    file1 << gridSize1 << endl;
    file1.close();
    file.open("ttt.txt", ios::out);
    for (int i = 0; i < gridSize1; i++)
    {
        for (int j = 0; j < gridSize1; j++)
        {
            file << board[i][j];
        }
        file << endl;
    }
    file.close();
}
void loadGame()
{
    fstream file, file1;
    char x;
    file1.open("board.txt", ios::in);
    file1 >> x;
    file1.close();
    gridSize1 = x - '0';
    file.open("ttt.txt", ios::in);
    for (int i = 0; i < gridSize1; i++)
    {
        for (int j = 0; j < gridSize1; j++)
        {
            file >> board[i][j];
        }
    }
    file.close();
}