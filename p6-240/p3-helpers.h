#ifndef P3_HELPERS_H  
#define P3_HELPERS_H

#include <iostream>
#include <vector>

using std::cout; 
using std::cin;
using std::endl;

// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
	short _a, _b, _c, _d, _e, _f;
	short valY, valX;
	std::vector<short> avgs;
	short top, _four = 4, seventy = 70;
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Project Functions --         |
// ------------------------------------------
	void asm_Math_Averages();
	void asm_Math_Expressions();
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |        -- Helper Functions --          |
// ------------------------------------------
	void getAverages();
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Project Func Def's --        |
// ------------------------------------------
	void asm_Math_Averages() {
		//getAverages();

		__asm {
			mov ax, seventy;
			add ax, 88;
			add ax, 90;
			add ax, 77;
			cwd;
			idiv _four;

			mov top, ax;
		}
		cout << top;
	}

	void asm_Math_Expressions() {
		std::cout << "Enter values for a-f :";
		std::cin >> _a >> _b >> _c >> _d >> _e >> _f;

		__asm {
			mov ax, _a;
			imul ax, _f;
			mov bx, _c;
			imul bx, _d;
			sub ax, bx;

			mov bx, _a;
			imul bx, _e;
			mov cx, _b;
			imul cx, _d;
			sub bx, cx;

			cwd;
			idiv bx;
			mov valY, ax;

			mov ax, _c;
			imul ax, _e;
			mov bx, _b;
			imul bx, _f;
			sub ax, bx;

			mov bx, _a;
			imul bx, _e;
			mov cx, _b;
			imul cx, _d;
			sub bx, cx;

			cwd;
			idiv bx;
			mov valX, ax;

		}
		cout << "Value of 'x' is: " << valX << endl;
		cout << "Value of 'y' is: " << valY << endl;
	}
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |         -- Helper Func Def's --        |
// ------------------------------------------
	void getAverages() {
		int val = 0;
		while (val != -1) {
			cout << "Enter values: ";
			cin >> val;
			avgs.push_back(val);
		}
	}
// ------------------------------------------ 
// ------------------------------------------ 
#endif 