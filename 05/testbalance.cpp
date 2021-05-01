#include"bintree.h"
#include<stdio.h>
#include<vector>
#include<numeric>
#include<algorithm>
#include<random>
#include<cmath>

using namespace std;

struct minMax
{
    int min;
    int max;
};

void instructionTest()
{
    vector<int> numbers(9000);
    vector<minMax> results(800);
    iota(numbers.begin(), numbers.end(), 1);
    unsigned seed = 990701;
    default_random_engine rand = default_random_engine(seed);
    shuffle (numbers.begin(), numbers.end(), rand);
    for (int i = 0; i < results.size(); i++)
    {
        Node * tree = nullptr;
        for (int j = 0; j < numbers.size(); j++)
        {
            insert(tree,numbers[j],(double)numbers[j]);
        }
        results[i] = minMax{min_height(tree), max_height(tree)};
        delete_tree(tree);
        next_permutation(numbers.begin(), numbers.end());
    }

    int maxSum = 0;
    int minSum = 0;
    int max = 0;
    int min = INT32_MAX;
    int minMax = results[0].max;
    int maxMin = results[0].min;;
    int diffSum = 0;
    int minDiff = INT32_MAX;
    int maxDiff = 0;
    for (int i = 0; i < results.size(); i++)
    {
        if(results[i].max > max) max = results[i].max;
        if(results[i].min < min) min = results[i].min;
        if(results[i].min > maxMin) maxMin = results[i].min;
        if(results[i].max < minMax) minMax = results[i].max;
        if(results[i].max-results[i].min < minDiff) minDiff = results[i].max-results[i].min;
        if(results[i].max-results[i].min > maxDiff) maxDiff = results[i].max-results[i].min;
        maxSum += results[i].max;
        minSum += results[i].min;
        diffSum += abs(results[i].max-results[i].min);
    }
    printf("Average height: %.2f\n", (((double)maxSum)/results.size()));
    printf("Maximum height: %d\n", max);
    printf("Average minimum height: %.2f\n", (((double)minSum)/results.size()));
    printf("Minimum height: %d\n", min);
    printf("Average difference between minimum and maximum height: %.2f\n", (((double)diffSum)/results.size()));
    printf("Greatest difference between minimum and maximum height: %d\n", abs(max-min));
    printf("Greatest difference between minimum and maximum height in the same tree: %d\n", abs(maxDiff));
    printf("Lowest difference between minimum and maximum height: %d\n", abs(minMax-maxMin));
    printf("Lowest difference between minimum and maximum height in the same tree: %d\n", abs(minDiff));
}

int main()
{
    printf("Tests according to instructions: \n");
    instructionTest();
    printf("\n");


    printf("Improved tests: \n");
    vector<int> numbers(9000);
    vector<minMax> results(800);
    iota(numbers.begin(), numbers.end(), 1);
    unsigned seed = 990701;
    default_random_engine rand = default_random_engine(seed);
    shuffle (numbers.begin(), numbers.end(), rand);
    for (int i = 0; i < results.size(); i++)
    {
        Node * tree = nullptr;
        for (int j = 0; j < numbers.size(); j++)
        {
            insert(tree,numbers[j],(double)numbers[j]);
        }
        results[i] = minMax{min_height(tree), max_height(tree)};
        delete_tree(tree);
        shuffle (numbers.begin(), numbers.end(), rand);
    }

    int maxSum = 0;
    int minSum = 0;
    int max = 0;
    int min = INT32_MAX;
    int minMax = results[0].max;
    int maxMin = results[0].min;;
    int diffSum = 0;
    int minDiff = INT32_MAX;
    int maxDiff = 0;
    for (int i = 0; i < results.size(); i++)
    {
        if(results[i].max > max) max = results[i].max;
        if(results[i].min < min) min = results[i].min;
        if(results[i].min > maxMin) maxMin = results[i].min;
        if(results[i].max < minMax) minMax = results[i].max;
        if(results[i].max-results[i].min < minDiff) minDiff = results[i].max-results[i].min;
        if(results[i].max-results[i].min > maxDiff) maxDiff = results[i].max-results[i].min;
        maxSum += results[i].max;
        minSum += results[i].min;
        diffSum += abs(results[i].max-results[i].min);
    }
    printf("Average height: %.2f\n", (((double)maxSum)/results.size()));
    printf("Maximum height: %d\n", max);
    printf("Average minimum height: %.2f\n", (((double)minSum)/results.size()));
    printf("Minimum height: %d\n", min);
    printf("Average difference between minimum and maximum height: %.2f\n", (((double)diffSum)/results.size()));
    printf("Greatest difference between minimum and maximum height: %d\n", abs(max-min));
    printf("Greatest difference between minimum and maximum height in the same tree: %d\n", abs(maxDiff));
    printf("Lowest difference between minimum and maximum height: %d\n", abs(minMax-maxMin));
    printf("Lowest difference between minimum and maximum height in the same tree: %d\n", abs(minDiff));
    return 0;
}