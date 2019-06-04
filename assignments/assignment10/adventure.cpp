//James Oppy, Text Adventure
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct adventurer {
  string name;
  int point;
  int hp;
  int epicness;
  string armament;
};

void stats(struct adventurer hero)
{
  cout << hero.name << " Stats:  HP = " << hero.hp << "  Epicness = " << hero.epicness << "  Armament = " << hero.armament << endl; 
}

int randomNumber(int max, int min)
{
  return rand() % max + min;
}

struct adventurer roomOne(struct adventurer hero, bool& play)
{
  char choice;
  cout << "You are " << hero.name << " your car has broken down in the middle of nowhere.\nWhat were you doing driving in the middle of nowhere? I dunno sounds like a personal problem." << endl;
  cout << "You do not have your phone but in the distance you see a small building you" << endl;
  cout << "1) go look for help there.\n2) run towards the house shouting 'I'm going on an adventure!'. \n3) wait at your car for someone to pass by and help you.\n4) freak out and assume it's a mirage, you are going to die, someone will eventually find your bones eaten clean by vultures and then take your car to use as scrap metal leaving them to lie there until the world ends." << endl; 
  while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'S') {
    cin.ignore(100, '\n');
    cin >> choice;
    if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'S')
      cout << "Please enter a valid input." << endl;
  }
  if (choice == '1') {
    cout << "You make it to the building and notice that the door is cracked open, it seems to be a old wooden shack there is nothing on the outside so you decide to check inside." << endl << endl;
    hero.point++;
  } 
  else if (choice == '2') {
    cout << "You make it to the building and notice the door is cracked open, ignoring that fact you kick it in and burst into the place ready for anything." << endl;
    hero.point++;
    hero.epicness++;
    cout << "Your epicness is at " << hero.epicness << endl << endl;
  } 
  else if (choice == '3') {
    cout << "You wait for awhile but quckly get bored, you're in the middle of nowhere and it may be a very long time before someone finds you you decide to check out the building." << endl; 
    cout << "You make it to the building and notice that the door is cracked open, it seems to be a old wooden shack there is nothing on the outside so you decide to check inside." << endl << endl;
    hero.point++;
  }
  else if (choice == '4') {
    cout << "Congratulations! You managed fail at a very simple choice.\nYou are dead, or at the very least brain dead." << endl << endl;
    hero.hp = 0; 
  } 
  else if (choice == 'S') {
    play = false;
  }
  return hero;
}

struct adventurer roomTwo(struct adventurer hero, bool& play)
{
  char choice;
  cout << "The inside of the shack seems to be as bare as the outside, you are about to exit the shack when suddenly the floor vanishes beneth your feet and you begin falling at 9.8m/s/s you" << endl;
  cout << "1) prepare for impact. Lets do this!\n2) Scream and panic. What do I do?\n3) Eh, this happens all the time maybe I can take a quick nap before I hit the bottom.\n4) think there must be water at the bottom and prepare to dive in." << endl;
  while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'S') {
    cin.ignore(100, '\n');
    cin >> choice;
    if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'S')
      cout << "Please enter a valid input." << endl;
  }
  if (choice == '1') {
    cout << "You brace for impact and preform a roll as you hit the bottom. You stand up and brush some dust off your shoulder." << endl;
    hero.point++;
    hero.epicness++;
    cout << "Your epicness is at " << hero.epicness << endl << endl;
  } 
  else if (choice == '2') {
    cout << "You scream like a little girl and land on your butt, ouch." << endl;
    hero.point++;
    hero.epicness--;
    cout << "Your epicness is at " << hero.epicness << endl << endl;
  } 
  else if (choice == '3') {
    cout << "You wake up at the bottom after awhile and yawn. You wonder how long you were asleep since the impact didn't wake you." << endl << endl;
    hero.point++;
  }
  else if (choice == '4') {
    cout << "There was not water at the bottom. You fall on your face and get a concussion, you also probably killed a few brain cells which seem to be a very limited resource for you." << endl;
    hero.point++;
    hero.hp -= 10; 
    cout << "Your HP is at " << hero.hp << endl << endl;
  } 
  else if (choice == 'S') {
    play = false;
  }
  return hero;
}

struct adventurer roomThree(struct adventurer hero, bool& play)
{
  string choice;
  cout << "The room you've fallen into seems to be filled with swords, shields and some health potions. There is a path leading deeper into the building but you should probably grab something to defend yourself with first." << endl; 
  cout << "1) You grab 2 swords.\n2) You grab a sword and a shield.\n3) You grab 2 shields" << endl;
  while (choice != "1" && choice != "2" && choice != "3" && choice != "magic" && choice != "S") {
    cin.ignore(100, '\n');
    cin >> choice;
    if (choice != "1" && choice != "2" && choice != "3" && choice != "magic" && choice != "S")
      cout << "Please enter a valid input." << endl;
  }
  if (choice == "1") {
    hero.armament = "two swords";
    hero.point++;
    hero.epicness++;
    cout << "Your epicness is at " << hero.epicness << endl << endl;
  } 
  else if (choice == "2") {
    hero.armament = "sword and shield";
    hero.point++;
  } 
  else if (choice == "3") {
    hero.armament = "two shields";
    hero.point++;
    hero.epicness++;
    cout << "Your epicness is at " << hero.epicness << endl << endl;
  }
  else if (choice == "magic") {
    hero.armament = "magic";
    hero.epicness += 3;
    hero.point++;
  } 
  else if (choice == "S") {
    play = false;
  }
  cout << "You head into the dungeon with some health potions and your " << hero.armament << " ready." << endl << endl;
  return hero;
}

struct adventurer monsterFight(struct adventurer hero, int& fight)
{
  char choice;
  cout << "A monster appeared" << endl;
  stats(hero);
  bool heal = false;
  while (choice != '1' && choice != '3') {
  cout << "1) attack\n2) drink health potion\n3) run" << endl; 
    choice = ' ';
    while (choice != '1' && choice != '2' && choice != '3' && choice != 'S') {
      cin.ignore(100, '\n');
      cin >> choice;
      if (choice != '1' && choice != '2' && choice != '3' && choice != 'S')
        cout << "Please enter a valid input." << endl;
    }
    if (choice == '1') {
      cout << "You attack the monster with your " << hero.armament << " and kill it but it also damages you." << endl;
      hero.hp -= randomNumber(6,5);
      cout << "Your hp is " << hero.hp << endl << endl;
      if (heal == false)
        fight++;
      return hero;
    } 
    else if (choice == '2') {
      cout << "How boring, You fully restore your health. No points for this fight" << endl;
      heal = true;
      hero.hp = 30;
      cout << "Your hp is " << hero.hp << endl;
    } 
    else if (choice == '3') {
      cout << "wimp" << endl << endl;
      fight -= 2;
      return hero;
    }
  }
}

struct adventurer roomDungeon(struct adventurer hero, bool& play)
{
  char choice;
  int fight = 0;
  for (int i = 0; i < 10; i++) {
    cout << "What direction do you wish to go?\n1) go forward\n2) go left\n3) go right" << endl;
    while (choice != '1' && choice != '2' && choice != '3' && choice != 'S') {
      cin.ignore(100, '\n');
      cin >> choice;
      if (choice != '1' && choice != '2' && choice != '3' && choice != 'S')
        cout << "Please enter a valid input." << endl;
    }
    if (choice == 'S') {
      play = false;
      return hero;
    }
    choice = ' ';
    int random = randomNumber(2,1);
    if (random == 1)
      hero = monsterFight(hero, fight);
    if (hero.hp <= 0)
      return hero;
  }
  hero.epicness += fight;
  hero.point++;
  return hero;
}

struct adventurer chooseRoom(struct adventurer hero)
{
  bool play = true;
  cout << endl << "If at any point outside combat you would like to save your adventure simply type 'S' to save and quit" << endl << endl;
  while (play == true && hero.hp > 0) {
    switch (hero.point) {
      case 1:
        hero = roomOne(hero, play);
        break;
      case 2:
        hero = roomTwo(hero, play);
        break;
      case 3:
        hero = roomThree(hero, play);
        break;
      case 4:
        hero = roomDungeon(hero, play);
        break;
      case 5:
        cout << "You reach the end of the dungeon and get swallowed up by a bright light you suddenly find yourself back in your car which is now running, Thanks for playing." << endl;
        cout << "You Win!" << endl << "Your epicness is at " << hero.epicness << endl;
        return hero;
    }
  }
  return hero;
}

int main()
{
  struct adventurer hero;
  string file;
  char choice;
  hero.point = 0;
  srand(time(NULL));
  cout << "What is the name of your character?" << endl;
  cin >> hero.name;
  ifstream resume;
  file = hero.name + ".txt";
  resume.open(file.c_str());
  resume >> hero.point >> hero.hp >> hero.epicness;
  resume.ignore();
  getline (resume, hero.armament);
  resume.close();
  if (hero.point != 0) {
    while (choice != '1' && choice != '2' && choice != '3') {
      cout << "There is already a character with this name in existance. What would you like to do?\nEnter 1,2 or 3\n1) Resume the adventure\n2) Overwrite this character\n3) Quit" << endl;
      stats(hero);
      cin.ignore(100, '\n');
      cin >> choice;
    }
    if (choice == '1') 
      hero = chooseRoom(hero);
    else if (choice == '2') {
      hero.point = 0;
      hero.hp = 30;
      hero.epicness = 0;
      hero.armament = "nothing";
      hero.point++;
      hero = chooseRoom(hero);
    }
    else if (choice == '3')
      return 0;
  }
  else {
    hero.point = 0;
    hero.hp = 30;
    hero.epicness = 0;
    hero.armament = "nothing";
    hero.point++;
    hero = chooseRoom(hero);
  }
  if (hero.hp != 0) {
    ofstream save;
    save.open(file.c_str());
    save << hero.point << endl << hero.hp << endl << hero.epicness << endl << hero.armament;
    save.close();
  }

  return 0;
}
