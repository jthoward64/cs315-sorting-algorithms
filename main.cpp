//
// Created by Tagho on 2/12/2023.
//

#include "insertionsorter.h"
#include "pokemondata.h"
#include<iostream>

int main() {
    auto sortedData = new PokemonData("../data/pokemonSortedSmall.csv");
    auto sortedDataForSorting = new PokemonData("../data/pokemonSortedSmall.csv");
    auto reverseSortedData = new PokemonData("../data/pokemonReverseSortedSmall.csv");
    auto unsortedData = new PokemonData("../data/pokemonRandomSmall.csv");


    unsortedData->print();

    MergeSorter sorter;

    std::cout << "Sorted is already sorted: " << (*sortedDataForSorting == *sortedData) << std::endl;
    std::cout << "Revered data is unsorted: " << (*reverseSortedData == *sortedData) << std::endl;
    std::cout << "Random data is unsorted: " << (*unsortedData == *sortedData) << std::endl;

    std::cout << "\nSORT ALREADY SORTED:\n" << std::endl;
    sorter.setData(sortedDataForSorting);
    sorter.sort();

    std::cout << "\nSORT REVERSED DATA:\n" << std::endl;
    sorter.setData(reverseSortedData);
    sorter.sort();

    std::cout << "\nSORT RANDOMIZED DATA:\n" << std::endl;
    sorter.setData(unsortedData);
    sorter.sort();
    unsortedData->print();

    std::cout << "Sorted is still sorted: " << (*sortedDataForSorting == *sortedData) << std::endl;
    std::cout << "Sorting worked on the reverse data: " << (*reverseSortedData == *sortedData) << std::endl;
    std::cout << "Sorting worked on the random data: " << (*unsortedData == *sortedData) << std::endl;
}