void translateVMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* Col=M103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=N103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    a64.vTmpIdx = xt_push_vreg();
  }
  /* Col=O103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    a64.zTmpIdx = xt_push_zreg();
  }
  /* Col=P103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    CodeGeneratorAArch64::ld1(xa::VReg(a64.vTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Q103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::ld1r(xa::VReg(a64.vTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=R103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::ld1rw(xa::ZReg(a64.zTmpIdx).s,
                                xa::PReg(a64.maskIdx) / xa::T_z,
                                xa::ptr(X_TMP_ADDR));
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::not_(P_TMP_0.b, P_ALL_ONE.b, xa::PRegB(a64.maskIdx));
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b,
                              xa::PRegB(a64.maskIdx));
  }
  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    CodeGeneratorAArch64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b,
                              xa::PRegB(a64.maskIdx));
  }
  /* Col=W103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG)) {
    CodeGeneratorAArch64::fmul(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.srcIdx).s4,
                               xa::VReg(a64.src2Idx).s4);
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    CodeGeneratorAArch64::fmul(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.srcIdx).s4,
                               xa::VReg(a64.vTmpIdx).s4);
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG)) {
    CodeGeneratorAArch64::fmul(xa::ZReg(a64.dstIdx).s, xa::ZReg(a64.srcIdx).s,
                               xa::ZReg(a64.src2Idx).s);
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::fmul(xa::ZReg(a64.dstIdx).s, xa::ZReg(a64.srcIdx).s,
                               xa::ZReg(a64.zTmpIdx).s);
  }
  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG)) {
    CodeGeneratorAArch64::fmul(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s,
                               xa::ZReg(a64.src2Idx).s);
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::fmul(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s,
                               xa::ZReg(a64.zTmpIdx).s);
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    xt_pop_vreg();
  }
  /* Col=AD103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    xt_pop_zreg();
  }
  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=AG103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_TMP_0 / xa::T_m, 0);
  }
  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST)) {
    CodeGeneratorAArch64::mov(xa::ZRegS(a64.dstIdx),
                              xa::PReg(a64.maskIdx) / xa::T_m,
                              xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AI103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MBCST) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM)) {
    xt_pop_zreg(); // In some cases, xt_pop_zreg() should be called here.
  }
}
