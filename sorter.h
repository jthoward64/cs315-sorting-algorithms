//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_SORTER_H
#define ASSIGNMENT_1_SORTER_H


#include "pokemondata.h"

class Sorter {

protected:
    PokemonData* data = nullptr;
public:
    explicit Sorter() = default;

    virtual void sort() = 0;

    virtual ~Sorter();

    [[nodiscard]] PokemonData* getData() const;
    void setData(PokemonData* newData);
};


#endif //ASSIGNMENT_1_SORTER_H
