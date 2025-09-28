#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Random Jewels 8x8 Matrix");

    // Load the textures of jewels from the folder
    const int gridSize = 8;
    const float jewelSize = 100.0f;
    const float spacing = 5.0f;

    const char* jewelFileNames[] = {
        "gems/blue_gem.png", "gems/green_gem.png", "gems/orange_gem.png",
        "gems/purple_gem.png", "gems/red_gem.png", "gems/white_gem.png", "gems/yellow_gem.png"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(jewelFileNames) / sizeof(jewelFileNames[0]) - 1);

    std::vector<sf::Texture> jewelTextures;
    for (const auto& fileName : jewelFileNames) {
        sf::Texture texture;
        if (!texture.loadFromFile(fileName)) {
            std::cout << "Failed to load: " << fileName << std::endl;
            return -1;
        }
        jewelTextures.push_back(texture);
    }

    sf::Sprite jewelSprite;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw the grid of random jewels
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                int randomIndex = dis(gen); // Generate a random index for jewelTextures
                jewelSprite.setTexture(jewelTextures[randomIndex]);

                // Set the position of the jewel based on grid coordinates
                float xPos = static_cast<float>(i * (jewelSize + spacing));
                float yPos = static_cast<float>(j * (jewelSize + spacing));
                jewelSprite.setPosition(xPos, yPos);

                // Draw the current jewel sprite
                window.draw(jewelSprite);
            }
        }

        window.display();
    }

    return 0;
}
