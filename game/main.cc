#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
	// command line arguments
	bool initState = false;
	bool testingState = false;
	bool graphicsState = false;
	bool deck1State = false;
	bool deck2State = false;
	ifstream initfile;
	ifstream deck1file;
	ifstream deck2file;

	// command line argument
	for(int i = 1; i < argc; i++){
		if(string(argv[i]) == "-init") {
			initState = true;
			initfile.open(argv[i + 1]);
			i += 1; // skip the next argument
		} else if(string(argv[i]) == "-testing"){
			testingState = true;
		} else if(string(argv[i]) == "-graphics"){
			graphicsState = true;
		} else if(string(argv[i]) == "-deck1"){
			deck1State = true;
			deck1file.open(argv[i + 1]);
			i += 1; // skip the next argument
		} else if(string(argv[i]) == "-deck2"){
			deck2State = true;
			deck2file.open(argv[i + 1]);
			i += 1; // skip the next argument
		}
	}

	string playername1;
	string playername2;
	string cmd;

	cout << "Welcome to Sorcery!" << endl;

	// read in player names
	cout << "Player 1: ";
	if(initState && initfile >> playername1){
		cout << playername1 << endl;
	} else {
		cin >> playername1;
	}
	cout << "Player 2: ";
	if(initState && initfile >> playername1){
		cout << playername1 << endl;
	} else {
		cin >> playername1;
	}
	
	// create players
	vector<Player *> players;
	players.emplace_back(new Player{playername1});
	players.emplace_back(new Player{playername2});
	int currentPlayer = 0;

	// enter game loop, change cin >> cmd to getline
	while (true){
		if (!(initfile >> cmd)){
			cin >> cmd;
		}
		// display help message
		if (cmd == "help"){
			ifstream helpfile{"help.txt"};
			string s;
			while(getline(helpfile, s)){
				cout << s << endl;
			}
		} 
		// end current player's turn
		else if (cmd == "end"){
			currentPlayer = (currentPlayer == 0) ? 1 : 0;
		} 
		// end game
		else if (cmd == "quit"){
			cout << "Bye!" << endl;
			// delete anything if needed
			return 0;
		} 
		// draw a card
		else if (cmd == "draw" && testingState == true){
			// only available in testing mode
			
		} 
		// disgard i: disgard the ith card in hand
		else if (cmd == "disgard" && testingState == true){
			// only available in testing mode

		} 
		// attack i: minion i to attack opposing player
		// attack i j: minion i to attact opposing player's minion j
		else if (cmd == "attack"){ 
			// attack i, attack i, j
			
		} 
		// play i: play the ith card
		// minion, ritual, spell with no target
		// play i p t/r : play the ith card on player p's minion t, or on ritual
		// enchantment and spell with targets
		else if (cmd == "play"){
			// play i, play i p t

		} 
		// use i: use minion i
		// use i p t/r : use minion i on player p's minion t, or on ritual
		else if (cmd == "use"){
			// use i, use i p t
			
		} 
		// inspect i: display minion i
		else if (cmd == "inspect"){
			// inspect i

		} 
		// hand: display hand
		else if (cmd == "hand"){
			
		} 
		// board: display board
		else if (cmd == "board"){
			
		}
	}
	return 0;
}