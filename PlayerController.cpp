#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Character* character) :CharacterController(character){
}
void PlayerController::Think(){
	character_->Run(true);
}