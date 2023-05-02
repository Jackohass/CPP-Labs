#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>

using namespace std;

void lambda1(vector<int> v)
{
    cout << "Lambda 1: \n\t";
    for_each(v.cbegin(), v.cend(), [](int i){
        if(i&1) cout << i << " ";
    });
    cout << endl;
}

void lambda2(vector<int> v)
{
    cout << "Lambda 2: \n\t";
    for_each(v.begin(), v.end(), [](int &i){
        if(i&1) i *= 2;
    });
    for (auto x : v) { cout << x << " ";};
    cout << endl;
}

void lambda3(vector<int> v)
{
    cout << "Lambda 3: \n\t";
    for_each(v.begin(), v.end(), [v](int &i){
        if(i&1) i += v.size();
    });
    for (auto x : v) { cout << x << " ";};
    cout << endl;
}

int OUTSIDEDATA = 22;
void lambda4()
{
    cout << "Lambda 4: \n";
    auto func1 = [&OUTSIDEDATA](int x){OUTSIDEDATA = x;};
    cout << "\tOUTSIDEDATA = " << OUTSIDEDATA << endl;
    func1(2);
    cout << "\tOUTSIDEDATA = " << OUTSIDEDATA << endl;
}


int main()
{
    vector<int> v = {1, 3, 4, 5, 6, 7, 8, 9};
    // printing v
    cout << "vector v:\n\t";
    for (auto x : v) { cout << x << " ";};
    cout << endl;

    //Lambda 1:
    lambda1(v);
    
    //Lambda 2:
    lambda2(v);

    //Lambda 3:
    lambda3(v);

    //Lambda 4:
    lambda4();

    return 0;
}