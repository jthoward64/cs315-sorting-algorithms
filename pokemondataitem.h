//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_POKEMONDATAITEM_H
#define ASSIGNMENT_1_POKEMONDATAITEM_H


class PokemonDataItem {
public:
    double pokemonNumber{};
    int totalStats{};

    explicit PokemonDataItem() = default;
    explicit PokemonDataItem(double pokemonNumber, int totalStats);

    bool operator<(const PokemonDataItem &rhs) const;

    bool operator>(const PokemonDataItem &rhs) const;

    bool operator<=(const PokemonDataItem &rhs) const;

    bool operator>=(const PokemonDataItem &rhs) const;

    bool operator==(const PokemonDataItem &rhs) const;

    bool operator!=(const PokemonDataItem &rhs) const;
};


#endif //ASSIGNMENT_1_POKEMONDATAITEM_H
