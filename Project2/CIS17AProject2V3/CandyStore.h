/* 
 * File:   CandyStore.h
 * Author: ajporter
 *
 * Created on December 18, 2022, 4:24 PM
 */

#ifndef CANDYSTORE_H
#define CANDYSTORE_H

#include <iostream>
#include <string>

using namespace std;

class Candyc {
    private:
        string namec;
        int pricec;
        static int countc;
    public:
        Candyc(string name, int price) : namec(name), pricec(price) {
            countc++;
        }

        Candyc(const Candyc &other) : namec(other.namec), pricec(other.pricec) {
            countc++;
        }

        ~Candyc() {
            countc--;
        }

        string getName() const {
            return namec;
        }

        int getPrice() const {
            return pricec;
        }

        static int getCount() {
            return countc;
        }

        friend ostream& operator<<(ostream& out, const Candyc& candy) {
            out << candy.namec << " - $" << candy.pricec;
            return out;
        }
};

int Candyc::countc = 0;

#endif /* CANDYSTORE_H */
