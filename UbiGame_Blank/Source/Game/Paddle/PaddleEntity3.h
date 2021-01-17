#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/Paddle/Paddlemovement3.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	

	class PaddleEntity3 : public GameEngine::Entity
	{
	public:
		PaddleEntity3();
		~PaddleEntity3();


	protected:
		Paddlemovement3* paddleMovement3;
		GameEngine::CollidableComponent* collidableComponet3;
		//GameEngine::CollidablePhysicsComponent* physicsComponet2;


	};
}

