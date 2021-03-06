#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/Paddle/Paddlemovement2.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	

	class PaddleEntity2 : public GameEngine::Entity
	{
	public:
		PaddleEntity2(int numbofplayer);
		~PaddleEntity2();
		int getnumbofplayer() {
			return numbofplayer;
		}

	protected:
		Paddlemovement2* paddleMovement2;
		GameEngine::CollidableComponent* collidableComponet2;
		//GameEngine::CollidablePhysicsComponent* physicsComponet2;
		int numbofplayer;


	};
}
