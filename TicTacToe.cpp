#include <iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard() 
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placemarker(int slot) 
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = currentMarker;
        return true;
    } else 
    {
        return false;
    }
}

int winner() 
{
    // Check rows
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            return currentPlayer;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            return currentPlayer;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
    {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerandMarker() 
{
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void game() 
{
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    while (markerP1 != 'X' && markerP1 != 'O') 
    {
        cout << "Invalid marker! Please choose X or O: ";
        cin >> markerP1;
    }

    currentPlayer = 1;
    currentMarker = markerP1;
    drawBoard();

    int playerWon = 0;

    for (int i = 0; i < 9; i++) 
    {
        cout << "It's Player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) 
        {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placemarker(slot)) 
        {
            cout << "Slot already occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        playerWon = winner();

        if (playerWon == 1) 
        {
            cout << "Player 1 wins!\n";
            break;
        }
        if (playerWon == 2) 
        {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerandMarker();
    }

    if (playerWon == 0) 
    {
        cout << "It's a tie!\n";
    }
}

int main() 
{
    game();
    return 0;
}