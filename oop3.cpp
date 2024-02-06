#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

struct magic {
    string name;
    int requiredLvl;
    int manaCost;
    double multiplier;
};

class dungeon {
private:
    int floor;
    int amountOfMonsters;

public:
    dungeon() {
        this->floor = 1;
        this->amountOfMonsters = 3;
    }
    int getFloor() {
        return this->floor;
    }
    int getAmount() {
        return this->amountOfMonsters;
    }
    void nextFloor() {
        this->floor += 1;
        this->amountOfMonsters *= 1.6;
    }
};

class character {
protected:
public:
    string name;
    int hp;
    int maxHp;
    int atk;
    int lvl;
    int amountOfAtks = 1;
    double accuracy;
    string clas;
    bool isAlive = 1;
    character(string name, int hp, int atk) {
        this->hp = hp;
        this->maxHp = hp;
        this->atk = atk;
        this->lvl = 1;
        this->isAlive = 1;
        this->name = name;
    }
    void getStatus() {
        cout << this->name << ": HP: " << this->hp << " ATK: " << this->atk << " Lvl: " << this->lvl << endl;
    }
    void takeDamage(int dmg) {
        this->hp -= dmg;
        cout << this->name << " has taken " << dmg << " points of damage";
        if (hp <= 0) {
            this->hp = 0;
            this->isAlive = 0;
            cout << " and died" << endl;
        }
        else {
            cout << " and has " << this->hp << " HP left" << endl;
        }
    }
    void attack(character& target) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        uniform_real_distribution<> dmg(-0.1, 0.1);

        for (int i = 0; i < this->amountOfAtks; i++) {
            if (dis(gen) <= this->accuracy) {
                target.takeDamage(this->atk + this->atk * dmg(gen));
            }
            else {
                cout << this->name << " has missed" << endl;
            }
        }
    }
};

class heavy : public character {
protected:
    int block;

public:
    heavy(string name, int hp, int atk)
        : character(name, hp, atk) {
        this->accuracy = 0.8;
        this->block = 0.5;
    }
    void getStat() {
        cout << this->name << ": HP: " << this->hp << " ATK: " << this->atk << " Lvl: " << this->lvl << endl;
    }
    void takeDamage(int dmg) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        if (dis(gen) > block) {
            this->hp -= dmg;
            cout << this->name << " has taken " << dmg << " points of damage";
        }
        else {
            cout << this->name << " has blocked enemy`s attack";
        }
        if (hp <= 0) {
            this->hp = 0;
            this->isAlive = 0;
        }
    }
    void incrLvl(int floor) {
        this->lvl = floor;
        this->maxHp *= 1.3;
        this->hp = maxHp;
        this->atk *= 1.3;
    }
};

class light : public character {
protected:
public:
    light(string name, int hp, int atk)
        : character(name, hp, atk) {
        this->accuracy = 0.5;
        this->amountOfAtks = 3;
    }
    void getStat() {
        cout << this->name << ": HP: " << this->hp << " ATK: " << this->atk << " Lvl: " << this->lvl << endl;
    }
    void incrLvl(int floor) {
        this->lvl = floor;
        this->maxHp *= 1.3;
        this->hp = maxHp;
        this->atk *= 1.3;
    }
};

class mage : public character {
protected:
    int mana;
    int maxMana;

public:
    mage(string name, int hp, int atk)
        : character(name, hp, atk) {
        this->accuracy = 0.3;
        this->mana = 75;
        this->maxMana = mana;
    }
    void getStat() {
        cout << this->name << ": HP: " << this->hp << " MP: " << this->mana << " ATK: " << this->atk << " Lvl: " << this->lvl << endl;
    }
    void incrLvl(int floor) {
        this->lvl = floor;
        this->maxHp *= 1.3;
        this->hp = this->maxHp;
        this->atk *= 1.3;
        this->maxMana *= 1.3;
        this->mana = this->maxMana;
    }
    bool Magic(character& target) {
        magic fireball;
        fireball.name = "Fireball";
        fireball.requiredLvl = 1;
        fireball.manaCost = 10;
        fireball.multiplier = 3;
        magic thunderbolt;
        thunderbolt.name = "Thunderbolt";
        thunderbolt.requiredLvl = 4;
        thunderbolt.manaCost = 15;
        thunderbolt.multiplier = 4.5;
        magic rock;
        rock.name = "Rock";
        rock.requiredLvl = 8;
        rock.manaCost = 20;
        rock.multiplier = 6;
        vector<magic> spells;
        spells.push_back(fireball);
        if (this->lvl >= thunderbolt.requiredLvl) {
            spells.push_back(thunderbolt);
        }
        if (this->lvl >= rock.requiredLvl) {
            spells.push_back(rock);
        }
        int pick;
        bool isPick = 1;
        do {
            cout << "Spells you can use: " << endl;
            cout << "9 Exit" << endl;
            for (int i = 0; i < spells.size(); i++) {
                cout << i + 1 << " " << spells[i].name << " mana use is " << spells[i].manaCost << " points of mana, which causes " << this->atk * spells[i].multiplier << " points of damage" << endl;
            }
            cout << "Pick the spell: ";
            cin >> pick;
            pick--;
            if (pick == 9) {
                isPick = 0;
                break;
            }
        } while (spells[pick].manaCost > this->mana);
        if (isPick) {
            target.takeDamage(this->atk * spells[pick].multiplier);
            return 1;
        }
        else {
            return 0;
        }
    }
};
class monster : public character {
public:
    monster(string name, int hp, int atk)
        : character(name, hp, atk) {
        this->accuracy = 1;
        this->lvl = 1;
    }
    void incrLvl(int floor) {
        this->lvl = floor;
        for (int i = 1; i < floor; i++) {
            this->hp *= 1.3;
            this->atk *= 1.3;
        }
    }
};
int main() {
    int choose;
    cout << "1 - Play game" << endl;
    cout << "2 - Exit game" << endl;
    cin >> choose;
    if (choose == 1) {
        light Kazuma("Kazuma", 60, 10);
        heavy Darkness("Darkness", 90, 15);
        mage Megumin("Megumin", 40, 5);
        dungeon dungeon;
        vector<character*> heroes;
        heroes.push_back(&Kazuma);
        heroes.push_back(&Darkness);
        heroes.push_back(&Megumin);
        random_device rd;
        while (heroes.size()) {
            mt19937 gen(rd());
            uniform_int_distribution<> hp(15, 20);
            uniform_int_distribution<> atk(5, 7);
            vector<monster> monsters;
            for (int i = 0; i < dungeon.getAmount(); i++) {
                monsters.emplace_back("Monster " + to_string(i + 1), hp(gen), atk(gen));
                monsters[i].incrLvl(dungeon.getFloor());
            }
            while (monsters.size() > 0 && heroes.size() > 0) {
                system("cls");
                cout << dungeon.getFloor() << "th floor" << endl;
                cout << "Heroes:" << endl;
                if (Kazuma.isAlive)
                    Kazuma.getStat();
                if (Darkness.isAlive)
                    Darkness.getStat();
                if (Megumin.isAlive)
                    Megumin.getStat();
                cout << "Monsters:" << endl;
                for (int i = 0; i < monsters.size(); i++) {
                    monsters[i].getStatus();
                }
                if (Kazuma.isAlive && monsters.size() > 0) {
                    int check;
                    cout << Kazuma.name << ": Choose target for attack, number between 1 and " << monsters.size() << " ";
                    cin >> check;
                    while (check < 1 || check > monsters.size()) {
                        cout << "Wrong number, enter again between 1 and " << monsters.size() << " ";
                        cin >> check;
                    }
                    check--;
                    Kazuma.attack(monsters[check]);
                    if (!monsters[check].isAlive) {
                        monsters.erase(monsters.begin() + check);
                    }
                }
                if (Darkness.isAlive && monsters.size() > 0) {
                    int check;
                    cout << Darkness.name << ": Choose target for attack, number between 1 and " << monsters.size() << " ";
                    cin >> check;
                    while (check < 1 || check > monsters.size()) {
                        cout << "Wrong number, enter again between 1 and " << monsters.size() << " ";
                        cin >> check;
                    }
                    check--;
                    Darkness.attack(monsters[check]);
                    if (!monsters[check].isAlive) {
                        monsters.erase(monsters.begin() + check);
                    }
                }
                if (Megumin.isAlive && monsters.size() > 0) {
                    int check, choose;
                    cout << Megumin.name << ": Choose physic attack (1) or magic (2) ";
                    cin >> choose;
                    while (choose != 1 && choose != 2) {
                        cout << "Wrong number, enter again 1 or 2 ";
                        cin >> check;
                    }
                    cout << Megumin.name << ": Choose target for attack, number between 1 and " << monsters.size() << " ";
                    cin >> check;
                    while (check < 1 || check > monsters.size()) {
                        cout << "Wrong number, enter again between 1 and " << monsters.size() << " ";
                        cin >> check;
                    }
                    check--;
                    if (choose == 1) {
                        Megumin.attack(monsters[check]);
                    }
                    else {
                        if (Megumin.Magic(monsters[check]) == 0) {
                            Megumin.attack(monsters[check]);
                        }
                    }
                    if (!monsters[check].isAlive) {
                        monsters.erase(monsters.begin() + check);
                    }
                }
                for (int i = 0; i < monsters.size(); i++) {
                    if (heroes.size() > 0) {
                        mt19937 gen(rd());
                        uniform_int_distribution<> attack(0, heroes.size() - 1);
                        int op = attack(gen);
                        monsters[i].attack(*heroes[op]);
                        if (!heroes[op]->isAlive) {
                            heroes.erase(heroes.begin() + op);
                        }
                    }
                }
                system("pause");
            }
            if (heroes.size() == 0) {
                cout << "Game is over" << endl;
                return 0;
            }
            else {
                cout << "Monsters have been defeated, entering new floor";
            }
            system("pause");
            dungeon.nextFloor();
            if (Kazuma.isAlive)
                Kazuma.incrLvl(dungeon.getFloor());
            if (Darkness.isAlive)
                Darkness.incrLvl(dungeon.getFloor());
            if (Megumin.isAlive)
                Megumin.incrLvl(dungeon.getFloor());
        }
    }
}