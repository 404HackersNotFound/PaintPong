#pragma once
#include <vector>
#include <map>
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "ScoreEntity.h"
#include "TimerEntity.h"

namespace Game
{

	class ScoreboardEntity : public GameEngine::Entity
	{
	public:
		ScoreboardEntity(int numPlayers);
		~ScoreboardEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void InitScoreboard();
		// Call this method to update the score
		virtual void UpdateScore(int playerNumber, int score); 
		virtual int GetSecondsRemaining() { return timer->GetSecondsRemaining(); };
		virtual void ShowWinner();

	protected:
		GameEngine::RenderComponent* m_renderComponent;
		std::vector<ScoreEntity*> scoreEntities;
		TimerEntity* timer;
		int numPlayers;
		// Black, Pink, Blue, Yellow, Green
		std::map<int, sf::Color> playerColorMap
		{
			{0, sf::Color::Black},
			{1, sf::Color(255, 155, 220)},
			{2, sf::Color(130, 152, 255)},
			{3, sf::Color(255, 255, 124)},
			{4, sf::Color(138, 255, 141)},
		};
	};
}

