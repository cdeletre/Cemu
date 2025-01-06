#pragma once

#include "HW/Espresso/Recompiler/IML/IMLInstruction.h"
#include "../PPCRecompiler.h"
struct CodeContext
{
	virtual ~CodeContext() = default;
};

std::unique_ptr<CodeContext> PPCRecompiler_generateAArch64Code(struct PPCRecFunction_t* PPCRecFunction, struct ppcImlGenContext_t* ppcImlGenContext);

void PPCRecompilerAArch64Gen_generateRecompilerInterfaceFunctions();

// architecture specific constants
namespace IMLArchAArch64
{
	static constexpr int PHYSREG_GPR_BASE = 0;
	static constexpr int PHYSREG_GPR_COUNT = 25;
	static constexpr int PHYSREG_FPR_BASE = PHYSREG_GPR_COUNT;
	static constexpr int PHYSREG_FPR_COUNT = 29;
}; // namespace IMLArchAArch64