//
// Created by Tagho on 2/12/2023.
//

#include <queue>
#include <cstdio>
#include <sstream>
#include <utility>
#include "pokemondata.h"

PokemonData::PokemonData(const std::string& path) {
    std::ifstream dataFile (path);

    std::string dataFileLine;

    // Advance past the header
    std::getline(dataFile, dataFileLine);

    std::queue<std::string> dataFileLines;

    while (std::getline(dataFile, dataFileLine)) {
        dataFileLines.push(dataFileLine);
    }

    this->data = new std::vector<PokemonDataItem>(dataFileLines.size());

    int i = 0;
    while(!dataFileLines.empty()) {
        std::istringstream iss(dataFileLines.front());

        double pokemonNumber;
        char comma;
        int totalStats;

        if (!(iss >> pokemonNumber >> comma >> totalStats)) { break; } // error

        this->data->at(i++) = PokemonDataItem{pokemonNumber, totalStats};

        dataFileLines.pop();
    }
}

void PokemonData::print() const {
    for (int i = 0; i < 10; ++i) {
        std::cout << this->data->operator[](i).pokemonNumber << ": " << this->data->operator[](i).totalStats << "\n";
    }
    std::cout << std::endl;
}

bool PokemonData::operator==(const PokemonData &rhs) const {
    if (this->size() != rhs.size()) {
        return false;
    } else {
        for (int i = 0; i < this->size(); ++i) {
            if (this->data->at(i) != rhs.data->at(i)) {
                return false;
            }
        }
        return true;
    }
}

bool PokemonData::operator!=(const PokemonData &rhs) const {
    return !(rhs == *this);
}

size_t PokemonData::size() const {
    return this->data->size();
}

PokemonDataItem &PokemonData::operator[](size_t index) {
    return this->data->operator[](index);
}

PokemonData::PokemonData(std::vector<PokemonDataItem> data) {
    this->data = new std::vector<PokemonDataItem>(std::move(data));
}

std::vector<PokemonDataItem> * PokemonData::getDataPointer() const {
    return this->data;
}

PokemonData::~PokemonData() {
    delete this->data;
}
