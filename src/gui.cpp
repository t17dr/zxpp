
#include "emulator.h"
#include "3rdparty/noc_file_dialog.h"
#include "gui.h"

#define STB_IMAGE_IMPLEMENTATION
#include "3rdparty/stb_image.h"

Gui::Gui(Emulator* emu)
    : m_renderMenu(true),
      m_renderDebugger(false),
      m_renderMemoryEditor(false),
      m_emu(emu)
{
    uploadTextures();
}

void Gui::draw()
{
    if (m_renderMenu)
    {
        renderMenu();
    }
    if (m_renderLoadROM)
    {
        renderLoadRomWindow();
    }
    if (m_renderDebugger)
    {
        renderDebugger();
    }
    if (m_renderMemoryEditor)
    {
        renderMemoryEditor();
    }
    if (m_renderVirtualKeyboard)
    {
        renderVirtualKeyboard();
    }
}

void Gui::handleInput(SDL_Event &e)
{

}

void Gui::renderMenu()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Load ROM")) { m_renderLoadROM = true; }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            // TODO: hotkeys
            if (ImGui::MenuItem("Reset machine", "CTRL+R")) { m_emu->reset(); }
            if (ImGui::MenuItem("Settings", "CTRL+K")) {}
            if (ImGui::BeginMenu("Display scale"))
            {
                static float s = m_emu->getDisplay()->getScale();
                ImGui::SliderFloat("Scale", &s, 0.1f, 10.0f);
                if (ImGui::Button("1:1")) { s = 1.0f; }
                ImGui::SameLine();
                if (ImGui::Button("2:1")) { s = 2.0f; }
                ImGui::SameLine();
                if (ImGui::Button("4:1")) { s = 4.0f; }
                ImGui::EndMenu();

                m_emu->getDisplay()->setScale(s);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Tools"))
        {
            if (ImGui::MenuItem("Virtual keyboard")) { m_renderVirtualKeyboard = true; }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Development"))
        {
            if (ImGui::MenuItem("Debugger")) { m_renderDebugger = true; }
            if (ImGui::MenuItem("Memory")) { m_renderMemoryEditor = true; }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Gui::renderLoadRomWindow()
{
    ImGui::SetNextWindowSize(ImVec2(400,70), NULL);
    if (!ImGui::Begin("Load ROM", &m_renderLoadROM, ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::End();
        return;
    }

    ImGui::PushItemWidth(-50);
    static char fileStr[260] = "48.rom";
    ImGui::InputText("", fileStr, 260);

    ImGui::SameLine();
    if (ImGui::SmallButton("..."))
    {
        const char* file = noc_file_dialog_open(NOC_FILE_DIALOG_OPEN, NULL, NULL, "48.rom");
        if (file != NULL)
        {
            if (strlen(file) < 260)
            {
                strcpy(fileStr, file);
            } else
            {
                std::cerr << "File path too long (>260 characters)" << std::endl;
            }
        }
    }

    if (ImGui::Button("Load"))
    {
        m_emu->loadROM(fileStr);
        m_emu->reset();
        m_renderLoadROM = false;
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel")) { m_renderLoadROM = false; }

    ImGui::End();
}

void Gui::renderDebugger()
{
    Debugger* debugger = m_emu->getDebugger();
    ImGui::SetNextWindowSize(ImVec2(760,500), ImGuiSetCond_Once);
    std::string title = std::string(ICON_FA_BUG) + std::string(" Debugger");
    if (debugger->shouldBreak())
    {
        title += std::string(" [stopped]") + "###DEBUG_ID";
    } else {
        title += "###DEBUG_ID";
    }

    if (!ImGui::Begin(title.c_str(), &m_renderDebugger, 0))
    {
        ImGui::End();
        return;
    }

    ImGui::Spacing();
    if (debugger->shouldBreak())
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.3f, 0.7f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.3f, 0.8f, 0.7f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.3f, 0.9f, 0.5f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.0f, 0.0f, 1.0f));
    } else
    {
        // Disabled
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.6361f, 0.0f, 0.3f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.6361f, 0.0f, 0.4f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.6361f, 0.0f, 0.2f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.0f, 0.0f, 0.45f));
    }

    if (ImGui::Button(ICON_FA_PLAY))
    {
        debugger->continueExecution();
    }
    ImGui::PopStyleColor(4);
    if (!debugger->shouldBreak())
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.6361f, 0.4f, 0.3f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.6361f, 0.4f, 0.4f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.6361f, 0.4f, 0.2f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.0f, 0.0f, 1.0f));
    } else {
        // Disabled
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.6361f, 0.0f, 0.3f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.6361f, 0.0f, 0.4f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.6361f, 0.0f, 0.2f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.0f, 0.0f, 0.45f));
    }
    ImGui::SameLine();
    if (ImGui::Button(ICON_FA_PAUSE) && !(debugger->shouldBreak()))
    {
        debugger->breakExecution();
        debugger->breakNextFrame();
    }
    ImGui::PopStyleColor(4);
    if (debugger->shouldBreak())
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.6361f, 0.4f, 0.3f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.6361f, 0.4f, 0.4f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.6361f, 0.4f, 0.2f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.6361f, 0.0f, 1.0f));
    } else {
        // Disabled
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.6361f, 0.0f, 0.3f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.6361f, 0.0f, 0.4f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.6361f, 0.0f, 0.2f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImColor::HSV(0.0f, 0.0f, 0.45f));
    }
    ImGui::SameLine();
    if (ImGui::Button(ICON_FA_CHEVRON_RIGHT))
    {
        debugger->breakExecution();
        debugger->breakNextFrame();
        debugger->getTrace()->clear();
    }
    if (ImGui::IsItemHovered()) 
    {
        ImGui::SetTooltip("Next frame");
    }
    ImGui::PopStyleColor(4);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::Columns(2, "debugColumns");
    ImGui::SetColumnOffset(1, 200);

    std::vector<InstructionTrace>* trace = debugger->getTrace();
    std::string traceStr = std::string(ICON_FA_SORT_AMOUNT_ASC) + std::string(" Instruction trace");
    if (ImGui::CollapsingHeader(traceStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Spacing();

        ImGui::BeginGroup();
        ImGui::BeginChild("Trace", ImVec2(ImGui::GetColumnWidth(0) * 0.95f,
            ImGui::GetWindowHeight() - 100.0f), true);
        int i = 0;
        for (auto it = trace->begin(); it != trace->end(); ++it)
        {
            i++;
            ImGui::PushID(i);
            std::stringstream stream;
            stream << std::setw(4) << std::setfill('0') << std::hex << it->address;
            std::string addressHex(stream.str());
            addressHex += "\t" + it->mnemonic;
            if (ImGui::Selectable(addressHex.c_str(),
                i == debugger->selectedTrace))
            {
                debugger->selectedTrace = i;
            }
            ImGui::PopID();
        }
        ImGui::EndChild();
        ImGui::EndGroup();
    }

    ImGui::NextColumn();

    ImGui::BeginGroup();
    ImGui::BeginChild("Right column", ImVec2(ImGui::GetColumnWidth(1) - 15.0f,
                      ImGui::GetWindowHeight() - 75.0f), true);

    std::string breakpointsStr = std::string(ICON_FA_CIRCLE) + std::string(" Breakpoints");
    if (ImGui::CollapsingHeader(breakpointsStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.7f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.0f, 0.8f, 0.7f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.0f, 0.9f, 0.5f));
        std::string add = std::string(ICON_FA_PLUS) + std::string(" Add breakpoint");
        if (ImGui::Button(add.c_str()))
        {
            debugger->addBreakpoint(Breakpoint());
        }
        ImGui::PopStyleColor(3);
        ImGui::NewLine();

        std::map<int, Breakpoint>* breakpoints = debugger->getBreakpoints();

        for (auto it = breakpoints->begin(); it != breakpoints->end(); ++it)
        {
            Breakpoint* bp = &(it->second);
            int i = it->first;
            ImGui::PushID(debugger->getBreakpointsCount()*7 + i);
            ImGui::Checkbox(ICON_FA_BULLSEYE, bp->getEnabled());
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::PushItemWidth(130);
            ImGui::PushID(debugger->getBreakpointsCount()*3 + i);
            int wtf2 = (int)*(bp->getAddress());
            ImGui::InputInt("", &wtf2, 1, 100, ImGuiInputTextFlags_CharsHexadecimal);
            bp->setAddress(wtf2);
            ImGui::PopID();
            ImGui::SameLine();
            const char* registers[] = { "None", "AF", "BC", "DE", "HL", "AF'", "BC'", "DE'",
                "HL'", "IX", "IY", "IR", "SP", "A", "F", "D", "E", "H", "L", "I", "R" };
            ImGui::PushItemWidth(70);
            ImGui::PushID(i);
            ImGui::Combo("", (int*)(bp->getCondition()), registers, 21);
            ImGui::SameLine();
            const char* operators[] = { ">", "<", "==", ">=", "<=", "!="};
            ImGui::PushItemWidth(70);
            ImGui::PopID();
            ImGui::PushID(debugger->getBreakpointsCount() + i);
            ImGui::Combo("", (int*)(bp->getOperator()), operators, 6);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::PushItemWidth(130);
            ImGui::PushID(debugger->getBreakpointsCount()*5 + i);
            int wtf = (int)*(bp->getConditionNumber());
            ImGui::InputInt(" ", &wtf, 1, 100, ImGuiInputTextFlags_CharsHexadecimal);
            bp->setConditionNumber(wtf);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.7f, 0.6f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(0.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(0.0f, 0.9f, 0.5f));
            ImGui::PushID(debugger->getBreakpointsCount()*4 + i);
            if (ImGui::Button(ICON_FA_TIMES))
            {
                debugger->removeBreakpoint(i);
            }
            ImGui::PopID();
            ImGui::PopStyleColor(3);
        }

        ImGui::Spacing();
    }
    
    std::string registersStr = std::string(ICON_FA_TASKS) + std::string(" Registers");
    SKIPPABLE
    if (ImGui::CollapsingHeader(registersStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        if (debugger->selectedTrace == -1)
        {
            ImGui::Text("No instruction selected");
            ImGui::Spacing();
            break;
        }
        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("PC");
        ImGui::SameLine();
        ImGui::Indent(120.0f);
        std::stringstream stream;
        stream << std::setw(4) << std::setfill('0') << std::hex << (*trace)[debugger->selectedTrace].registers.PC;
        std::string pcHex(stream.str());
        std::string pcDec = std::to_string((*trace)[debugger->selectedTrace].registers.PC);
        std::string pcBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.PC).to_string();
        stream.str(std::string());
        ImGui::Text(pcHex.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(pcDec.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(pcBin.c_str());
        ImGui::Unindent(240.0f);

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("SP");
        ImGui::SameLine();
        ImGui::Indent(120.0f);
        stream << std::setw(4) << std::setfill('0') << std::hex << (*trace)[debugger->selectedTrace].registers.SP;
        std::string spHex(stream.str());
        std::string spDec = std::to_string((*trace)[debugger->selectedTrace].registers.SP);
        std::string spBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.SP).to_string();
        stream.str(std::string());
        ImGui::Text(spHex.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(spDec.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(spBin.c_str());
        ImGui::Unindent(240.0f);

        if(ImGui::TreeNode("IR"))
        {
            stream << std::setw(4) << std::setfill('0') << std::hex << (*trace)[debugger->selectedTrace].registers.IR.word;
            std::string irHex(stream.str());
            std::string irDec = std::to_string((*trace)[debugger->selectedTrace].registers.IR.word);
            std::string irBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.IR.word).to_string();
            stream.str(std::string());
            ImGui::SameLine();
            ImGui::Indent(104.0f);
            ImGui::Text(irHex.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(irDec.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(irBin.c_str());
            ImGui::Unindent(224.0f);
            ImGui::TreeAdvanceToLabelPos(); ImGui::Text("I");
            stream << std::setw(2) << std::setfill('0') << std::hex << +((*trace)[debugger->selectedTrace].registers.IR.bytes.high);
            std::string iHex(stream.str());
            std::string iDec = std::to_string((*trace)[debugger->selectedTrace].registers.IR.bytes.high);
            std::string iBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.IR.bytes.high).to_string();
            stream.str(std::string());
            ImGui::SameLine();
            ImGui::Indent(104.0f);
            ImGui::Text(iHex.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(iDec.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(iBin.c_str());
            ImGui::Unindent(224.0f);
            ImGui::TreeAdvanceToLabelPos(); ImGui::Text("R");
            stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.IR.bytes.low);
            std::string rHex(stream.str());
            std::string rDec = std::to_string((*trace)[debugger->selectedTrace].registers.IR.bytes.low);
            std::string rBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.IR.bytes.low).to_string();
            stream.str(std::string());
            ImGui::SameLine();
            ImGui::Indent(104.0f);
            ImGui::Text(rHex.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(rDec.c_str());
            ImGui::SameLine();
            ImGui::Indent(60.0f);
            ImGui::Text(rBin.c_str());
            ImGui::Unindent(224.0f);
            ImGui::TreePop();
        }

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("IX");
        ImGui::SameLine();
        ImGui::Indent(120.0f);
        stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.IX.word;
        std::string ixHex(stream.str());
        std::string ixDec = std::to_string((*trace)[debugger->selectedTrace].registers.IX.word);
        std::string ixBin = std::bitset< 16 >((*trace)[debugger->selectedTrace].registers.IX.word).to_string();
        stream.str(std::string());
        ImGui::Text(ixHex.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(ixDec.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(ixBin.c_str());
        ImGui::Unindent(240.0f);

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("IY");
        ImGui::SameLine();
        ImGui::Indent(120.0f);
        stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.IY.word;
        std::string iyHex(stream.str());
        std::string iyDec = std::to_string((*trace)[debugger->selectedTrace].registers.IY.word);
        std::string iyBin = std::bitset< 16 >((*trace)[debugger->selectedTrace].registers.IY.word).to_string();
        stream.str(std::string());
        ImGui::Text(iyHex.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(iyDec.c_str());
        ImGui::SameLine();
        ImGui::Indent(60.0f);
        ImGui::Text(iyBin.c_str());
        ImGui::Unindent(240.0f);

        if(ImGui::TreeNode("Basic"))
        {
            if(ImGui::TreeNode("AF"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.AF.word;
                std::string afHex(stream.str());
                std::string afDec = std::to_string((*trace)[debugger->selectedTrace].registers.AF.word);
                std::string afBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.AF.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(afHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(afDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(afBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("A");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.AF.bytes.high);
                std::string aHex(stream.str());
                std::string aDec = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.high);
                std::string aBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.AF.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(aHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(aDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(aBin.c_str());
                ImGui::Unindent(207.0f);
                // ImGui::TreeAdvanceToLabelPos(); ImGui::Text("F");
                if(ImGui::TreeNode("F"))
                {
                    stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.AF.bytes.low.byte);
                    std::string fHex(stream.str());
                    std::string fDec = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.byte);
                    std::string fBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.AF.bytes.low.byte).to_string();
                    stream.str(std::string());
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(fHex.c_str());
                    ImGui::SameLine();
                    ImGui::Indent(60.0f);
                    ImGui::Text(fDec.c_str());
                    ImGui::SameLine();
                    ImGui::Indent(60.0f);
                    ImGui::Text(fBin.c_str());
                    ImGui::Unindent(192.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("CF");
                    std::string cf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.CF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(cf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("NF");
                    std::string nf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.NF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(nf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("PF");
                    std::string pf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.PF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(pf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("XF");
                    std::string xf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.XF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(xf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("HF");
                    std::string hf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.HF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(hf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("YF");
                    std::string yf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.YF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(yf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("ZF");
                    std::string zf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.ZF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(zf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreeAdvanceToLabelPos(); ImGui::Text("SF");
                    std::string sf = std::to_string((*trace)[debugger->selectedTrace].registers.AF.bytes.low.SF);
                    ImGui::SameLine();
                    ImGui::Indent(72.0f);
                    ImGui::Text(sf.c_str());
                    ImGui::Unindent(72.0f);

                    ImGui::TreePop();
                }
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("BC"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.BC.word;
                std::string bcHex(stream.str());
                std::string bcDec = std::to_string((*trace)[debugger->selectedTrace].registers.BC.word);
                std::string bcBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.BC.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(bcHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bcDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bcBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("B");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.BC.bytes.high);
                std::string bHex(stream.str());
                std::string bDec = std::to_string((*trace)[debugger->selectedTrace].registers.BC.bytes.high);
                std::string bBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.BC.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(bHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("C");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.BC.bytes.low);
                std::string cHex(stream.str());
                std::string cDec = std::to_string((*trace)[debugger->selectedTrace].registers.BC.bytes.low);
                std::string cBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.BC.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(cHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(cDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(cBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("DE"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.DE.word;
                std::string deHex(stream.str());
                std::string deDec = std::to_string((*trace)[debugger->selectedTrace].registers.DE.word);
                std::string deBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.DE.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(deHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(deDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(deBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("D");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.DE.bytes.high);
                std::string dHex(stream.str());
                std::string dDec = std::to_string((*trace)[debugger->selectedTrace].registers.DE.bytes.high);
                std::string dBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.DE.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(dHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("E");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.DE.bytes.low);
                std::string eHex(stream.str());
                std::string eDec = std::to_string((*trace)[debugger->selectedTrace].registers.DE.bytes.low);
                std::string eBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.DE.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(eHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(eDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(eBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("HL"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.HL.word;
                std::string hlHex(stream.str());
                std::string hlDec = std::to_string((*trace)[debugger->selectedTrace].registers.HL.word);
                std::string hlBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.HL.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(hlHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hlDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hlBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("H");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.HL.bytes.high);
                std::string hHex(stream.str());
                std::string hDec = std::to_string((*trace)[debugger->selectedTrace].registers.HL.bytes.high);
                std::string hBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.HL.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(hHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("L");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.HL.bytes.low);
                std::string lHex(stream.str());
                std::string lDec = std::to_string((*trace)[debugger->selectedTrace].registers.HL.bytes.low);
                std::string lBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.HL.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(lHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(lDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(lBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            ImGui::TreePop();
        }

        if(ImGui::TreeNode("Alternative"))
        {
            if(ImGui::TreeNode("AF'"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.AFx.word;
                std::string afxHex(stream.str());
                std::string afxDec = std::to_string((*trace)[debugger->selectedTrace].registers.AFx.word);
                std::string afxBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.AFx.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(afxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(afxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(afxBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("A'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.AFx.bytes.high);
                std::string axHex(stream.str());
                std::string axDec = std::to_string((*trace)[debugger->selectedTrace].registers.AFx.bytes.high);
                std::string axBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.AFx.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(axHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(axDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(axBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("F'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.AFx.bytes.low.byte);
                std::string fxHex(stream.str());
                std::string fxDec = std::to_string((*trace)[debugger->selectedTrace].registers.AFx.bytes.low.byte);
                std::string fxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.AFx.bytes.low.byte).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(fxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(fxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(fxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("BC'"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.BCx.word;
                std::string bcxHex(stream.str());
                std::string bcxDec = std::to_string((*trace)[debugger->selectedTrace].registers.BCx.word);
                std::string bcxBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.BCx.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(bcxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bcxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bcxBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("B'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.BCx.bytes.high);
                std::string bxHex(stream.str());
                std::string bxDec = std::to_string((*trace)[debugger->selectedTrace].registers.BCx.bytes.high);
                std::string bxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.BCx.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(bxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(bxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("C'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.BCx.bytes.low);
                std::string cxHex(stream.str());
                std::string cxDec = std::to_string((*trace)[debugger->selectedTrace].registers.BCx.bytes.low);
                std::string cxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.BCx.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(cxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(cxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(cxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("DE'"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.DEx.word;
                std::string dexHex(stream.str());
                std::string dexDec = std::to_string((*trace)[debugger->selectedTrace].registers.DEx.word);
                std::string dexBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.DEx.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(dexHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dexDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dexBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("D'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.DEx.bytes.high);
                std::string dxHex(stream.str());
                std::string dxDec = std::to_string((*trace)[debugger->selectedTrace].registers.DEx.bytes.high);
                std::string dxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.DEx.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(dxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(dxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("E'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.DEx.bytes.low);
                std::string exHex(stream.str());
                std::string exDec = std::to_string((*trace)[debugger->selectedTrace].registers.DEx.bytes.low);
                std::string exBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.DEx.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(exHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(exDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(exBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("HL'"))
            {
                stream << std::hex << std::setw(4) << std::setfill('0') << (*trace)[debugger->selectedTrace].registers.HLx.word;
                std::string hlxHex(stream.str());
                std::string hlxDec = std::to_string((*trace)[debugger->selectedTrace].registers.HLx.word);
                std::string hlxBin = std::bitset<16>((*trace)[debugger->selectedTrace].registers.HLx.word).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(88.0f);
                ImGui::Text(hlxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hlxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hlxBin.c_str());
                ImGui::Unindent(208.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("H'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.HLx.bytes.high);
                std::string hxHex(stream.str());
                std::string hxDec = std::to_string((*trace)[debugger->selectedTrace].registers.HLx.bytes.high);
                std::string hxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.HLx.bytes.high).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(hxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(hxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreeAdvanceToLabelPos(); ImGui::Text("L'");
                stream << std::hex << std::setw(2) << std::setfill('0') << +((*trace)[debugger->selectedTrace].registers.HLx.bytes.low);
                std::string lxHex(stream.str());
                std::string lxDec = std::to_string((*trace)[debugger->selectedTrace].registers.HLx.bytes.low);
                std::string lxBin = std::bitset<8>((*trace)[debugger->selectedTrace].registers.HLx.bytes.low).to_string();
                stream.str(std::string());
                ImGui::SameLine();
                ImGui::Indent(87.0f);
                ImGui::Text(lxHex.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(lxDec.c_str());
                ImGui::SameLine();
                ImGui::Indent(60.0f);
                ImGui::Text(lxBin.c_str());
                ImGui::Unindent(207.0f);
                ImGui::TreePop();
            }
            ImGui::TreePop();
        }

    }

    std::string interruptsStr = std::string(ICON_FA_BELL) + std::string(" Interrupts");
    SKIPPABLE
    if (ImGui::CollapsingHeader(interruptsStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        if (debugger->selectedTrace == -1)
        {
            ImGui::Text("No instruction selected");
            ImGui::Spacing();
            break;
        }

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("IFF1");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        std::string iff1Str = std::to_string((*trace)[debugger->selectedTrace].IFF1);
        ImGui::Text(iff1Str.c_str());
        ImGui::Unindent(240.0f);

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("IFF2");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        std::string iff2Str = std::to_string((*trace)[debugger->selectedTrace].IFF2);
        ImGui::Text(iff2Str.c_str());
        ImGui::Unindent(240.0f);

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("Interrupt mode");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        std::string imStr = std::to_string((*trace)[debugger->selectedTrace].interruptMode);
        ImGui::Text(imStr.c_str());
        ImGui::Unindent(240.0f);

    }

    std::string timingStr = std::string(ICON_FA_CLOCK_O) + std::string(" Timing");
    SKIPPABLE
    if (ImGui::CollapsingHeader(timingStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        if (debugger->selectedTrace == -1)
        {
            ImGui::Text("No instruction selected");
            ImGui::Spacing();
            break;
        }

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("T-states since interrupt");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        std::string cyclesStr = std::to_string((*trace)[debugger->selectedTrace].frameCycleNumber);
        ImGui::Text(cyclesStr.c_str());
        ImGui::Unindent(240.0f);

        float cTime = (float)((*trace)[debugger->selectedTrace].frameCycleNumber) * (float)CLOCK_TIME;
        cTime *= 1000000.0f;
        std::string timeStr = std::to_string(cTime) + " us";
        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("Time since interrupt");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        ImGui::Text(timeStr.c_str());
        ImGui::Unindent(240.0f);

        std::string numStr = std::to_string(debugger->getTrace()->size());
        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("Instructions this frame");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        ImGui::Text(numStr.c_str());
        ImGui::Unindent(240.0f);

        std::string selStr = std::to_string(debugger->selectedTrace);
        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("Selected instruction #");
        ImGui::SameLine();
        ImGui::Indent(240.0f);
        ImGui::Text(selStr.c_str());
        ImGui::Unindent(240.0f);
    }

    std::string bytesStr = std::string(ICON_FA_HDD_O) + std::string(" Bytes");
    SKIPPABLE
    if (ImGui::CollapsingHeader(bytesStr.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        if (debugger->selectedTrace == -1)
        {
            ImGui::Text("No instruction selected");
            ImGui::Spacing();
            break;
        }

        ImGui::TreeAdvanceToLabelPos(); ImGui::Text("Raw");
        ImGui::SameLine();
        ImGui::Indent(120.0f);
        float unindent = 0.0f;
        int i = 0;
        for (auto byte : (*trace)[debugger->selectedTrace-1].opcodeBytes)
        {
            if (i != 0) { ImGui::SameLine(); }
            i++;
            std::stringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << std::hex << +byte;
            std::string strHex(strstream.str());
            ImGui::TextColored(ImVec4(0.937f, 0.913f, 0.529f, 1.0f), strHex.c_str());
            ImGui::Indent(30.0f);
            unindent += 30.0f;
        }
        for (auto byte : (*trace)[debugger->selectedTrace-1].bytes)
        {
            ImGui::SameLine();
            std::stringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << std::hex << +byte;
            std::string strHex(strstream.str());
            ImGui::Text(strHex.c_str());
            ImGui::Indent(30.0f);
            unindent += 30.0f;
        }
        ImGui::Unindent(120.0f + unindent);
    }

    ImGui::EndChild();
    ImGui::EndGroup();

    ImGui::End();
}

void Gui::renderMemoryEditor()
{
    static MemoryEditor memory_editor;
    memory_editor.Draw("Memory", m_emu->getMemory()->memory, m_emu->getMemory()->size);
}

void Gui::uploadTextures()
{
    for (auto texture : TEXTURE_FILES)
    {
        int x, y, n;
        unsigned char *data = stbi_load(texture.second.c_str(), &x, &y, &n, 0);
        GLuint id;
        glGenTextures(1, &id);
        glLogLastError();
        m_textureIDs.insert(std::pair<std::string, GLuint>(texture.first, id));
        glBindTexture(GL_TEXTURE_2D, id);
        glLogLastError();
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glLogLastError();
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glLogLastError();
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glLogLastError();
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glLogLastError();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glLogLastError();
        stbi_image_free(data);
    }
}

void Gui::renderVirtualKeyboard()
{
    m_virtualKeyboardPressedKeys.clear();

    ImGui::SetNextWindowSize(ImVec2(760,500), ImGuiSetCond_Once);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f,0.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(512, 205.75f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::SetNextWindowSizeConstraints(ImVec2(512, 205.75f), ImVec2(FLT_MAX, FLT_MAX),
        [](ImGuiSizeConstraintCallbackData* data){
            // Keep aspect ratio
            float aspectRatio = data->DesiredSize.x / data->DesiredSize.y;
            const float epsilon = 0.0001f;
            const float desiredAspect = /*2.48845f*/ KEYBOARD_TEXTURE_WIDTH / KEYBOARD_TEXTURE_HEIGHT;
            if (aspectRatio > desiredAspect + epsilon || aspectRatio < desiredAspect - epsilon)
            {
                data->DesiredSize.y = data->DesiredSize.x / desiredAspect;
            }
        });
    if (!ImGui::Begin("Virtual keyboard", &m_renderVirtualKeyboard, 
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse ))
    {
        ImGui::End();
        ImGui::PopStyleVar(3);
        return;
    }

    // Background
    ImGui::Image((void *)(intptr_t)(m_textureIDs["TEXTURE_KEYBOARD"]), ImGui::GetWindowSize(),
        ImVec2(0,0), ImVec2(1.0f, 1.0f));
    
    ImVec2 textureSize = ImVec2(KEYBOARD_TEXTURE_WIDTH, KEYBOARD_TEXTURE_HEIGHT);

    int i = 0;

    // Render the keys
    for (auto key : keyPositionsSizes)
    {
        ImVec2 windowSize = ImGui::GetWindowSize();
        ImVec2 normalizedPosition = ImVec2(key.second.first.x / textureSize.x, key.second.first.y / textureSize.y);
        ImVec2 normalizedSize = ImVec2(key.second.second.x / textureSize.x, key.second.second.y / textureSize.y);
        ImVec2 inWindowSize = ImVec2(normalizedSize.x * windowSize.x, normalizedSize.y * windowSize.y);
        ImVec2 uvCorner = ImVec2(normalizedPosition.x + normalizedSize.x, normalizedPosition.y + normalizedSize.y);
        ImVec2 inWindowPosition = ImVec2(normalizedPosition.x * windowSize.x, normalizedPosition.y * windowSize.y + TITLEBAR_HEIGHT);

        ImGui::PushID(i);
        ImGui::SetCursorPos(inWindowPosition);
        if (
            ImGui::ImageButton(
                    (void*)(intptr_t)(m_textureIDs["TEXTURE_KEYBOARD"]),
                    inWindowSize, normalizedPosition, uvCorner, 0, ImColor(0,0,0,255)
                )
           )
        {
            m_virtualKeyboardPressedKeys.push_back(key.first);
        }
        ImGui::PopID();
        i++;
    }

    ImGui::End();
    ImGui::PopStyleVar(3);
}

std::vector<std::string>* Gui::getVirtualKeyboardPressedKeys()
{
    return &m_virtualKeyboardPressedKeys;
}
