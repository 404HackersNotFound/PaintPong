#include "Paddlemovement.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

Paddlemovement::Paddlemovement()
{

}

Paddlemovement::~Paddlemovement()
{

}


void Paddlemovement::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Paddlemovement::Update()
//Add keyboard movements
{
	int numbofplayer = GetEntity()->numbofplayer;
	int paddlesize = 50;
	__super::Update();

	//return time between time updated frame 
	
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 150.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (numbofplayer == 2) {

			if ((GetEntity()->GetPos().y + wantedVel.y) > (0 + paddlesize / 2) + 6)
			{
				wantedVel.y -= playerVel * dt;
			}
		}
		else
		{
			if ((GetEntity()->GetPos().y + wantedVel.y) > (0 + paddlesize / 2) + 66)
			{
				wantedVel.y -= playerVel * dt;
			}
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (numbofplayer == 2) 
		{
			if ((GetEntity()->GetPos().y + wantedVel.y) < (GameEngine::GameEngineMain::GetPixelHeight(90.f) - paddlesize / 2) - 16)
			{
				wantedVel.y += playerVel * dt;
			}
		}
		else
		{
			if ((GetEntity()->GetPos().y + wantedVel.y) < (GameEngine::GameEngineMain::GetPixelHeight(90.f) - paddlesize / 2) - 66)
			{
				wantedVel.y += playerVel * dt;
			}
		}
		
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
	
} 