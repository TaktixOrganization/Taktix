#include <TGUI/TGUI.hpp>

void login(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout << "Username: " << username->getText().toAnsiString() << std::endl;
    std::cout << "Password: " << password->getText().toAnsiString() << std::endl;
}

void loadWidgets( tgui::Gui& gui )
{
    // Get a bound version of the window size
    // Passing this to setPosition or setSize will make the widget automatically update when the view of the gui changes
    auto windowWidth = tgui::bindWidth(gui);
    auto windowHeight = tgui::bindHeight(gui);

    tgui::Picture::Ptr picture = tgui::Picture::create("Assets/Textures/logo.png");
    gui.add(picture);

    // Create the username edit box
    tgui::EditBox::Ptr editBoxUsername = tgui::EditBox::create();
    editBoxUsername->setSize(windowWidth * 2/3, windowHeight / 8);
    editBoxUsername->setPosition(windowWidth / 6, windowHeight / 6);
    editBoxUsername->setDefaultText("Username");
    gui.add(editBoxUsername, "Username");

    // Create the password edit box
    tgui::EditBox::Ptr editBoxPassword = tgui::EditBox::create();
    editBoxPassword->setSize(windowWidth * 2/3, windowHeight / 8);
    editBoxPassword->setPosition(windowWidth / 6, windowHeight * 5/12);
    editBoxPassword->setPasswordCharacter('*');
    editBoxPassword->setDefaultText("Password");
    gui.add(editBoxPassword, "Password");

    // Create the login button
    tgui::Button::Ptr button = tgui::Button::create();
    button->setSize(windowWidth / 2, windowHeight / 6);
    button->setPosition(windowWidth / 4, windowHeight * 7/10);
    button->setText("Login");
    gui.add(button);

    // Call the login function when the button is pressed
    button->connect("pressed", login, editBoxUsername, editBoxPassword);
}

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(400, 300), "TGUI window");
    tgui::Gui gui(window);

    try
    {
        // Load the widgets
        loadWidgets(gui);
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return 1;
    }

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // When the window is closed, the application ends
            if (event.type == sf::Event::Closed)
                window.close();

                // When the window is resized, the view is changed
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                gui.setView(window.getView());
            }

            // Pass the event to all the widgets
            gui.handleEvent(event);
        }

        window.clear();

        // Draw all created widgets
        gui.draw();

        window.display();
    }

    return EXIT_SUCCESS;
}
