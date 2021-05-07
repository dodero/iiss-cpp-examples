#include <optional>
#include <string>

using namespace std;

class ScreenResolution
{
private:
    int width, height;
public:
    ScreenResolution(int width, int height);
    int getWidth();
    int getHeight();
};

ScreenResolution::ScreenResolution(int width, int height)
{
    this->width = width;
    this->height = height;
}

inline int ScreenResolution::getWidth() {return width;}
inline int ScreenResolution::getHeight(){return height;}

class DisplayFeatures
{
private:
    string size; // Imperial In
    optional<ScreenResolution> resolution;
public:
    DisplayFeatures(string size, optional<ScreenResolution> resolution);
    string getSize();
    optional<ScreenResolution> getResolution();
};

DisplayFeatures::DisplayFeatures(string size, optional<ScreenResolution> resolution)
{
    this->size = size;
    this->resolution = resolution;
}

inline string DisplayFeatures::getSize(){return size;}

inline optional<ScreenResolution> DisplayFeatures::getResolution(){return resolution;}

class Mobile
{
private:
    long id;
    string brand;
    string name;
    optional<DisplayFeatures> displayFeatures;
public:
    Mobile(long id, string brand, string name, optional<DisplayFeatures> displayFeatures);
    long getId();
    string getBrand();
    string getName();
    optional<DisplayFeatures> getDisplayFeatures();
};

Mobile::Mobile(long id, string brand, string name, optional<DisplayFeatures> displayFeatures)
{
    this->id = id;
    this->brand = brand;
    this->name = name;
    this->displayFeatures = displayFeatures;
}

inline long Mobile::getId(){return id;}

inline string Mobile::getBrand(){return brand;}

inline string Mobile::getName(){return name;}

inline optional<DisplayFeatures> Mobile::getDisplayFeatures(){return displayFeatures;}