#include "Instruction.h"



Instruction::Instruction()
// Creates a default instruction that has the opcode UNDEFINED
{
  myOpcode = UNDEFINED;
  myRS = myRT = myRD = NumRegisters;
}

Instruction::Instruction(Opcode op, Register rs, Register rt, Register rd, int imm)
// Constructs new instruction and initializes fields according to arguments:
// opcode, first source register, second source register, destination
// register, and immediate value
{
  setValues(op, rs, rt, rd, imm);
}

void Instruction::setValues(Opcode op, Register rs, Register rt, Register rd, int imm)
// Allows you to set all the fields of the Instruction:
// opcode, first source register, second source register, destination
// register, and immediate value
{

  myOpcode = op;
  if(op < 0 || op >= UNDEFINED)
    myOpcode = UNDEFINED;

  myRS = rs;
  if(rs < 0 || rs >= NumRegisters)
    myRS = NumRegisters;

  myRT = rt;
  if(rt < 0 || rt >= NumRegisters)
    myRT = NumRegisters;

  myRD = rd;
  if(rd < 0 || rd >= NumRegisters)
    myRD = NumRegisters;

  myImmediate = imm;

  //  if(!( (imm & 0xFFFF0000) << 1))  // make sure it has nothing in upper 16 bits
  //    myImmediate = imm;  

}

string Instruction::getString()
// Returns a string which represents all of the fields 
{
  stringstream s ;
  s << "OP: \t" << myOpcode << "\t" << "RD: " << myRD << "\t" << 
    "RS: " << myRS << "\t" << "RT: " << "\t" << myRT << "\t" <<
    "Imm: " << myImmediate;
  
  return s.str();
  
}

