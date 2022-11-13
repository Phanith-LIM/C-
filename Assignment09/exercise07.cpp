#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
class Score {
private:
  double math_score;
  double phy_score;
  double chem_score;
public:
  Score(double math_score, double phy_score, double chem_score){
    if(math_score < 0 or phy_score < 0 or chem_score < 0){
      this->math_score = 0;
      this->phy_score = 0;
      this->chem_score = 0;
      std::cout << "Score must be positive number." << std::endl;
    }else{
      this->math_score = math_score;
      this->phy_score = phy_score;
      this->chem_score = chem_score;
    }
  }
  Score(){};
  //Getter and Setter
  double getMath() {
    return math_score;
  }
  double getChem() {
    return chem_score;
  }
  double getPhy() {
    return phy_score;
  }
  void setMath(double score){
    if(score < 0) {
      std::cout << "Score must be positive number." << std::endl;
      this->math_score = 0;
    }else this->math_score = score;
  }
  void setChem(double score){
     if(score < 0) {
      std::cout << "Score must be positive number." << std::endl;
      this->chem_score = 0;
    }else this->chem_score = score;
  }
  void setPhy(double score){
    if(score < 0) {
      std::cout << "Score must be positive number." << std::endl;
      this->phy_score = 0;
    }else this->phy_score = score;
  }
  //Method
  double get_total_score(){
    return math_score + phy_score + chem_score;
  }
  void get_score(){
    do{
      std::cout << "Maths: ";
      std::cin >> math_score;
      fflush(stdin);
    }while (math_score < 0);
    do{
      std::cout << "Physics: ";
      std::cin >> phy_score;
      fflush(stdin);
    }while (phy_score < 0);
    do{
      std::cout << "Chemistry: ";
      std::cin >> chem_score;
      fflush(stdin);
    }while (chem_score < 0);    
  }
};
class Student {
private:
  int id;
  std::string name;
  Score score;
public:
  Student(int id, std::string name, Score score){
    this->id = id;
    this->name = name;
    this->score = score;
  }
  Student(){};
  void display_info(){
    std::cout << std::setw(10) << std::left << id <<
    std::setw(20) << std::left << name <<
    std::setw(15) << std::left << score.getMath() << 
    std::setw(15) << std::left << score.getPhy() << 
    std::setw(15) << std::left << score.getChem() <<
    std::setw(15) << std::left << score.get_total_score() <<
    std::endl;
  }
  void read_student(int id){
    this->id = id;
    fflush(stdin);
    std::cout << "Name: ";
    getline(std::cin, name);
    score.get_score();
    fflush(stdin);
  }
  int getID(){
    return id;
  }
};
class StudentList {
private:
  std::vector<Student> student_list;
public:
  StudentList(std::vector<Student> student_list){
    this->student_list = student_list;
  }
  void display_all(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(10) << std::left << "ID" << 
    std::setw(20) << std::left << "Name" << 
    std::setw(15) << std::left << "Maths" <<
    std::setw(15) << std::left << "Physics" <<
    std::setw(15) << std::left << "Chemistry" <<
    std::setw(15) << std::left << "Total" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < student_list.size(); i++){
      student_list[i].display_info();
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
  }
  void add(){
    bool is_not_found = false;
    int id;
    Student student;
    do{
      is_not_found = true;
      std::cout << "ID: ";
      std::cin >> id;
      fflush(stdin);
      for(int i = 0; i < student_list.size(); i++){
        if(student_list[i].getID() == id){
          is_not_found = false;
        }
      }
      if(is_not_found == false) std::cout << "ID already exist." << std::endl;
    }while(!is_not_found);
    student.read_student(id);
    student_list.push_back(student);
    std::cout << "Add Successfully..." << std::endl;
  }
  void remove(){
    bool is_found = false;
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    fflush(stdin);
    for(int i = 0; i < student_list.size(); i++){
      if(student_list[i].getID() == id){
        is_found = true;
        student_list.erase(student_list.begin() + i);
        i--;
      }
    }
    is_found == true ? std::cout << "Delete Successful.." << std::endl : std::cout << "ID no exist: " << id << std::endl << "Delete Unsuccessful.." << std::endl;
  }
  int index_of(int id){
    for(int i = 0; i < student_list.size(); i++){
      if(student_list[i].getID() == id) return i;
    }
    return -1;
  }
  void search(){
    bool is_found = false;
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(10) << std::left << "ID" << 
    std::setw(20) << std::left << "Name" << 
    std::setw(15) << std::left << "Maths" <<
    std::setw(15) << std::left << "Physics" <<
    std::setw(15) << std::left << "Chemistry" <<
    std::setw(15) << std::left << "Total" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < student_list.size(); i++){
      if(student_list[i].getID() == id) {
        is_found = true;
        student_list[i].display_info();
      };
    }
    if(is_found == false) std::cout << "Search Not Found." << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
  }
};
int main(){
  StudentList list = StudentList({
    Student(301, "Iron Man", Score(10,10,10)),
    Student(302, "Dr.Strange", Score(11,11,11)),
    Student(303, "Spider Man", Score(13,12,12)),
    Student(304, "Black Panther",Score(14,14,14)),
  });
  list.display_all();
  char option;
  do{
    std::cout << "a. Add a new student." << std::endl;
    std::cout << "b. Delete student by id." << std::endl;
    std::cout << "c. Display all student." << std::endl;
    std::cout << "d. Search by id." << std::endl;
    std::cout << "e. Exit program" << std::endl;
    std::cout << "OPTION: ";
    std::cin >> option;
    if(option == 'a') list.add();
    if(option == 'b') list.remove();
    if(option == 'c') list.display_all();
    if(option == 'd') list.search();
  }while(option == 'a' or option == 'b' or option == 'c' or option == 'd');
  return 0;
}