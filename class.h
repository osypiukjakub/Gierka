
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>



using namespace std;

class Przedmiot;
class Jedzenie;
class Bohater;













// KLASA	ABSTAKCYJA	POSTAC


class Postac
{
friend class Zbroja;
friend class Bron;
friend Postac * stworz_wrogow(string rodzaj, int ilosc);

string nazwa;
int hp;
int atk;
int obr;
int zre;
int intel;
int posiadane_zloto=0;



	

public:
vector<Przedmiot>ekwipunek ;




Postac(string inazwa="postac",int ihp=100,int iatk=5,int iobr=5, int izre=5, int iintel=5)
:nazwa{inazwa},hp{ihp},atk{iatk},obr{iobr},zre{izre},intel{iintel} {};

int intel_getter(){return intel;};
void intel_setter(int i){intel=i;};
string nazwa_getter(){return nazwa;}

void nazwa_setter(string n){nazwa=n;}

void zre_setter(int z){zre=z;};
int zre_getter(){return zre;};
bool zycie()
{if(hp>0)return true;
else return false;}

void hp_setter(int ihp)
{hp=ihp;} 

int hp_getter()
{return hp;}
	
void atk_setter(int iatk)
{atk=iatk;}


int atk_getter()
{return atk;}


void obr_setter(int iobr)
{obr=iobr;}


int obr_getter()
{return obr;}

virtual void branie_przedmiotu(Przedmiot *n )=0;

virtual int moc_broni_getter(){return 1;};
virtual int moc_zbroi_getter(){return 1;};



~Postac(){};
};















//KLASA	WROG



class Wrog: public Postac
{
friend Postac* stworz_wrogow(string rodzaj, int ilosc);
friend void walka(Postac * bohater,Postac *wrog );

	
public:
Wrog()
:Postac(){};

Wrog(string nazwa, int hp, int atk, int obr, int zre)
:Postac(nazwa, hp, atk, obr, zre){};

virtual void branie_przedmiotu(Przedmiot *n ){};

virtual int moc_broni_getter(){return 100;};
virtual int moc_zbroi_getter(){return 100;};
	
 	~ Wrog(){};
};


















//KLASA	PRZEMIOT

//KLASA	PRZEMIOT

class Przedmiot
{
friend class Bohater;
friend void walka(Postac* bohater, Postac* wrog);
//friend Postac * stworz_wrogow(string rodzaj, int ilosc);

string nazwa;
int waga;
int cena;
protected:

bool jedzenie=0;
bool bron=0;
bool zbroja=0;
bool mikstura=0;
	
public:

Przedmiot(string inazwa="przedmiot", 	int iwaga=0, int icena=5)
:nazwa{inazwa},waga{iwaga},cena{icena}{};

string nazwa_getter(){return nazwa;};	
void bron_setter(){bron=1;};
void jedzenie_setter(){jedzenie=1;};	
	void zbroja_setter(){zbroja=1;};
	void mikstura_setter(){mikstura=1;};
	int waga_getter(){return waga;};
	
virtual int specjalna_cecha_getter(){return 0;};

	
~Przedmiot(){};
};


















//KLASy roznych przedmiotow
	
class Jedzenie:public Przedmiot
{

friend class Bohater;
int hp_boost=5;

public:
Jedzenie(string inazwa,int iwaga, int icena, int ihp_boost):
Przedmiot(inazwa,iwaga,icena),hp_boost{ihp_boost}
{jedzenie_setter();};


int hp_boost_getter(){return hp_boost ;};
void hp_boost_setter(int h){hp_boost=h;};	


	
	
int specjalna_cecha_getter(){return hp_boost;};
	
};








class Zbroja: public Przedmiot
{
	friend class Bohater;
	int obr_boost;
	//bool zalozona =0;
	
	public:
	Zbroja(string inazwa,int iwaga, int icena, int iobr_boost):
Przedmiot(inazwa,iwaga,icena)
{zbroja_setter();
obr_boost=iobr_boost;};


int obr_boost_getter(){return obr_boost ;};
void obr_boost_setter(int h){obr_boost=h;};	

int specjalna_cecha_getter(){return obr_boost;};

};	







class Mikstura: public Przedmiot
{
	friend class Bohater;
	//int atk_boost;
	
	public:
	Mikstura(string inazwa,int iwaga, int icena):
Przedmiot(inazwa,iwaga,icena)
{mikstura_setter();};


int specjalna_cecha_getter(){return 0;};
};	










class Bron: public Przedmiot
{
	friend class Bohater;
	int atk_boost;
	
	public:
	Bron(string inazwa,int iwaga, int icena, int iatk_boost):
Przedmiot(inazwa,iwaga,icena),atk_boost{iatk_boost}
{bron_setter();};


int atk_boost_getter(){return atk_boost ;};
void atk_boost_setter(int h){atk_boost=h;};	

int specjalna_cecha_getter(){return atk_boost;};
};











//FUNKCJA	TWORZENIA	WROGOW	DYNAMICZNIE

Postac * stworz_wrogow(string rodzaj, int ilosc)
{	
	
if(rodzaj=="wilki")
	{
		Postac*wsk= new Wrog[ilosc];
	
		for(int i=0;i<ilosc; i++)
		{
	 	wsk[i].nazwa_setter("wilk");
	 	wsk[i].hp_setter(50);
	 	wsk[i].atk_setter(3);
	 	wsk[i].obr_setter(3);
	 	wsk[i].zre_setter(5);
	 	
	 Przedmiot skora_wilka("skora wilka",5,10); 	 	
	 Jedzenie mieso_wilka("mieso wilka",2,5,5);
	  
	  wsk[i].ekwipunek.push_back(skora_wilka);
	  wsk[i].ekwipunek.push_back(mieso_wilka);
	  	
	 	
	 	}
	 	
	 	return wsk;
	 	
	 }
	 
if(rodzaj=="ogry")
	{
		Postac *wsk= new Wrog[ilosc];
	
		for(int i=0;i<ilosc; i++)
		{
	
	 	wsk[i].nazwa_setter("ogr");
	 	wsk[i].hp_setter(70);
	 	wsk[i].atk_setter(4);
	 	wsk[i].obr_setter(4);	
	 	wsk[i].zre_setter(2); 	}
	 	
	 	
	 	return wsk;
	 }
	 
if(rodzaj=="szczury")
	{
		Postac *wsk= new Wrog[ilosc];
	
		for(int i=0;i<ilosc; i++)
		{

	 	wsk[i].nazwa_setter("szczur");
	 	wsk[i].hp_setter(20);
	 	wsk[i].atk_setter(1);
	 	wsk[i].obr_setter(1);
	 	wsk[i].zre_setter(6);	 
	 
	 
	 		}
	 	
	 
	 	return wsk;
	 }	 
	 
	  };













//KLASA	GLOWNEGO	BOHATERA

class Bohater: public Postac
{

friend void menu_glowne(Bohater *b);	
friend void walka(Postac *bohater, Postac* wrog);
friend void tworzenie_postaci();
friend class Przedmiot;
friend class Bron;
friend class Zbroja;
friend bool test_na_intel(Bohater *b, int trudnosc);
friend bool test_na_zre(Bohater *b, int trudnosc);

	int udzwig=100;
	int level;
	int max_hp;
	
	
	
	
	
vector<Przedmiot>ekwipunek;
vector<Jedzenie>ejedzenie;
vector<Bron>ebron;
vector<Zbroja>ezbroja;
vector<Mikstura>emikstura;

public:
	Bron zal_bron;
	Zbroja zal_zbroja;

Bohater(string inazwa, int ihp, int iatk, int iobr, int izre, int intel)
:Postac(inazwa,ihp,iatk,iobr,izre,intel),level{1}, zal_bron("brak",0,0,100),zal_zbroja("brak",0,0,100){	
	max_hp=hp_getter();};
	
	virtual int moc_broni_getter(){return zal_bron.atk_boost_getter();};
virtual int moc_zbroi_getter(){return zal_zbroja.obr_boost_getter();};


int max_hp_getter(){return max_hp;};	
void level_setter(int i){level=i;};
int level_getter(){return level;};
int waga_ekwipunku_getter()
{
	int waga_e=0;
	for(int i=0;i<ekwipunek.size();i++)
	{
		waga_e=waga_e+ekwipunek[i].waga;
	}
	return waga_e;
}
	
void branie_przedmiotu(Przedmiot *n )
{
	if(udzwig>=waga_ekwipunku_getter()	and n->waga<=udzwig-waga_ekwipunku_getter())	
{ekwipunek.push_back(*n);

if(n->jedzenie==1)
{

Jedzenie *wsk;
wsk=(Jedzenie*)n;
wsk->hp_boost_setter(n->specjalna_cecha_getter());
ejedzenie.push_back(*wsk);};


if(n->zbroja==1){
	Zbroja *wsk;
wsk=(Zbroja*)n;
wsk->obr_boost_setter(n->specjalna_cecha_getter());
ezbroja.push_back(*wsk);};


if(n->bron==1){
Bron*wsk;
wsk=(Bron*)n;
wsk->atk_boost_setter(n->specjalna_cecha_getter());
ebron.push_back(*wsk);};


if(n->mikstura==1){
	
	Mikstura *wsk;
wsk=(Mikstura*)n;
emikstura.push_back(*wsk);};

cout<<"Do ekwipunka dodano "<<n->nazwa_getter()<<endl;

}

else {cout<<"\nNie jestes w stanie uniesc "<<n->nazwa_getter()<<" wazacego "<<n->waga_getter()<<" czy chcesz wyzucic cos z ekwipunku?"<<endl;
string w;
cin>>w;
if(w=="tak" or w=="Tak"){cout<<"W ekwipunku znajduje sie: "<<endl;
for(int i=0;i<ekwipunek.size();i++)
{
	cout<<i+1<<ekwipunek[i].nazwa<<" wazacy :"<<ekwipunek[i].waga<<endl;  
};
cout<<"Waga ekwipunku ="<<waga_ekwipunku_getter()<<"/"<<udzwig_getter()<<endl;
cout<<"\n-------------\n";
usuwanie_z_ekwipunku();
branie_przedmiotu(n);
}
else{};
}
}


int udzwig_getter(){return udzwig;};

void udzwig_setter(int u){udzwig=u;};

void wyswietlanie_ekwipunku()
{
	if(ekwipunek.empty())cout<<"Ekwipunek jest pusty";
	
	else cout<<"W ekwipunku znajduje sie: "<<endl;
for(int i=0;i<ekwipunek.size();i++)
{
	cout<<i+1<<"."<<ekwipunek[i].nazwa<<" wazacy :"<<ekwipunek[i].waga<<endl;  
};
cout<<"Waga ekwipunku ="<<waga_ekwipunku_getter()<<endl;
cout<<"\n-------------\n";
int w;

cout<<"Co chcesz zrobic?\n1.Wyswietl jedzenie\n2.Wyswietl zbroje\n3.Wyswietl bronie\n4.Wyswietl mikstury\n5.Wyrzuc z ekwipunka\n6.Cofnij"<<endl;
cin>>w;
cout<<endl;
switch(w)
{
	case 1:{wyswietlanie_jedzenia();
	break;}
	case 2:{wyswietlanie_zbroi();
	break;}
	case 3:{wyswietlanie_broni();
	break;}
	case 4:{wyswietlanie_mikstur();
	break;}
	case 6:{
	break;}
	case 5:{usuwanie_z_ekwipunku();
	break;}
		
	default:{cout<<"Nie ma takiej opcji, wpisz jeszcze raz"<<endl;
	wyswietlanie_ekwipunku();}
	
}
}
void usuwanie_z_ekwipunku()
{cout<<"Podaj numer przedmiotu, ktory chcesz usunac"<<endl;
int j;
cin>>j;
cout<<"Czy napewno chcesz usunac "<<ekwipunek[j-1].nazwa_getter()<<endl;
string a;
cin>>a;

if (a=="tak" or a=="Tak"){ 
cout<<ekwipunek[j-1].nazwa_getter()<<" zostaje usuniety"<<endl;


if (ekwipunek[j-1].jedzenie)
{
	for(int i=0;i<ejedzenie.size();i++)
	{if(ejedzenie[i].nazwa_getter()==ekwipunek[j-1].nazwa_getter())
	{ejedzenie.erase(ejedzenie.begin()+i);}}
}

if (ekwipunek[j-1].zbroja)
{
	for(int i=0;i<ezbroja.size();i++)
	{if(ezbroja[i].nazwa_getter()==ekwipunek[j-1].nazwa_getter())
	{ezbroja.erase(ezbroja.begin()+i);}}
}

if (ekwipunek[j-1].bron)
{
	for(int i=0;i<ebron.size();i++)
	{if(ebron[i].nazwa_getter()==ekwipunek[j-1].nazwa_getter())
	{ebron.erase(ebron.begin()+i);}}
}

if (ekwipunek[j-1].mikstura)
{
	for(int i=0;i<emikstura.size();i++)
	{if(emikstura[i].nazwa_getter()==ekwipunek[j-1].nazwa_getter())
	{emikstura.erase(emikstura.begin()+i);}}
}




ekwipunek.erase(ekwipunek.begin()+j-1);










}
else{}
}



void wyswietlanie_jedzenia()
{
if(ejedzenie.empty())cout<<"\nBrak jedzenia"<<endl;
	
	else cout<<"Jedzenie: "<<endl;
for(int i=0;i<ejedzenie.size();i++)
{
	cout<<i+1<<"."<<ejedzenie[i].nazwa<<" przywraca "<<ejedzenie[i].hp_boost_getter()<<endl;	            
	              
}

if(ejedzenie.empty())cout<<"1.Powrot"<<endl;

else cout<<"\n1.Powrot\n2.Zjedz"<<endl;
int w;
cin>>w;

switch(w)
{
	case 1:{ break;}
	case 2:{
		
if(ejedzenie.empty()==0)	cout<<"Podaj numer jedzenia, ktore chcesz zjesc"<<endl;
	int j;
	cin>>j;

if(hp_getter()>=max_hp_getter()){cout<<"Masz pelne zdrowie";
wyswietlanie_jedzenia();}
else if(hp_getter()+ejedzenie[j-1].hp_boost_getter()<max_hp_getter())
{hp_setter(hp_getter()+ejedzenie[j-1].hp_boost_getter());
cout<<"Twoje zycie zwieksza sie o "<<ejedzenie[j-1].hp_boost_getter()<<" wynosi teraz "<<hp_getter()<<"/"<<max_hp_getter()<<endl;
for(int i=0;i<ekwipunek.size();i++){if(ekwipunek[i].nazwa_getter()==ejedzenie[j-1].nazwa_getter()){ekwipunek.erase(ekwipunek.begin()+i); break;}}
	
	ejedzenie.erase(ejedzenie.begin()+j-1);
wyswietlanie_jedzenia();}
else if(hp_getter()+ejedzenie[j-1].hp_boost_getter()>max_hp_getter())
{hp_setter(max_hp_getter());
	cout<<"Twoje zycie zwieksza sie i wynosi"<<hp_getter()<<"/"<<max_hp_getter()<<endl;
	
	for(int i=0;i<ekwipunek.size();i++){if(ekwipunek[i].nazwa_getter()==ejedzenie[j-1].nazwa_getter()){ekwipunek.erase(ekwipunek.begin()+i); break;}}
	
	ejedzenie.erase(ejedzenie.begin()+j-1);
	
	wyswietlanie_jedzenia();}
	
break;
}
default:{ cout<<"Brak takiej opcji"<<endl;
//wyswietlanie_jedzenia();
}
}
}

void wyswietlanie_zbroi()
{
if(ezbroja.empty())cout<<"\nBrak opancerzenia";
	
	else cout<<"Opancerzenie: "<<endl;
for(int i=0;i<ezbroja.size();i++)
{
	cout<<i+1<<"."<<ezbroja[i].nazwa<<" wspolczynnik ochrony wynosi "<<ezbroja[i].obr_boost_getter()<<endl;
	if(zal_zbroja.nazwa_getter()== ezbroja[i].nazwa_getter()){cout<<"(zalozona)"<<endl;;}             
}
if(ezbroja.empty())cout<<"1.Powrot"<<endl;

cout<<"--------------------\n1.Powrot\n2.Zaloz zbroje\n";

int w;
cin>>w;

switch(w)
{
	case 1:{ break;}
case 2:{
	if(ezbroja.empty()==0) cout<<"Ktora zbroje chcesz zalozyc?"<<endl;
	int j;
	cin>>j;
	
	zal_zbroja=ezbroja[j-1];
	cout<<"Zalozyles zbroje "<<zal_zbroja.nazwa_getter()<<endl;
	wyswietlanie_zbroi();
};
default:{ cout<<"Brak takiej opcji"<<endl;
///wyswietlanie_zbroi();
}}
}

void wyswietlanie_broni()
{
if(ebron.empty())cout<<"\nBrak broni";
	
	else cout<<"Bronie: "<<endl;
for(int i=0;i<ebron.size();i++)
{
	cout<<i+1<<"."<<ebron[i].nazwa<<" sila ataku broni wynosi"<<ebron[i].atk_boost_getter()<<endl;	                          
}
if(ebron.empty())cout<<"1.Powrot"<<endl;

cout<<"--------------------\n1.Powrot\n2.Zaloz bron\n";

int w;
cin>>w;

switch(w)
{
	case 1:{break;}
case 2:{
	if(ebron.empty()==0)cout<<"Ktora bron chcesz zalozyc?"<<endl;
	int j;
	cin>>j;
	
	zal_bron=ebron[j-1];
	cout<<"Zalozyles bron "<<zal_bron.nazwa_getter();
	wyswietlanie_broni();
};
default:{ cout<<"Brak takiej opcji"<<endl;
//wyswietlanie_zbroi();
}}
};

void wyswietlanie_mikstur()
{
if(emikstura.empty())cout<<"\nBrak mikstur";
	
	else cout<<"Mikstury: "<<endl;
for(int i=0;i<emikstura.size();i++)
{
	cout<<i+1<<"."<<emikstura[i].nazwa<<endl;	                          
}
};







void menu_glowne()
{
	cout<<"1.Ekwipunek\n2.Dziennik\n3.Awans\n4.Postac\n5.Powrot"<<endl;
	int wybor;
	cin>>wybor;
	
	switch (wybor)
	{case 1:{
	wyswietlanie_ekwipunku();
	
	menu_glowne();
	break;}
	
	case 4:{
		wyswietlanie_atrybutow();
		
		
		cout<<"----------------\n1.Powrot"<<endl;
		int w;
		cin>>w;
		
		menu_glowne();	
		break;
	}
	
	case 5:{break;}
	
	
}
}


void wyswietlanie_atrybutow()

{cout<<"NAZWA POSTACI ="<<nazwa_getter()<<endl;
cout<<"Poziom: "<<level_getter()<<endl;
cout<<"HP: "<<hp_getter()<<"/"<<max_hp_getter()<<endl;
cout<<"ATAK ="<<atk_getter()<<endl;
cout<<"OBRONA="<<obr_getter()<<endl;
cout<<"ZRECZNOSC="<<zre_getter()<<endl;
cout<<"INTELIGENCJA="<<intel_getter()<<endl;

cout<<"--------------------------------"<<endl;

cout<<"Zalozona zbroja :"<<zal_zbroja.nazwa_getter()<<" o wspolczynniku obrony =";
if(zal_zbroja.obr_boost_getter()<=100)cout<<0<<endl;
else cout<<zal_zbroja.obr_boost_getter()<<endl;
cout<<"Uzywana bron : "<<zal_bron.nazwa_getter()<<" o wspolczyniku ataku =";
if(zal_bron.atk_boost_getter()<=100)cout<<0<<endl;   
else cout<<zal_bron.atk_boost_getter()<<endl;

}

};


//koniec klasy












//Funkcja ataku







void atak(Postac *atakujacy, Postac* broniacy)
{


		int d=rand()%100+100;	
        float b=(float)d/100;
        float c=(float)atakujacy->moc_broni_getter()/100;
		
		float sila_ataku_b=atakujacy->atk_getter()*b*c*2;
		
		cout<<"Sila ataku "<<atakujacy->nazwa_getter()<<"a wyniosla "<<round(sila_ataku_b)<<" "<<"---------";
		
		int r=rand()%10;
		float u=r*broniacy->zre_getter();
	
		float o=broniacy->obr_getter();
		if(u>50)cout<<broniacy->nazwa_getter()<<" uniknal ataku"<<endl;
		else {
			
			int d2=rand()%100+100;	
        float b2=(float)d2/100;
        float c2=(float)broniacy->moc_zbroi_getter()/100;
        
        float m=broniacy->obr_getter()*b2*c2;
      float moc_obrony=m/4;
        float obrazenia=sila_ataku_b/moc_obrony;
       
     
       
        
         
           broniacy->hp_setter(broniacy->hp_getter()-obrazenia);
     cout<<broniacy->nazwa_getter()<<" otrzymal "<<round(obrazenia)<<" obrazen"<<endl;
					
					
					}
		
		if(broniacy->hp_getter()>0)
		{cout<<broniacy->nazwa_getter()<<"owi zostalo "<<broniacy->hp_getter()<<" zycia"<<endl;}
		
		if(broniacy->hp_getter()<0){cout<<broniacy->nazwa_getter()<<" umiera"<<endl;};
		                                                           

	}			




//FUNKCJA	WALKI

void walka(Postac *bohater, Postac* wrog)
{
	
	while(bohater->hp_getter()>0 and wrog->hp_getter()>0)
	{
		cout<<"Co chcesz zrobic?"<<endl;
		cout<<"1.Atak"<<endl;
		int wybor;
		
		cin>>wybor;
		
		switch(wybor)
		case 1:
		{atak(bohater,wrog);
		break;}
		
		
	  if(wrog->hp_getter()>0) atak(wrog,bohater);
	}
	
	
	if(bohater->hp_getter()<=0){cout<<"UMARLES GAME OVER";}
else{string q="tak";
	while(q=="tak" and wrog->ekwipunek.empty()==0){
	cout<<"Z "<<wrog->nazwa_getter()<<" wypadlo :"<<endl;

for(int i=0;i<wrog->ekwipunek.size();i++)
{
cout<<i+1<<"."<<wrog->ekwipunek[i].nazwa_getter()<<endl;
}
cout<<"Czy chcesz zabrac ktorys z przedmiotow ?"<<endl;
cin>>q;
if(q=="tak")
{
cout<<"Ktory przedmiot chcesz zabrac"<<endl;
int j;
cin>>j;

Przedmiot temp(wrog[0].ekwipunek[j-1]);
bohater->branie_przedmiotu(&temp);
wrog->ekwipunek.erase(wrog->ekwipunek.begin()+j-1);

}
else{};
}
}
}













//Funkcja tworzenia postaci





	void tworzenie_postaci(Bohater *b)
	{
		string imie;
		int pula=10;
		
		cout<<"Jak sie nazywasz";
		cin>>imie;
		cout<<endl;
		b->nazwa_setter(imie);
		cout<<"Masz 10 punktow do rozdzielenia dla swoich cech podstawowych"<<endl;
		cout<<"ATAK = 5"<<endl;
		cout<<"OBRONA=5"<<endl;
		cout<<"ZRECZNOSC=5"<<endl;
		cout<<"INTELIGENCJA=5"<<endl;
	
		
				while(pula>0)
		{cout<<"Do czego chcesz dodac punkty? : 1.ATK, 2.OBR, 3.ZRE, 4.INT"<<endl;
		
		int wybor=0;
		int ile=0;
		cin>>wybor;
		
		
        
       		
		switch (wybor){
		
		
		case 1:
		{cout<<"Ile punktow chcesz dodac do ataku?"<<endl;
		cin>>ile;
		if(ile<=pula){
		b->atk_setter(b->atk_getter()+ile);
		pula=pula-ile;
		}
		else {cout<<"nie masz tyle punktow"<<endl;};
		break;}
		
		case 2:{cout<<"Ile punktow chcesz dodac do obrony?"<<endl;
		cin>>ile;
		if(ile<=pula){
		b->obr_setter(b->obr_getter()+ile);
		pula=pula-ile;
		}
		else {cout<<"nie masz tyle punktow"<<endl;}
		break;}
		
		case 3:{cout<<"Ile punktow chcesz dodac do zrecznosci?"<<endl;
		cin>>ile;
		if(ile<=pula){
		b->zre_setter(b->zre_getter()+ile);
		pula=pula-ile;
		}
		else {cout<<"nie masz tyle punktow"<<endl;}
		break;}
		
		case 4:{cout<<"Ile punktow chcesz dodac do inteligencji?"<<endl;
		cin>>ile;
		if(ile<=pula){
		b->intel_setter(b->intel_getter()+ile);
		pula=pula-ile;
		}
		else{ cout<<"nie masz tyle punktow"<<endl;}
		break;}
		
		}
			cout<<"Zostalo ci "<<pula<<" punktow"<<"do wydania"<<endl;
	}
b->wyswietlanie_atrybutow();
}
		
	




bool test_na_zre(Bohater *b, int trudnosc)
{
	srand(time(NULL));
int rzut=rand()%250+50;
float wspol=(float)rzut/100;
float zre=(float)b->zre_getter();	
float wynik=zre*wspol;

if(wynik>trudnosc*3)return 1;
else return 0;	
	
	
	
	
}

bool test_na_intel(Bohater *b, int trudnosc)
{
	srand(time(NULL));
int rzut=rand()%250+50;
float wspol=(float)rzut/100;
float intel=(float)b->intel_getter();	
float wynik=intel*wspol;

if(wynik>trudnosc*3)return 1;
else return 0;	

}

//Handel i tworzenie NPC









