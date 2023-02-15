## How to build
Run on Linux with CMake and GNU make:

```shell
cmake .
make pokemonsort
./pokemonsort(.exe)
```

You can also just feed all the `.cpp` files to `g++` and be done with it. i.e.

```shell
g++ ./*.cpp && ./a.out && rm ./a.out
```

Personally I used CLion's build in CMake support and the ninja build tools.

## How to run
Just execute the binary produced by your compiler of choice, I've tested on Windows 11 and Linux

*Note that the code has a hardcoded default path to the data directory (a folder with all the csv files in it), you may also pass a custom path, for example:*
```shell
./cmake-build-debug/pokemonsort /home/username/Source/cs315/assignment-1/data/
```

## Estimate and Graph Runtime

### Small Dataset (166 Pokémon)
|                | Merge Sort | Quick sort | Insertion Sort |
| -------------- | ---------- | ---------- | --------- |
| Already Sorted | 579        | 13695      | 165       |
| Reverse Sorted | 659        | 13695      | 13695     |
| Unsorted       | 1030       | 1198       | 7037      | 

$$166^2=27556$$

$$166 \log 166 \approx 369$$

### Medium Dataset (432 Pokémon)
|                | Merge Sort | Quick sort | Insertion Sort |
| -------------- | ---------- | ---------- | --------- |
| Already Sorted | 1824        | 93096      | 431       |
| Reverse Sorted | 1984        | 93096      | 93096     |
| Unsorted       | 3217       | 4424       | 47209      |

$$432^2=186624$$

$$432 \log 432 \approx 1138$$

### Large Dataset (800 Pokémon)
|                | Merge Sort | Quick sort | Insertion Sort |
| -------------- | ---------- | ---------- | --------- |
| Already Sorted | 3728        | 319600      | 799       |
| Reverse Sorted | 4048        | 319600      | 319600     |
| Unsorted       | 6707       | 8990       | 164967      |

$$800^2=640000$$

$$800\log 800 \approx 2322$$

### Runtime Notes
Insertion sort performed exactly as expected thanks to its clear cut best and worst case runtime. It's best case is $O(n)$ which is essentially what I saw in the already sorted data, and I likewise saw terrible performance in the reverse sorted data, with a runtime of about $O(\frac{1}{2}n^2)$, which can also be represented as $O(n^2)$, the standard worst case for insertion sort.
For quick sort, in my implementation, the worst case is when the array is already sorted, in this case the runtime should be $O(n^2)$.  This is pretty much what I saw (same as for insertion sort) for every run. As far as best and average runtime goes, both are $n\log{n}$, I usually saw a comparison count of about four times $O(nlogn)$.
Lastly, while I do not understand why, my merge sort results were more inconsistent than I expected, it is possible it has something to do with my slightly unorthodox implementation. Regardless, it did hold relatively well to the expected runtime of $O(logn)$.

## Implementation Details
I decided to go for an object oriented structure for the project which did lead to some added complexity with regards to data ownership and encapsulation, but I liked the savings it gave me as far as code duplication. In my `PokemonDataItem` class you will note that my comparison functions fall back to the Pokémon's number if the total stats are the same, this reflects the pre sorted file provided in the data zip, and means that running that file through any of the three algorithms will result in identical data. In the event that two Pokémon have the same number (impossible in this project), the behavior depends on the algorithm. 

## Example run
```
Running the Small File:
        Merge sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 579 comparisons
                Running the reverse sorted data
                Made 659 comparisons
                Running the not sorted data
                Made 1030 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Quick sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 13695 comparisons
                Running the reverse sorted data
                Made 13695 comparisons
                Running the not sorted data
                Made 1198 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Insertion sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 165 comparisons
                Running the reverse sorted data
                Made 13695 comparisons
                Running the not sorted data
                Made 7037 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

Running the Medium File:
        Merge sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 1824 comparisons
                Running the reverse sorted data
                Made 1984 comparisons
                Running the not sorted data
                Made 3217 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Quick sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 93096 comparisons
                Running the reverse sorted data
                Made 93096 comparisons
                Running the not sorted data
                Made 4424 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Insertion sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 431 comparisons
                Running the reverse sorted data
                Made 93096 comparisons
                Running the not sorted data
                Made 47209 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

Running the Large File:
        Merge sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 3728 comparisons
                Running the reverse sorted data
                Made 4048 comparisons
                Running the not sorted data
                Made 6707 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Quick sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 319600 comparisons
                Running the reverse sorted data
                Made 319600 comparisons
                Running the not sorted data
                Made 8990 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes

        Insertion sort:
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: No
                3. Random data is sorted: No
                Running the already sorted data
                Made 799 comparisons
                Running the reverse sorted data
                Made 319600 comparisons
                Running the not sorted data
                Made 164967 comparisons
                1. Pre-sorted data is sorted: Yes
                2. Reversed data is sorted: Yes
                3. Random data is sorted: Yes
```