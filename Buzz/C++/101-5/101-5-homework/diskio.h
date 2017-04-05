#ifndef DISKIO_H
#define DISKIO_H

#include <string>
#include <vector>
#include "types.h"

using namespace std;

vector<Product> LoadProducts(string filename);
void SaveProducts(vector<Product> inventory, string filename);

#endif