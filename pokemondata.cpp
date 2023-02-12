//
// Created by Tagho on 2/12/2023.
//

#include <queue>
#include "pokemondata.h"

PokemonData::PokemonData(std::string path) {
    std::ifstream dataFile (path);

    std::string dataFileLine;

    // Advance past the header
    std::getline(dataFile, dataFileLine);

    std::queue<std::string> dataFileLines;

    while (std::getline(dataFile, dataFileLine)) {
        dataFileLines.push(dataFileLine);
    }

    this->dataSize = dataFileLines.size();
    PokemonDataItem dataArray[this->dataSize];

    int i = 0;
    while(!dataFileLines.empty()) {
        std::string line = dataFileLines.front();

        double pokemonNumber = 0;
        int totalStats = 0;

        bool wasComma = false;
        int decimal = 0;
        for (char letter : line) {
            if (letter == ',') {
                wasComma = true;
                continue;
            } else if (wasComma) {
                totalStats *= 10;
                totalStats += (letter - '0');
            } else if (letter == '.') {
                decimal++;
                continue;
            } else if (decimal > 0) {
                pokemonNumber += (pow(0.1,decimal) * (letter - '0'));
            } else {
                pokemonNumber *= 10;
                pokemonNumber += (letter - '0');
            }
        }

        dataArray[i++] = PokemonDataItem(pokemonNumber, totalStats);

        dataFileLines.pop();
    }

    this->data = dataArray;
}

void PokemonData::print() {
    for (int i = 0; i < this->dataSize; ++i) {
        std::cout << this->data[i].pokemonNumber << ": " << this->data[i].totalStats << "\n";
    }
    std::cout << std::flush;
}
