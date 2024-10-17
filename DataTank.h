#pragma once
#include <stdio.h>

#include "Vector.h"
#include "Any.h"

struct TankItem {
	Any T;
	Any M;
	Any I;
};

TankItem ConstructTankItem(const Any& T, const Any& M);
bool WrireI(TankItem& In, const Any& B);
bool Free(TankItem& In);
DataTank ConstructDataTank();
bool Free(DataTank& In);
TankItem* Index(DataTank& In, size_t P);