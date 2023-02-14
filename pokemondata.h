//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_POKEMONDATA_H
#define ASSIGNMENT_1_POKEMONDATA_H


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <cmath>

#include "pokemondataitem.h"

class PokemonData {
public:
    explicit PokemonData(const std::string& path);

    explicit PokemonData(std::vector<PokemonDataItem> data);

    void print() const;

    bool operator==(const PokemonData &rhs) const;

    bool operator!=(const PokemonData &rhs) const;

    PokemonDataItem &operator[](size_t index);

    [[nodiscard]] size_t size() const;
    [[nodiscard]] std::vector<PokemonDataItem> * getDataPointer() const;

    virtual ~PokemonData();

private:
    std::vector<PokemonDataItem>* data;
};


#endif //ASSIGNMENT_1_POKEMONDATA_H
