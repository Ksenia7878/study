#pragma once
#include "spisok_Node.h"
#include "Node.h"
#include "Dec.h"


int proverka_meni1();
int proverka_meni0();
int proverka_meni();
void vvod(Dec<Payment>& macc, int index);
void vvivod(Dec<Payment>& macc);

int proverka_index3();
int proverka_index4(int polizovatel, size_t size);
void zapici_10(std::vector<Payment*>& macciv1);
int zapici_12(std::vector<Payment*>& macciv);
void zapic_binary(std::vector<Payment*>& macciv);
int izfaila_bin(std::vector<Payment*>& macciv1);
void perezapic(std::vector<Payment*>& macciv);
int proverka_index012();