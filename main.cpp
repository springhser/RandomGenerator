/*
 * @Descripttion: 
 * @version: 
 * @Author: springhser
 * @Date: 2022-01-22 17:46:43
 * @LastEditors: springhser
 * @LastEditTime: 2022-01-26 15:37:39
 */

#include <random>
#include <iostream>
#include <unordered_set>
#include <set>
#include <chrono>
#include <thread>

// 在1到33中生成6个不同的随机整数，连续产生5组
// 采用不用的随机数生成

struct DoubleColor 
{
std::set<int> red;
int blue;
void print()
{
    std::cout << "Red: ";
    for(auto r:red)
    {
        std::cout << r << " ";
    }
    std::cout << ", Blue: " << blue << std::endl;
}
};

int generateSingleRandom(int left, int right)
{
// construct a trivial random generator engine from a time-based seed:


  std::normal_distribution<double> normal_distribution (0.0, 1.0);
  std::uniform_int_distribution<> uniform_distri(left,right);

  int res = 1;

//   std::cout << "max: " << normal_distribution.max() << std::endl;
//   std::cout << "min: " << normal_distribution.min() << std::endl;

  while(1)
  {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator (seed);
    double rate = normal_distribution(generator);

    if(rate <1.5 && rate > -1.5)
    {
        res =uniform_distri(generator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        break;
    } 
    std::cout << "over 2.35" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  return res;
}

void generateDiffRandom(std::set<int>& result)
{
    while(result.size() < 6)
    {
        int single_num = generateSingleRandom(1, 33);

        if(result.find(single_num) == result.end())
        {
            result.insert(single_num);
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(200));

    }

}

void generateOneLoop()
{
    for(int i=0;i<5; ++i)
    {
        DoubleColor dc;
        // Red
        generateDiffRandom(dc.red);
        // Blue
        dc.blue = generateSingleRandom(1,16);

        dc.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}



int main()
{
    generateOneLoop();
    return 0;
}