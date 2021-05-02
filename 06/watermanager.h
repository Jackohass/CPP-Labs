#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

class WaterManager
{
private:
    condition_variable conV;
    mutex mu;
    random_device rd;
    
public:
    atomic<int> hyenasInside;
    atomic<int> gnusInside;
    unordered_map<thread::id, string> animals;
    const bool trace;
    const int numRuns;
    uniform_int_distribution<int> distribution;
    default_random_engine re;
    
    WaterManager(int runs, bool withTrace);
    void hyenaEnters();
    void gnuEnters();
    void hyenaLeaves();
    void gnuLeaves();
    void insertAnimal(thread::id id, string text);
};

class Gnu
{
private:
    
public:
    int id;

    Gnu(int id);
    void operator()(WaterManager* watermanager);
};
ostream& operator<<(ostream & os, const Gnu & g);