void translateSUB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/14 21:41 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_REG && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    add_imm(Xbyak_aarch64::WReg(a64.dstIdx), Xbyak_aarch64::WReg(a64.dstIdx),
            static_cast<uint32_t>(a64.uimm), W_TMP_0, W_TMP_1);
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_REG && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_IMM && true)) {
    sub_imm(Xbyak_aarch64::XReg(a64.dstIdx), Xbyak_aarch64::XReg(a64.dstIdx),
            a64.uimm, X_TMP_0, X_TMP_1);
  }

  /* Col=W103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_REG && a64.EVEXb == MEM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_subR));
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_REG && a64.EVEXb == MEM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(X_TMP_0, xa::ptr(X_TMP_subR));
  }

  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    CodeGeneratorAArch64::sub_imm(
        W_TMP_0, W_TMP_0, static_cast<uint32_t>(a64.uimm), W_TMP_1, W_TMP_2);
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::sub_imm(X_TMP_0, X_TMP_0, a64.uimm, X_TMP_1, X_TMP_2);
  }

  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_REG && a64.EVEXb == REG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx),
                              xa::WReg(a64.srcIdx));
  }
  /* Col=AF103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_REG && a64.EVEXb == REG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx),
                              xa::XReg(a64.srcIdx));
  }

  /* Col=AJ103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(W_TMP_0, W_TMP_0, xa::WReg(a64.srcIdx));
  }
  /* Col=AK103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(X_TMP_0, X_TMP_0, xa::XReg(a64.srcIdx));
  }

  /* Col=AQ103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_REG && a64.EVEXb == MEM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::sub(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx),
                              W_TMP_0);
  }
  /* Col=AR103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_REG && a64.EVEXb == MEM &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::sub(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx),
                              X_TMP_0);
  }

  /* Col=AT103*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(W_TMP_0, xa::ptr(X_TMP_subR));
  }
  /* Col=AU103*/
  if (false ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == IMM &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_MEM && a64.EVEXb == REG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(X_TMP_0, xa::ptr(X_TMP_subR));
  }
}
