// #include <iostream>

// bool isLeapYear(int year) {
    
//     if (year % 4 == 0) {
        
//         if (year % 100 != 0 || year % 400 == 0) {
//             return true; 
//         }
//     }
//     return false; 
// }

// int main() {
//     int thYear, adYear;

//     // input
//     std::cout << "Input TH year: ";
//     std::cin >> thYear;

//     // change year
//     adYear = thYear - 543;

//     //  check_leap year 
//     if (isLeapYear(adYear)) {
//         std::cout << adYear << " is a leap year" << std::endl;
//     } else {
//         std::cout << adYear << " is not a leap year" << std::endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <chrono>
// #include <ctime>
// #include <iomanip>

// int main() {
    
//     auto now = std::chrono::system_clock::now();
//     std::time_t th_time = std::chrono::system_clock::to_time_t(now);
//     std::tm th_tm = *std::localtime(&th_time);
//     th_tm.tm_hour += 7; 
//     std::mktime(&th_tm); 

    
//     std::cout << "In TH: " << std::put_time(&th_tm, "%Y-%m-%d %H:%M:%S") << std::endl;

    
//     now = std::chrono::system_clock::now();
//     std::time_t ca_time = std::chrono::system_clock::to_time_t(now);
//     std::tm ca_tm = *std::localtime(&ca_time);
//     ca_tm.tm_hour -= 7; 
//     std::mktime(&ca_tm); 

   
//     std::cout << "In CA: " << std::put_time(&ca_tm, "%Y-%m-%d %H:%M:%S") << std::endl;

//     return 0;
// }






#include <iostream>
#include <conio.h>
#include <ctime>

#define UTC (+7)

using namespace std;

int main()
{
	time_t curr_time; //Ex. Jan 01, 2023 (Long value)
	tm * curr_tm; //Separated by time structure (tm)

	char date_string[100];
	char time_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, sizeof(date_string), "Thailand date is %A, %d %B %Y", curr_tm);
	strftime(time_string, sizeof(time_string), "Thailand time is %H:%M:%S", curr_tm);
	
	cout << date_string << endl;
	cout << time_string << endl;
    cout << curr_tm->tm_hour << endl;
    
    
    time_t rawtime;
    struct tm * ptm;

    time(&rawtime);
    ptm = gmtime(&rawtime);
    if(curr_tm->tm_hour<13){
        ptm->tm_mday=ptm->tm_mday-1;
        // cout << "if" << endl;
        ptm->tm_hour = 24 + (ptm->tm_hour - 13);
    }
    else{    
        ptm->tm_hour=ptm->tm_hour-13;
        //  cout << "else" << endl;
        
    }
    puts ("Current time around the World:");
    char str_date[256];
    strftime(str_date, sizeof(str_date), "%A, %d %B %Y", ptm);
    printf("Canada Date: %s\n", str_date);
    printf (" Canada Time:  %2d:%02d:%02d\n", (ptm->tm_hour+UTC)%24, ptm->tm_min, ptm->tm_sec);
    
    return 0;
}



