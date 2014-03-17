// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-10 00:34:33
// status:	0
// result:	15
// memory:	3028
// signal:	0
// public:	false
// ------------------------------------------------
/////////////////////////////////////
// timepoint classes (booking.hpp)

struct timepoint
{
    int hour, minute;

    timepoint normalized()                     const; 
    int totalMinutes    ()                     const; 
    int roundedHours    ()                     const; 
    timepoint operator- (timepoint const& rhs) const; 
};

struct booking_t
{
    char vehicle;
    timepoint enter, exit;

    timepoint parked() const { return exit - enter; }
};

/////////////////////////////////////
// main program (main.cpp)
booking_t inputData();
void displayBill(booking_t const& booking);

int main(void)
{
    auto booking = inputData();
    displayBill(booking);
}

/////////////////////////////////////
// timepoint methods (booking.cpp)

timepoint timepoint::normalized() const
{
    timepoint tmp { (hour + minute/60) % 24, minute % 60 };
    while (tmp.minute < 0) tmp.hour--, tmp.minute+=60;
    while (tmp.hour   < 0) tmp.hour+=24;
    return tmp;
}

int timepoint::roundedHours() const
{
    return (totalMinutes()-1) / 60 + 1; // TODO check rounding logic
}

int timepoint::totalMinutes() const
{
    return hour*60 + minute;
}

timepoint timepoint::operator-(timepoint const& rhs) const
{
    return timepoint { 0, totalMinutes() - rhs.totalMinutes() } .normalized();
}

#include <iostream>   //used for cout/cin

timepoint getTime(std::string label)
{
    int hour, minute;
    std::cout  << "\nHour "   << label << " 0-24: ";
    std::cin >> hour;
    std::cout  << "\nMinute " << label << " 0-60: ";
    std::cin >> minute;
    return { hour, minute };
}

/////////////////////////////////////
// global functions - input
booking_t inputData()
{
    std::cout << "Enter C for car, B for bus, T for truck: ";
    char v;
    std::cin >> v;
    auto entered = getTime("vehicle entered");
    auto exited  = getTime("vehicle exited");
    return { v, entered.normalized(), exited.normalized() };
}

/////////////////////////////////////
// calculation + billing
#include <sstream>
#include <iomanip>   //used to manipulate data 
#include <map>

static std::ostream& operator <<(std::ostream& os, timepoint const& tp)
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << tp.hour << ':' 
        << std::setw(2) << std::setfill('0') << tp.minute;
    return os << oss.str();
}

std::pair<float,float> charge(booking_t const& booking)
{
    struct tariff_t { int threshold; float rate1, rate2; };
    const static auto tariffs = std::map<char, tariff_t> {
        { 'c', { 3, 0   , 1.25 } },
        { 'b', { 2, 2.  , 2.5  } },
        { 't', { 1, 3.75, 4.5 } } ,
    };

    auto& tariff = tariffs.at(std::tolower(booking.vehicle));
    auto  parked = booking.parked().roundedHours();

    return std::make_pair(
            tariff.rate1 * std::min(tariff.threshold, parked)    ,
            tariff.rate2 * std::max(0, parked - tariff.threshold));
}

void displayBill(booking_t const& booking)
{
    std::cout << "\n\n    PARKING LOT CHARGE\n";
    std::cout << "Type of vehicle: Car or Bus or Truck\n";
    std::cout << "TIME-IN         " << booking.enter << "\n";
    std::cout << "TIME-OUT        " << booking.exit  << "\n";
    std::cout << "                " << "--------\n";
    std::cout << "PARKING TIME    " << booking.parked() << "\n";
    std::cout << "        ROUNDED " << booking.parked().roundedHours() << "\n";
    std::cout << "                " << "--------\n";

    auto  rates = charge(booking);
    float total = rates.first + rates.second;
    std::cout << "TOTAL CHARGE    " << std::fixed << std::setw(7) << std::setprecision(2) << total << "\n\n";
}

// ------------------------------------------------
#if 0 // stdin
c 23 55 4 56
#endif
#if 0 // stdout
Enter C for car, B for bus, T for truck: 
Hour vehicle entered 0-24: 
Minute vehicle entered 0-60: 
Hour vehicle exited 0-24: 
Minute vehicle exited 0-60: 

    PARKING LOT CHARGE
Type of vehicle: Car or Bus or Truck
TIME-IN         23:55
TIME-OUT        04:56
                --------
PARKING TIME    05:01
        ROUNDED 6
                --------
TOTAL CHARGE       3.75


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
