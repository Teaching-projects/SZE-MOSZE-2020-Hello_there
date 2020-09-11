#include "DungeonMaster.h"

void DungeonMaster::Fight(Unit *atk, Unit *def)
{
    std::cout << units[0]->ToString();
    std::cout << units[1]->ToString();
    std::cout << atk->GetName() << " -> " << def->GetName() << std::endl;

    def->Defend(atk->Attack());

    if (def->IsDead())
    {
        std::cout << units[0]->ToString();
        std::cout << units[1]->ToString();
        std::cout << def->GetName() << " died. " << atk->GetName() << " wins." << std::endl;
    }
    else
    {

        Fight(def, atk);
    }
}

DungeonMaster::DungeonMaster()
{
}

DungeonMaster::~DungeonMaster()
{
    for (int i = 0; i < units.size(); i++)
    {
        delete units[i];
    }
    units.clear();
}

DungeonMaster *DungeonMaster::GetInstance()
{
    if (!instance)
        instance = new DungeonMaster;
    return instance;
}

void DungeonMaster::Init(char *argv[])
{

    for (int i = 0; i < 2; i++)
    {
        std::string name = argv[i * 3 + 1];

        std::string sHp = argv[i * 3 + 2];
        int hp = std::stoi(sHp);

        std::string sDmg = argv[i * 3 + 3];
        int dmg = std::stoi(sDmg);

        units.push_back(new Unit(name, hp, dmg));
    }

    Fight(units[0], units[1]);
}

DungeonMaster *DungeonMaster::instance = nullptr;