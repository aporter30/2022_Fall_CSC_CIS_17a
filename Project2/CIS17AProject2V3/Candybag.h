/* 
 * File:   Candybag.h
 * Author: ajporter
 *
 * Created on December 18, 2022, 2:50 PM
 */

#ifndef CANDYBAG_H
#define CANDYBAG_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Candy is a class for different types of candies
template <typename T>
class Candyb {
    public:
        Candyb(T flavorb) : flavor_b(flavorb) {}
        T getFlavor() const { return flavor_b; }
    private:
        T flavor_b;
};

// CandyBag is a class for a bag of candies
template <typename T>
class CandyBag {
    public:
        CandyBag() {}
        // Function to add a candy to the bag
        void addCandy(const Candyb<T>& candy) {
            candies_.push_back(candy);
        }
        // Function to get the flavor of the candy at a specific index
        T getCandyFlavor(int index) const {
            // Use the STL function "at" to access the element at a specific index
            // and throw an out_of_range exception if the index is invalid
            return candies_.at(index).getFlavor();
        }
    private:
        vector<Candyb<T> > candies_;
};

#endif /* CANDYBAG_H */
