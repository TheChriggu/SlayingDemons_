//
// Created by christian.heusser on 07.01.2020.
//

#include "NavigationWord.h"

sd::NavigationWord::NavigationWord() {

}

sd::NavigationWord::~NavigationWord() {

}

sd::Word::type sd::NavigationWord::GetType() {
    return navigation;
}

void sd::NavigationWord::SetName(std::string _name) {
    name = _name;
}

std::string sd::NavigationWord::GetName() {
    return name;
}


