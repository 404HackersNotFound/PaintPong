
#include "Game/Paddle/Paddlemovement4.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>
#include <Game/Paddle/PaddleEntity4.h>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"



using namespace Game;



PaddleEntity4::PaddleEntity4()
{
	paddleMovement4 = AddComponent<Paddlemovement4>();
	collidableComponet4 = AddComponent<GameEngine::CollidableComponent>();
	//physicsComponet2 = AddComponent<GameEngine::CollidablePhysicsComponent>();


	//movement



}
PaddleEntity4::~PaddleEntity4()
{

}
