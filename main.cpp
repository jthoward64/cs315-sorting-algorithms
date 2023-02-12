//
// Created by Tagho on 2/12/2023.
//

#include "mergesorter.h"
#include "quicksorter.h"
#include "insertionsorter.h"
#include "pokemondata.h"

int main() {
    PokemonData data("./data/pokemonRandomLarge.csv");
    data.print();
}