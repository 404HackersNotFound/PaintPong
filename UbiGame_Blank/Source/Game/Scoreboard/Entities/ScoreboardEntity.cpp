#include "ScoreboardEntity.h"
#include "GameEngine/GameEngineMain.h"
#include "ScoreEntity.h"
#include "TimerEntity.h"

using namespace Game;

ScoreboardEntity::ScoreboardEntity(int numPlayers)
	: timer(nullptr), numPlayers(numPlayers)
{
	// Render
	m_renderComponent = AddComponent<GameEngine::RenderComponent>();
	m_renderComponent->SetFillColor(sf::Color::White);
	m_renderComponent->SetZLevel(1);
}


ScoreboardEntity::~ScoreboardEntity()
{

}


void ScoreboardEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void ScoreboardEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void ScoreboardEntity::InitScoreboard()
{
	// Render Text
	float xScoreboard = GetPos().x;
	float yScoreboard = GetPos().y;
	float widthScoreboard = GetSize().x;
	float heightScoreboard = GetSize().y;

	std::vector<int> scoreColors(4, 0);
	for (int i = 1; i <= 4; i++) {
		if (i <= numPlayers) {
			scoreColors[i - 1] = i;
		}
	}

	ScoreEntity* scoreP1 = new ScoreEntity(playerColorMap[scoreColors[0]], 0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP1);
	scoreP1->SetPos(sf::Vector2f(xScoreboard - widthScoreboard * 0.40f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scoreEntities.push_back(scoreP1);

	ScoreEntity* scoreP2 = new ScoreEntity(playerColorMap[scoreColors[1]], 0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP2);
	scoreP2->SetPos(sf::Vector2f(xScoreboard - widthScoreboard * 0.20f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scoreEntities.push_back(scoreP2);

	ScoreEntity* scoreP3 = new ScoreEntity(playerColorMap[scoreColors[2]], 0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP3);
	scoreP3->SetPos(sf::Vector2f(xScoreboard + widthScoreboard * 0.20f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scoreEntities.push_back(scoreP3);

	ScoreEntity* scoreP4 = new ScoreEntity(playerColorMap[scoreColors[3]], 0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP4);
	scoreP4->SetPos(sf::Vector2f(xScoreboard + widthScoreboard * 0.40f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scoreEntities.push_back(scoreP4);

	timer = new TimerEntity(playerColorMap[0], 60);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(timer);
	timer->SetPos(sf::Vector2f(xScoreboard - GameEngine::GameEngineMain::GetPixelWidth(2.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
}

void ScoreboardEntity::UpdateScore(int playerNumber, int score)
{
	scoreEntities[playerNumber]->UpdateScore(score);
}

void ScoreboardEntity::ShowWinner()
{
	int firstPlacePlayer = 0;
	int firstPlaceScore = 0;
	int secondPlacePlayer = 1;
	int secondPlaceScore = 0;
	for (int i = 0; i < numPlayers; i++) {
		if (scoreEntities[i]->GetScore() > firstPlaceScore) {
			secondPlaceScore = firstPlaceScore;
			secondPlacePlayer = firstPlacePlayer;
			firstPlaceScore = scoreEntities[i]->GetScore();
			firstPlacePlayer = i;
		}
		else if (scoreEntities[i]->GetScore() == firstPlaceScore ||
			(scoreEntities[i]->GetScore() < firstPlaceScore && scoreEntities[i]->GetScore() > secondPlaceScore)) 
		{
			secondPlaceScore = scoreEntities[i]->GetScore();
			secondPlacePlayer = i;
		}
	}
	if (firstPlaceScore != secondPlaceScore) {
		timer->ShowWinner(playerColorMap[firstPlacePlayer + 1]);
	}
	else {
		timer->ShowWinner(playerColorMap[0]);
	}
}