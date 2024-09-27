#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        };
        Chicken(const Chicken& d)
        {
            age = d.getAge();
            // if(d.name != nullptr) //判断是否为空指针
            // {
            //     int len = strlen(d.name) + 1;
            //     name = new char[len];
            //     for(int i = 0; i < len; i++)
            //         name[i] = d.name[i];
            // }
            // else
            // {
            //     name = nullptr;
            // }
            setName(d.getName());
        };
        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
            // std::cout<<"Oh my Kunkun"<<std::endl;
        }
        Chicken& operator=(const Chicken& d)
        {
            // if(this != &d)
            // {
            //     age = d.age;
            //     if(name != nullptr)
            //         delete[] name;
            //     if(d.name != nullptr) //判断是否为空指针
            //     {
            //         int len = strlen(d.name) + 1;
            //         name = new char[len];
            //         for(int i = 0; i < len; i++)
            //             name[i] = d.name[i];
            //     }
            //     else
            //     {
            //         name = nullptr;
            //     }
            // } 
            if(this != &d)
            {
                age = d.getAge();
                setName(d.getName());
            }
            
            return *this;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
            if(_name != nullptr)
            {
                int len = strlen(_name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++)
                    name[i] = _name[i];
            }
            else
            {
                name = nullptr;
            }
            
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }

        

        
};

int main(){
    auto print = [](const Chicken &c){
        std::cout << "Hi, everyone! My name is " << c.getName()                   
        << ", I am " << c.getAge() << " years old." << std::endl;    
        };
    Chicken c(24, "Kunkun");    
    print(c);    
    Chicken d;    
    d = c;    
    print(d); // 测试【赋值运算符】是否正确，能正确输出给 20 分    
    Chicken a = c;    
    print(a); // 测试【赋值构造函数】是否正确，能正确输出给 20 分    
    c.setName("Xukun Cai");    
    print(c);    
    print(a);    
    print(d); // 测试是否为【深度复制】，本行与上两行能正确输出给 20 分    
    Chicken b;    
    b = d = c;    
    print(b);    
    print(d); // 测试【连续赋值】功能，本行与上一行能正确输出给 20 分
    return 0;
}