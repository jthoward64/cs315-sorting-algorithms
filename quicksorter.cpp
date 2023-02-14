//
// Created by Tagho on 2/12/2023.
//

#include "quicksorter.h"

void QuickSorter::sort() {
    QuickSorter::quickSort(this->data->getDataPointer(), 0, this->data->size() - 1);
}

void QuickSorter::quickSort(std::vector<PokemonDataItem> *dataToSort, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int q = QuickSorter::partition(dataToSort, startIndex, endIndex);
        QuickSorter::quickSort(dataToSort, startIndex, q-1);
        QuickSorter::quickSort(dataToSort, q+1, endIndex);
    }
}

int QuickSorter::partition(std::vector<PokemonDataItem> *data, int startIndex, int endIndex) {
    PokemonDataItem pivot = data->at(endIndex);
    int i = startIndex - 1;
    for (int j = startIndex; j < endIndex; j++) {
        if (data->at(j) < pivot) {
            i++;
            PokemonDataItem temp = data->at(i);
            data->at(i) = data->at(j);
            data->at(j) = temp;
        }
    }
    PokemonDataItem temp = data->at(i+1);
    data->at(i+1) = data->at(endIndex);
    data->at(endIndex) = temp;

    return i+1;
}
