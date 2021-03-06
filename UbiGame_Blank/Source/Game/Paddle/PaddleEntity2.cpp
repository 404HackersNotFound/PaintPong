
#include "Game/Paddle/Paddlemovement2.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>
#include <Game/Paddle/PaddleEntity2.h>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"



using namespace Game;



PaddleEntity2::PaddleEntity2(int numbofplayer)
{
	paddleMovement2 = AddComponent<Paddlemovement2>();
	collidableComponet2 = AddComponent<GameEngine::CollidableComponent>();
	//physicsComponet2 = AddComponent<GameEngine::CollidablePhysicsComponent>();


	//movement



}
PaddleEntity2::~PaddleEntity2()
{

}

template <class T>
T* AddComponent()
{
	T* newComponent = new T(numbofplayer);
	newComponent->SetEntity(this);
	m_components.push_back(newComponent);

	return newComponent;
}
