#include "ScoreEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

ScoreEntity::ScoreEntity(sf::Color color, int score):
	score{score}
{
	// Render
	m_scoreTextRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_scoreTextRenderComponent->SetFont("arial.ttf");
	m_scoreTextRenderComponent->SetColor(color);
	m_scoreTextRenderComponent->SetCharacterSizePixels(GameEngine::GameEngineMain::GetPixelHeight(4.f));
	m_scoreTextRenderComponent->SetFillColor(sf::Color::Transparent);
	m_scoreTextRenderComponent->SetZLevel(2);

	m_scoreTextRenderComponent->SetString(std::to_string(score));
}


ScoreEntity::~ScoreEntity()
{

}


void ScoreEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void ScoreEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void ScoreEntity::UpdateScore(int score)
{
	ScoreEntity::score = score;
	m_scoreTextRenderComponent->SetString(std::to_string(score));
}
