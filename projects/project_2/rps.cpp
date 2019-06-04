// James Oppy, Project 2
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int randomNumber;
  int pR = 0;
  int pS = 0;
  int pP = 0;
  int pRwin = 0;
  int pSwin = 0;
  int pPwin = 0;
  int cRwin = 0;
  int cSwin = 0;
  int cPwin = 0;
  int tie = 0;
  string choice;
  char play = 'Y';
  srand(time(NULL));

  cout << "Let's play Rock, Paper, Scissors" << endl;
  while (play == 'Y' or play == 'y') {
    cout << endl << "Enter 1 for Rock, 2 for Paper, 3 for Scissors" << endl;
    cin >> choice;
    randomNumber = rand() % 3 + 1;
    if (choice == "1") {
      cout << "You chose rock" << endl;
      pR++;
      if (randomNumber == 1) {
        cout << "The computer chose rock" << endl;
        cout << "It's a tie" << endl;
        tie++;
      }
      else if (randomNumber == 2) {
        cout << "The computer chose paper" << endl;
        cout << "The computer won" << endl;
        cPwin++;
      }
      else if (randomNumber == 3) {
        cout << "The computer chose scissors" << endl;
        cout << "You won!" << endl;
        pRwin++;
      }
      cout << "Would you like to play again (Y for yes, N for no)?" << endl;
      cin >> play;
    }
    else if (choice == "2") {
      cout << "You chose paper" << endl;
      pP++;
      if (randomNumber == 1) {
        cout << "The computer chose rock" << endl;
        cout << "You won!" << endl;
        pPwin++;
      }
      else if (randomNumber == 2) {
        cout << "The computer chose paper" << endl;
        cout << "It's a tie" << endl;
        tie++;
      }
      else if (randomNumber == 3) {
        cout << "The computer chose scissors" << endl;
        cout << "The computer won" << endl;
        cSwin++;
      }
      cout << "Would you like to play again (Y for yes, N for no)?" << endl;
      cin >> play;
    }
    else if (choice == "3") {
      cout << "You chose scissors" << endl;
      pS++;
      if (randomNumber == 1) {
        cout << "The computer chose rock" << endl;
        cout << "The computer won" << endl;
        cRwin++;
      }
      else if (randomNumber == 2) {
        cout << "The computer chose paper" << endl;
        cout << "You won!" << endl;
        pSwin++;
      }
      else if (randomNumber == 3) {
        cout << "The computer chose scissors" << endl;
        cout << "It's a tie" << endl;
        tie++;
      }
      cout << "Would you like to play again (Y for yes, N for no)?" << endl;
      cin >> play;
    }
    else {
      cout << choice << " is not a valid choice" << endl;
    }
  }
  cout << endl << "You won " << pRwin + pPwin + pSwin << " times" << endl;
  cout << "You lost " << cRwin + cPwin + cSwin << " times" << endl;
  cout << "You tied " << tie << " times" << endl << endl;
  cout << "You selected rock " << pR << " times" << endl;
  cout << "You selected paper " << pP << " times" << endl;
  cout << "You selected scissors " << pS << " times" << endl;
  if (pRwin + pPwin + pSwin < cRwin + cPwin + cSwin) {
    cout << "The computer won the most rounds";
    if (cRwin > cPwin and cRwin > cSwin) {
      cout << " and mostly used rock, you should have chosen paper to win" << endl;
    }
    else if (cPwin > cRwin and cPwin > cSwin) {
      cout << " and mostly used paper, you should have chosen scissors to win" << endl;
    }
    else {
      cout << " and mostly used scissors, you should have chosen rock to win" << endl;
    }
  }
  else if (pRwin + pPwin + pSwin > cRwin + cPwin + cSwin) {
    cout << "You won the most rounds using ";
    if (pRwin > pPwin and pRwin > pSwin) {
      cout << "rock" << endl;
    }
    else if (pPwin > pRwin and pPwin > pSwin) {
      cout << "paper" << endl;
    }
    else {
      cout << "scissors" << endl;
    }
  }
  else {
    cout << "You and the computer won an equal number of rounds, the computer ";
    if (cRwin > cPwin and cRwin > cSwin) {
      cout << "mostly won with rock, you should have chosen paper to win" << endl;
    }
    else if (cPwin > cRwin and cPwin > cSwin) {
      cout << "mostly won with paper, you should have chosen scissors to win" << endl;
    }
    else {
      cout << "mostly won with scissors, you should have chosen rock to win" << endl;
    }
  }
  return 0;
}
