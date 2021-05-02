#include"watermanager.h"

WaterManager::WaterManager(int runs, bool withTrace) : numRuns{runs}, trace{withTrace}, gnusInside{0}, hyenasInside{0}
{
    distribution = uniform_int_distribution<int>(200,2000);
    re = default_random_engine(rd());
}
void WaterManager::insertAnimal(thread::id id, string text)
{
    if(trace) animals.emplace(id, text);
}
void WaterManager::hyenaEnters()
{
    unique_lock<mutex> hyenaLock(mu);
    conV.wait(hyenaLock, [this] {return gnusInside == 0;});
	hyenasInside += 1;
}
void WaterManager::gnuEnters()
{
    unique_lock<mutex> gnuLock(mu);
    conV.wait(gnuLock, [this] {return hyenasInside == 0;});
	gnusInside += 1;
}
void WaterManager::hyenaLeaves()
{
    mu.lock();
    hyenasInside -= 1;
    conV.notify_all();
    mu.unlock();
}
void WaterManager::gnuLeaves()
{
    mu.lock();
    gnusInside -= 1;
    conV.notify_all();
    mu.unlock();
}

Gnu::Gnu(int id)
{
    this->id = id;
}
void Gnu::operator()(WaterManager* watermanager)
{
    int i = 0;
    while (watermanager->numRuns > i)
    {
        chrono::milliseconds waitTime{watermanager->distribution(watermanager->re)};
        this_thread::sleep_for(waitTime);
        // sleep for a while
        if(watermanager->trace) cout << *this << " is thristy\n";
        watermanager->gnuEnters();            // see monitoring class below
        if(watermanager->trace)
        {
            cout << string("A gnu enters the watercave\thyenas = ")
                + to_string(watermanager->hyenasInside.load())
                + string("\tgnu = ") 
                + to_string(watermanager->gnusInside.load()) 
                + string("\n");
        }
        // drink water for a while i.e. sleep for a short while
        chrono::milliseconds drinkTime{watermanager->distribution(watermanager->re)};
        this_thread::sleep_for(drinkTime);
        watermanager->gnuLeaves();
        if(watermanager->trace) cout << *this << " finished drinking and exits the watercave\n";
        i++;
    }
}

ostream & operator<<(ostream & os, const Gnu & g)
{
    os << "Gnu " << g.id;
    return os;
}
