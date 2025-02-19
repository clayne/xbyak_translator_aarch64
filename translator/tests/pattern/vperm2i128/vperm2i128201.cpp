/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#include "test_generator2.h"

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
/* Here write JIT code with x86_64 mnemonic function to be tested. */
/* z31 - z29 are used as zTmpIdx - zTmp3Idx */

/* VEX */
#define IMM 1
    vperm2i128(Ymm(0), Ymm(14), Ymm(15),
               (0x0 << 6) + (IMM << 4) + (0x1 << 2) + IMM);
    vperm2i128(Ymm(1), Ymm(14), Ymm(15),
               (0x0 << 6) + (IMM << 4) + (0x2 << 2) + IMM);
    vperm2i128(Ymm(2), Ymm(14), Ymm(15),
               (0x0 << 6) + (IMM << 4) + (0x3 << 2) + IMM);
    vperm2i128(Ymm(3), Ymm(14), Ymm(15),
               (0x1 << 6) + (IMM << 4) + (0x1 << 2) + IMM);
    vperm2i128(Ymm(4), Ymm(14), Ymm(15),
               (0x1 << 6) + (IMM << 4) + (0x2 << 2) + IMM);
    vperm2i128(Ymm(5), Ymm(14), Ymm(15),
               (0x1 << 6) + (IMM << 4) + (0x3 << 2) + IMM);

    vperm2i128(Ymm(6), Ymm(14), Ymm(15),
               (0x2 << 6) + (IMM << 4) + (0x1 << 2) + IMM);
    vperm2i128(Ymm(7), Ymm(14), Ymm(15),
               (0x3 << 6) + (IMM << 4) + (0x2 << 2) + IMM);
    vperm2i128(Ymm(8), Ymm(14), Ymm(15),
               (0x2 << 6) + (IMM << 4) + (0x3 << 2) + IMM);
    vperm2i128(Ymm(9), Ymm(14), Ymm(15),
               (0x3 << 6) + (IMM << 4) + (0x1 << 2) + IMM);
    vperm2i128(Ymm(10), Ymm(14), Ymm(15),
               (0x3 << 6) + (IMM << 4) + (0x2 << 2) + IMM);
    vperm2i128(Ymm(11), Ymm(14), Ymm(15),
               (0x3 << 6) + (IMM << 4) + (0x3 << 2) + IMM);
  }
};

int main(int argc, char *argv[]) {
  /* Initializing arrays of inputData, inputGenReg, inputPredReg, inputZReg,
   * checkGenRegMode, checkPredRegMode,checkZRegMode */
  TestPtnGenerator gen;

  /* Set bool output_jit_on_, bool exec_jit_on_ = 0; */
  gen.parseArgs(argc, argv);

  /* Generate JIT code and get function pointer */
  void (*f)();
  if (gen.isOutputJitOn()) {
    f = (void (*)())gen.gen();
  }

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
     * inputZReg. */
    gen.dumpInputReg();
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
