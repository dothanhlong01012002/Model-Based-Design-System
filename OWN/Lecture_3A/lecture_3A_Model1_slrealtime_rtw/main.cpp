/* Main generated for Simulink Real-Time model lecture_3A_Model1 */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "lecture_3A_Model1.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(lecture_3A_Model1_step), slrealtime::TaskInfo::PERIODIC, 0.0001, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo lecture_3A_Model1_Info =
{
    "lecture_3A_Model1",
    lecture_3A_Model1_initialize,
    lecture_3A_Model1_terminate,
    []()->char const*& { return lecture_3A_Model1_M->errorStatus; },
    []()->unsigned char& { return lecture_3A_Model1_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::SegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, lecture_3A_Model1_Info);
}
