#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

	class TimerEntity : public GameEngine::Entity
	{
	public:
		TimerEntity(sf::Color color, int seconds);
		~TimerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		virtual void Update() override;

		virtual int GetSecondsRemaining() { return secondsRemaining; };
		virtual void ShowWinner(sf::Color color);

	protected:
		GameEngine::TextRenderComponent* m_timerTextRenderComponent;
		// Number of seconds set on the timer;
		int timerSeconds;
		int secondsRemaining;
		time_t startTimeInSeconds;
	};
}

