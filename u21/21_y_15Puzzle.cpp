#include <iostream>
#include "../Random.h"

int randomUniqueNumber(std::vector<int>& v)
{
    while (true)
    {
        int r { Random::get(1, 16) };
        if (std::find(v.begin(), v.end(), r) == v.end())
        {
            v.push_back(r);
            return r;
        }
    }

}

class PlayerGrid
{
private:
    std::array<std::array<int, 4>, 4> m_grid{};
public:
    PlayerGrid()
    {
        std::vector<int> u {};
        // Randomly populate grid with unique numbers
        for (int i { 0 }; i < m_grid.size(); ++i)
        {
            for (int j { 0 }; j < m_grid[i].size(); ++j)
            {
                    m_grid[i][j] = randomUniqueNumber(u);
            }
        }
    }

    int& operator()(int row, int col);

};

int& PlayerGrid::operator()(int row, int col)
{
    return m_grid[row][col];
}

void printGrid(PlayerGrid& grid)
{
    for (int i { 0 }; i < 4; ++i)
    {
        for (int j { 0 }; j < 4; ++j)
        {
            if (grid(i, j) == 16)
            {
                std::cout << "  ";
            } else {
                std::cout << grid(i, j) << ' ';
            }
        }
        std::cout << '\n';
    }

    std::cout << "\n\n\n\n";
}

std::array<int, 2> findBlankSpace(PlayerGrid& grid)
{
    for (int i { 0 }; i < 4; ++i)
    {
        for (int j { 0 }; j < 4; ++j)
        {
            if (grid(i, j) == 16)
            {
                return { i, j };
            }
        }
    }
}

class Gameboard
{
private:
    int row {};
    int col {};
    PlayerGrid& grid;
public:
    explicit Gameboard(PlayerGrid& pg)
        : grid { pg }
    {
        std::array<int, 2> whitespaceCoord { findBlankSpace(pg) };
        row = whitespaceCoord[0];
        col = whitespaceCoord[1];
    }

    void moveUp()
    {
        if (row > 0)
        {
            grid(row, col) = grid(row - 1, col);
            grid(row - 1, col) = 16;
            --row;
            printGrid(grid);
        }
    }

    void moveLeft()
    {
        if (col > 0)
        {
            grid(row, col) = grid(row, col - 1);
            grid(row, col - 1) = 16;
            --col;
            printGrid(grid);
        }
    }

    void moveDown()
    {
        if (row < 4)
        {
            grid(row, col) = grid(row + 1, col);
            grid(row + 1, col) = 16;
            ++row;
            printGrid(grid);
        }
    }

    void moveRight()
    {
        if (col < 4)
        {
            grid(row, col) = grid(row, col + 1);
            grid(row, col + 1) = 16;
            ++col;
            printGrid(grid);
        }
    }

    void print() const
    {
        std::cout << "row: " << row << " col: " << col << '\n';
    }
};

void start(Gameboard& gb)
{
    char move {};
    while (move != 'q')
    {
        std::cin >> move;
        switch (move) {
            case 'w':
                gb.moveUp();
                break;
            case 'a':
                gb.moveLeft();
                break;
            case 's':
                gb.moveDown();
                break;
            case 'd':
                gb.moveRight();
                break;
            case 'p':
                gb.print();
                break;
            case 'q':
                break;
            default:
                std::cin >> move;
                break;
        }
    }
}

int main()
{
    PlayerGrid grid;
    Gameboard board(grid);

    printGrid(grid);

    start(board);

    return 0;
}