#pragma once
#include "GameEngine/EntitySystem/Component.h"
//Paddlemovement 4
namespace Game
{
	class Paddlemovement4 :public GameEngine::Component
	{
	public:
		Paddlemovement4();
		~Paddlemovement4();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}
