#include <iostream>
class Date {
private:
    int day;
    int month;
    int year;
public:
    //Constructor
    Date(int day, int month, int year){
        bool is_negative = false;
        bool is_success = true;
        if(day < 0 || month < 0 || year < 0){
            is_negative = true;
            is_success = false;
            std::cout << "Error: Day, Month and Year is must be in positive numbers." << std::endl;
        }
        if(is_negative == false){
           if(month > 0 and month <= 12){
                if(month == 2 || month == 4 || month == 6 || month == 9 || month == 11){
                    if(month == 2){
                        if(year % 4 == 0){
                            if(day > 29) {
                                is_success = false;
                                std::cout << "Error: "<< year << " is the leap the years. Days has only 29 days" << std::endl;
                            }
                        }else if (year % 4 != 0) {
                            if(day > 28) {
                                is_success = false;
                                std::cout << "Error: "<< year << " is the leap the years. Days has only 28 days" << std::endl;
                            }
                        }
                    }else {
                        if(day > 30) {
                            is_success = false;
                            std::cout << "Error: "<< month << " has only 30 days" << std::endl;
                        }
                    }
                }else {
                    if(day > 31) {
                        is_success = false;
                        std::cout << "Error: "<< month << " has only 31 days" << std::endl;
                    }
                };
            }else {
                is_success = false;
                std::cout << "Error: "<< "Month must be between 1 - 12." << std::endl;
            }
        }
        if(is_success == true){
            this->day = day;
            this->month = month;
            this->year = year;
        }else if(is_success == false){
            this->day = 0;
            this->month = 0;
            this->year = 0;
            std::cout << "Error: can't set date." << std::endl;
        }
    }
    // Getter and Setter
    int get_day(){
        return day;
    }
    int get_month() {
        return month;
    }
    int get_year() {
        return year;
    }
    //Method
    std::string date_to_string(){
        std::string date_str = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
        return date_str;
    }
    bool is_older_than(Date date){
        if(this->year < date.get_year()) return true;
        else if(this->year > date.get_year()) return false;
        
        if((this->year == date.get_year()) and (this->month < date.get_month())) return true;
        else if ((this->year == date.get_year()) and (this->month > date.get_month())) return false;

        if((this->year == date.get_year()) and (this->month == date.get_month()) and (this->day < date.get_day())) return true;
        return false;
    }
    bool is_same_age_as(Date date){
        if((this->year == date.get_year()) and (this->month == date.get_month()) and (this->day == date.get_day())) return true;
        return false;
    }
};
int main(){
    Date date1 = Date(30, 9, 2002);
    Date date2 = Date(30, 12, 2002);
    std::cout << "Date1: " << date1.date_to_string() << std::endl;
    std::cout << "Date2: " << date2.date_to_string() << std::endl;
    std::cout << std::boolalpha << "is_older_than: " << date1.is_older_than(date2) << std::endl;
    std::cout << std::boolalpha << "is_same_age: " << date1.is_same_age_as(date2) << std::endl;
    return 0;
}