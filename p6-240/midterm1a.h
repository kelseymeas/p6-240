#ifndef MIDTERM1A_H  
#define MIDTERM1A_H  

#include <iostream>
#include <vector>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;

// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
    short _inds = 0, _sprinklers, counter = 0, offBits, front = 0, back = 0;
    std::vector<short> _brokenSprinklers;

    int mArray[3][4] = {{33, 31, 20, 18 }, 
                        {23, 22, 23, 31 }, 
                        {10, 20, 30, 40 }};

    int fresh, soph, jun, sen;
    int irvine, rowT = 0;

    void _addSprinkler();
// ------------------------------------------ 
// ------------------------------------------ 
    
// ------------------------------------------
// |       -- Project Functions --         |
// ------------------------------------------
    void midterm_bitM() {
        __asm {
            mov ax, 0000000011000000b; //try xor?
            mov bx, 1100111111011100b;
            mov dx, 1; //check each bit val
            xor ax, bx;
            mov offBits, ax;
            not bx;


        forLoop:
            cmp _inds, 16;
            Je exitLoop;

            and dx, bx;
            shl dx, 15;
            shr dx, 15;

            cmp dx, 0;
            Je sprinklerCount;

            mov dx, 1;
            shr bx, 1;
            inc _inds;
            Jmp forLoop;

        sprinklerCount:
            call _addSprinkler;
            inc counter;
            mov dx, 1;
            shr bx, 1;

            cmp _inds, 8;
            Jle _front;

            inc back;
            inc _inds;
            Jmp forLoop;

        _front:
            inc front;
            inc _inds;
            Jmp forLoop;

        exitLoop:
        }

        cout << "On bits count: "  << counter << endl;
        cout << "Turn off 6 and 7: " << std::bitset<16>(offBits) << endl;
        
        if (front > back) { cout << "Front Area is using more water" << endl; }
        else { cout << "Back Area is using more water." << endl; }

        //for (auto each : brokenSprinklers) {
        //  cout << each << " ";
        //}
    }

    void midterm_array_sum() {
        __asm {
            mov eax, 0;
            mov ebx, 0;
            mov ecx, 0;
            mov _inds, 0;
            lea esi, [mArray];

        forLoop1: // calc freshman
            cmp _inds, 3;
            Je exit1;
            add eax, [esi];
            inc _inds;
            add esi, 16;
            Jmp forLoop1;

        exit1:
            mov fresh, eax;
            mov eax, 0;
            mov _inds, 0;
            lea esi, [mArray];
            add esi, 4;
            Jmp forLoopSoph;

        forLoopSoph:
            cmp _inds, 3;
            Je exitSoph;
            add eax, [esi];
            inc _inds;
            add esi, 16;
            Jmp forLoopSoph;

        exitSoph:
            mov soph, eax;
            mov eax, 0;
            mov _inds, 0;
            lea esi, [mArray];
            add esi, 8;
            Jmp forLoopJun;

        forLoopJun:
            cmp _inds, 3;
            Je exitJun;
            add eax, [esi];
            inc _inds;
            add esi, 16;
            Jmp forLoopJun;

        exitJun:
            mov jun, eax;
            mov eax, 0;
            mov _inds, 0;
            lea esi, [mArray];
            add esi, 12;
            Jmp forLoopSen;

        forLoopSen:
            cmp _inds, 3;
            Je exitSen;
            add eax, [esi];
            inc _inds;
            add esi, 16;
            Jmp forLoopSen;

        exitSen:
            mov sen, eax;
            mov eax, 0;
            lea esi, [mArray];
            add esi, 16;
            mov _inds, 0;
            Jmp forLoop2;


        forLoop2: // calc sum of medium shirts
            cmp _inds, 4;
            Je exit2;
            add eax, [esi];
            inc _inds;
            add esi, 4;
            Jmp forLoop2;

        exit2:
            mov irvine, eax;          
        }

        std::cout << "\nMajority Students are SENIORS. " << sen;
        std::cout << "\nSum of irvine students is: " << irvine << std::endl;
    }
    //helpers
    void _addSprinkler() {
        _brokenSprinklers.push_back(_inds + 1);
    }
// ------------------------------------------ 
// ------------------------------------------ 
#endif 