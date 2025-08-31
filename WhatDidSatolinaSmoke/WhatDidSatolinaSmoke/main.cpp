#include "Base.h"
#include "Sorts.h"
#include "Beauty.h"
int main() 
{
    try {

        std::cout << "what do u want to play with?\n 1) int 2) double 3) char 4) string 5) Students\n";
        int32_t choose{};
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            IntChoose();
            break;
        case 2:
            DoubleChoose();
            break;
        case 3:
            CharChoose();
            break;
        case 4:
            StringChoose();
            break;
        case 5:
            StudentChoose();
            break;
        default:
            throw std::invalid_argument("you have only 1 - 5 options");
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