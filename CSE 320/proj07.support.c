#include <stdio.h>
#include "/user/cse320/Projects/project07.hardware.h"

unsigned int sign_bit(unsigned int a){return a >> 31;}

unsigned int set_C_and_V_add(unsigned int a, unsigned int b, unsigned int c, unsigned
    int nzcv){
    if((sign_bit(a) && sign_bit(b)) || (!sign_bit(c) && (sign_bit(a) || sign_bit(b)))){
        nzcv = nzcv | 0x2;
    }
    if((sign_bit(a) == sign_bit(b)) && (sign_bit(c) != sign_bit(a))){
        nzcv = nzcv | 0x1;
    }
    return nzcv;
}

unsigned int set_C_and_V_sub(unsigned int a, unsigned int b, unsigned int c,
    unsigned int nzcv){
    if((!sign_bit(a) && sign_bit(b)) || (sign_bit(c) && (!sign_bit(a) || sign_bit(b)))){
        nzcv = nzcv | 0x2;
    }
    if((sign_bit(a) != sign_bit(b)) && (sign_bit(c) == sign_bit(b))){
        nzcv = nzcv | 0x1;
    }
    return nzcv;
}

void execute(){
    unsigned int I = (IR & 0x02000000) >> 25;
    unsigned int opcode = (IR & 0x01e00000) >> 21;
    unsigned int S = (IR & 0x00100000) >> 20;
    unsigned int Rn = (IR & 0x000f0000) >> 16;
    unsigned int Rd = (IR & 0x0000f000) >> 12;
    unsigned int immediate_val = IR & 0x000000ff;
    unsigned int Rm = IR & 0x0000000f;
    
    unsigned int C = (CPSR & 0x20000000) >> 29;
    
    
    // if the first 6 bits are not 111000, or bits 11:8 are not 0000, or I is set to 0 and bits 7:4 are not 0000
    if ((IR & 0xe0000000) != 0xe0000000 || (IR & 0x00000f00) != 0x00000000 || 
    (I == 0x00000000 && ((IR & 0x000000f0) != 0x0))){
        // set the illegal bit to 1
        CPSR = CPSR | 0x00000001;
        return;
    }
    else{
      CPSR = (CPSR & 0xfffffffe);
    }
    signal4 NZCV = 0x0;
    signal4 rd = Rd;
    signal4 rs1 = Rn;
    signal4 rs2 = Rm;
    signal32 operand1 = 0x0;
    signal32 operand2 = 0x0;
    signal32 RD = 0x0;
    
    read_reg_file( rs1, rs2, &operand1, &operand2 );
    if (I){operand2 = immediate_val;}
    
    
    switch(opcode) {
        
        case 0x0:  // and
            RD = operand1 & operand2;
            write_reg_file(rd, RD);
        case 0x1:  // eor
            RD = operand1 ^ operand2;
            write_reg_file(rd, RD);
        case 0x2:  // sub
            RD = operand1 - operand2;
            write_reg_file(rd, RD);
        case 0x3:  // rsb
            RD = operand2 - operand1;
            write_reg_file(rd, RD);
        case 0x4:  // add
            RD = operand1 + operand2;
            write_reg_file(rd, RD);
            NZCV = set_C_and_V_add(operand1, operand2, RD, NZCV);
            
        case 0x5:  // adc
            RD = operand1 + operand2 + C;
            write_reg_file(rd, RD);
            NZCV = set_C_and_V_add(operand1, operand2, RD, NZCV);
        case 0x6:  // sbc
            if (C){C = 0x0;}
            else {C = 0x1;}
            RD = operand1 - operand2 - C;
            write_reg_file(rd, RD);
            NZCV = set_C_and_V_sub(operand1, operand2, RD, NZCV);
            
        case 0x7:  // rsc
            if (C){C = 0x0;}
            else {C = 0x1;}
            RD = operand2 - operand1 - C;
            write_reg_file(rd, RD);
            NZCV = set_C_and_V_sub(operand1, operand2, RD, NZCV);
        case 0x8:  // tst
            RD = operand1 & operand2;
        case 0x9:  // teq
            RD = operand1 ^ operand2;
        case 0xa:  // cmp
            RD = operand1 - operand2;
            NZCV = set_C_and_V_sub(operand1, operand2, RD, NZCV);
        case 0xb:  // cmn
            RD = operand1 + operand2;
            NZCV = set_C_and_V_add(operand1, operand2, RD, NZCV);
        case 0xc:  // orr
            RD = operand1 | operand2;
            write_reg_file(rd, RD);
        case 0xd:  // mov
            RD = operand2;
            write_reg_file(rd, RD);
        case 0xe:  // bic
            RD = operand1 & ~operand2;
            write_reg_file(rd, RD);
        case 0xf:  // mvn
            RD = ~operand2;
            write_reg_file(rd, RD);
    }
    if(sign_bit(RD) == 0x1){NZCV = NZCV | 0x8;}
    if((RD & 0x0) == 0x0){NZCV = NZCV | 0x4;}
    
    if(S){
        CPSR = ((CPSR & 0x0fffffff) | (NZCV << 27));
    }
}

