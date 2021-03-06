#include "Paddlemovement2.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/Paddle/PaddleEntity2.h"

#include <SFML/Window/Keyboard.hpp>
//Paddlemovement 2
using namespace Game;

Paddlemovement2::Paddlemovement2()

{

}

Paddlemovement2::~Paddlemovement2()
{

}


void Paddlemovement2::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Paddlemovement2::Update()
//Add keyboard movements
{
	int numbofplayer = GetEntity()->numbofplayer;
	//printf("%d", numbofplayer);
	int paddlesize = 50;
	__super::Update();

	//return time between time updated frame 

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 150.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
			//top border + paddlesize middle + top border thickness
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (numbofplayer == 2) {
			if ((GetEntity()->GetPos().y + wantedVel.y) < (GameEngine::GameEngineMain::GetPixelHeight(90.f) - paddlesize / 2) + -16)
			{
				wantedVel.y += playerVel * dt;
			}
		}
		else
		{
			if ((GetEntity()->GetPos().y + wantedVel.y) < (GameEngine::GameEngineMain::GetPixelHeight(90.f) - paddlesize / 2) + -66)
			{
				wantedVel.y += playerVel * dt;
			}
		}
		
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);


}
/*Paddlemovement2* Paddlemovement2::AddComponent()
{
	Paddlemovement2* newComponent = new Paddlemovement2(numbofplayer);
	newComponent->SetEntity(this);
	m_components.push_back(newComponent);

	return newComponent;
}*/