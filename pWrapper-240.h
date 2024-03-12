#ifndef PWRAPPER_240_H  
#define PWRAPPER_240_H  

#include <iostream>
#include <string>
#include <vector>

//Projects shown in program
#include "p5-helpers.h"
#include "p6-helpers.h"


// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
std::vector<void(*)()>   functions = {
    // Project 6
    asm_Area_Perimeter,
    asm_Quadratic_Formula_Add,
    asm_Quadratic_Formula_Sub,
    asm_Convenient_Store,
    asm_2d_array_sum,
    asm_sort_array,
    asm_3d_array_sum,
};

std::vector<std::string> functionNames = {
    "1. Area & Perimeter",
    "2. Quadratic Formula +",
    "3. Quadratic Formula -",
    "4. Convenience Store Receipt",
    "5. Sum of 2D Array",
    "6. Sum of 3D Array",
    "7. Bubble Sort",
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
    }
    else {
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

// ------------------------------------------ 
// ------------------------------------------ 


#endif 
