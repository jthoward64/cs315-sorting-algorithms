//
// Created by Tagho on 2/12/2023.
//

#ifndef ASSIGNMENT_1_MERGESORTER_H
#define ASSIGNMENT_1_MERGESORTER_H

#include "sorter.h"

class MergeSorter : public Sorter {
public:
    explicit MergeSorter();

    void sort() override;

private:

    static void sortRecurse(std::vector<PokemonDataItem>* data);
};


#endif //ASSIGNMENT_1_MERGESORTER_H
