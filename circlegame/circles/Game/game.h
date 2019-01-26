#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
class Game{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
    void ShowShapes();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    sf::RectangleShape sideBar;
    System system;
    int command;
    sf::Font font;
    sf::Text myTextLabel;
    bool mouseIn;
    Sidebar sidebar;

};


#endif // GAME_H
