#include<iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <string>
using namespace std;

string RomanceAnimesNames[15] = {"Horimiya", "Twin Star Exorcist", "Plastic Memories", "High School DxD", "Sword Art Online", "Accel World", "Blue Spring Ride", "Your Lie in April", "Charlotte", "Guilty Crown ", "Kaguya Sama Love is War", "Your Name", "The Detective is Already Dead", "My Dress Up Darling", "Darling in the Franxx"};
string usedLetters = "Used Letters: ";
string unknownName2point0 = " ";
string actionAnimesNames[27] = {"That Time I got Reincarnated as a Slime","One Piece", "One Punch Man","Fate Stay Night","Bleach","Dragon Ball","Naruto","Inuyasha","Overlord","Boruto","Black Clover","Attack on Titan","Jujutsu Kaisen","The Rising of The Shield Hero","My Hero Academia","Demon Slayer","Full Metal Alchemist","Sword Art Online","Tokyo Ghoul","Hunter X Hunter", "Code Geass","Akame Ga Kill","Seven Deadly Sins","Fairy Tail","Darling in The Franxx","Noragami","Seraph of the End"};


void dead(){
    cout << endl;
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "    /|\\           | " << endl;
    cout << "    / \\           | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void startPole(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void headPole(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void body(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "     |            | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void leftArm(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "    /|            | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void rightArm(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "    /|\\           | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}

void leftLeg(){
    cout << "     |------------| " << endl;
    cout << "     |            | " << endl;
    cout << "     |            | " << endl;
    cout << "     O            | " << endl;
    cout << "    /|\\           | " << endl;
    cout << "    /             | " << endl;
    cout << "                  | " << endl;
    cout << "                  | " << endl;
    cout << "   ---------------- " << endl;
}


void unknownName(string name){
    for(int i = 0; i < name.size(); i++){
        if(name[i] == ' ')
            unknownName2point0 += "   ";
        else
            unknownName2point0 += "_ ";
    }
    
}

char guessLetter(){
    char letter;
    cout << "Guess the letter: ";
    cin >> letter;
    return letter;
}

bool checkLetter(char letter, string name){
    for(int i = 0; i < name.size(); i++){
        if(letter == name[i]){
            return true;
        }
    }
    return false;
}

void stringName(string name, char letter){
    int index = -1;
    for(int i = 0; i < unknownName2point0.size(); i++){
        if(unknownName2point0[i] == '_' || isalpha(unknownName2point0[i])){
            index++;
            if(name[index] == ' ')
                index++;
            if(name[index] == toupper(letter) || name[index] == tolower(letter) || name[index] == letter){
                unknownName2point0[i] = name[index];
            }
        }

    }
  
}

int updateUnknownName(string name, int life){
    char letter = guessLetter();
    if(checkLetter(letter, name)){
        cout << endl;
        stringName(name, letter);
        return life;
    }
    else{
        life--;
        string s(1, letter);
        usedLetters+= s + ", ";
        return life;
    }
        
}

void suicidalPole(int life){
    switch(life){
        case 0:
            dead();
            break;
        case 1:
            leftLeg();
            break;
        case 2:
            rightArm();
            break;
        case 3:
            leftArm();
            break;
        case 4:
            body();
            break;
        case 5:
            headPole();
            break;
        case 6:
            startPole();
            break;
    }
}

bool nameGuessed(){
    for(int i = 0; i < unknownName2point0.size(); i++){
        if(unknownName2point0[i] == '_')
            return false;
    }
    return true;
}

void startGame(string name){
    int life = 6;
    bool oneTime = true;
    
    while(life>0){
        suicidalPole(life);
        cout << usedLetters << endl;
        cout << endl;
        if(oneTime)
            unknownName(name);
        oneTime = false;
        cout << unknownName2point0 << endl;
        life = updateUnknownName(name, life);
        if(nameGuessed())
            break;
    }
    
    if(life == 0){
        dead();
        cout << "You lost!" << endl;
    }
    
    else
        cout << "You won!" << endl;
    
        
}
    
int category(){
    int pickTheAnime;
    cout << "Welcome to Guess the Anime !!!" << endl;
    cout << "Btw if you risk guessing the entire word you might lose so good luck :D\n";
    cout << "Please Pick 1 for action animes and 2 for romance animes" << endl;
    cin >> pickTheAnime;
    return pickTheAnime;
}


void menu(){
    int categories = 0;
    categories = category();
    string randomAnime;
    if(categories == 2){
        cout << "Welcome to Guess the Romance Animes !!!" << endl;
        /* initialize random seed: */
        srand (time(NULL));
        
        int randomIndex = rand() % 14; 
        /* generate an index between 0 and 15: */
    
        randomAnime = RomanceAnimesNames[randomIndex];
    }
    
    else{
        cout << "Welcome to Guess the Action Animes !!!" << endl;
        /* initialize random seed: */
        srand (time(NULL));
        
        int randomIndex = rand() % 26; 
        /* generate an index between 0 and 26: */
    
        randomAnime = actionAnimesNames[randomIndex];
    }
    
    startGame(randomAnime);
        
        
    
}

int main()
{

    menu();

    return 0;
}







