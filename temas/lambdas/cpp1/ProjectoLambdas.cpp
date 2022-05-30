#include <iostream>

int main()
{
    // Función Lambda
    auto print = [](int v[]){
        for(int i = 0; i < 10; i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

    };

    // Función Lambda Variádica
    auto sumParams = [](auto...args)
    {
        int r = 0;
        ((r+=args),...);
        return r;
    };

    //Función Lambda Mutable
    auto prodVector = [](int v[]) mutable{
        for(int i = 0; i < 10; i++)
        {
            v[i] = v[i]*10;
        }
    };

    int v1[10] = {1,2,3,4,5,6,7,8,9,10};
    int v2[10] = {11,12,13,14,15,16,17,18,19,20};
    print(v1);
    print(v2);
    int sum = sumParams(1,2,3);
    std::cout << sum << std::endl; 
    prodVector(v1);
    print(v1);
}