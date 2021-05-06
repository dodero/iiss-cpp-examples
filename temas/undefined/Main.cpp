#include "MobileService.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ScreenResolution resolution = ScreenResolution(750, 1334);
    DisplayFeatures dfeatures = DisplayFeatures("4.7", optional<ScreenResolution>(resolution));
    Mobile mobile = Mobile(2015001, "Apple", "iPhone 6s", optional<DisplayFeatures>(dfeatures));

    optional<int> widht = getMobileScreenWidth(optional<Mobile>(mobile));
    cout<<"Apple iPhone 6s screen width is "<<widht.value_or(0)<<endl;

    Mobile mobile2 = Mobile(2015001, "Apple", "iPhone 6s", optional<DisplayFeatures>(nullopt));

    optional<int> widht2 = getMobileScreenWidth(optional<Mobile>(mobile2));
    cout<<"Apple iPhone 6s screen width is "<<widht2.value_or(0)<<endl;

    return 0;
}
