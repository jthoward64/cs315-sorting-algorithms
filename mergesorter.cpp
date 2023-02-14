//
// Created by Tagho on 2/12/2023.
//

#include "mergesorter.h"

void MergeSorter::sort() {
    MergeSorter::sortRecurse(this->data->getDataPointer());
}

void MergeSorter::sortRecurse(std::vector<PokemonDataItem>* data) {
    if(data->size() <= 1) {
        // Atomic, the input is already sorted
        return;
    } else {
        size_t middleIndex = data->size() / 2;
        // 6 2 7 9 8 3 (size is 6, "data.size() / 2" is 3)
        // 0 1 2 3 4 5
        //       ^

        // 6 2 7 9 8 3 1 (size is 7, "data.size() / 2" is 3 with integer conversion)
        // 0 1 2 3 4 5 6
        //       ^

        size_t leftSideSize = middleIndex;
        size_t rightSideSize = data->size() - leftSideSize;

        int dataIndex = 0;
        auto* leftSideData = new std::vector<PokemonDataItem>(leftSideSize);
        while (dataIndex < leftSideSize) {
            leftSideData->at(dataIndex) = data->at(dataIndex);
            dataIndex++;
        }

        auto* rightSideData = new std::vector<PokemonDataItem>(rightSideSize);
        while (dataIndex < rightSideSize + leftSideSize) {
            rightSideData->at(dataIndex - leftSideSize) = data->at(dataIndex);
            dataIndex++;
        }

        MergeSorter::sortRecurse(leftSideData);
        MergeSorter::sortRecurse(rightSideData);

        dataIndex = 0;

        size_t leftSideIndex = 0;
        size_t rightSideIndex = 0;

        while (leftSideIndex < leftSideSize && rightSideIndex < rightSideSize) {
            if (leftSideData->at(leftSideIndex) < rightSideData->at(rightSideIndex)) {
                data->at(dataIndex++) = leftSideData->at(leftSideIndex++);
            } else {
                data->at(dataIndex++) = rightSideData->at(rightSideIndex++);
            }
        }

        while (leftSideIndex != leftSideSize) {
            data->at(dataIndex++) = leftSideData->at(leftSideIndex++);
        }
        while (rightSideIndex != rightSideSize) {
            data->at(dataIndex++) = rightSideData->at(rightSideIndex++);
        }

        delete leftSideData;
        delete rightSideData;
    }
}

MergeSorter::MergeSorter() : Sorter() {

}
