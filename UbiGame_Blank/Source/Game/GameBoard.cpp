#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Grid.h"
#include "Game/Scoreboard/Entities/ScoreboardEntity.h"
#include "Game/Ball/BallEntity.h"
#include "Game/Paddle/PaddleEntity.h"
#include "Game/Paddle/PaddleEntity2.h"
#include "Game/Paddle/PaddleEntity3.h"
#include "Game/Paddle/PaddleEntity4.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;
float s = 0;
GameBoard::GameBoard()
	: left_paddle(nullptr), right_paddle(nullptr), top_paddle(nullptr), bot_paddle(nullptr), ball(nullptr), scoreboard(nullptr), Border(nullptr)
{
	CreatePaddle();
	CreateBall();
	CreateScoreboard();
	Border = new Game::Grid();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	if (scoreboard->GetSecondsRemaining() > 0) {
		if(ball->flag !=-1)
		Border->UpdatePixel(ball->GetPos().x, ball->GetPos().y, ball->flag-2, scoreboard);
	}
	else {
		scoreboard->ShowWinner();
	}
}


void GameBoard::CreatePaddle() {
	float h = GameEngine::GameEngineMain::GetPixelHeight(100.f);
	int player = 4;

	//LeftMan
	left_paddle = new PaddleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_paddle);
	left_paddle->flag = 2;
	left_paddle->SetPos(sf::Vector2f(50.f, 100.f));
	left_paddle->SetSize(sf::Vector2f(10.f, 50.f));
	GameEngine::SpriteRenderComponent* render_left = static_cast<GameEngine::SpriteRenderComponent*>(left_paddle->AddComponent<GameEngine::SpriteRenderComponent>());
	render_left->SetFillColor(sf::Color::Transparent); //pink
	render_left->SetTexture(GameEngine::eTexture::LeftPaddle);
	render_left->SetZLevel(2);

	//RightMan
	right_paddle = new PaddleEntity2(player);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_paddle);
	right_paddle->flag = 3;
	right_paddle->SetPos(sf::Vector2f(h - 50.f, 100.f));
	right_paddle->SetSize(sf::Vector2f(10.f, 50.f));
	GameEngine::SpriteRenderComponent* render_right = static_cast<GameEngine::SpriteRenderComponent*>(right_paddle->AddComponent<GameEngine::SpriteRenderComponent>());
	render_right->SetFillColor(sf::Color::Transparent); //green
	render_right->SetTexture(GameEngine::eTexture::RightPaddle);
	render_right->SetZLevel(2);
	
	if (player >= 3)
	{
		//TopMan
		top_paddle = new PaddleEntity3();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(top_paddle);
		top_paddle->flag = 4;
		top_paddle->SetPos(sf::Vector2f(100.f, 50.f));
		top_paddle->SetSize(sf::Vector2f(50.f, 10.f));
		GameEngine::SpriteRenderComponent* render_top = static_cast<GameEngine::SpriteRenderComponent*>(top_paddle->AddComponent<GameEngine::SpriteRenderComponent>());
		render_top->SetFillColor(sf::Color::Transparent); //yellow
		render_top->SetTexture(GameEngine::eTexture::TopPaddle);
		render_top->SetZLevel(2);
	}

	if (player == 4)
	{
		//BotMan
		bot_paddle = new PaddleEntity4();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bot_paddle);
		bot_paddle->flag = 5;
		bot_paddle->SetPos(sf::Vector2f(100.f, h - 100.f));
		bot_paddle->SetSize(sf::Vector2f(50.f, 10.f));
		GameEngine::SpriteRenderComponent* render_bot = static_cast<GameEngine::SpriteRenderComponent*>(bot_paddle->AddComponent<GameEngine::SpriteRenderComponent>());
		render_bot->SetFillColor(sf::Color::Transparent); //blue
		render_bot->SetTexture(GameEngine::eTexture::BotPaddle);


	//set sprite
	
	//render_right->SetTexture(GameEngine::eTexture::RightPaddle

		render_bot->SetZLevel(2);
	}

}

void GameBoard::CreateBall() {
	ball = new BallEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);

	ball->SetPos(sf::Vector2f(250.f, 250.f));
	ball->SetSize(sf::Vector2f(20.f, 20.f));
}

void GameBoard::CreateScoreboard() {
	scoreboard = new ScoreboardEntity(2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreboard);

	scoreboard->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(50.f), GameEngine::GameEngineMain::GetPixelHeight(95.f)));
	scoreboard->SetSize(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(100.f), GameEngine::GameEngineMain::GetPixelHeight(10.f)));

	scoreboard->InitScoreboard();
}
