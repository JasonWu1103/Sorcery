#include "textdisplay.h"
#include "ascii_graphics.h"

TextDisplay::TextDisplay(){
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(player->getplayercard());
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);

	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(player->getplayercard());
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
}


void TextDisplay::notify(Subject & whoNotified){
	if(whoNotified.getplayernum() == 1){
		// update player row
		if(whoNotified.getritual()) displayPlayer1[0] = (whoNotified.getritual())->getoutput();
		displayPlayer1[2] = whoNotified.getplayercard();
		if(!(whoNotified.getgraveyard()).empty) displayPlayer1[4] = ((whoNotified.getgraveyard()).back())->getoutput();

		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot1[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot1[i] = CARD_TEMPLATE_BORDER;
		}

		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand1[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand1[i] = CARD_TEMPLATE_BORDER;
		}

	} else if(whoNotified.getplayernum() == 2){
		// update player row
		if(whoNotified.getritual()) displayPlayer2[0] = (whoNotified.getritual())->getoutput();
		displayPlayer2[2] = whoNotified.getplayercard();
		if(!(whoNotified.getgraveyard()).empty) displayPlayer2[4] = ((whoNotified.getgraveyard()).back())->getoutput();
		
		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot2[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot2[i] = CARD_TEMPLATE_BORDER;
		}
		
		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand2[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand2[i] = CARD_TEMPLATE_BORDER;
		}
	}
}

void TextDisplay::displayBoard(){
	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;

	// first row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// second row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// centre graphic
	for(int i = 0; i < CENTRE_GRAPHIC.size(); i++){
		std::cout << CENTRE_GRAPHIC[i] << std::endl;
	}
	// third row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// fourth row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << std::endl;
}

void displayHand(Player * player){
	if(player->getplayernum() == 1){
		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand1[j][i];
			}
		}
	} else if(player->getplayernum() == 1){
		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand1[j][i];
			}
		}
	}
}

void inspectCard(Player * player, int num){
	std::vector<std::string> temp{player.getminionslot()[num]};
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << temp[i];
	}
	std::cout << std::endl;
}

