#include <iostream>
#include <vector>
#include <iomanip>
class Score {
private:
  double math_score;
  double phy_score;
  double chem_score;
public:
  Score(double math_score, double phy_score, double chem_score){
    this->math_score = math_score;
    this->phy_score = phy_score;
    this->chem_score = chem_score;
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
    this->math_score = score;
  }
  void setChem(double score){
    this->chem_score = score;
  }
  void setPhy(double score){
    this->phy_score = score;
  }
  double get_total_score(){
    return math_score + phy_score + chem_score;
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
  void display_info(){
    std::cout << std::setw(10) << std::left << id <<
    std::setw(20) << std::left << name <<
    std::setw(15) << std::left << score.getMath() << 
    std::setw(15) << std::left << score.getPhy() << 
    std::setw(15) << std::left << score.getChem() <<
    std::setw(15) << std::left << score.get_total_score() <<
    std::endl;
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
  void add(Student student){
    student_list.push_back(student);
  }
  void remove(int id){
    bool is_found = false;
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
      if(student_list[i].getID() == id){
        return i;
      }
    }
    return -1;
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
  std::cout << "index_of: " << list.index_of(303) << std::endl;
  return 0;
}