//
// Created by Tagho on 2/12/2023.
//

#include "insertionsorter.h"

void InsertionSorter::sort() {
    auto* dataPointer = this->data->getDataPointer();
    size_t length = this->data->size();

    for (size_t i = 1; i < length; i++) {
        size_t j = i;
        while (j > 0 && dataPointer->at(j - 1) > dataPointer->at(j)) {
            auto temp = dataPointer->at(j);
            dataPointer->at(j) = dataPointer->at(j-1);
            dataPointer->at(j-1) = temp;
            j--;
        }
    }
}
