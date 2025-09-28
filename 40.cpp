#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>
using namespace std;

const int BOARD_SIZE = 8;
const int MATCH_LENGTH = 3;
const float windowSize = 600.0f;
const float boxSize = windowSize / BOARD_SIZE;

struct MatchPosition {
    int row;
    int col;
    int noOfConsecutive;
    char orientation;   //H for horizontal, V for vertical
};

// Function to load textures for different jewels from file
void initializeJewelTextures(sf::Texture jewelTextures[]) {
    const char* jewelFileNames[] = {
        "gems/blue_gem.png", "gems/green_gem.png", "gems/orange_gem.png",
        "gems/purple_gem.png", "gems/white_gem.png"
    };

    for (int i = 0; i < 5; ++i) {
        // Load jewel textures from files
        if (!jewelTextures[i].loadFromFile(jewelFileNames[i])) {
            cerr << "Failed to load " << jewelFileNames[i] << endl;
            exit(1); // Exit the program if loading fails
        }
    }
}

// Function to initialize the grid with random jewel values
void initializeJewelGrid(int jewelGrid[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the jewel grid with random values
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            jewelGrid[i][j] = rand() % 5; // Generate a random number between 0 and 4 (5 different jewels)
        }
    }
}

// Function to check for matches in the jewel grid
bool checkMatches(int(&jewelGrid)[BOARD_SIZE][BOARD_SIZE], MatchPosition positionsToRemove[], int& noOfmatches, int& score) {
    //Check for consecutive matches in rows and columns
    bool isMatch = false;
    int counterr = 0;

    // Check for horizontal matches
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 2; j++) {
            // Check for consecutive jewels in a row
            if ((jewelGrid[i][j] == jewelGrid[i][j + 1]) && (jewelGrid[i][j] == jewelGrid[i][j + 2])) {
                isMatch = true;
                positionsToRemove[counterr].row = i;
                positionsToRemove[counterr].col = j;
                positionsToRemove[counterr].noOfConsecutive = 3;
                positionsToRemove[counterr].orientation = 'V';
                j += 2; // Move the loop counter to skip checked jewels
                score += 10;

                // Check for longer matches
                // 4 same
                if (jewelGrid[i][j] == jewelGrid[i][j + 3]) {

                    positionsToRemove[counterr].noOfConsecutive++;
                    j++;
                    score += 5;

                    // 5 same
                    if (jewelGrid[i][j] == jewelGrid[i][j + 4]) {

                        positionsToRemove[counterr].noOfConsecutive++;
                        j++;
                        score += 5;
                    }
                }
                counterr++;
            }
        }
    }

    // Check for vertical matches
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = 0; i < BOARD_SIZE - 2; i++) {
            // Check for consecutive jewels in a column
            if ((jewelGrid[i][j] == jewelGrid[i + 1][j]) && (jewelGrid[i][j] == jewelGrid[i + 2][j])) {
                isMatch = true;
                positionsToRemove[counterr].row = i;
                positionsToRemove[counterr].col = j;
                positionsToRemove[counterr].noOfConsecutive = 3;
                positionsToRemove[counterr].orientation = 'H';
                j += 2; // Move the loop counter to skip checked jewels
                score += 10;

                // Check for longer matches
                // 4 same
                if (jewelGrid[i][j] == jewelGrid[i + 3][j]) {

                    positionsToRemove[counterr].noOfConsecutive++;
                    j++;
                    score += 5;

                    // 5 same
                    if (jewelGrid[i][j] == jewelGrid[i + 4][j]) {

                        positionsToRemove[counterr].noOfConsecutive++;
                        j++;
                        score += 5;
                    }
                }
                counterr++;
            }
        }
    }

    noOfmatches = counterr;
    return isMatch;
}

// Function to remove matched jewels and generate random in their place
void removeJewels(int(&jewelGrid)[BOARD_SIZE][BOARD_SIZE], const MatchPosition positionsToRemove[], int noOfMatches) {

   
    for (int i = 0; i < noOfMatches; i++)
    {
        // Handle horizontal matches  (i change, j same)
        // Update grid cells with new random jewel values
        // based on the number of consecutive jewels removed    
        if (positionsToRemove[i].orientation == 'H')
        {

            if (positionsToRemove[i].noOfConsecutive == 3)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 1][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 2][positionsToRemove[i].col] = rand() % 5;


            }
            else if (positionsToRemove[i].noOfConsecutive == 4)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 1][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 2][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 3][positionsToRemove[i].col] = rand() % 5;

            }
            else if (positionsToRemove[i].noOfConsecutive == 5)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 1][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 2][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 3][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[(positionsToRemove[i].row) + 4][positionsToRemove[i].col] = rand() % 5;

            }

        }

            // Handle vertical matches (j change, i same)
            // Update grid cells with new random jewel values
            // based on the number of consecutive jewels removed
        else if (positionsToRemove[i].orientation == 'V')       
        {

            if (positionsToRemove[i].noOfConsecutive == 3)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 1] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 2] = rand() % 5;


            }
            else if (positionsToRemove[i].noOfConsecutive == 4)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 1] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 2] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 3] = rand() % 5;

            }
            else if (positionsToRemove[i].noOfConsecutive == 5)
            {
                jewelGrid[positionsToRemove[i].row][positionsToRemove[i].col] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 1] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 2] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 3] = rand() % 5;
                jewelGrid[positionsToRemove[i].row][(positionsToRemove[i].col) + 4] = rand() % 5;
            }

        }

    }

}

// Function to handle movement of jewels on the grid
// Handle movement of selected jewel in different directions
void moveJewel(sf::RenderWindow& window, int& selectedRow, int& selectedCol, sf::Keyboard::Key direction, int jewelGrid[BOARD_SIZE][BOARD_SIZE], int& score, bool& jewelSelected) {
    
    int newRow = selectedRow;
    int newCol = selectedCol;

    switch (direction) {
    case sf::Keyboard::Left:
        if (newRow > 0) {
            newRow--;
        }
        break;
    case sf::Keyboard::Right:
        if (newRow < BOARD_SIZE - 1) {
            newRow++;
        }
        break;
    case sf::Keyboard::Up:
        if (newCol > 0) {
            newCol--;
        }
        break;
    case sf::Keyboard::Down:
        if (newCol < BOARD_SIZE - 1) {
            newCol++;
        }
        break;
    default:
        break;
    }

    //Swap the jewels only if one is selected
    if (jewelSelected) {
        std::swap(jewelGrid[selectedRow][selectedCol], jewelGrid[newRow][newCol]);

        selectedRow = newRow;
        selectedCol = newCol;
    }
}

// Function to handle user input
void handleInput(sf::RenderWindow& window, int& selectedRow, int& selectedCol, bool& jewelSelected, int& selectedJewelValue, int jewelGrid[BOARD_SIZE][BOARD_SIZE], int& score) {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            window.close();
        }
        else if (e.type == sf::Event::KeyPressed) {
            if (!jewelSelected) {
                //Handle cursor movement without jewel swapping
                if (e.key.code == sf::Keyboard::Left && selectedRow > 0) {
                    selectedRow--;
                }
                else if (e.key.code == sf::Keyboard::Right && selectedRow < BOARD_SIZE - 1) {
                    selectedRow++;
                }
                else if (e.key.code == sf::Keyboard::Up && selectedCol > 0) {
                    selectedCol--;
                }
                else if (e.key.code == sf::Keyboard::Down && selectedCol < BOARD_SIZE - 1) {
                    selectedCol++;
                }
                else if (e.key.code == sf::Keyboard::Enter) {
                    //Set the selected jewel and its position
                    jewelSelected = true;
                    selectedJewelValue = jewelGrid[selectedRow][selectedCol];
                }
            }
            else {
                //If a jewel is selected, handle swapping
                if (e.key.code == sf::Keyboard::Return) {
                    //Unselect the jewel
                    jewelSelected = false;
                }
                else {
                    //Move and swap the selected jewel
                    moveJewel(window, selectedRow, selectedCol, e.key.code, jewelGrid, score, jewelSelected);
                    jewelSelected = false;
                }
            }
        }

    }
}

// Function to draw the background image
void drawBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture) {
    // Load the background image
    const char* backgroundPath = "background/background.png.png"; // Correct the path to match the image file name and location

    if (!backgroundTexture.loadFromFile(backgroundPath)) {
        cerr << "Failed to load background image." << endl;
        exit(1);
    }

    // Draw the background image
    sf::Sprite backgroundSprite(backgroundTexture);
    window.draw(backgroundSprite);
}


// Function to draw jewels on the grid
void drawJewels(sf::RenderWindow& window, const int jewelGrid[BOARD_SIZE][BOARD_SIZE], int selectedRow, int selectedCol, bool jewelSelected, const sf::Texture jewelTextures[]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            sf::RectangleShape box;
            box.setSize(sf::Vector2f(boxSize, boxSize));
            box.setPosition(i * boxSize, j * boxSize);
            box.setFillColor(sf::Color::Transparent);
            box.setOutlineThickness(2.f);
            box.setOutlineColor(sf::Color::White);

            sf::Sprite jewel;
            jewel.setTexture(jewelTextures[jewelGrid[i][j]]);
            jewel.setPosition(i * boxSize, j * boxSize);
            jewel.setScale(boxSize / jewelTextures[jewelGrid[i][j]].getSize().x,
                boxSize / jewelTextures[jewelGrid[i][j]].getSize().y);

            window.draw(box);
            window.draw(jewel);

            if (i == selectedRow && j == selectedCol && !jewelSelected) {
                sf::RectangleShape highlight;
                highlight.setSize(sf::Vector2f(boxSize, boxSize));
                highlight.setPosition(i * boxSize, j * boxSize);
                highlight.setFillColor(sf::Color(255, 255, 255, 128));
                window.draw(highlight);
            }
        }
    }
   
}

// Function to draw highlight around the selected jewel
void drawHighlight(sf::RenderWindow& window, int selectedRow, int selectedCol, bool jewelSelected, float boxSize) {
    //Draw the highlight if a jewel is selected
    if (jewelSelected) {
        sf::RectangleShape highlight;
        highlight.setSize(sf::Vector2f(boxSize, boxSize));
        highlight.setPosition(selectedRow * boxSize, selectedCol * boxSize);
        highlight.setFillColor(sf::Color(255, 255, 255, 128));
        window.draw(highlight);
    }
}

// Function to display the score on the window
void displayScore(sf::RenderWindow& window, int score) {
    sf::Font font;
    if (!font.loadFromFile("font/font.ttf")) {
        cerr << "Failed to load font file." << endl;
        return;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(36); // Increased font size
    scoreText.setFillColor(sf::Color::Yellow); // Yellow color
    scoreText.setPosition(window.getSize().x - 180, 10); // Top right corner

    window.draw(scoreText);
}


// Main function
int main()
{
    //file handling
    char playername[100];
    ifstream infile;
    infile.open("input.txt");
    infile.getline(playername,100);
    infile.close();

    srand(static_cast<unsigned int>(time(NULL))); //to generate different random numbers at start everytime
    sf::RenderWindow window(sf::VideoMode(800, 850), "Random Jewels 8x8 Matrix");
    window.setFramerateLimit(60);
   
    // Initialization code, window setup, and variables

    sf::Texture backgroundTexture; // Create an empty texture
    drawBackground(window, backgroundTexture);

    int jewelGrid[BOARD_SIZE][BOARD_SIZE];

    int selectedRow = 0;
    int selectedCol = 0;
    bool jewelSelected = false;
    int selectedJewelValue = 0;

    int score = 0;
    bool scoreinitializer = true;



    sf::Texture jewelTextures[5]; // Assuming there are 5 different jewel types
    initializeJewelTextures(jewelTextures);

    initializeJewelGrid(jewelGrid);

    sf::Clock timerClock;
    sf::Time timeLimit = sf::seconds(60); // 1-minute countdown

    sf::RectangleShape timerBar(sf::Vector2f(windowSize, 20)); // Timer bar rectangle
    timerBar.setPosition(0, windowSize);
    timerBar.setFillColor(sf::Color::Green);

    while (window.isOpen()) {

       // Game loop
       // Input handling, time calculations, and drawing
       // Check for time's up or game logic
       // Match removal and regeneration logic
       // Handle end of the game or score

        handleInput(window, selectedRow, selectedCol, jewelSelected, selectedJewelValue, jewelGrid, score);

        //Calculate time left
        sf::Time elapsedTime = timerClock.getElapsedTime();
        sf::Time timeLeft = timeLimit - elapsedTime;

        //Update timer bar
        float remainingPercentage = timeLeft.asSeconds() / timeLimit.asSeconds();
        timerBar.setSize(sf::Vector2f(windowSize * remainingPercentage, 20));

        window.clear();

        drawBackground(window, backgroundTexture);  // Draw the background first
        drawJewels(window, jewelGrid, selectedRow, selectedCol, jewelSelected, jewelTextures);
        drawHighlight(window, selectedRow, selectedCol, jewelSelected, boxSize);

        //Draw and display the timer bar
        window.draw(timerBar);


        displayScore(window, score);

        //Display the window
        window.display();

        //Check if time is up
        if (timeLeft <= sf::Time::Zero) {
            cout << "Time's up!" << endl;
            break; // Exit the loop or handle end of the game logic here
        }

        //Match removal and regeneration logic
        MatchPosition positionsToRemove[100]; // Define outside the loop
        int noOfMatches = 0;
        
        
        //sf::Clock clock;  // Create a clock for measuring time

        
        while (checkMatches(jewelGrid, positionsToRemove, noOfMatches, score))
        {
            removeJewels(jewelGrid, positionsToRemove, noOfMatches);
            sf::sleep(sf::seconds(1)); // Introducing a 1-second pause
        }

        //will run once on start of game
        if (scoreinitializer == true)
        {
            score = 0;
            scoreinitializer = false;
        }

    }
   
    //displaying total score on console as well
    cout << "Total Score: " << score << endl;


    //file handling
    ofstream outfile;
    outfile.open("output.txt");
    outfile<<playername<< endl << "Score: " << score << endl;
    outfile.close();

    return 0;
}