//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_QUICKSORTER_H
#define ASSIGNMENT_1_QUICKSORTER_H

#include "sorter.h"

class QuickSorter : public Sorter {
public:
    void sort() override;

private:
    static void quickSort(std::vector<PokemonDataItem>* data, int startIndex, int endIndex);
    static int partition(std::vector<PokemonDataItem>* data, int startIndex, int endIndex);
};


#endif //ASSIGNMENT_1_QUICKSORTER_H
