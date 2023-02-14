//
// Created by Tagho on 2/12/2023.
//

#include "mergesorter.h"
#include "quicksorter.h"
#include "pokemondata.h"
#include<iostream>

template <typename T>
void testSorter(T sorter) {
    auto sortedData = new PokemonData("../data/pokemonSortedSmall.csv");
    auto sortedDataForSorting = new PokemonData("../data/pokemonSortedSmall.csv");
    auto reverseSortedData = new PokemonData("../data/pokemonReverseSortedSmall.csv");
    auto unsortedData = new PokemonData("../data/pokemonRandomSmall.csv");

    std::cout << "Sorted is already sorted: " << (*sortedDataForSorting == *sortedData) << '\n';
    std::cout << "Revered data is unsorted: " << (*reverseSortedData == *sortedData) << '\n';
    std::cout << "Random data is unsorted: " << (*unsortedData == *sortedData) << '\n';

    std::cout << "\nSORT ALREADY SORTED:\n" << '\n';
    sorter.setData(sortedDataForSorting);
    sorter.sort();

    std::cout << "\nSORT REVERSED DATA:\n" << '\n';
    sorter.setData(reverseSortedData);
    sorter.sort();

    std::cout << "\nSORT RANDOMIZED DATA:\n" << '\n';
    sorter.setData(unsortedData);
    sorter.sort();
    unsortedData->print();

    std::cout << "Sorted is still sorted: " << (*sortedDataForSorting == *sortedData) << '\n';
    std::cout << "Sorting worked on the reverse data: " << (*reverseSortedData == *sortedData) << '\n';
    std::cout << "Sorting worked on the random data: " << (*unsortedData == *sortedData) << '\n';

    std::cout << std::endl;
}

int main() {
    std::cout << "Merge sort:\n" << std::endl;
    MergeSorter mergeSorter;
    testSorter(mergeSorter);

    std::cout << "Quick sort:\n" << std::endl;
    QuickSorter quickSorter;
    testSorter(quickSorter);
}