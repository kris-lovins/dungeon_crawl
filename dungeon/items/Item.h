#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
public:
    Item(int ivalue, char iglyph, std::string idesc);
    int value;
    char glyph;
    std::string desc;
};

#endif
