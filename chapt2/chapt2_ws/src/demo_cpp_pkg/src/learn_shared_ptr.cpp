#include <iostream>
#include <memory>

int main()
{
    auto p1 = std::make_shared<std::string>("This is a str.");
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl;

    auto p2 = p1;
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl;
    std::cout<< "p2的引用计数:"<< p2.use_count() << ",指向内存地址:"<< p2.get() << std::endl;

    p1.reset(); // p1不再指向内存地址，p2仍然指向内存地址
    std::cout<< "p1的引用计数:"<< p1.use_count() << ",指向内存地址:"<< p1.get() << std::endl;
    std::cout<< "p2的引用计数:"<< p2.use_count() << ",指向内存地址:"<< p2.get() << std::endl;

    std::cout<< "p2的指向内存地址数据:"<< p2->c_str() << std::endl;

    return 0;
}