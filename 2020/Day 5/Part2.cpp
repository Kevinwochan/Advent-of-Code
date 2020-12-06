#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>

int getSeatID(std::string boardingPass)
{
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
    /*
    std::cout << rowBounds[0] << " : " << rowBounds[1] << "\n";
    std::cout << colBounds[0] << " : " << colBounds[1] << "\n\n";
    std::cout << "seat ID is: " << colBounds[0] + rowBounds[0] * 8 << "\n";
    */
    return colBounds[0] + rowBounds[0] * 8;
}

int main()
{
    std::ifstream ifs("input.txt");
    std::vector<bool> occupied_seats(128 * 8, false);
    for (std::string line; std::getline(ifs, line);)
    {
        // ignore front and back rows
        int seat_id = getSeatID(line);
        if (seat_id > 7 && seat_id < 8 * 127)
            occupied_seats[seat_id] = true;
    }

    for (auto row = 0; row<127; ++row){
        for (auto col=0; col<8; ++col){
            if (!occupied_seats[8*row+col])
                std::cout << "missing passenger in " << 8*row+col << "\n";
        }
    }
}