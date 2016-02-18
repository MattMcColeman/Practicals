/**
* Author: Matt McColeman
* Date: 03/28/2015
* Description: This program creates a text based RPG based off of star wars. It uses a base class, derived classes, 
*              protected variable, overridden function and redefined function to create a battle against the dark side.
*              Dodge attacks left and right and strike back at the enemy in order to survive.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//global variables
int myHP = 100;
int enemyHP;

//Base class!!!
class Warrior{
  protected:
    int attackPower; //protected member variable!!!
  public:
    //used to set attack power for each object
    void setAttackPower(int a){
      attackPower=a;
    }
    void attack(){
      cout << "Enemy Attacks! He cannot hurt a jedi though!" << endl;
    }
};

//Five derived classes!!!
class Jedi: public Warrior{
  public:
    //overridden function!!!
    void attack(){
      cout << "Light saber slash! -" << attackPower << " Damage to enemy!" << endl;
      enemyHP = enemyHP - attackPower; //takes down health of enemy
      cout << "Enemy health is now: " << enemyHP << endl;
    }
};

class Clone: public Warrior{
  public:
    void attack(){
      cout << "Clone laser! -" << attackPower << " Damage!" << endl;
      myHP = myHP - attackPower; //takes down health of player
      cout << "Your health is now: " << myHP << endl;
    }
};

class Droid: public Warrior{
  public:
    void attack(){
      cout << "Droid laser! -" << attackPower << " Damage!" << endl;
      myHP = myHP - attackPower;
      cout << "Your health is now: " << myHP << endl;
    }
};

class Hobbit: public Warrior{
  public:
    void attack(){
      cout << "HOBBIT SMASH! -" << attackPower << " Damage!" << endl;
      myHP = myHP - attackPower;
      cout << "Your health is now: " << myHP << endl;
    }
};

class SithLord: public Warrior{
  public:
    void attack(){
      cout << "Force Electricity! -" << attackPower << " Damage!" << endl;
      myHP = myHP - attackPower;
      cout << "Your health is now: " << myHP << endl;
    }
};

int main(){
  srand(time(NULL)); //uses time to generate seemingly random number
  
  Clone c; //creates object
  Warrior *warrior1 = &c; //sets warrior pointer equal to c adress
  warrior1->setAttackPower(20); // sets objects power
  Droid d;
  Warrior *warrior2 = &d;
  warrior2->setAttackPower(15);
  Jedi j;
  Warrior *warrior3 = &j;
  warrior3->setAttackPower(50);
  Hobbit h;
  Warrior *warrior4 = &h;
  warrior4->setAttackPower(0);
  SithLord s;
  Warrior *warrior5 = &s;
  warrior5->setAttackPower(100);

  cout << endl << "Hello Young Jedi! Jedi Master Yoda this is." << endl
    << "Speaking to you through the force, I am! The Sith have come and" << endl
    << "danger you are in! The clones have turned to the dark side!" << endl 
    << "Yourself you must save!" << endl 
    << "May the force be with you." << endl;

  cout << endl << "A clone see's you, dodge his laser by jumping 'right' or 'left'" << endl;
  
  for(int i = 0; i < 3; i++){ //for loop for multiple same enemies
    enemyHP = 50; //sets current enemy's health
          //while loop goes until you or the enemy loses
	  while(1){
	    string direction;
	    int shot;
	    int dodge;   
            //while loop goes until you type 'right' or 'left'
	    while(1){
              cout << "Type direction: ";
	      cin >> direction;
	      if(direction == "right"){
		dodge = 1;
		break;
	      }
	      if(direction == "left"){
		dodge = 2;
		break;
	      }
	      cout << endl << endl << "please enter 'right' or 'left' to dodge" << endl;
	    }
	    shot = (rand()%2)+1; //generates randomly either number 1 or 2
            //if the dodge direction is equal to the shot the clone attacks else the jedi attacks
	    if(dodge == shot){
	      cout << "You jumped into his laser! " << endl;
	      c.attack();
              //if statement exits if player loses
	      if(myHP <= 0){
	        cout << endl << "YOU LOSE!!!" << endl << endl;
	        return 0;
	      }
              cout << endl << "The clone is still firing at you attempt to dodge his attack by jumping 'right' or 'left'" << endl;
	    } else {
	      cout << "You dodged his attack!" << endl;
	      j.attack();
	    }
            //breaks the loop if the enemy has lost
	    if(enemyHP <= 0){
	      cout << "YOU DEFEATED HIM!!!" << endl;
              //if else statement ensures that after the last enemy is defeated text does not display
              if(i == 2){} else {cout << endl << "Another clone see's you, dodge his laser by jumping 'right' or 'left'" << endl;}
	      break;       
	    }
	  }
  }
  
  cout << endl << "A Hobbit see's you, dodge his attack by jumping 'right' or 'left'" << endl;
  enemyHP = 50;
	  while(1){
	    string direction;
	    int slash;
	    int dodge;        
	    while(1){
              cout << "Type direction: ";
	      cin >> direction;
	      if(direction == "right"){
		dodge = 1;
		break;
	      }
	      if(direction == "left"){
		dodge = 2;
		break;
	      }
	      cout << endl << endl << "please enter 'right' or 'left' to dodge" << endl;
	    }
	    slash = (rand()%2)+1;
	    if(dodge == slash){
	      cout << "You jumped into his attack! " << endl;
	      h.Warrior::attack(); //redefined function!!!
              cout << endl << "The Hobbit is still trying to attack you! attempt to dodge his attack by jumping 'right' or 'left'" << endl;
	    } else {
	      cout << "You dodged his attack!" << endl;
	      j.attack();
	    }
	    if(enemyHP <= 0){
	      cout << "THIS REALLY DOESN'T MAKE SENSE OFCOURSE YOU DEFEATED HIM!!!" << endl;
	      break;
	    }
	  }
  
  cout << endl << "A droid see's you, dodge his laser by jumping 'right' or 'left'" << endl;
  for(int i = 0; i < 2; i++){
    enemyHP = 50;
	  while(1){
	    string direction;
	    int shot;
	    int dodge;   
	    while(1){
              cout << "Type direction: ";
	      cin >> direction;
	      if(direction == "right"){
		dodge = 1;
		break;
	      }
	      if(direction == "left"){
		dodge = 2;
		break;
	      }
	      cout << endl << endl << "please enter 'right' or 'left' to dodge" << endl;
	    }
	    shot = (rand()%2)+1;
	    if(dodge == shot){
	      cout << "You jumped into his laser! " << endl;
	      d.attack();
              if(myHP <= 0){
	        cout << endl << "YOU LOSE!!!" << endl << endl;
	        return 0;
	      }
              cout << endl << "The droid is still firing at you attempt to dodge his attack by jumping 'right' or 'left'" << endl;
	    } else {
	      cout << "You dodged his attack!" << endl;
	      j.attack();
	    }
	    if(enemyHP <= 0){
	      cout << "YOU DEFEATED HIM!!!" << endl;
              if(i == 1){} else {cout << endl << "Another droid see's you, dodge his laser by jumping 'right' or 'left'" << endl;}
	      break;       
	    }
	  }
  }

  cout << endl << "The Sith Lord locks his sights on you, dodge his electricity by jumping 'right' or 'left'" << endl;
  enemyHP = 200;
	  while(1){
	    string direction;
	    int force;
	    int dodge;        
	    while(1){
              cout << "Type direction: ";
	      cin >> direction;
	      if(direction == "right"){
		dodge = 1;
		break;
	      }
	      if(direction == "left"){
		dodge = 2;
		break;
	      }
	      cout << endl << endl << "please enter 'right' or 'left' to dodge" << endl;
	    }
	    force = (rand()%2)+1;
	    if(dodge == force){
	      cout << "You jumped into his attack! " << endl;
	      s.attack();
	    } else {
	      cout << "You dodged his attack!" << endl;
	      j.attack();
	    }
	    if(enemyHP <= 0){
	      cout << "YOU'VE STUNNED HIM RUN!!!" << endl;
	      break;
	    }
	    if(myHP <= 0){
	      cout << endl << "YOU LOSE!!!" << endl << endl;
	      return 0;
	    }
	  }
  
  cout << "YOU SURVIVED!" << endl;

  return 0;
}
