#include <iostream>
#include <cstring>
class String {
private:
    std::string value;
public:
    String(std::string value) {
        this->value = value;
    };
    int index_of(char my_char){
        for(int i = 0; i < value.length(); ++i){  
            if(value[i] == my_char) return i;
        }
        return -1;
    }
    int count_char(char my_char){
        int count = 0;
        for(int i = 0; i < value.length(); ++i){  
            if(value[i] == my_char){
                count++;
            }
        }
        return count;
    }
    std::string upper(){
        std::string sub_value = value;
        for(int i = 0; i < value.length(); ++i){  
           sub_value[i] = toupper(sub_value[i]);
        }
        return sub_value;
    }
    std::string remove_char(char my_char){
        std::string sub_value;
        for(int i = 0; i < value.length(); ++i){  
            if(value[i] == my_char) continue;
            sub_value += value[i];
        }
        return sub_value;
    }
    std::string reverse(){
        std::string sub_value;
        for(int i = value.length(); i >= 0; i--){
            sub_value += value[i];
        }
        return sub_value;
    }
};
int main(){
    String my_string = String("Forever");
    std::cout << "index_of: " << my_string.index_of('e') << std::endl;
    std::cout << "cout_char: " << my_string.count_char('e') << std::endl;
    std::cout << "upper: " << my_string.upper() << std::endl;
    std::cout << "remove_char: " << my_string.remove_char('v') << std::endl;
    std::cout << "reverse: " << my_string.reverse() << std::endl;
    return 0;
}