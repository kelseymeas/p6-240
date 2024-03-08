#ifndef P5_HELPERS_H  
#define P5_HELPERS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>

// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
	int sumAll, sumMed, sumBlue, sumShort, 
		sumRed, ind, count;

	int arr1[4][4] = {{10, 20, 30, 40},  //Red
					 {20, 10, 40, 30},  //Green
					 {5 , 15, 20, 25},  //Blue
					 {30, 25, 20, 15}}; //Black				

	int arr2[5] = {9,3,22,8,1};
	
	int arr3[3][3][2] = {{{1 ,  2}, {3 ,  4}, {5 ,  6}},
						 {{7 ,  8}, {9 , 10}, {11, 12}},
						 {{13, 14}, {15, 16}, {17, 18}}};
// ------------------------------------------ 
// ------------------------------------------ 
/////////////////////////////////////////////
// ------------------------------------------
// |       -- Project Functions --         |
// ------------------------------------------
	void asm_2d_array_sum() {
		__asm {
			mov eax, 0;
			mov ebx, 0;
			mov ecx, 0;
			mov ind, 0;
			lea esi, [arr1];

		forLoop1: // calc sum of all shirts
			cmp ind, 16;
			Je exit1;
			add eax, [esi];
			inc ind;
			add esi, 4;
			Jmp forLoop1;

		forLoop2: // calc sum of medium shirts
			cmp ind, 4;
			Je exit2;
			add ebx, [esi];
			inc ind;
			add esi, 16;
			Jmp forLoop2;
		
		forLoop3: // calc sum of blue shirts
			cmp ind, 4;
			Je exit3;
			add ecx, [esi];
			inc ind;
			add esi, 4;
			Jmp forLoop3;

		exit1:
			mov sumAll, eax;
			mov ind, 0;
			lea esi, [arr1];
			add esi, 4;
			Jmp forLoop2;
		
		exit2:
			mov sumMed, ebx;
			mov ind, 0;
			lea esi, [arr1];
			add esi, 32;
			Jmp forLoop3

		exit3:
			mov sumBlue, ecx;
		}

		std::cout << "Sum of array is: "         << sumAll << std::endl;
		std::cout << "Sum of medium shirts is: " << sumMed << std::endl;
		std::cout << "Sum of blue shirts is: "   << sumBlue << std::endl;
	}

	void asm_sort_array() {
		std::cout << "Original Array: ";
		for (auto each : arr2) {
			std::cout << each << " ";
		}
		std::cout << std::endl;

		__asm {
			lea esi, [arr2];
			mov eax, [esi];
			mov ebx, 0;
			mov ind, 0;

		forLoop:
			cmp ind, 4;
			Je exit1;
			cmp eax, [esi + 4];
			Jg swapper;
			inc ind;
			add esi, 4;
			mov eax, [esi];
			Jmp forLoop;	

		swapper:		
			xchg eax, [esi + 4];
			xchg eax, [esi]
			inc count;
			inc ind;
			add esi, 4;  
			Jmp forLoop;

		checkSorted:
			mov count, 0;
			mov ind, 0;
			lea esi, [arr2];
			mov eax, [esi];
			Jmp forLoop;
		
		exit1:
			cmp count, 0;
			Jne checkSorted;
		}

		std::cout << "Sorted Array: ";
		for (auto each : arr2) {
			std::cout << each << " ";
		}
	}

	void asm_3d_array_sum() {
		__asm {
			mov eax, 0;
			mov ind, 0;
			mov count, 0;
			lea esi, [arr3];

		forLoop1: // calc sum of all shirts
			cmp ind, 18;
			Je exit1;
			add eax, [esi];
			inc ind;
			add esi, 4;
			Jmp forLoop1;

		forLoop2:
			cmp ind, 2;
			Je exit2;
			add eax, [esi];
			inc ind;
			inc count;
			add esi, 4; //after first itr, ends at 5
			Jmp forLoop2;

		forLoop3:
			cmp ind, 9;
			Je exit3;
			add eax, [esi];
			inc ind;
			add esi, 8;
			Jmp forLoop3;

		forLoop4:
			cmp ind, 6;
			Je exit4;
			add eax, [esi];
			inc ind;
			add esi, 4;
			Jmp forLoop4;

		exit1:
			mov sumAll, eax;
			mov eax, 0;
			mov ind, 0;
			lea esi, [arr3];
			add esi, 8; // set up forLoop2
			Jmp forLoop2;
		
		medShirt:
			mov ind, 0;
			add esi, 16;
			Jmp forLoop2;
		
		exit2:			 
			cmp count, 6;
			Jne medShirt;
			mov sumMed, eax;
			mov eax, 0;
			mov ind, 0;
			mov count, 0;
			lea esi, [arr3];
			//add esi, ; // set up forLoop3
			Jmp forLoop3;

		exit3:
			mov sumShort, eax;
			mov eax, 0;
			mov ind, 0;
			lea esi, [arr3];
			Jmp forLoop4;

		exit4:
			mov sumRed, eax;
		}

		std::cout << "Sum of array is: " << sumAll << std::endl;
		std::cout << "Sum of medium shirts is: " << sumMed << std::endl;
		std::cout << "Sum of short sleeve shirts is: " << sumShort << std::endl;
		std::cout << "Sum of red shirts is: " << sumRed << std::endl;
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
