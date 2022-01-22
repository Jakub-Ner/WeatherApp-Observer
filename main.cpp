#include <bits//stdc++.h>
#include "code/app/Menu.h"
#include "shit.h"
#include "code/locations/locations/Wroclaw.h"
#include <memory>


void note(){
    Wroclaw wroclaw = Wroclaw("Wroclaw");
    std::cout<<"\n";
    wroclaw.get_measurement().display_measurement();
    std::cout<<"\n";
    wroclaw.get_measurement().display_measurement();

}
void note2(){
    std::optional<float> t;
    t = 20;
    t.value()+= 15 + t.value()*0.1;
    std::cout<<t.value();
}

int main() {
//    Menu().menu();
//    shit();
    note();
//note2();
    return 0;

}
