#include "MobileTester_Optional.hpp"

optional<int> getMobileScreenWidth(optional<Mobile> mobile)
{
    optional<DisplayFeatures> df = mobile.value().getDisplayFeatures();
    if(df.has_value())
    {
        optional<ScreenResolution> sc = df.value().getResolution();
        if(sc.has_value())
        {
            return optional<int>(sc.value().getWidth());
        }
        else
            return optional<int>{};
    }
    else
        return optional<int>{};
}