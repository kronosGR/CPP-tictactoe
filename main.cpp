#include <iostream>

using namespace std;


int main()
{
    const char PLAYER_X = 'O';
    const char PLAYER_O = 'X';

    char lastPlayer = PLAYER_X;
    char currentPlayer = PLAYER_O;

    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int played=0;
    bool isValid= false;


    for (int i=1; i<=10; i++){
        cout << endl;
        cout << "Current board state:" << endl;
        cout << endl;

        //display the board
        int line = 0;
        for (int y=0; y<3; y++){
            cout << "    ";
            for (int x=0; x<3; x++){
                cout << board[(line * 3 ) + x];
                if (x!= 2){
                    cout << "|";
                } else {
                    cout << endl;
                }
            }
            //line
            if (y!=2){
                cout << "    ";
                cout << "-+-+-" << endl;
            }
            line++;
        }

        // check if there is a win
        if (board[0] == currentPlayer && board[1] == currentPlayer && board[2]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the top row!" << endl;
            goto finish;
        }
        else if (board[3] == currentPlayer && board[4] == currentPlayer && board[5]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the middle row!" << endl;
            goto finish;
        }
        else if (board[6] == currentPlayer && board[7] == currentPlayer && board[8]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the bottom row!" << endl;
            goto finish;
        }
        else if (board[0] == currentPlayer && board[3] == currentPlayer && board[6]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the left column!" << endl;
            goto finish;
        }
        else if (board[1] == currentPlayer && board[4] == currentPlayer && board[7]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the middle column!" << endl;
            goto finish;
        }
        else if (board[2] == currentPlayer && board[5] == currentPlayer && board[8]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the right column!" << endl;
            goto finish;
        }
        else if (board[0] == currentPlayer && board[4] == currentPlayer && board[8]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the upward diagonal!" << endl;
            goto finish;
        }
        else if (board[2] == currentPlayer && board[4] == currentPlayer && board[6]==currentPlayer)
        {
            cout << "----------------------------" << endl;
            cout << "Player " << currentPlayer << " wins on the downward diagonal!" << endl;
            goto finish;
        } else {
            if (isValid)
            {
              swap(currentPlayer, lastPlayer);
            }
        }

        //check if 9 times played
        if (played >= 9){
            cout << "----------------------------"<< endl;
            cout << "Draw. Nobody Wins." << endl;
            break;
        }
        else
        {
            //get user input
            do{
                printf("Player %c, enter a number between 1 and 9: \n", currentPlayer);
                int chosenSquare;
                cin >> chosenSquare;
                if (chosenSquare<1 || chosenSquare >9){
                    cout << "Not a valid choice. Try again."<< endl;
                    i--;
                    isValid = false;
                    break;
                }
                else if (board[chosenSquare-1] == 'X' || board[chosenSquare-1] == 'O'){
                    cout << "That square is not available. Try again";
                    i--;
                    isValid = false;
                    break;
                }
                else{
                    board[chosenSquare-1] = currentPlayer;
                    played++;
                    isValid = true;
                    break;
                }
            } while(true);
        }
        cout << endl;
    }
    finish:
        cout << "Thanks for playing!" << endl;

    return 0;
}
