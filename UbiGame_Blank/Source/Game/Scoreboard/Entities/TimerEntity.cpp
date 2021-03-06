#include <time.h>
#include "TimerEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

TimerEntity::TimerEntity(sf::Color color, int seconds)
	: timerSeconds(seconds), secondsRemaining(seconds), startTimeInSeconds(time(NULL))
{
	// Render
	m_timerTextRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_timerTextRenderComponent->SetFont("arial.ttf");
	m_timerTextRenderComponent->SetColor(color);
	m_timerTextRenderComponent->SetCharacterSizePixels(GameEngine::GameEngineMain::GetPixelHeight(4.f));
	m_timerTextRenderComponent->SetFillColor(sf::Color::Transparent);
	m_timerTextRenderComponent->SetZLevel(2);

	m_timerTextRenderComponent->SetString(std::to_string(secondsRemaining));
}


TimerEntity::~TimerEntity()
{

}


void TimerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void TimerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void TimerEntity::Update()
{
	time_t nowInSeconds = time(NULL);
	int secondsPassed = nowInSeconds - startTimeInSeconds;
	secondsRemaining = timerSeconds - secondsPassed;
	if (secondsRemaining > 0) {
		m_timerTextRenderComponent->SetString(std::to_string(secondsRemaining));
	}
}

void TimerEntity::ShowWinner(sf::Color color) 
{
	m_timerTextRenderComponent->SetString("Winner");
	m_timerTextRenderComponent->SetColor(color);
}