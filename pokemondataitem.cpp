//
// Created by Tagho on 2/12/2023.
//

#include <iostream>
#include "pokemondataitem.h"

bool PokemonDataItem::operator<(const PokemonDataItem &rhs) const {
    if (this->totalStats == rhs.totalStats) {
        return this->pokemonNumber < rhs.pokemonNumber;
    } else {
        return this->totalStats < rhs.totalStats;
    }
}

bool PokemonDataItem::operator>(const PokemonDataItem &rhs) const {
    if (this->totalStats == rhs.totalStats) {
        return this->pokemonNumber > rhs.pokemonNumber;
    } else {
        return this->totalStats > rhs.totalStats;
    }
}

bool PokemonDataItem::operator<=(const PokemonDataItem &rhs) const {
    return !(rhs < *this);
}

bool PokemonDataItem::operator>=(const PokemonDataItem &rhs) const {
    return !(rhs > *this);
}

bool PokemonDataItem::operator==(const PokemonDataItem &rhs) const {
    return this->totalStats == rhs.totalStats && this->pokemonNumber == rhs.pokemonNumber;
}

bool PokemonDataItem::operator!=(const PokemonDataItem &rhs) const {
    return !(rhs == *this);
}

PokemonDataItem::PokemonDataItem(double d, int i) {
    this->pokemonNumber = d;
    this->totalStats = i;
}
