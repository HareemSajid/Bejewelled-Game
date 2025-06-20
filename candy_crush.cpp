//#include<SFML/Graphics.hpp>
//#include<fstream>
//#include<iostream>
//
//using namespace std;
//using namespace sf;
//
//const int row = 8, col = 8;
//const int NumOfJewels = 5;
//int tempscore = 0;
//int highscore = 0;
//
//bool IsAdjacent(int row1, int col1, int row2, int col2) {
//	return abs(row1 - row2) + abs(col1 - col2) == 1;
//}
//void RemoveSame(int BOARD[][col]) {
//	srand(static_cast<unsigned int>(time(0)));
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2]) {
//				if (j < col && j + 1 < col && j + 2 < col)
//				{
//					for (int n = 0; n < 3; n++) {
//						BOARD[i][j] = rand() % 5;
//						j++;
//					}
//				}
//			}
//			else if ((BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j])) {
//				if (i < row || i + 1 < row || i + 2 < row)
//					for (int n = 0; n < 3; n++) {
//						BOARD[i][j] = rand() % 5;
//						i++;
//					}
//			}
//
//			else if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2] && BOARD[i][j] == BOARD[i][j + 3]) {
//				if (j + 3 < col)
//				{
//					for (int u = j; u < j + 4; u++)
//					{
//						BOARD[i][u] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j] && BOARD[i][j] == BOARD[i + 3][j])
//			{
//				if (i + 3 < row)
//				{
//					for (int u = i; u < i + 4; u++)
//					{
//						BOARD[u][j] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2] && BOARD[i][j] == BOARD[i][j + 3] && BOARD[i][j] == BOARD[i][j + 4]) {
//				if (j + 4 < col)
//				{
//					for (int u = j; u < j + 5; u++)
//					{
//						BOARD[i][u] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j] && BOARD[i][j] == BOARD[i + 3][j] && BOARD[i][j] == BOARD[i][j + 4])
//			{
//				if (i + 4 < row)
//				{
//					for (int u = i; u < i + 5; u++)
//					{
//						BOARD[u][j] = rand() % 5;
//					}
//				}
//			}
//
//		}
//	}
//}
//void CalculateScore(int BOARD[][col], int& score) {
//	srand(static_cast<unsigned int>(time(0)));
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2]) {
//				if (j < col && j + 1 < col && j + 2 < col)
//				{
//					score += 30;
//					for (int n = 0; n < 3; n++) {
//						BOARD[i][j] = rand() % 5;
//						j++;
//					}
//				}
//			}
//			else if ((BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j])) {
//				if (i < row || i + 1 < row || i + 2 < row)
//				{
//					score += 30;
//					for (int n = 0; n < 3; n++) {
//						BOARD[i][j] = rand() % 5;
//						i++;
//					}
//				}
//			}
//
//			else if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2] && BOARD[i][j] == BOARD[i][j + 3]) {
//				if (j + 3 < col)
//				{
//					score += 40;
//					for (int u = j; u < j + 4; u++)
//					{
//						BOARD[i][u] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j] && BOARD[i][j] == BOARD[i + 3][j])
//			{
//				if (i + 3 < row)
//				{
//					score += 40;
//					for (int u = i; u < i + 4; u++)
//					{
//						BOARD[u][j] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i][j + 1] && BOARD[i][j] == BOARD[i][j + 2] && BOARD[i][j] == BOARD[i][j + 3] && BOARD[i][j] == BOARD[i][j + 4]) {
//				if (j + 4 < col)
//				{
//					score += 50;
//					for (int u = j; u < j + 5; u++)
//					{
//						BOARD[i][u] = rand() % 5;
//					}
//				}
//			}
//			else if (BOARD[i][j] == BOARD[i + 1][j] && BOARD[i][j] == BOARD[i + 2][j] && BOARD[i][j] == BOARD[i + 3][j] && BOARD[i][j] == BOARD[i][j + 4])
//			{
//				if (i + 4 < row)
//				{
//					score += 50;
//					for (int u = i; u < i + 5; u++)
//					{
//						BOARD[u][j] = rand() % 5;
//					}
//				}
//			}
//
//		}
//	}
//}
//void SwapJewels(int BOARD[][col], int OriginalPosX, int OriginalPosY, int NewPosX, int NewPosY, int& score) {
//	int temp = 0;
//	temp = BOARD[OriginalPosX][OriginalPosY];
//	BOARD[OriginalPosX][OriginalPosY] = BOARD[NewPosX][NewPosY];
//	BOARD[NewPosX][NewPosY] = temp;
//	if (NewPosX > 0 && NewPosX < row - 1 && NewPosY > 0 && NewPosY < col - 1 &&
//		(BOARD[NewPosX - 1][NewPosY] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX + 1][NewPosY] == BOARD[NewPosX][NewPosY]) ||
//		(BOARD[NewPosX - 1][NewPosY] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX - 2][NewPosY] == BOARD[NewPosX][NewPosY]) ||
//		(BOARD[NewPosX + 2][NewPosY] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX + 1][NewPosY] == BOARD[NewPosX][NewPosY]) ||
//		(BOARD[NewPosX][NewPosY - 1] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX][NewPosY + 1] == BOARD[NewPosX][NewPosY]) ||
//		(BOARD[NewPosX][NewPosY - 1] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX][NewPosY - 2] == BOARD[NewPosX][NewPosY]) ||
//		(BOARD[NewPosX][NewPosY + 1] == BOARD[NewPosX][NewPosY]) &&
//		(BOARD[NewPosX][NewPosY + 2] == BOARD[NewPosX][NewPosY])) {
//	}
//	else {
//		temp = BOARD[OriginalPosX][OriginalPosY];
//		BOARD[OriginalPosX][OriginalPosY] = BOARD[NewPosX][NewPosY];
//		BOARD[NewPosX][NewPosY] = temp;
//
//		OriginalPosX = NewPosX;
//		OriginalPosY = NewPosY;
//	}
//	CalculateScore(BOARD, score);
//}
//int main()
//{
//	int BOARD[row][col];
//	const float squareSize = 55.0f, BorderSize = 2.0f;
//	int selectedJewelRow = -1, selectedJewelCol = -1, cursorRow = 0, cursorCol = 0, swapPosX = 0, swapPosY = 0, SCORE = 0;
//
//	ifstream infile("highscore.txt");
//	infile >> highscore;
//
//
//	Color borderColor(255, 255, 0);
//
//	RenderWindow window(VideoMode(1000, 768), "BEJEWLLED BLITZ");
//
//	Texture backgroundTexture;
//	backgroundTexture.loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\bejeweled 3 backgrounds   Google Search.jpg");
//
//	Sprite background(backgroundTexture);
//	background.setScale(1.0f, 1.2f);
//
//	const float BoardPositionX = window.getSize().x - (col * squareSize) - 50.0f;
//	const float BoardPositionY = (window.getSize().y - (row * squareSize)) / 2.0f;
//	Texture Jewels[NumOfJewels];
//
//	Jewels[0].loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\Bejeweled_blue_gem_promotional.png");
//	Jewels[1].loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\Bejeweled_green_gem_promotional.png");
//	Jewels[2].loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\Bejeweled_orange_gem_promotional.png");
//	Jewels[3].loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\Bejeweled_purple_gem_promotional.png");
//	Jewels[4].loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\Bejeweled_red_gem_promotional.png");
//
//	srand(static_cast<unsigned int>(time(0)));
//	int index = 0;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			index = rand() % NumOfJewels;
//			BOARD[i][j] = index;
//		}
//	}
//	RemoveSame(BOARD);
//	Sprite JewelSprite[NumOfJewels];
//	for (int i = 0; i < NumOfJewels; ++i) {
//		JewelSprite[i].setTexture(Jewels[i]);
//	}
//	int score = 0;
//	Font font;
//	font.loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\score.ttf"); // Replace with the path to your font file
//	Text scoreText;
//	scoreText.setFont(font);
//	scoreText.setCharacterSize(80);
//	scoreText.setFillColor(Color::Red);
//	scoreText.setStyle(Text::Bold);
//	scoreText.setString("SCORE");
//	scoreText.setPosition(93.0f, 40.0f);
//
//	//HIGH-SCORE file-handling
//	/*Font fh;
//	fh.loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\score.ttf");
//	Text highscoreText;
//	highscoreText.setFont(font);
//	highscoreText.setCharacterSize(60);
//	highscoreText.setFillColor(Color::Red);
//	highscoreText.setStyle(Text::Bold);
//	highscoreText.setString("HIGH SCORE");
//	highscoreText.setPosition(68.0f, 135.0f);*/
//
//	// TIME
//	Font ft;
//	ft.loadFromFile("C:\\Users\\DELL\\source\\repos\\Project2\\Project2\\timenormal.ttf"); // Replace with the path to your font file
//
//	Text timerText;
//	timerText.setFont(ft);
//	timerText.setCharacterSize(34);
//	timerText.setFillColor(Color::Red);
//	timerText.setStyle(Text::Bold);
//	timerText.setPosition(93.0f, 125.0f);
//	Clock timerClock;
//	int gameDurationSeconds = 60;
//	int remainingSeconds = 0;
//	while (window.isOpen()) {
//
//		Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == Event::Closed)
//				window.close();
//			if (event.type == Event::KeyPressed) {
//				if (event.key.code == Keyboard::Left && cursorCol > 0) {
//					cursorCol--;
//				}
//				else if (event.key.code == Keyboard::Right && cursorCol < col - 1) {
//					cursorCol++;
//				}
//				else if (event.key.code == Keyboard::Up && cursorRow > 0) {
//					cursorRow--;
//				}
//				else if (event.key.code == Keyboard::Down && cursorRow < row - 1) {
//					cursorRow++;
//				}
//				else if (event.key.code == Keyboard::Space) {
//					if (selectedJewelRow == -1 && selectedJewelCol == -1) {
//						selectedJewelRow = cursorRow;
//						selectedJewelCol = cursorCol;
//					}
//					else {
//						int swapPosX = cursorRow;
//						int swapPosY = cursorCol;
//						if (IsAdjacent(selectedJewelRow, selectedJewelCol, swapPosX, swapPosY)) {
//							RemoveSame(BOARD);
//							SwapJewels(BOARD, selectedJewelRow, selectedJewelCol, swapPosX, swapPosY, score);
//							CalculateScore(BOARD, SCORE);
//						}
//						selectedJewelRow = -1;
//						selectedJewelCol = -1;
//					}
//				}
//			}
//
//			if (score > highscore)
//			{
//				tempscore = score;
//				ofstream outfile("highscore.txt");
//				outfile << tempscore;
//			}
//
//			window.clear();
//			window.draw(background);
//			for (int i = 0; i < row; i++) {
//				for (int j = 0; j < col; j++) {
//					RectangleShape square(Vector2f(squareSize, squareSize));
//
//					if ((i + j) % 2 == 0) {
//						square.setFillColor(Color(100, 100, 100, 128));
//					}
//					else {
//						square.setFillColor(Color(0, 0, 0, 100));
//					}
//
//					square.setPosition(BoardPositionX + static_cast<float>(j) * squareSize, BoardPositionY + static_cast<float>(i) * squareSize);
//					window.draw(square);
//
//					if (BOARD[i][j] >= 0 && BOARD[i][j] < NumOfJewels) {
//						Sprite jewelSprite = JewelSprite[BOARD[i][j]];
//						float scaleFactor = min(squareSize / jewelSprite.getLocalBounds().width, squareSize / jewelSprite.getLocalBounds().height);
//						jewelSprite.setScale(scaleFactor, scaleFactor);
//						jewelSprite.setPosition(BoardPositionX + static_cast<float>(j) * squareSize,
//							BoardPositionY + static_cast<float>(i) * squareSize);
//						window.draw(jewelSprite);
//					}
//
//					if (selectedJewelRow != -1 && selectedJewelCol != -1) {
//						RectangleShape selectedBorder(Vector2f(squareSize, squareSize));
//						selectedBorder.setFillColor(Color::Transparent);
//						selectedBorder.setOutlineThickness(BorderSize);
//						selectedBorder.setOutlineColor(borderColor);
//						selectedBorder.setPosition(BoardPositionX + static_cast<float>(selectedJewelCol) * squareSize,
//							BoardPositionY + static_cast<float>(selectedJewelRow) * squareSize);
//						window.draw(selectedBorder);
//					}
//
//					RectangleShape moveableBorder(Vector2f(squareSize, squareSize));
//					moveableBorder.setFillColor(Color::Transparent);
//					moveableBorder.setOutlineThickness(BorderSize);
//					moveableBorder.setOutlineColor(borderColor);
//					moveableBorder.setPosition(BoardPositionX + static_cast<float>(cursorCol) * squareSize,
//						BoardPositionY + static_cast<float>(cursorRow) * squareSize);
//					window.draw(moveableBorder);
//				}
//				Time elapsed = timerClock.getElapsedTime();
//
//				// Calculating remaining time
//				remainingSeconds = gameDurationSeconds - static_cast<int>(elapsed.asSeconds());
//			}
//			scoreText.setString("SCORE " + to_string(score));
//			timerText.setString("Time: " + to_string(remainingSeconds));
//			highscoreText.setString("HIGH SCORE : " + to_string(highscore));
//
//			window.draw(scoreText);
//			window.draw(timerText);
//			window.draw(highscoreText);
//			window.display();
//			if (remainingSeconds <= 0) {
//				cout << "Game Over! Time's up!" << endl;
//				window.close();
//			}
//		}
//	}
//	ofstream fileout("output.txt");
//	fileout << "Your total score is: " << score;
//	fileout.close();
//	return 0;
//}