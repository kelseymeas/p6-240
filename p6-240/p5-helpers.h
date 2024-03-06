#ifndef P5_HELPERS_H  
#define P5_HELPERS_H

#include "p6-helpers.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>

// ------------------------------------------
// |            -- Variables --            |  
// ------------------------------------------ 
std::vector<void(*)()> functions = {
    asm_Area_Perimeter,
    asm_Quadratic_Formula_Add,
    asm_Quadratic_Formula_Sub,
    asm_Convenient_Store
};

std::vector<std::string> functionNames = {
    "1. Area & Perimeter",
    "2. Quadratic Formula +",
    "3. Quadratic Formula -",
    "4. Convenient Store"
};

// ------------------------------------------ 
// ------------------------------------------ 



// ------------------------------------------
// |       -- Project Functions --         |
// ------------------------------------------
void selectAndExecuteFunction() {
    int choice;
    std::cout << "Please select a function to execute by its number:\n";
    
    // Display function names
    for (const auto& name : functionNames) {
        std::cout << name << std::endl;
    }

    std::cin >> choice;
    
    // Adjust choice to match vector indexing (starts from 0)
    choice -= 1;

    if (choice >= 0 && choice < functions.size()) {
        functions[choice](); // Call the selected function
    } else {
        std::cout << "Invalid selection. Please select a valid function number.\n";
    }
}
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |        -- Helper Functions --          |
// ------------------------------------------

// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Project Func Def's --        |
// ------------------------------------------

// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |         -- Helper Func Def's --        |
// ------------------------------------------


    return ((_b * _b) - (4 * _a * _c)) < 0;

}
// ------------------------------------------ 
// ------------------------------------------ 


#endif 
