#include "Paddlemovement4.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
//Paddlemovement 4
using namespace Game;

Paddlemovement4::Paddlemovement4()
{

}

Paddlemovement4::~Paddlemovement4()
{

}


void Paddlemovement4::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Paddlemovement4::Update()
//Add keyboard movements
{
	int paddlesize = 50;
	__super::Update();

	//return time between time updated frame 

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 150.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//top border + paddlesize middle + top border thickness
		if ((GetEntity()->GetPos().x + wantedVel.x) > (0 + paddlesize / 2) + 66)
		{
			wantedVel.x -= playerVel * dt;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if ((GetEntity()->GetPos().x + wantedVel.x) < (GameEngine::GameEngineMain::GetPixelWidth(90.f) - paddlesize / 2) - 36)
		{
			wantedVel.x += playerVel * dt;
		}
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}