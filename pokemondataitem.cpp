//
// Created by Tagho on 2/12/2023.
//

#include "pokemondataitem.h"

bool PokemonDataItem::operator<(const PokemonDataItem &rhs) const {
    return totalStats < rhs.totalStats;
}

bool PokemonDataItem::operator>(const PokemonDataItem &rhs) const {
    return rhs < *this;
}

bool PokemonDataItem::operator<=(const PokemonDataItem &rhs) const {
    return !(rhs < *this);
}

bool PokemonDataItem::operator>=(const PokemonDataItem &rhs) const {
    return !(*this < rhs);
}

bool PokemonDataItem::operator==(const PokemonDataItem &rhs) const {
    return pokemonNumber == rhs.pokemonNumber &&
           totalStats == rhs.totalStats;
}

bool PokemonDataItem::operator!=(const PokemonDataItem &rhs) const {
    return !(rhs == *this);
}

PokemonDataItem::PokemonDataItem(double pokemonNumber, int totalStats) : pokemonNumber(pokemonNumber),
                                                                      totalStats(totalStats) {}
