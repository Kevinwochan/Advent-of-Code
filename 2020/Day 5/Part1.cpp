#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>

int getSeatID(std::string boardingPass){
    // 128 rows (0-127)
    // 8 columns (0-7)
    std::vector<int> rowBounds({0, 127});
    std::vector<int> colBounds({0, 7});
    for (const auto ch : boardingPass)
    {
        switch (ch)
        {
        case 'F':
            rowBounds[1] = (rowBounds[0] + rowBounds[1]) / 2;
            break;
        case 'B':
            rowBounds[0] = (rowBounds[0] + rowBounds[1]) / 2 + 1;
            break;
        case 'L':
            colBounds[1] = (colBounds[0] + colBounds[1]) / 2;
            break;
        case 'R':
            colBounds[0] = (colBounds[0] + colBounds[1]) / 2 + 1;
            break;
        default:
            std::cout << "unrecognised char: " << ch;
            break;
        }
    }
    std::cout <<rowBounds[0] << " : " << rowBounds[1]<< "\n";
    std::cout <<colBounds[0] << " : " << colBounds[1] << "\n\n";
    std::cout << "seat ID is: " << colBounds[0] + rowBounds[0] * 8 << "\n";
    return colBounds[0] + rowBounds[0] * 8;
}

int main()
{
    std::ifstream ifs("input.txt");
    //std::vector<char> line(4);
    int max_seat_id = -1;
    for (std::string line; std::getline(ifs, line);){
        max_seat_id = std::max(max_seat_id, getSeatID(line));
    }
    std::cout << "max seat id was " << max_seat_id;
}