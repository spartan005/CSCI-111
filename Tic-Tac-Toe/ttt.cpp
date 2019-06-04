// James Oppy, Tic-Tac-Toe
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//  1 | 2 | 3
// -----------
//  4 | 5 | 6
// ------------
//  7 | 8 | 9

char compChoice(char* tile)
{ 
  char choice;
  if (tile[0] == '1') {
    choice = '1';
  }
  else if (tile[4] == '5'){
    if ((tile[1] == 'X' || tile[3] == 'X' || tile[5] == 'X' || tile[7] == 'X'))
      choice = '5';
    else if ((tile[2] == 'X' || tile [8] == 'X') && tile[6] == '7')
      choice = '7';
    else if (tile[6] == 'X' && tile[2] == '3')
      choice = '3';
    else {
      choice = '0' + (rand() % 9 + 1);
    }
  }
  else {
    choice = '0' + (rand() % 9 + 1);
  }
  return choice;
}

int main() { 
  int turns = 9; 
  char tile[] = {'1', '2', '3', '4', '5' , '6', '7', '8', '9'};
  char choice;
  char player = 'X';
  bool win = false;
  bool turn = false;
  bool comp = false;
  srand ( time(NULL) );
  cout << "Welcome to Tic-Tac-Toe" << endl;
  while (choice != '1' && choice != '2') {
    cout << "1 or 2 players?" << endl;
    cin >> choice;
    if (choice == '1')
      comp = true;
    else if (choice == '2')
      comp = false;
    else
      cout << "That is not a valid input, please enter 1 or 2." << endl;
  }
  cin.ignore(1000, '\n');
  choice = '0';
  while (turns > 0 && win == false) {
    cout << endl << endl << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << endl << "-----------" << endl << " " << tile[3] << " | " 
      << tile[4] << " | " << tile[5] << endl << "-----------" << endl << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << endl << endl;
    turns--;
    if (player == 'X') {
      player = 'O';
      turn = true;
    }
    else if (player == 'O') {
      player = 'X';
      turn = true;
    }
    if (comp == false || player == 'X')
      cout << "It is " << player << "'s turn, choose a space" << endl;
    while (turn == true) {  // chosing a space
      if (comp == false || player == 'X') {
        cin >> choice;
        cin.ignore(1000, '\n');
      }
      else {
        choice = compChoice(tile);
      }
      if (tile[choice - '1'] == choice) {
        tile[choice - '1'] = player;
        turn = false;
      }
      else {
        if (comp == false || player == 'X')
          cout << "That is not a valid input, please enter the number of an unused space." << endl;
      }
      if (tile[0] == player && tile[1] == player && tile[2] == player || tile[0] == player && tile[3] == player && tile[6] == player || tile[0] == player && tile[4] == player && tile[8] == player ||
          tile[1] == player && tile[4] == player && tile[7] == player || tile[2] == player && tile[5] == player && tile[8] == player || tile[2] == player && tile[4] == player && tile[6] == player ||
          tile[3] == player && tile[4] == player && tile[5] == player || tile[6] == player && tile[7] == player && tile[8] == player) { // win conditions
        cout << endl << endl << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << endl << "-----------" << endl << " " << tile[3] << " | " 
          << tile[4] << " | " << tile[5] << endl << "-----------" << endl << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << endl << endl;
        win = true;
        cout << player << " wins!" << endl; 
      }
    }
    if (turns == 0 && win == false) { // Why is a tie in Tic-Tack-Toe called Cat's game?
      cout << endl << endl << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << endl << "-----------" << endl << " " << tile[3] << " | " 
        << tile[4] << " | " << tile[5] << endl << "-----------" << endl << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << endl << endl;
      cout << "Cat's game" << endl;
    }
  }
  return 0;
}
