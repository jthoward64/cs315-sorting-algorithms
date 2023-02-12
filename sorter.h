//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_SORTER_H
#define ASSIGNMENT_1_SORTER_H


#include "pokemondata.h"

class Sorter {
private:
    PokemonData data;

public:
    explicit Sorter(PokemonData data);

    virtual void sort() = 0;

    const PokemonData &getData() const;
};


#endif //ASSIGNMENT_1_SORTER_H
