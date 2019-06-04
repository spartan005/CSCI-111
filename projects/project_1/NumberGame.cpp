// James Oppy, Project 1
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 
int main()
{
  srand ( time(NULL) );
  int randomNumber;
  char difficulty;
  int guess;
  int attempts;
  int numSize;
  while (difficulty != '1' and difficulty != '2' and difficulty != '3') {
    cout << "Please select difficulty:\nEasy = 1\nMedium = 2\nHard = 3" << endl;
    cin >> difficulty;
    if (difficulty == '1') {
      cout << "You selected easy" << endl;
      attempts = 3;
      numSize = 10;
    } 
    else if (difficulty == '2') {
      cout << "You selected medium" << endl;
      attempts = 4;
      numSize = 50;
    }
    else if (difficulty == '3') {
      cout << "You selected hard" << endl;
      attempts = 5;
      numSize = 100;
    }
    else {
      cout << "Please enter 1, 2 or 3" << endl;
    }
  }
  randomNumber = rand() % numSize + 1;
  while (attempts > 0 and guess != randomNumber) {
    cout << endl << "You have " << attempts << " guesses left" << endl;
    cout << "Please guess a number between 1 and " << numSize << endl;
    cin >> guess;
    if (guess == randomNumber) {
      cout << endl << "That is correct!" << endl << "YOU WIN!" << endl;
    }
    else if (guess < randomNumber) {
      cout << "Your guess was low" << endl;
      attempts--;
    }
    else if (guess > randomNumber) {
      cout << "Your guess was high" << endl;
      attempts--;
    }
    else {
      cout << "That is not an acceptable input" << endl;
    }
  }
  if (attempts == 0) {
    cout << endl << "The number was " << randomNumber << endl << "YOU LOSE..." << endl;
  }
  return 0;
}
