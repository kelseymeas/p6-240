#ifndef P4_HELPERS_H  
#define P4_HELPERS_H

#include <iostream>
#include <bitset>
#include <vector>

using std::cout;
using std::endl;

// ------------------------------------------
// |            -- Variables --             |  
// ------------------------------------------ 
short numOfPrinters, numOfFloppy, sizeOfRam;
short hexVal, inds = 0, sprinklers;
std::vector<short> brokenSprinklers;
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Project Functions --         |
// ------------------------------------------
    void asm_bitM_Parse();
    void asm_bitM_Sprinklers();
    void asm_bitM_Elevator();
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |        -- Helper Functions --          |
// ------------------------------------------
    void displayPrinters();
    void displayFloppy();
    void displayRam();
    void addSprinkler();
    void hexToBinary();
    void addSprinkler();
    void hexToBinary();
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |       -- Project Func Def's --         |
// ------------------------------------------
    void asm_bitM_Parse() {
        _asm {
            //Q1a
            mov ax, 1100111010011100b; //ax = state of register
            mov bx, 1100000000000000b; //want to compare the first 2 bits
            and ax, bx; //ax & bx
            shr ax, 14; //shift ax 14 to the right
            mov numOfPrinters, ax; //numOfPrinters = ax
            call displayPrinters; //display the number of printers
            //Q1b
            mov ax, 1100111010011100b; //ax = state of register
            mov bx, 0000000011000000b; //want to compare bits 7 and 8
            and ax, bx; //ax & bx
            shl ax, 8; //shift ax 8 to the left
            shr ax, 14; //shift ax 14 to the right
            mov numOfFloppy, ax; //numOfFloppy = ax
            add numOfFloppy, 1; //numOfFloppy = numOfFloppy + 1
            call displayFloppy; //display the number of floppy disks
            //Q1c
            mov ax, 1100111010011100b; //ax = state of register
            mov bx, 0000000000001100b; //want to compare bits 3 and 4
            and ax, bx; //ax & bx
            shl ax, 12; //shift ax 12 to the left
            shr ax, 14; //shift ax 14 to the right
            cmp ax, 0000000000000000b; //see if all are 0
            Jne testRAM; //if not all 0, jump to testRAM
            mov sizeOfRam, 16; //else, sizeOfRAM = 16
            Jmp displayR; //go to end (displayR)
        testRAM:
            cmp ax, 0000000000000001b; //see if bit 3 was 1 and bit 4 was 0
            Jne test48; //if not equal, jump to test48
            mov sizeOfRam, 32; //else, sizeOfRAM = 32
            Jmp displayR; //go to end (displayR)
        test48:
            cmp ax, 0000000000000010b; //see if bit 3 was 1 and bit 4 was 1
            Jne elseR; //if not equal, go to elseR
            mov sizeOfRam, 48; //else, sizeOfRAM = 48
            Jmp displayR; //go to end (displayR)
        elseR:
            mov sizeOfRam, 64; //sizeOfRAM = 64
        displayR:
            call displayRam; //display the RAM
        }
    }

    void asm_bitM_Sprinklers() {
        __asm {
            mov hexVal, 0x6A2F;
            call hexToBinary;
            mov bx, 0110101000101111b;
            mov dx, 1; //check each bit val
            not bx;


        forLoop:
            cmp inds, 16;
            Je exitLoop;

            and dx, bx;
            shl dx, 15;
            shr dx, 15;

            cmp dx, 0;
            Jne sprinklerCount;

            mov dx, 1;
            shr bx, 1;
            inc inds;
            Jmp forLoop;

        sprinklerCount:
            call addSprinkler;
            mov dx, 1;
            shr bx, 1;
            inc inds;
            Jmp forLoop;

        exitLoop:
        }

        for (auto each : brokenSprinklers) {
            cout << each << " ";
        }
    }

    void asm_bitM_Elevator() {
        __asm {
            mov bx, 1001000100001100b;
            mov dx, 1; //check each bit val
            not bx;


        forLoop:
            cmp inds, 16;
            Je exitLoop;

            and dx, bx;
            shl dx, 15;
            shr dx, 15;

            cmp dx, 0;
            Je sprinklerCount;

            mov dx, 1;
            shr bx, 1;
            inc inds;
            Jmp forLoop;

        sprinklerCount:
            call addSprinkler;
            mov dx, 1;
            shr bx, 1;
            inc inds;
            Jmp forLoop;

        exitLoop:
        }

        for (auto each : brokenSprinklers) {
            std::cout << each << " ";
        }
    }
// ------------------------------------------ 
// ------------------------------------------ 


// ------------------------------------------
// |         -- Helper Func Def's --        |
// ------------------------------------------
    void addSprinkler() {
        brokenSprinklers.push_back(inds + 1);
    }

    void hexToBinary() {
        std::cout << std::bitset<16>(hexVal) << endl;
    }

    void displayPrinters()
    {
        cout << " The number of printers connected = " << numOfPrinters << endl;
    }

    void displayFloppy()
    {
        cout << " The number of floppy disk drives = " << numOfFloppy << endl;
    }

    void displayRam()
    {
        cout << " The size of the RAM = " << sizeOfRam << "GB RAM" << endl;
    }
// ------------------------------------------ 
// ------------------------------------------ 

#endif 
