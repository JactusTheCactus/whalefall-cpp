#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#define key_pressed sf::Keyboard::isKeyPressed
#define SPEED (1.f / 10.f / 2.f)
#define WIDTH 50.f
enum Direction
{
	NORTH = 600,
	SOUTH = 0,
	EAST = 800,
	WEST = 0
};
float clamp(float min, float n, float max)
{
	return std::min(std::max(min, n), max);
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(EAST, NORTH), "Whalefall");
	sf::RectangleShape player(sf::Vector2f(WIDTH, WIDTH));
	player.setFillColor(sf::Color::Red);
	player.setPosition(375.f, 275.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				key_pressed(sf::Keyboard::Q) ||
				key_pressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		float x, y = 0.f;
		if (key_pressed(sf::Keyboard::Up))
		{
			y = 1.f;
		}
		else if (key_pressed(sf::Keyboard::Down))
		{
			y = -1.f;
		}
		else
		{
			y = 0.f;
		}
		if (key_pressed(sf::Keyboard::Left))
		{
			x = -1.f;
		}
		else if (key_pressed(sf::Keyboard::Right))
		{
			x = 1.f;
		}
		else
		{
			x = 0.f;
		}
		float speed = x != 0 && y != 0
						  ? SPEED / std::sqrt(2)
						  : SPEED;
		player.move(speed * x, speed * -y);
		window.clear(sf::Color::Black);
		player.setPosition(clamp(WEST,
								 player.getPosition().x,
								 EAST - WIDTH),
						   clamp(SOUTH,
								 player.getPosition().y,
								 NORTH - WIDTH));
		window.draw(player);
		window.display();
	}
	return 0;
}
