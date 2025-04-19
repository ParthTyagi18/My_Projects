/*=========================================================
BACCARAT - Casino Number Game
Project by Parth Tyagi
Registration Number - RA2411026030105
pt3583@srmist.edu.in

Player chooses between two sides either
'banker' or 'player'. After drawing two cards the one
who has the nearest number to 9 wins.

Whenever sum overboards to 9, 1 card will be drawn
from the deck. However if at the first two draw
results a sum of 8 and 9, the dealer won't draw
additional card anymore.

===========================================================*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class CARD {
    public:
int card_1 , card_2 , extra_card , sum_card;
CARD();
void display_card();
friend int winner_function (CARD &a, CARD &b);
};

//declaring functions
void declare_winner (int w, int d, int b);
bool play_again (string a, int m);

//Defining variables//
int decision, prize, winner, money = 10000, bet;
bool logic = true;
string name, input;

int main(){
    system("Color 0A");
    srand(time(NULL)); /*It generates random cards when object is initialized*/

cout<<"====================================\n"
    <<" To start, please enter your card.\n";
    
//input name//
cout<<"please enter your name:";
getline(cin, name);

cout<<"\nGood Day ,"<<name<<endl;
cout<<"======================================\n"
    <<"WELCOME TO THE VIRTUAL BACCARAT TABLE\n"
    <<"======================================\n";

do{//main do-while loop//
    cout<<"Your account balance is Rupees "<<money<<endl;
    do{cout<<"1-BANKER\n"
           <<"2-PLAYER\n"
           <<"Enter your choice:";
           cin>>decision;}
    //checking input for validity//
    while(cin.fail() || decision < 1 || decision > 2);
    
    while (true) {
    cout<<"Place Bet:";
    cin>>bet;
    //checking validity for bet//
    if(bet > money){
        cout<<"Insufficient Balance.";
    }
    else if(bet <= 0){
        cout<<"Please enter valid amount.";
    }
    else {
        break;
    }
    }

    cout<<"=============================\n"
        <<"      GAME      BEGINS       \n"
        <<"=============================\n";
    
    CARD Banker, Player;            //creating two objects//

    cout<<"==============================\n"
        <<"       Banker's Card          \n"
        <<"==============================\n";
    
    Banker.display_card();

    cout<<"==============================\n"
        <<"       Player's Card          \n"
        <<"==============================\n";

    Player.display_card();                 

    winner = winner_function(Banker, Player);

    declare_winner(winner, decision, bet);

    cout<<"Want to play again?\n"<<"Enter Y/y or N/n:";
    cin>>input;
    //check the input's validity//
    logic = play_again(input, money);
}
while (logic);
return 0;
}

//definitions//
CARD::CARD() { 
    card_1 = rand() % 10 + 1;         
    card_2 = rand() % 10 + 1;
    sum_card = card_1 + card_2;
    sum_card = sum_card % 10;
    extra_card = 0;
    //if the sum of the two cards is not 8 or 9 then EXTRA card will be taken
    if ((sum_card != 9) && (sum_card != 8)) {
        extra_card = rand() % 10 + 1;
        sum_card += extra_card;
        sum_card = sum_card % 10;
    }
}

//function to display card

void CARD::display_card () {
    cout<<"============\n"        
        <<"||        ||\n"
        <<"||        ||\n"
        <<"||   "<<sum_card<<"    ||\n"
        <<"||        ||\n"
        <<"||        ||\n"
        <<"============\n";
    cout<<"card_1 = "<<card_1<<endl;
    cout<<"card_2 = "<<card_2<<endl;
    if (extra_card != 0){
        cout<<"extra_card = "<<extra_card<<endl;
    }
    cout<<"sum_card = "<<sum_card<<endl;
}

int winner_function (CARD &obj_1, CARD &obj_2) {
     //function to determine nearest number to 9
    //returns 1,2,3 depending on condiiton met
    if (obj_1.sum_card > obj_2.sum_card){
        return 1;
    }

    else if (obj_1.sum_card < obj_2.sum_card){
        return 2;
    }
    else{
        return 3;
    }
}

//prints the outcomes
void declare_winner (int w, int d, int b) {
    if(w == d) {
        money += b;
        cout<<"YOU WIN!!"<<endl;
        cout<<"Amount Won :"<<b<<"\n"
            <<"Account Balance :Rupees "<<money<<endl;
    }
    else if (w == 3) {
        cout<<"DRAW\n"<<"Amount Won : 0\n"
            <<"Account Balance :Rupees "
            <<money<<endl;
    }
    else {
        money -= b;
        b = -b;
        cout<<"YOU LOSE\n"<<"Amount Won :"<<b<<endl;
        cout<<"Account Balance :Rupees "
            <<money<<endl;
    }
}

bool play_again (string a, int m){
    if (m <= 0){
        return false;
    }
    else if (a=="Y"||a=="y"){
        return true;
    }
    else{
        return false;
    }
}
/*==============================END OF CODE===================================*/
