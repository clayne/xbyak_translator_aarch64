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
    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    inputZReg[0].sp_dt[0] = 0.0f;
    inputZReg[0].sp_dt[1] = 0.4f;
    inputZReg[0].sp_dt[2] = 0.5f;
    inputZReg[0].sp_dt[3] = 0.6f;
    inputZReg[0].sp_dt[4] = 1.4f;
    inputZReg[0].sp_dt[5] = 1.5f;
    inputZReg[0].sp_dt[6] = 1.6f;
    inputZReg[0].sp_dt[7] = 2.4f;
    inputZReg[0].sp_dt[8] = 2.5f;
    inputZReg[0].sp_dt[9] = 2.6f;
    inputZReg[0].sp_dt[10] = 3.5f;
    inputZReg[0].sp_dt[11] = 4.5f;
    inputZReg[0].sp_dt[12] = 5.5f;
    inputZReg[0].us_dt[13] = 0x4efffffd;
    inputZReg[0].us_dt[14] = 0x4efffffe;
    inputZReg[0].us_dt[15] =
        0x4effffff; /* max float number represented by int32_t */

    inputZReg[1].sp_dt[0] = 0.0f;
    inputZReg[1].sp_dt[1] = -0.4f;
    inputZReg[1].sp_dt[2] = -0.5f;
    inputZReg[1].sp_dt[3] = -0.6f;
    inputZReg[1].sp_dt[4] = -1.4f;
    inputZReg[1].sp_dt[5] = -1.5f;
    inputZReg[1].sp_dt[6] = -1.6f;
    inputZReg[1].sp_dt[7] = -2.4f;
    inputZReg[1].sp_dt[8] = -2.5f;
    inputZReg[1].sp_dt[9] = -2.6f;
    inputZReg[1].sp_dt[10] = -3.5f;
    inputZReg[1].sp_dt[11] = -4.5f;
    inputZReg[1].sp_dt[12] = -5.5f;
    inputZReg[1].us_dt[13] = 0xcefffffd;
    inputZReg[1].us_dt[14] = 0xcefffffe;
    inputZReg[1].us_dt[15] =
        0xceffffff; /* min float number represented by int32_t */

    for (int j = 2; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        while (inputZReg[j].sp_dt[i] < -2.14748352e+9 ||
               2.14748352e+9 < inputZReg[j].sp_dt[i]) {
          inputZReg[j].uh_dt[2 * i + 0] = getLfsr();
          inputZReg[j].uh_dt[2 * i + 1] = getLfsr();
        }
      }
    }

#if 1
    for (int j = 16; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        float scale = pow(2.0f, (float)(j - 16));
        inputZReg[j].sp_dt[i] /= scale;
      }
    }
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
/* Here write JIT code with x86_64 mnemonic function to be tested. */
/* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
 * r15 */

#if 0 // rounding_direction=0 round_to_nearest_even_interger
    /* Register index is VEX range. */
    vrndscaleps(Zmm(2), Zmm(0), 0x04);
    vrndscaleps(Zmm(3), Zmm(1), 0x04);
    vrndscaleps(Zmm(4), Zmm(0), 0x14);
    vrndscaleps(Zmm(5), Zmm(1), 0x14);
    vrndscaleps(Zmm(6), Zmm(0), 0x24);
    vrndscaleps(Zmm(7), Zmm(1), 0x24);
    vrndscaleps(Zmm(8), Zmm(0), 0x54);
    vrndscaleps(Zmm(9), Zmm(1), 0x54);
    vrndscaleps(Zmm(10), Zmm(0), 0xa4);
    vrndscaleps(Zmm(11), Zmm(1), 0xa4);
    vrndscaleps(Zmm(12), Zmm(0), 0xc4);
    vrndscaleps(Zmm(13), Zmm(1), 0xc4);
    vrndscaleps(Zmm(14), Zmm(0), 0xf4);
    vrndscaleps(Zmm(15), Zmm(1), 0xf4);

    /* Register index is EVEX range. */
    vrndscaleps(Zmm(16), Zmm(16), 0x04); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(17), Zmm(17), 0x14); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(18), Zmm(18), 0x24); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(19), Zmm(19), 0x34); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(20), Zmm(20), 0x44); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(21), Zmm(21), 0x54); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(22), Zmm(22), 0x64); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(23), Zmm(23), 0x74); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(24), Zmm(24), 0x84); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(25), Zmm(25), 0x94); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(26), Zmm(26), 0xa4); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(27), Zmm(27), 0xb4); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(28), Zmm(28), 0xc4); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(29), Zmm(29), 0xd4); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(30), Zmm(30), 0xe4); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(31), Zmm(31), 0xf4); /* dstIdx = srcIdx */
#else // rounding_direction=3 round_to_nearest_smallest_magnitude_integer
    /* Register index is VEX range. */
    vrndscaleps(Zmm(2), Zmm(0), 0x03);
    vrndscaleps(Zmm(3), Zmm(1), 0x03);
    vrndscaleps(Zmm(4), Zmm(0), 0x13);
    vrndscaleps(Zmm(5), Zmm(1), 0x13);
    vrndscaleps(Zmm(6), Zmm(0), 0x23);
    vrndscaleps(Zmm(7), Zmm(1), 0x23);
    vrndscaleps(Zmm(8), Zmm(0), 0x53);
    vrndscaleps(Zmm(9), Zmm(1), 0x53);
    vrndscaleps(Zmm(10), Zmm(0), 0xa3);
    vrndscaleps(Zmm(11), Zmm(1), 0xa3);
    vrndscaleps(Zmm(12), Zmm(0), 0xc3);
    vrndscaleps(Zmm(13), Zmm(1), 0xc3);
    vrndscaleps(Zmm(14), Zmm(0), 0xf3);
    vrndscaleps(Zmm(15), Zmm(1), 0xf3);

    /* Register index is EVEX range. */
    vrndscaleps(Zmm(16), Zmm(16), 0x03); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(17), Zmm(17), 0x13); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(18), Zmm(18), 0x23); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(19), Zmm(19), 0x33); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(20), Zmm(20), 0x43); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(21), Zmm(21), 0x53); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(22), Zmm(22), 0x63); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(23), Zmm(23), 0x73); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(24), Zmm(24), 0x83); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(25), Zmm(25), 0x93); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(26), Zmm(26), 0xa3); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(27), Zmm(27), 0xb3); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(28), Zmm(28), 0xc3); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(29), Zmm(29), 0xd3); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(30), Zmm(30), 0xe3); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(31), Zmm(31), 0xf3); /* dstIdx = srcIdx */
#endif
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
