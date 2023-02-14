//
// Created by Tagho on 2/12/2023.
//

#include "sorter.h"

PokemonData* Sorter::getData() const {
    return data;
}

Sorter::~Sorter() {
    delete this->data;
}

void Sorter::setData(PokemonData *newData) {
    this->data = newData;
}
