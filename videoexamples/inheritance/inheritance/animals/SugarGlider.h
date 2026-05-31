#ifndef SUGARGLIDER_H
#define SUGARGLIDER_H

#include <string>
#include "Animal.h"

class SugarGlider : public Animal {
public:
    SugarGlider(std::string name);

    void speak() override;
};

#endif
