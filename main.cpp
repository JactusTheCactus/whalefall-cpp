#include <algorithm>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#define key_pressed(k) sf::Keyboard::isKeyPressed(sf::Keyboard::k)
#define FPS 60
#define SIZE 50.f
#define WIDTH 800.f
#define HEIGHT 600.f
#define SPEED 5.f
float clamp(float min, float n, float max)
{
	return std::min(std::max(min, n), max);
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Whalefall");
	sf::RectangleShape player(sf::Vector2f(SIZE, SIZE));
	window.setFramerateLimit(FPS);
	player.setFillColor(sf::Color::Red);
	player.setPosition(375.f, 275.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				key_pressed(Q) || key_pressed(Escape))
			{
				window.close();
			}
		}
		float x, y = 0.f;
		if (key_pressed(Up) || key_pressed(W))
		{
			y = 1;
		}
		else if (key_pressed(Down) || key_pressed(S))
		{
			y = -1;
		}
		else
		{
			y = 0.f;
		}
		if (key_pressed(Left) || key_pressed(A))
		{
			x = -1;
		}
		else if (key_pressed(Right) || key_pressed(D))
		{
			x = 1;
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
		player.setPosition(clamp(0,
								 player.getPosition().x,
								 WIDTH - SIZE),
						   clamp(0,
								 player.getPosition().y,
								 HEIGHT - SIZE));
		window.draw(player);
		window.display();
	}
	return 0;
}
