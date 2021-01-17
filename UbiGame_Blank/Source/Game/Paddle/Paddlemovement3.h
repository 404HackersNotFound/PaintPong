#pragma once
#include "GameEngine/EntitySystem/Component.h"
//Paddlemovement 3
namespace Game
{
	class Paddlemovement3 :public GameEngine::Component
	{
	public:
		Paddlemovement3();
		~Paddlemovement3();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}

