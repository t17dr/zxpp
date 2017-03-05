#include "defines.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_ttf.h>
#include <iostream>
#include <bitset>

#include "window.h"
#include "z80.h"
#include "instructions.h"
// #include "tests/tests.h"
#include "display.h"

#include <fstream>
#include <random>
#include <functional>
#include <string>
#include <chrono>
#include <memory>

#include "utils.h"

#define REFRESH_RATE (1.0/50.0)

inline bool fileExists (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* args[])
{
    SDL_Window* window = createWindow(256, 192, "ZX++");
    if (window == nullptr)
	{
		return -1;
	}

    if (TTF_Init() < 0)
    {
        std::cerr << "TTF error" << std::endl;
    }

    Z80 proc;
    Spectrum48KMemory memory;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,255);
    auto dice = std::bind ( distribution, generator );
    for (int i = 0; i < memory.screen_size + memory.screenColor_size; i++)
    {
        int dice_roll = dice();
        *(memory.screenMemory + i) = (uint8_t) dice_roll;
    }

    // TODO: zkontrolovat "practically NOP" instrukce jestli nemaj nastavovat flagy
    // TODO: inkrementovat PC před(!) vykonanim instrukce, zkontrolovat ze skoky jdou spravne
    // TODO: disablovat maskable interrupty v prubehu DI a EI (+1 instrukce dal u EI)

    #define ITERS 100000

    int op = 9;
    std::shared_ptr<std::array<Instruction, NUM_INSTRUCTIONS>> instructions
        = z80InstructionSet();
    std::vector<uint8_t> data;// = {7, 235};
    proc.getRegisters()->HL.word = 0;
    proc.getRegisters()->BC.word = 1;

    auto u = (*instructions)[op];
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++)
    {
        // auto u = instructions[op];//.execute(&proc, &memory, data);
        u.execute(&proc, &memory, data);
    }

    auto now1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Execute only: " << timeSpan1.count() << std::endl;


    proc.getRegisters()->HL.word = 0;
    proc.getRegisters()->BC.word = 1;

    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++)
    {
        auto v = (*instructions)[op];//.execute(&proc, &memory, data);
//u.execute(&proc, &memory, data);
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Find only: " << timeSpan1.count() << std::endl;



    proc.getRegisters()->HL.word = 0;
    proc.getRegisters()->BC.word = 1;

    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++)
    {
        (*instructions)[op].execute(&proc, &memory, data);
//u.execute(&proc, &memory, data);
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Full: " << timeSpan1.count() << std::endl;



    proc.getRegisters()->HL.word = 0;
    proc.getRegisters()->BC.word = 1;

    auto z = &proc;

    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++)
    {
        Z80Registers* r = z->getRegisters();
        r->HL.word = add(r->HL.word, r->BC.word, r, ADD16);
        setUndocumentedFlags(r->HL.word, r);
        r->AF.bytes.low.NF = false;
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Full inline: " << timeSpan1.count() << std::endl;

    /*auto start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        memory[i % 0xFFFF] = 5;
    }

    auto now1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Direct operator write: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        memory.memory[i % 0xFFFF] = 5;
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Direct array write: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        int b = memory.memory[i % 0xFFFF];
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Direct array read: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ITERS; i++)
    {
        int b = memory[i % 0xFFFF];
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Direct operator read: " << timeSpan1.count() << std::endl;

    /////////////////////////////////////////////

    Spectrum48KMemory* mm = &memory;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        (*mm)[i % 0xFFFF] = 5;
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Pointer operator write: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        (*mm).memory[i % 0xFFFF] = 5;
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Pointer array write: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        int b = (*mm).memory[i % 0xFFFF];
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Pointer array read: " << timeSpan1.count() << std::endl;

    start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERS; i++)
    {
        int b = (*mm)[i % 0xFFFF];
    }

    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << "Pointer operator read: " << timeSpan1.count() << std::endl;*/

    start1 = std::chrono::high_resolution_clock::now();
    // runTests(proc, memory);
    now1 = std::chrono::high_resolution_clock::now();
    timeSpan1 = std::chrono::duration_cast<std::chrono::duration<double>>(now1 - start1);
    std::cout << std::endl << +timeSpan1.count() << std::endl;
    for (int i = 0; i < 0xFFFF; i++) { memory[0] = 0; }
    proc.init();

    // proc.printState();


    std::string file = "48.rom";
    // const std::string file = "DiagROM.v27";
    // const std::string file = "testrom.bin";
    // const std::string file = "test.hex";

    if (argc > 1)
    {
        file = std::string(args[1]);
    }
    std::ifstream inf;
    inf.open(file, std::ios::in|std::ios::binary);

    inf.seekg (0, std::ios::end);
    int length = (int)inf.tellg();
    inf.seekg (0, std::ios::beg);

    inf.read((char *)memory.ROM, length);

    inf.close();


    TTF_Font* font = TTF_OpenFont("x64/Debug/OverpassMono-Regular.ttf", 40);

    SDL_Color c = { 255, 0, 0, 255 };
    SDL_Color c2 = { 255, 255, 0, 255 };
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Display display(&memory, renderer);

    auto start = std::chrono::high_resolution_clock::now();

    // Main loop
	bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }


        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(now - start);

        if (timeSpan.count() >= REFRESH_RATE)
        {
            start = std::chrono::high_resolution_clock::now();
            
            //auto startTest = std::chrono::high_resolution_clock::now();            
            proc.simulateFrame(&memory);
            //auto nowTest = std::chrono::high_resolution_clock::now();
            //std::chrono::duration<double> timeSpanTest = std::chrono::duration_cast<std::chrono::duration<double>>(nowTest - startTest);

            //SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
            //SDL_RenderClear(renderer);
            display.draw();
            //std::string s = std::to_string(proc.getRegisters()->PC);
            //std::string s2 = std::to_string(proc.getRegisters()->HL.word);


            //SDL_Rect rect3 = {0,192/2-20,256,40};
            //std::string fps = std::to_string(1.0/timeSpan.count());
            //SDL_Surface* surface3 = TTF_RenderText_Solid(font, fps.c_str(), c2);
            //SDL_Texture* t3 = SDL_CreateTextureFromSurface(renderer, surface3);
            //SDL_RenderCopy(renderer, t3, NULL, &rect3);
            //SDL_DestroyTexture(t3);

            // SDL_Rect rect3 = {0,192/2-20,256,40};
            // std::string testTime = std::to_string(1.0/timeSpanTest.count());
            // SDL_Surface* surface3 = TTF_RenderText_Solid(font, testTime.c_str(), c2);
            // SDL_Texture* t3 = SDL_CreateTextureFromSurface(renderer, surface3);
            // SDL_RenderCopy(renderer, t3, NULL, &rect3);
            // SDL_DestroyTexture(t3);


            //SDL_Surface* surface = TTF_RenderText_Solid(font, s.c_str(), c);
            //SDL_Surface* surface2 = TTF_RenderText_Solid(font, s2.c_str(), c);
            //SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, surface);
            //SDL_Texture* t2 = SDL_CreateTextureFromSurface(renderer, surface2);
            //SDL_Rect rect = {0,0,256,192/2};
            //SDL_Rect rect2 = {0,192/2,256,192/2};
            //SDL_RenderCopy(renderer, t, NULL, &rect);
            //SDL_RenderCopy(renderer, t2, NULL, &rect2);
            //SDL_DestroyTexture(t);
            //SDL_DestroyTexture(t2);
        }


        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}