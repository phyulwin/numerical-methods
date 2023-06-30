#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

class SpaceInvader {
private:
    bool game_over;
    const int width = 40;
    const int height = 20;
    int x, y; // Player coordinates
    int enemyX, enemyY; // Enemy coordinates
    int bulletX, bulletY; // Bullet coordinates
    int score;

    enum Direction { STOP = 0, LEFT, RIGHT };
    Direction dir;

private:
    void Setup()
    {
        game_over = false;
        dir = STOP;
        x = width / 2;
        y = height - 1;
        enemyX = width / 2;
        enemyY = 0;
        bulletX = x;
        bulletY = y;
        score = 0;
    }

    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0 || j == width - 1)
                    std::cout << "#";
                else if (i == y && j == x)
                    std::cout << "A";
                else if (i == enemyY && j == enemyX)
                    std::cout << "E";
                else if (i == bulletY && j == bulletX)
                    std::cout << "|";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;

        std::cout << "Score: " << score << std::endl;
    }

    void Input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = STOP;
                break;
            case ' ':
                bulletX = x;
                bulletY = y;
                break;
            case 'x':
                game_over = true;
                break;
            }
        }
    }

    void Logic()
    {
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
        }

        if (bulletY >= 0)
        {
            bulletY--;
            if (bulletY == enemyY && bulletX == enemyX)
            {
                score++;
                enemyX = rand() % width;
                enemyY = 0;
            }
        }

        if (y == enemyY && x == enemyX)
        {
            game_over = true;
        }
    }

 public:
    void PlayInvader() {
        std::cout << "Game Start" << std::endl;

        Setup();
        while (!game_over)
        {
            Draw();
            Input();
            Logic();
            Sleep(50); // Delay for smoother movement
        }
        std::cout << "Game Over! Your score: " << score << std::endl;
    }
};