//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_POKEMONDATA_H
#define ASSIGNMENT_1_POKEMONDATA_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <stack>
#include <cmath>

#include "pokemondataitem.h"

class PokemonData {
public:
    explicit PokemonData(std::string path);

    void print();

private:
    size_t dataSize;
    PokemonDataItem* data;
};


#endif //ASSIGNMENT_1_POKEMONDATA_H
