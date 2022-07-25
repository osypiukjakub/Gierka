
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "class.h"

using namespace std;

int main() 
{

Bohater a("Postac",100,5,5,5,5);

tworzenie_postaci(&a);



Jedzenie ziemniak("ziemniak",4,4,15);
Jedzenie malina("malina",4,4,10);


Bron miecz1("Miecz zmora gniewu",5,4,156);
Bron topur("Krasnoludzi topur",5,3,186);

a.hp_setter(15);
a.branie_przedmiotu(&miecz1);
a.branie_przedmiotu(&topur);
a.branie_przedmiotu(&ziemniak);
Zbroja zbroja1("zlota zbroja",5,3,345);
Zbroja zbroja2("czerwona zbroja",5,3,235);

a.branie_przedmiotu(&zbroja1);
a.branie_przedmiotu(&zbroja2);

Postac *wsk=stworz_wrogow("wilki",1);

a.menu_glowne();
cout<<"Spotykasz wilka"<<endl;
walka(&a,wsk);

a.menu_glowne();

cout<<"GIT";


	
	
	
	
	
	
	
	
	
	
	
	}
