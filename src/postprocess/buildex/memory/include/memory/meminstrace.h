#ifndef _MEMINSTRACE_H
#define _MEMINSTRACE_H

#include <memory/memregions.h>

#include <analysis/x86_analysis.h>

#include <common/meminfo.h>

#include <fstream>
#include <vector>

void create_mem_layout(
    std::ifstream& in, std::vector<mem_info_t*>& mem_info, uint32_t version);
void create_mem_layout(
    std::ifstream& in, std::vector<pc_mem_region_t*>& pc_mems,
    uint32_t version);

void create_mem_layout(
    std::vector<cinstr_t*>& instrs, std::vector<mem_info_t*>& mem_info);
void create_mem_layout(
    std::vector<cinstr_t*>& instrs, std::vector<pc_mem_region_t*>& pc_mems);

#endif
