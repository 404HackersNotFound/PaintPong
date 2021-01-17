#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/Paddle/Paddlemovement4.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	

	class PaddleEntity4 : public GameEngine::Entity
	{
	public:
		PaddleEntity4();
		~PaddleEntity4();


	protected:
		Paddlemovement4* paddleMovement4;
		GameEngine::CollidableComponent* collidableComponet4;
		//GameEngine::CollidablePhysicsComponent* physicsComponet2;


	};
}

