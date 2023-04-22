#include "Set.h"
#include <iostream>

Set::Set(int minElement, int maxElement) {
	if (minElement > maxElement) {
		int temp = minElement;
		minElement = maxElement;
		maxElement = temp;
	}
	for (int i = minElement; i < maxElement; i++) {
		
	}
}