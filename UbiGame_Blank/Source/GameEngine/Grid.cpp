#include "Grid.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/TextureManager.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>

using namespace Game;
Grid::Grid()
	: top_border(nullptr), bottom_border(nullptr), left_border(nullptr), right_border(nullptr)
{
	CreateBorder();
	int plynA[4] = { 0,0,0,0 };
}

Grid::~Grid() {

}


void Grid::CreateBorder() {

	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::Background);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);
	
	//m_backGround = bgEntity;

	top_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(top_border);
	bottom_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bottom_border);
	left_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_border);
	right_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_border);
	float h = GameEngine::GameEngineMain::GetPixelHeight(100.f);
	float w = GameEngine::GameEngineMain::GetPixelWidth(100.f);
	float border_w = 10;
	top_border->SetPos(sf::Vector2f(w / 2, 0));
	top_border->SetSize(sf::Vector2f(w, border_w + 3));

	bottom_border->SetPos(sf::Vector2f(w / 2, h));
	bottom_border->SetSize(sf::Vector2f(w,border_w+ h/5));

	left_border->SetPos(sf::Vector2f(0, h / 2));
	left_border->SetSize(sf::Vector2f(border_w, h));

	right_border->SetPos(sf::Vector2f(w, h / 2));
	right_border->SetSize(sf::Vector2f(border_w, h));

	GameEngine::RenderComponent* r_top = static_cast<GameEngine::RenderComponent*>(top_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_bot = static_cast<GameEngine::RenderComponent*>(bottom_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_left = static_cast<GameEngine::RenderComponent*>(left_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_right = static_cast<GameEngine::RenderComponent*>(right_border->AddComponent<GameEngine::RenderComponent>());

	r_top->SetFillColor(sf::Color::Red);
	r_bot->SetFillColor(sf::Color::Yellow);
	r_left->SetFillColor(sf::Color::Blue);
	r_right->SetFillColor(sf::Color::Green);

	top_border->AddComponent<GameEngine::CollidableComponent>();
	bottom_border->AddComponent<GameEngine::CollidableComponent>();
	left_border->AddComponent<GameEngine::CollidableComponent>();
	right_border->AddComponent<GameEngine::CollidableComponent>();

	top_border->flag = 1;
	bottom_border->flag = 1;
	left_border->flag = 0;
	right_border->flag = 0;
	
}

void Grid::UpdatePixel(float x, float y, int plyn, ScoreboardEntity* scoreboard) {
	
	sf::Texture* background = GameEngine::TextureManager::GetInstance()->GetTexture(GameEngine::eTexture::Background);
	sf::Image img = background->copyToImage();
	sf::Color bc;

	if (plyn == 0)
		bc = sf::Color(255, 155, 220);
	else if (plyn == 1)
		bc = sf::Color(130, 152, 255);
	else if (plyn == 2)
		bc = sf::Color(255, 255, 124);
	else if (plyn == 3)
		bc = sf::Color(138, 255, 141);
	else
		bc = sf::Color::Black;
	

	for(float i = -1; i <2;i=i+2)
		for (float k = -1; k < 2; k = k + 2) {
		for (float j = 0; j < 36; j++) {
			float yd = j*k/3;
			float xd = sqrt(1 - (j / 36)) * 12 * i;
				
				sf::Color check = img.getPixel(x + xd, y + yd);
				img.setPixel(x + xd, y + yd, bc);

				if (check != bc) {
					plynA[plyn]++;
					scoreboard->UpdateScore(plyn, plynA[plyn]);
					int over = whatplayer(check);
						if (over != -1) {
							plynA[over]--;
							scoreboard->UpdateScore(over, plynA[over]);
					}

				}
			}
		}
	
	background->loadFromImage(img);
}


int Game::Grid::whatplayer(sf::Color check) {
	
	if(check == sf::Color(255, 155, 220))
		return 0;
	if(check == sf::Color(130, 152, 255))
		return 1;
	if(check == sf::Color(255, 255, 124))
		return 2;
	if (check == sf::Color(138, 255, 141))
		return 3;
	
		return -1;
	
	
}