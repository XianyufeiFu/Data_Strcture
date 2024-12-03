#include <algorithm>
#include <cstdlib>
#include <random>
#include <exception>
#include <ctime>
#include <iostream>

template <typename T>
class HeapSort
{
public:
    std::vector<T> v1;

    // void random_generator(){
    //     v1.clear();
    //     srand((unsigned)time(NULL));
    //     for(int i = 0; i < 2000000; i++){
    //         T p = static_cast<T>(rand());
    //         v1.push_back(p);
    //     }
    // }

    void random_generator() {
        v1.clear();
        static bool seed_initialized = false;
        if (!seed_initialized) {
            srand((unsigned)time(NULL));
            seed_initialized = true;
        }
        std::random_device rd; // 非确定性随机数生成器
        std::mt19937 gen(rd()); // 以随机_device为种子的Mersenne Twister生成器
        std::uniform_int_distribution<> dis; // 均匀分布的整数

        for (int i = 0; i < 2000000; i++) {
            T p = dis(gen); // 生成随机数
            v1.push_back(p);
    }
}

    void ascending_queue(){
        v1.clear();
        for(T i = 0; i < 2000000; i += 1){
            v1.push_back(i);
        }
    }

    void descending_queue(){
        v1.clear();
        for(T i = 2000000 - 1; i >= 0; i -= 1){
            v1.push_back(i);
        }
    }

    void repetitive_queue(){
        v1.clear();
        random_generator();
        T p = rand();
        for(int i = 0; i < 2000000; i += 5){
            v1[i] = p;//替换其中的重复元素
        }
    }

    bool check(){
        for(int i = 0; i < v1.size() - 1; i++){
            if(v1[i] > v1[i+1])
                return false;//有逆序对立即返回
        }
        return true;
    }

    void sort(){
        std::make_heap(v1.begin(), v1.end());//转化为一个二叉堆
        for(int i = 0; i < v1.size(); i++){
            std::pop_heap(v1.begin(), v1.end() - i);//每次选出一个最大元素放在最后
        }
    }

    void printvector(){
        for(int i = 100000; i < 50+100000; i++){
            std::cout << v1[i] << " " ;
        }
        std::cout << std::endl;
    }

    void std_sort(){
        std::make_heap(v1.begin(), v1.end());
        std::sort_heap(v1.begin(), v1.end());
    }
};