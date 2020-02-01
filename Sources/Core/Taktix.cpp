#include <Core/Taktix.hpp>
#include <TGUI/TGUI.hpp>

void Taktix::run()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "TGUI window");
    tgui::Gui gui(window);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::Resized) {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                gui.setView(window.getView());
            }

            gui.handleEvent(event);
        }

        window.clear();
        gui.draw();
        window.display();
    }
}