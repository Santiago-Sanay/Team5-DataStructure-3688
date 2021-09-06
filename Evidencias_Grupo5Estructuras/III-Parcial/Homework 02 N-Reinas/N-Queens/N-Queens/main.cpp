#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

static std::ofstream archivo("archivo.txt", std::ios::app);
bool calQueens(int size, std::vector<int>& board);
bool queens(std::vector<int>& board, int current, int size);
bool no_conflicts(std::vector<int> board, int current);
inline int readInt(std::string message, int min = 0, int max = INT_MAX);
void print_array(std::vector<int> array, std::ostream& out);
inline int readInt(std::string message, int min, int max)
{
    int input;
    do
    {
        std::cout << message;
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (input < min || input > max)
        {
            continue;
        }

        break;
    } while (true);

    return input;
}

bool calQueens(int size, std::vector<int>& board)
{
    for (int i = 0; i < size; ++i)
    {
        board.at(i) = -1;
    }
    return queens(board, 0, size);
}

bool queens(std::vector<int>& board, int current, int size)
{
    if (current == size)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            board.at(current) = i;

            if (no_conflicts(board, current))
            {
                print_array(board, archivo);
                bool done = queens(board, current + 1, size);
                if (done)
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool no_conflicts(std::vector<int> board, int current)
{
    for (int i = 0; i < current; ++i)
    {
        if (board[i] == board.at(current))
        {
            return false;
        };
        if (current - i == std::abs(board.at(current) - board[i]))
        {
            return false;
        }
    }
    return true;
}

void print_solution(std::vector<std::vector<char>> board, int size, std::ostream& out)
{
    std::cout << std::endl;
    out << std::setw(20) << "SOLUCION " << std::endl;
    for (int i = 0; i < size; i++)
    {
        out << "  ";
        if (&std::cout == &out)
        {
            printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 249, 90, 10, std::to_string(i).data());
        }
        else
        {
            out << i;
        }
        out << " ";
    }
    out << std::endl
        << "+";

    for (int i = 0; i < size; i++)
    {
        out << "---+";
    }

    out << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int value = board[i][j];

            if (j == 0)
            {
                out << "|";
            }
            if (value == 'R')
            {
                std::string s(1, board[i][j]);
                out << " ";
                if (&std::cout == &out)
                {
                    printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 10, 249, 10, s.data());
                }
                else
                {
                    out << s;
                }

                out << " |";
            }
            else
            {
                char c = ' ';
                if (board[i][j] == '0')
                {
                    c = ' ';
                }
                out << " " << c << " |";
            }
        }
        out << " ";
        if (&std::cout == &out)
        {
            printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 249, 90, 10, std::to_string(i).data());
        }
        else
        {
            out << i;
        }
        out << std::endl
            << "+";
        for (int i = 0; i < size; i++)
        {
            out << "---+";
        }
        out << std::endl;
    }
    out << std::endl;
}

void print_array(std::vector<int> array, std::ostream& out)
{
    out << "Vector solucion: [ ";
    for (auto& i : array)
    {
        out << i << ",";
    }
    out << "]" << std::endl;
}

int main(int argc, char** argv)
{
    int size = readInt("Ingrese el numero de reinas: ");
    std::vector<int> array(size);

    if (calQueens(size, array))
    {
        print_array(array, std::cout);
        print_array(array, archivo);
    }
    std::vector<std::vector<char>> board(size, std::vector<char>(size));
    for (int i = 0; i < size; i++)
    {
        board.at(array[i]).at(i) = 'R';
    }
    print_solution(board, size, std::cout);
    print_solution(board, size, archivo);
}
