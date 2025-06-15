#include <iostream> 
#include <cctype>
// For std::cout, std::cin, std::endl

int main(int ac, char **av) {
    if (ac == 1)
    std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    int j = 1;
    while (av[j])
    {
        std::string firstarg = av[j];
        int i = 0;
        while (firstarg[i])
        {
            std::cout<<(char)toupper(firstarg[i]);
            i++;
        }
        j++;
    }
    return 0;
}