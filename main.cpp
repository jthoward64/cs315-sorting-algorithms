//
// Created by Tagho on 2/12/2023.
//

#include "mergesorter.h"
#include "quicksorter.h"
#include "pokemondata.h"
#include "insertionsorter.h"
#include<iostream>

void printSortingStatus(const PokemonData *sortedData, const PokemonData *sortedDataForSorting,
                        const PokemonData *reverseSortedData, const PokemonData *unsortedData) {
    std::cout << "\u001b[32;1m";
    std::cout << "\t\t1. Pre-sorted data is sorted: " << (*sortedDataForSorting == *sortedData ? "Yes" : "No") << '\n';
    std::cout << "\t\t2. Reversed data is sorted: " << (*reverseSortedData == *sortedData ? "Yes" : "No") << '\n';
    std::cout << "\t\t3. Random data is sorted: " << (*unsortedData == *sortedData ? "Yes" : "No") << '\n';
    std::cout << "\u001b[0m";
}

template<typename T>
void runSorting(T &sorter, PokemonData *dataForSorting, const std::string& adjective) {
    PokemonDataItem::comparisonsMade = 0;
    std::cout << "\u001b[36m";
    std::cout << "\t\tRunning the " << adjective << " sorted data\n";
    sorter.setData(dataForSorting);
    sorter.sort();
    std::cout << "\t\tMade " << PokemonDataItem::comparisonsMade << " comparisons\n";
}

std::string pathToDataDir{"../data/"};
std::string makePathToCsv(const std::string& pathSortSegment, const std::string& pathSizeSegment) {
    std::string basePath{pathToDataDir};
    return basePath + "pokemon" + pathSortSegment + pathSizeSegment + ".csv";
}

template <typename T>
void testSorter(T sorter, const std::string& pathSegment) {
    std:: string sortedDataPath = makePathToCsv("Sorted", pathSegment);
    std:: string reverseSortedDataPath = makePathToCsv("ReverseSorted", pathSegment);
    std:: string unsortedDataPath = makePathToCsv("Random", pathSegment);

    auto sortedData = new PokemonData(sortedDataPath);
    auto sortedDataForSorting = new PokemonData(sortedDataPath);
    auto reverseSortedData = new PokemonData(reverseSortedDataPath);
    auto unsortedData = new PokemonData(unsortedDataPath);

    printSortingStatus(sortedData, sortedDataForSorting, reverseSortedData, unsortedData);

    runSorting<T>(sorter, sortedDataForSorting, "already");
    runSorting<T>(sorter, reverseSortedData, "reverse");
    runSorting<T>(sorter, unsortedData, "not");

    printSortingStatus(sortedData, sortedDataForSorting, reverseSortedData, unsortedData);

    std::cout << std::endl;
}

void testAllSortersOnFile(const std::string& pathSegment) {
    std::cout << "\u001b[34m" << "\tMerge sort:" << "\u001b[0m" << std::endl;
    MergeSorter mergeSorter;
    testSorter(mergeSorter, pathSegment);

    std::cout << "\u001b[34m" << "\tQuick sort:" << "\u001b[0m" << std::endl;
    QuickSorter quickSorter;
    testSorter(quickSorter, pathSegment);

    std::cout << "\u001b[34m" << "\tInsertion sort:" << "\u001b[0m" << std::endl;
    InsertionSorter insertionSorter;
    testSorter(insertionSorter, pathSegment);
}

int main(int argc, char** argv) {
    if(argc == 2) {
        std::cout << argv[1] << std::endl;
        pathToDataDir = argv[1];
    }

    std::cout << "\u001b[35m" << "Running the Small File:" << "\u001b[0m" << std::endl;
    testAllSortersOnFile("Small");
    std::cout << "\u001b[35m" << "Running the Medium File:" << "\u001b[0m" << std::endl;
    testAllSortersOnFile("Medium");
    std::cout << "\u001b[35m" << "Running the Large File:" << "\u001b[0m" << std::endl;
    testAllSortersOnFile("Large");
}
