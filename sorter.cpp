//
// Created by Tagho on 2/12/2023.
//

#include "sorter.h"

Sorter::Sorter(PokemonData data) : data(data) {}

const PokemonData &Sorter::getData() const {
    return data;
}
