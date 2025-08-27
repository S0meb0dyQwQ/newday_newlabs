#include "Base.h"
#include "Sorts.h"
int main() 
{
    try {
        int32_t choose{};
        std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            WorkFromConsole();
            break;
        case 2:
            WorkByRandom();
            break;
        case 3:
            WorkFromFile();
            break;
        default:
            throw std::invalid_argument("you have only 1,2 and 3 options");
        }
    }
    catch (std::ios_base::failure& e)
    {
        std::cout << e.what();
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what();
    }
 	return 0;
}