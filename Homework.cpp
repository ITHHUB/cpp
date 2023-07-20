#include <iostream>

bool isLeapYear(int year) {
    
    if (year % 4 == 0) {
        
        if (year % 100 != 0 || year % 400 == 0) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int thYear, adYear;

    // input
    std::cout << "Input TH year: ";
    std::cin >> thYear;

    // change year
    adYear = thYear - 543;

    //  check_leap year 
    if (isLeapYear(adYear)) {
        std::cout << adYear << " is a leap year" << std::endl;
    } else {
        std::cout << adYear << " is not a leap year" << std::endl;
    }

    return 0;
}