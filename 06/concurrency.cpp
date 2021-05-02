#include"watermanager.h"

void gnu(WaterManager* watermanager) {
    int i = 0;
    while (watermanager->numRuns > i)
    {
        chrono::milliseconds waitTime{watermanager->distribution(watermanager->re)};
        this_thread::sleep_for(waitTime);
        // sleep for a while
        if(watermanager->trace) cout << watermanager->animals[this_thread::get_id()] + " is thristy\n";
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
        if(watermanager->trace) cout << watermanager->animals[this_thread::get_id()] + string(" finished drinking and exits the watercave\n");
        i++;
    }
}

void hyena(WaterManager* watermanager) {
    int i = 0;
    while (watermanager->numRuns > i)
    {
        chrono::milliseconds waitTime{watermanager->distribution(watermanager->re)};
        this_thread::sleep_for(waitTime);
        // sleep for a while
        if(watermanager->trace) cout << watermanager->animals[this_thread::get_id()] + " is thristy\n";
        watermanager->hyenaEnters();            // see monitoring class below
        if(watermanager->trace)
        {
            cout << string("A hyena enters the watercave\thyenas = ")
                + to_string(watermanager->hyenasInside.load())
                + string("\tgnu = ") 
                + to_string(watermanager->gnusInside.load()) 
                + string("\n");
        }
        // drink water for a while i.e. sleep for a short while
        chrono::milliseconds drinkTime{watermanager->distribution(watermanager->re)};
        this_thread::sleep_for(drinkTime);
        watermanager->hyenaLeaves();
        if(watermanager->trace) cout << watermanager->animals[this_thread::get_id()] + string(" finished drinking and exits the watercave\n");
        i++;
    }
}


/**
 * argv[0] = name
 * argv[1] = if we have trace or not. If this is not included we assume that trace is off.
 */
int main(int argc, char *argv[])
{
    bool trace;
    if(argc > 1)
    {
        string condition(argv[1]);
        if(condition.compare("true")) trace = true;
        else if(condition.compare("True")) trace = true;
        else if(condition.compare("TRUE")) trace = true;
        else if(condition.compare("false")) trace = false;
        else if(condition.compare("False")) trace = false;
        else if(condition.compare("FALSE")) trace = false;
    }
    else trace = false;
    WaterManager* watermanager = new WaterManager(5, trace);

    const int nrGnus = 4;
    const int nrHyenas = 3;
    vector<thread> threadvec;
    threadvec.reserve(nrGnus + nrHyenas);
    for(int i = 0; i < nrGnus; i++)
    {
        // threadvec.push_back(thread(gnu, watermanager));
        // watermanager->insertAnimal(threadvec[i].get_id(), "Gnu " + to_string(i));
        Gnu g = Gnu(i);
        std::function<void(WaterManager*)> threadjob = g;
        threadvec.push_back(thread(threadjob, watermanager));
    }
    for(int i = 0; i < nrHyenas; i++)
    {
        threadvec.push_back(thread(hyena, watermanager));
        watermanager->insertAnimal(threadvec[i+nrGnus].get_id(), "Hyena " + to_string(i));
    }
    for (auto& thread : threadvec) thread.join();

    delete watermanager;

    return 0;
}