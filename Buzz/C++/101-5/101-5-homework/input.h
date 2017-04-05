#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>
#include "types.h"

using namespace std;

int GetInt();
int GetInt(string prompt);
double GetDouble();
double GetDouble(string prompt);
string GetString();
string GetString(string prompt);
MenuState GetMenuSelection(double mymoney);
Product CreateProduct();
int GetVectorPosition();
double BuyProduct(vector<Product> products, int vectorpos, double mymoney);

#endif
