#include "DataTank.h"

TankItem ConstructTankItem(const Any& T, const Any& M) {
	TankItem TI;
	TI.T = ConstructAny(T);
	TI.M = ConstructAny(M);
	TI.I = ConstructAny(0xdeadbeef);

	return TI;
}
bool WrireI(TankItem& In, const Any& B) {
	Free(In.I);
	In.I = ConstructAny(B);
	return true;
}
bool Free(TankItem& In) {
	Free(In.T);
	Free(In.M);
	Free(In.I);

	return true;
}

DataTank ConstructDataTank() {
	DataTank D;
	D.V = ConstructVector<TankItem>(16);

	return D;
}
bool Free(DataTank& In) {
	for (size_t i = 0; i < Size(In.V); i++) {
		if (Index(In.V, i) == NULL) { return false; }
		Free(Index(In.V, i)->T);
		Free(Index(In.V, i)->M);
		Free(Index(In.V, i)->I);
	}
	Free(In.V);

	return true;
}

TankItem* Index(DataTank& In, size_t P) {
	return Index(In.V, P);
}