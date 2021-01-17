
#include "Game/Paddle/Paddlemovement3.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>
#include <Game/Paddle/PaddleEntity3.h>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"



using namespace Game;



PaddleEntity3::PaddleEntity3()
{
	paddleMovement3 = AddComponent<Paddlemovement3>();
	collidableComponet3 = AddComponent<GameEngine::CollidableComponent>();
	//physicsComponet2 = AddComponent<GameEngine::CollidablePhysicsComponent>();


	//movement



}
PaddleEntity3::~PaddleEntity3()
{

}
