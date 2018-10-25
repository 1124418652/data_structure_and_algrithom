#pragma once
#include <iostream>
#include "SqList.h"
#include "stack.h"

using namespace std;

int partition(SqList<int> &list, int low, int high);
void quickSort(SqList<int> &list, int low, int high);