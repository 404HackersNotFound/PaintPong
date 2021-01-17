#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

	class ScoreEntity : public GameEngine::Entity
	{
	public:
		ScoreEntity(sf::Color color, int score);
		~ScoreEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		
		virtual void UpdateScore(int score);
		virtual int GetScore() { return score; }

	protected:
		GameEngine::TextRenderComponent* m_scoreTextRenderComponent;
		int score;
	};
}

