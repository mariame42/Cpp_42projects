
// Zombie::Zombie() {
//     this->name = "unnamed";
// }

// Zombie::Zombie(std::string name) {
//     this->name = name;
// }

// Zombie::~Zombie() {
//     std::cout<< this->name << " is destroyed" << std::endl;
// }

// void Zombie::setName(std::string name) {
//     this->name = name;
// }
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name );
void randomChump( std::string name );

Zombie* zombieHorde(int N, std::string name )
{
    Zombie *zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombiehorde[i].setName(name);
    }
    return (zombiehorde);
}

int main()
{
    Zombie *zombiehorde = zombieHorde(5, "zombie");
    for (int i = 0; i < 5; i++)
    {
        zombiehorde[i].announce();
    }
    delete[] zombiehorde;
}
