#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Grid.h"
#include "Game/Scoreboard/Entities/ScoreboardEntity.h"


using namespace Game;

GameBoard::GameBoard()
	: left_paddle(nullptr), right_paddle(nullptr), ball(nullptr), scoreboard(nullptr), Border(nullptr)
{
	CreatePaddle();
	CreateBall();
	CreateScoreboard();
	Border = new GameEngine::Grid();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}


void GameBoard::CreatePaddle() {
	left_paddle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_paddle);
	right_paddle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_paddle);

	left_paddle->SetPos(sf::Vector2f(10.f, 10.f));
	left_paddle->SetSize(sf::Vector2f(10.f, 10.f));

	right_paddle->SetPos(sf::Vector2f(10.f, 10.f));
	right_paddle->SetSize(sf::Vector2f(10.f, 10.f));
}

void GameBoard::CreateBall() {
	ball = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);

	ball->SetPos(sf::Vector2f(10.f, 10.f));
	ball->SetSize(sf::Vector2f(10.f, 10.f));
}

void GameBoard::CreateScoreboard() {
	scoreboard = new ScoreboardEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreboard);

	scoreboard->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(50.f), GameEngine::GameEngineMain::GetPixelHeight(95.f)));
	scoreboard->SetSize(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(100.f), GameEngine::GameEngineMain::GetPixelHeight(10.f)));

	scoreboard->InitScoreboard();
}
