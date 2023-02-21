// bill.cpp

#include "bill.h"


Bill::Bill(){
    this->id = -1;
    this->tegund = "";
    this->litur = "";
}

Bill::Bill(int id){
    this->id = id;
    this->tegund = "";
    this->litur = "";
}

Bill::Bill(int id, std::string tegund, std::string litur){
    this->id = id;
    this->tegund = tegund;
    this->litur = litur;
}

int Bill::getID(){
    return this->id;
}

void Bill::setID(int id){
    this->id = id;
}

std::string Bill::getTegund(){
    return this->tegund;
}

void Bill::setTegund(std::string tegund){
    this->tegund = tegund;
}

std::string Bill::getLitur(){
    return this->litur;
}

void Bill::setLitur(std::string litur){
    this->litur = litur;
}

void Bill::prenta(){
    std::cout << "ID: " << this->id << ", tegund: " << this->tegund << ", litur: " << this->litur << "\n";
}

std::string Bill::toString(){
    return "ID: " + std::to_string(this->id) + 
    ", tegund: " + this->tegund + 
    ", litur: " + this->litur;
}

bool Bill::operator==(Bill &hinn) {
    return this->tegund == hinn.getTegund() &&
        this->litur == hinn.getLitur();
}
bool Bill::operator!=(Bill &hinn) {
    return !(*this == hinn);
}
bool Bill::operator<(Bill &hinn) {
    if (this->tegund == hinn.getTegund()) {
        if (this->litur == hinn.getLitur()) {
            return this->id < hinn.getID();
        }
        else {
            return this->litur < hinn.getLitur();
        }
    }
    else {
        return this->tegund < hinn.getTegund();
    }
}
bool Bill::operator>(Bill &hinn) {
    return hinn < *this;
}
bool Bill::operator<=(Bill &hinn) {
    return !(*this > hinn);
}
bool Bill::operator>=(Bill &hinn) {
    return !(*this < hinn);
}

std::ostream& operator<<(std::ostream& ostr, Bill& b) {
    // return ostr << b.toString();
    return ostr << "ID: " << b.getID() << 
        ", tegund: " << b.getTegund() << 
        ", litur: " << b.getLitur();
}