#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
//Abel Abebe
int rollDice()
{
return (rand()%6 +1);
}
int PlayerTurn(int Score)
{
int diceValue;
int pot=0;
char choice;
char input;
cout<<"Players Turn"<<endl;
do
{
diceValue=rollDice();
cout<<"Die Roll : "<<diceValue;
if(diceValue==1)
{
cout<<" Bust"<<endl;
return Score;
}
else
{
pot+=diceValue;
cout<<" Pot: "<<pot;
}
while(1)
{
cout<<" (R)oll again or (H)old ? ";
cin>>choice;
if(choice=='r' || choice=='h')
break;
else
cout<<"You must enter R or H"<<endl;
}

}while(choice=='r' || choice=='H');
return Score+pot;
}
int ComputerTurn(int Score)
{
int pot=0;
int diceValue;
cout<<"AI Turn"<<endl;
do
{
diceValue=rollDice();
cout<<"Die Roll: "<<diceValue;
if(diceValue==1)
{
cout<<" Bust"<<endl;
return Score;
}
else
{
pot+=diceValue;
cout<<" pot: "<<pot<<endl;
}

}while(pot<20);
return pot+Score;
}
int main()
{
srand(time(0));
int score_player=0;
int score_computer=0;
char turn='P';
char choice;
do{
score_player=0;
score_computer=0;
cout<<"You : "<<score_player<<" AI : "<<score_computer<<endl;
while(1)
{
if(turn=='P')
{
score_player= PlayerTurn(score_player);
turn='C';
}
else
{
score_computer=ComputerTurn(score_computer);
turn='P';
}
cout<<"You : "<<score_player<<" AI : "<<score_computer<<endl;
if(score_computer >=50 || score_player>=50)
break;
}
if(score_player>=50)
cout<<"You Won!"<<endl;
else
cout<<"You Lost!"<<endl;
cout<<"Do you want to play again ? ";
cin>>choice;
}while(choice=='Y' || choice=='y');
return 0;
}