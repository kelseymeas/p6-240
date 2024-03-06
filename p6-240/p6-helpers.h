#ifndef P6_HELPERS_H  
#define P6_HELPERS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
float A, B, C, l, w, h;                      // Q1 -- Input Var's    
float perT, perR, arT, arR;                  // Q1 -- Calculations

float a, b, c, sqrVal;                       // Q2 -- Formula Var's
float negOne = -1, two = 2, four = 4, x = 0; // Q2 -- Constants

float bill, bill2, finalBill;                // Q3 -- Sum Var's
float drink, sand, drinkp = 1, sandp = 1;    // Q3 -- Items
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Assembly Functions --         |
// ------------------------------------------
void asm_Area_Perimeter();                   // Q1
void asm_Quadratic_Formula_Add();            // Q2 
void asm_Quadratic_Formula_Sub();            // Q2 
void asm_Convenient_Store();                 // Q3
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |         -- Helper Functions --         |
// ------------------------------------------
void getVars();                              // Q2
void getOutp();                              // Q2
void fixVars();                              // Q2
bool isNeg(float&, float&, float&);          // Q2
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Assembly Func Def's --        |
// ------------------------------------------
void asm_Area_Perimeter() {

    std::cout << std::setfill('-') << std::setw(8) << '-' << "Perimeter & Area"
        << std::setfill('-') << std::setw(8) << '-' << std::endl;

    std::cout << "Please enter side lengths of your Triangle" << std::endl;
    std::cin >> A;
    std::cin >> B;
    std::cout << "Please enter base and height of your Triangle" << std::endl;
    std::cin >> C;
    std::cin >> h;
    std::cout << "Please enter Length and Width of your Rectangle" << std::endl;
    std::cin >> l;
    std::cin >> w;

    __asm {
        // Perimeter for Triangle
        fld A;      //   st[0] = A  
        fld B;      //   st[0] = B     //   st[1] = A    
        fld C;      //   st[0] = C     //   st[1] = B   //   st[2] = A   
        fadd;       //   st[0] = B+C   //   st[1] = B   
        fadd;       //   st[0] = A+B+C   
        fstp perT;  //   perT  = A+B+C


        // Area For Triangle
        fld C;      //   st[0] = C
        fld h;      //   st[0] = h     //   st[1] = C
        fmul;       //   st[0] = C*h
        fld two;    //   st[0] = 2     //   st[1] = C*h
        fdiv;       //   st[0] = (C*h) / (2)
        fstp arT;   //   arT   = (C*h) / (2)


        // Perimeter For Rectangle
        fld l;      //   st[0] = l     
        fld w;      //   st[0] = w     //   st[1] = l
        fadd;       //   st[0] = l+w     
        fld two;       //   st[0] = 2     //   st[1] = l+w
        fmul;       //   st[0] = (l+w) * (2)
        fstp perR;  //   perR  = (l+w) * (2)

        //Area for Rectangle
        fld l;      //   st[0] = l     
        fld w;      //   st[0] = w     //   st[1] = l
        fmul;       //   st[0] = l*w    
        fstp arR;   //   arR   = l*w
    }

    std::cout << std::setfill('-') << std::setw(3) << '-' << "Triangle" << std::setfill('-') << std::setw(3) << '-' << std::endl;
    std::cout << "Area of The Triangle: \n" << arT << std::endl;
    std::cout << "Perimeter of The Triangle: \n" << perT << std::endl << std::endl;
    std::cout << std::setfill('-') << std::setw(3) << '-' << "Rectangle" << std::setfill('-') << std::setw(3) << '-' << std::endl;
    std::cout << "Area of The Rectangle: \n" << arR << std::endl;
    std::cout << "Perimeter of The Rectangle: \n" << perR << std::endl << std::endl << std::endl << std::endl;

}

void asm_Quadratic_Formula_Add() {
    // Call 'getVars()' to init variables
    getVars();

    // Process variables using Assembly
    __asm {
        fld b;      //   st[0] = b
        fld negOne; //   st[0] = -1  //   st[1] = b
        fmul;       //   st[0] = -b

        fld b;      //   st[0] = b   //   st[1] = -b
        fld b;      //   st[0] = b   //   st[1] = b     //   st[2] = -b
        fmul;       //   st[0] = b^2 //   st[1] = -b

        fld four;   //   st[0] = 4   //   st[1] = b^2   //   st[2] = -b
        fld a;      //   st[0] = a   //   st[1] = 4     //   st[2] = b^2   //   st[3] = -b
        fmul;       //   st[0] = 4a  //   st[1] = b^2   //   st[2] = -b

        fld c;      //   st[0] = c   //   st[1] = 4a    //   st[2] = b^2   //   st[3] = -b
        fmul;       //   st[0] = 4ac //   st[1] = b^2   //   st[2] = -b

        fsub;       //   st[0] =     //   st[1] = -b
        //    (b^2 - 4ac)

        cmp sqrVal, 0;
        Jl error_neg;

        fsqrt;      //   st[0] =     //   st[1] = -b
        fadd;       //   st[0] =     //   st[1] = -b
        //    (-b + sqrt( b^2 - 4ac ))

        fld a;
        fld two;
        fmul;       // st[0] = 2a

        fdiv;       // st[0] = (-b + sqrt( b^2 - 4ac )) / (2a)
        fstp x;

    error_neg:
        call fixVars;
    }

    // Output solution & Exit
    getOutp();
    std::exit(EXIT_SUCCESS);
}

void asm_Quadratic_Formula_Sub() {
    // Call 'getVars()' to init variables
    getVars();

    // Process variables using Assembly
    __asm {
        fld b;      //   st[0] = b
        fld negOne; //   st[0] = -1  //   st[1] = b
        fmul;       //   st[0] = -b

        fld b;      //   st[0] = b   //   st[1] = -b
        fld b;      //   st[0] = b   //   st[1] = b     //   st[2] = -b
        fmul;       //   st[0] = b^2 //   st[1] = -b

        fld four;   //   st[0] = 4   //   st[1] = b^2   //   st[2] = -b
        fld a;      //   st[0] = a   //   st[1] = 4     //   st[2] = b^2   //   st[3] = -b
        fmul;       //   st[0] = 4a  //   st[1] = b^2   //   st[2] = -b

        fld c;      //   st[0] = c   //   st[1] = 4a    //   st[2] = b^2   //   st[3] = -b
        fmul;       //   st[0] = 4ac //   st[1] = b^2   //   st[2] = -b

        fsub;       //   st[0] =     //   st[1] = -b
        //    (b^2 - 4ac)

        cmp sqrVal, 0;
        Jl error_neg;

        fsqrt;      //   st[0] = sqrt( b^2 - 4ac )      //   st[1] = -b
        fsub;       //   st[0] = (-b - sqrt( b^2 - 4ac )) 

        fld a;      //   st[0] = a   //   st[1] = (-b - sqrt( b^2 - 4ac ))    
        fld two;    //   st[0] = 2   //   st[1] = a    //   st[2] = (-b - sqrt( b^2 - 4ac ))
        fmul;       //   st[0] = 2a  //   st[1] = (-b - sqrt( b^2 - 4ac ))
        fdiv;       //   st[0] = (-b - sqrt( b^2 - 4ac )) / (2a)

        fstp x;     //   x = (-b - sqrt( b^2 - 4ac )) / (2a)

    error_neg:
        call fixVars;
    }

    // Output solution & Exit
    getOutp();
    std::exit(EXIT_SUCCESS);
}

void asm_Convenient_Store() {

    std::cout << std::setfill('-') << std::setw(8) << '-' << "MENU" << std::setfill('-') << std::setw(8) << '-' << std::endl;
    std::cout << "Drinks" << std::setfill('.') << std::setw(7) << '.' << drinkp << std::endl;
    std::cout << "Sandwiches" << std::setfill('.') << std::setw(7) << '.' << sandp << std::endl;
    std::cout << "How Many Drinks? ";
    std::cin >> drink;
    std::cout << "How Many Sandwiches? ";
    std::cin >> sand;

    __asm {
        fld drinkp;
        fld drink;
        fmul;
        fstp bill;

        fld sandp;
        fld sand;
        fmul;
        fstp bill2;

        fld bill;
        fld bill2;
        fadd;
        fstp finalBill;
    }

    std::cout << "Your Total Today Is: $"
        << finalBill << std::endl << std::endl << std::endl << std::endl;
}
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |         -- Helper Func Def's --        |
// ------------------------------------------
void getVars() {
    std::cout << "Please provide values for variables 'a', 'b', and 'c' below.\n"
              << "\nEnter value for 'a': ";
    std::cin >> a;
    std::cout << "\nEnter value for 'b': ";
    std::cin >> b;
    std::cout << "\nEnter value for 'c': ";
    std::cin >> c;

    sqrVal = (b * b) - (4 * a * c);

    return;
}

void getOutp() {
    std::cout << "\nYour quadratic value is: " << x << '\n';
}

void fixVars() {
    while (isNeg(a, b, c)) {
        std::string quitP = "";

        std::cout << "[Error] -- Negative Squareroot Value\n"
            << "Would you like to try new values? (y/n): ";
        std::cin >> quitP;


        if ((quitP.length() == 1) && (quitP[0] == 'n' || quitP[0] == 'N')) {

            // Exit Program 
            std::cout << "Program Successfully Exited";
            std::exit(EXIT_SUCCESS);
        }
        else {

            asm_Quadratic_Formula_Add();
        }
    }
}

bool isNeg(float& _a, float& _b, float& _c) {

    return ((_b * _b) - (4 * _a * _c)) < 0;

}
// ------------------------------------------ 
// ------------------------------------------ 


#endif 
