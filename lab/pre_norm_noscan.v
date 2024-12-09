
module pre_norm_DW_cmp_0 ( A, B, TC, GE_LT, GE_GT_EQ, GE_LT_GT_LE, EQ_NE );
  input [26:0] A;
  input [26:0] B;
  input TC, GE_LT, GE_GT_EQ;
  output GE_LT_GT_LE, EQ_NE;
  wire   n238, n158, n159, n160, n161, n162, n163, n164, n165, n166, n167,
         n168, n169, n170, n171, n172, n173, n174, n175, n176, n177, n178,
         n179, n180, n181, n182, n183, n184, n185, n186, n187, n188, n189,
         n190, n191, n192, n193, n194, n195, n196, n197, n198, n199, n200,
         n201, n202, n203, n204, n205, n206, n207, n208, n209, n210, n211,
         n212, n213, n214, n215, n216, n217, n218, n219, n220, n221, n222,
         n223, n224, n225, n226, n227, n228, n229, n230, n231, n232, n233,
         n234, n235, n236, n237;

  INVM0N U71 ( .A(n195), .Z(n165) );
  OAI22M1N U72 ( .A1(B[21]), .A2(n176), .B1(B[21]), .B2(n195), .Z(n194) );
  INVM2N U73 ( .A(n219), .Z(n164) );
  INVM2N U74 ( .A(B[26]), .Z(n173) );
  CKBUFM2N U75 ( .A(n238), .Z(GE_LT_GT_LE) );
  INVM2N U76 ( .A(A[3]), .Z(n163) );
  INVM2N U77 ( .A(A[21]), .Z(n176) );
  INVM2N U78 ( .A(B[18]), .Z(n166) );
  INVM2N U79 ( .A(A[17]), .Z(n167) );
  INVM2N U80 ( .A(A[12]), .Z(n171) );
  INVM2N U81 ( .A(A[8]), .Z(n159) );
  INVM2N U82 ( .A(A[23]), .Z(n178) );
  INVM2N U83 ( .A(B[4]), .Z(n162) );
  INVM2N U84 ( .A(B[13]), .Z(n170) );
  INVM2N U85 ( .A(B[6]), .Z(n160) );
  INVM2N U86 ( .A(B[9]), .Z(n158) );
  INVM2N U87 ( .A(A[5]), .Z(n161) );
  INVM2N U88 ( .A(A[10]), .Z(n172) );
  INVM2N U89 ( .A(B[15]), .Z(n168) );
  INVM2N U90 ( .A(B[24]), .Z(n179) );
  INVM2N U91 ( .A(B[20]), .Z(n175) );
  INVM2N U92 ( .A(A[14]), .Z(n169) );
  INVM2N U93 ( .A(A[25]), .Z(n180) );
  INVM2N U94 ( .A(A[19]), .Z(n174) );
  INVM2N U95 ( .A(B[22]), .Z(n177) );
  OAI21M0N U96 ( .A1(n181), .A2(n182), .B(n183), .Z(n238) );
  OAI222M0N U97 ( .A1(A[26]), .A2(n173), .B1(n173), .B2(n184), .C1(A[26]), 
        .C2(n184), .Z(n183) );
  OAI222M0N U98 ( .A1(B[25]), .A2(n180), .B1(B[25]), .B2(n185), .C1(n180), 
        .C2(n185), .Z(n184) );
  OAI222M0N U99 ( .A1(A[24]), .A2(n179), .B1(n179), .B2(n186), .C1(A[24]), 
        .C2(n186), .Z(n185) );
  OAI222M0N U100 ( .A1(B[23]), .A2(n178), .B1(B[23]), .B2(n187), .C1(n178), 
        .C2(n187), .Z(n186) );
  CKND2M2N U101 ( .A(A[22]), .B(n177), .Z(n187) );
  OAI21M0N U102 ( .A1(A[26]), .A2(n173), .B(n188), .Z(n182) );
  OAI22M0N U103 ( .A1(n189), .A2(n180), .B1(B[25]), .B2(n189), .Z(n188) );
  OAI21M0N U104 ( .A1(A[24]), .A2(n179), .B(n190), .Z(n189) );
  OAI22M0N U105 ( .A1(n191), .A2(n178), .B1(B[23]), .B2(n191), .Z(n190) );
  NR2M0N U106 ( .A(n177), .B(A[22]), .Z(n191) );
  AOI221M0N U107 ( .A1(A[21]), .A2(n165), .B1(n192), .B2(n193), .C(n194), .Z(
        n181) );
  OAI22M0N U108 ( .A1(n176), .A2(n196), .B1(B[21]), .B2(n196), .Z(n193) );
  OAI21M0N U109 ( .A1(A[20]), .A2(n175), .B(n197), .Z(n196) );
  OAI22M0N U110 ( .A1(n174), .A2(n198), .B1(B[19]), .B2(n198), .Z(n197) );
  OAI222M0N U111 ( .A1(A[18]), .A2(n166), .B1(n166), .B2(n199), .C1(A[18]), 
        .C2(n199), .Z(n198) );
  OAI222M0N U112 ( .A1(B[17]), .A2(n167), .B1(B[17]), .B2(n200), .C1(n200), 
        .C2(n167), .Z(n199) );
  NR2B1M0N U113 ( .NA(B[16]), .B(A[16]), .Z(n200) );
  CKND2M2N U114 ( .A(n201), .B(n202), .Z(n192) );
  OAI211M0N U115 ( .A1(A[15]), .A2(n168), .B(n203), .C(n204), .Z(n202) );
  OAI221M0N U116 ( .A1(B[10]), .A2(n205), .B1(B[10]), .B2(n172), .C(n206), .Z(
        n204) );
  AOI22B20M0N U117 ( .B1(n207), .B2(n208), .NA1(n172), .NA2(n205), .Z(n206) );
  OAI22M0N U118 ( .A1(n172), .A2(n209), .B1(B[10]), .B2(n209), .Z(n208) );
  OAI21M0N U119 ( .A1(A[9]), .A2(n158), .B(n210), .Z(n209) );
  OAI22M0N U120 ( .A1(n211), .A2(n159), .B1(B[8]), .B2(n211), .Z(n210) );
  NR2B1M0N U121 ( .NA(B[7]), .B(A[7]), .Z(n211) );
  OAI21M0N U122 ( .A1(n212), .A2(n213), .B(n214), .Z(n207) );
  OAI222M0N U123 ( .A1(A[6]), .A2(n160), .B1(n160), .B2(n215), .C1(A[6]), .C2(
        n215), .Z(n214) );
  OAI222M0N U124 ( .A1(B[5]), .A2(n161), .B1(B[5]), .B2(n216), .C1(n161), .C2(
        n216), .Z(n215) );
  CKND2M2N U125 ( .A(A[4]), .B(n162), .Z(n216) );
  OAI21M0N U126 ( .A1(A[6]), .A2(n160), .B(n217), .Z(n213) );
  OAI22M0N U127 ( .A1(n218), .A2(n161), .B1(B[5]), .B2(n218), .Z(n217) );
  NR2M0N U128 ( .A(n162), .B(A[4]), .Z(n218) );
  AOI221M0N U129 ( .A1(A[3]), .A2(n219), .B1(n220), .B2(n221), .C(n222), .Z(
        n212) );
  OAI22M0N U130 ( .A1(B[3]), .A2(n163), .B1(B[3]), .B2(n164), .Z(n222) );
  OAI22M0N U131 ( .A1(n223), .A2(n163), .B1(B[3]), .B2(n223), .Z(n221) );
  NR2B1M0N U132 ( .NA(B[2]), .B(A[2]), .Z(n223) );
  AO22B10M0N U133 ( .B1(n224), .B2(A[0]), .A1(A[1]), .NA2(B[1]), .Z(n220) );
  AOI21B10M0N U134 ( .NA2(A[1]), .A1(B[1]), .B(B[0]), .Z(n224) );
  NR2B1M0N U135 ( .NA(A[2]), .B(B[2]), .Z(n219) );
  OAI222M0N U136 ( .A1(A[9]), .A2(n158), .B1(n225), .B2(n158), .C1(A[9]), .C2(
        n225), .Z(n205) );
  OAI222M0N U137 ( .A1(B[8]), .A2(n159), .B1(B[8]), .B2(n226), .C1(n226), .C2(
        n159), .Z(n225) );
  ND2B1M0N U138 ( .NA(B[7]), .B(A[7]), .Z(n226) );
  OAI22M0N U139 ( .A1(n227), .A2(n169), .B1(B[14]), .B2(n227), .Z(n203) );
  OAI222M0N U140 ( .A1(A[13]), .A2(n170), .B1(n228), .B2(n170), .C1(A[13]), 
        .C2(n228), .Z(n227) );
  OAI222M0N U141 ( .A1(B[12]), .A2(n171), .B1(B[12]), .B2(n229), .C1(n229), 
        .C2(n171), .Z(n228) );
  NR2B1M0N U142 ( .NA(B[11]), .B(A[11]), .Z(n229) );
  OAI222M0N U143 ( .A1(A[15]), .A2(n168), .B1(n168), .B2(n230), .C1(A[15]), 
        .C2(n230), .Z(n201) );
  OAI222M0N U144 ( .A1(B[14]), .A2(n169), .B1(B[14]), .B2(n231), .C1(n169), 
        .C2(n231), .Z(n230) );
  OAI222M0N U145 ( .A1(A[13]), .A2(n170), .B1(n170), .B2(n232), .C1(A[13]), 
        .C2(n232), .Z(n231) );
  OAI222M0N U146 ( .A1(B[12]), .A2(n171), .B1(B[12]), .B2(n233), .C1(n171), 
        .C2(n233), .Z(n232) );
  ND2B1M0N U147 ( .NA(B[11]), .B(A[11]), .Z(n233) );
  OAI222M0N U148 ( .A1(A[20]), .A2(n175), .B1(n234), .B2(n175), .C1(A[20]), 
        .C2(n234), .Z(n195) );
  OAI222M0N U149 ( .A1(B[19]), .A2(n174), .B1(B[19]), .B2(n235), .C1(n235), 
        .C2(n174), .Z(n234) );
  OAI222M0N U150 ( .A1(A[18]), .A2(n166), .B1(n236), .B2(n166), .C1(A[18]), 
        .C2(n236), .Z(n235) );
  OAI222M0N U151 ( .A1(B[17]), .A2(n167), .B1(B[17]), .B2(n237), .C1(n237), 
        .C2(n167), .Z(n236) );
  ND2B1M0N U152 ( .NA(B[16]), .B(A[16]), .Z(n237) );
endmodule


module pre_norm_DW_rightsh_0 ( A, DATA_TC, SH, B );
  input [26:0] A;
  input [4:0] SH;
  output [26:0] B;
  input DATA_TC;
  wire   n172, n173, n174, n175, n176, n177, n178, n179, n180, n181, n182,
         n183, n184, n185, n186, n187, n188, n189, n190, n191, n192, n193,
         n194, n195, n196, n197, n198, n199, n200, n201, n202, n203, n204,
         n205, n206, n207, n208, n209, n210, n211, n212, n213, n214, n215,
         n216, n217, n218, n219, n220, n221, n222, n223, n224, n225, n226,
         n227, n228, n229, n230, n231, n232, n233, n234, n235, n236, n237,
         n238, n239, n240, n241, n242, n243, n244, n245, n246, n247, n248,
         n249, n250, n251, n252, n253, n254, n255, n256, n257, n258, n259,
         n260, n261, n262, n263, n264, n265, n266, n267, n268, n269, n270,
         n271, n272, n273, n274, n275, n276, n277, n278, n279, n280, n281,
         n282, n283, n284, n285;

  BUFM4N U137 ( .A(SH[2]), .Z(n174) );
  BUFM4N U138 ( .A(SH[4]), .Z(n177) );
  BUFM4N U139 ( .A(n179), .Z(n173) );
  INVM4N U140 ( .A(n176), .Z(n175) );
  INVM2N U141 ( .A(n172), .Z(n178) );
  INVM2N U142 ( .A(SH[0]), .Z(n179) );
  BUFM4N U143 ( .A(SH[3]), .Z(n172) );
  INVM2N U144 ( .A(SH[1]), .Z(n176) );
  MXB2DM0N U145 ( .A(n180), .B(n181), .S(n177), .Z(B[9]) );
  MXB2DM0N U146 ( .A(n182), .B(n183), .S(n172), .Z(n180) );
  MXB2DM0N U147 ( .A(n184), .B(n185), .S(n177), .Z(B[8]) );
  MXB2DM0N U148 ( .A(n186), .B(n187), .S(n172), .Z(n184) );
  MXB2DM0N U149 ( .A(n188), .B(n189), .S(n177), .Z(B[7]) );
  MXB2DM0N U150 ( .A(n190), .B(n191), .S(n172), .Z(n188) );
  MXB2DM0N U151 ( .A(n192), .B(n193), .S(n174), .Z(n190) );
  MXB2DM0N U152 ( .A(n194), .B(n195), .S(n177), .Z(B[6]) );
  MXB2DM0N U153 ( .A(n196), .B(n197), .S(n172), .Z(n194) );
  MXB2DM0N U154 ( .A(n198), .B(n199), .S(n174), .Z(n196) );
  MXB2DM0N U155 ( .A(n200), .B(n201), .S(n177), .Z(B[5]) );
  MXB2DM0N U156 ( .A(n202), .B(n203), .S(n172), .Z(n200) );
  MXB2DM0N U157 ( .A(n204), .B(n205), .S(n174), .Z(n202) );
  MXB2DM0N U158 ( .A(n206), .B(n207), .S(n177), .Z(B[4]) );
  MXB2DM0N U159 ( .A(n208), .B(n209), .S(n172), .Z(n206) );
  MXB2DM0N U160 ( .A(n210), .B(n211), .S(n174), .Z(n208) );
  MXB2DM0N U161 ( .A(n212), .B(n213), .S(n177), .Z(B[3]) );
  MXB2DM0N U162 ( .A(n214), .B(n215), .S(n172), .Z(n212) );
  MXB2DM0N U163 ( .A(n216), .B(n192), .S(n174), .Z(n214) );
  MXB2DM0N U164 ( .A(n217), .B(n218), .S(n175), .Z(n192) );
  MXB2DM0N U165 ( .A(n219), .B(n220), .S(n175), .Z(n216) );
  MXB2DM0N U166 ( .A(n221), .B(n222), .S(n177), .Z(B[2]) );
  MXB2DM0N U167 ( .A(n223), .B(n224), .S(n172), .Z(n221) );
  MXB2DM0N U168 ( .A(n225), .B(n198), .S(n174), .Z(n223) );
  MXB2DM0N U169 ( .A(n226), .B(n227), .S(SH[1]), .Z(n198) );
  MXB2DM0N U170 ( .A(n228), .B(n229), .S(SH[1]), .Z(n225) );
  NR2M0N U171 ( .A(n177), .B(n230), .Z(B[26]) );
  NR2M0N U172 ( .A(n177), .B(n181), .Z(B[25]) );
  CKND2M2N U173 ( .A(n231), .B(n178), .Z(n181) );
  NR2M0N U174 ( .A(n177), .B(n185), .Z(B[24]) );
  CKND2M2N U175 ( .A(n232), .B(n178), .Z(n185) );
  NR2M0N U176 ( .A(n177), .B(n189), .Z(B[23]) );
  CKND2M2N U177 ( .A(n233), .B(n178), .Z(n189) );
  NR2M0N U178 ( .A(n177), .B(n195), .Z(B[22]) );
  CKND2M2N U179 ( .A(n234), .B(n178), .Z(n195) );
  NR2M0N U180 ( .A(SH[4]), .B(n201), .Z(B[21]) );
  CKND2M2N U181 ( .A(n235), .B(n178), .Z(n201) );
  NR2M0N U182 ( .A(SH[4]), .B(n207), .Z(B[20]) );
  CKND2M2N U183 ( .A(n236), .B(n178), .Z(n207) );
  MXB2DM0N U184 ( .A(n237), .B(n238), .S(n177), .Z(B[1]) );
  MXB2DM0N U185 ( .A(n239), .B(n182), .S(n172), .Z(n237) );
  MXB2DM0N U186 ( .A(n205), .B(n240), .S(n174), .Z(n182) );
  MXB2DM0N U187 ( .A(n218), .B(n241), .S(SH[1]), .Z(n205) );
  CKMUX2M2N U188 ( .A(A[10]), .B(A[9]), .S(n173), .Z(n218) );
  MXB2DM0N U189 ( .A(n242), .B(n204), .S(n174), .Z(n239) );
  MXB2DM0N U190 ( .A(n220), .B(n217), .S(n175), .Z(n204) );
  CKMUX2M2N U191 ( .A(A[8]), .B(A[7]), .S(n173), .Z(n217) );
  CKMUX2M2N U192 ( .A(A[6]), .B(A[5]), .S(n173), .Z(n220) );
  CKND2M2N U193 ( .A(n175), .B(n219), .Z(n242) );
  CKMUX2M2N U194 ( .A(A[4]), .B(A[3]), .S(n173), .Z(n219) );
  NR2M0N U195 ( .A(n177), .B(n213), .Z(B[19]) );
  CKND2M2N U196 ( .A(n243), .B(n178), .Z(n213) );
  NR2M0N U197 ( .A(n177), .B(n222), .Z(B[18]) );
  MXB2DM0N U198 ( .A(n244), .B(n245), .S(n172), .Z(n222) );
  NR2M0N U199 ( .A(SH[4]), .B(n238), .Z(B[17]) );
  MXB2DM0N U200 ( .A(n183), .B(n231), .S(n172), .Z(n238) );
  NR2M0N U201 ( .A(n246), .B(n174), .Z(n231) );
  MXB2DM0N U202 ( .A(n247), .B(n248), .S(n174), .Z(n183) );
  NR2M0N U203 ( .A(SH[4]), .B(n249), .Z(B[16]) );
  NR2M0N U204 ( .A(SH[4]), .B(n250), .Z(B[15]) );
  MXB2DM0N U205 ( .A(n191), .B(n233), .S(n172), .Z(n250) );
  NR2M0N U206 ( .A(n251), .B(n174), .Z(n233) );
  MXB2DM0N U207 ( .A(n252), .B(n253), .S(n174), .Z(n191) );
  NR2M0N U208 ( .A(n177), .B(n254), .Z(B[14]) );
  MXB2DM0N U209 ( .A(n197), .B(n234), .S(n172), .Z(n254) );
  MXB2DM0N U210 ( .A(n255), .B(n256), .S(n174), .Z(n234) );
  MXB2DM0N U211 ( .A(n257), .B(n258), .S(n174), .Z(n197) );
  NR2M0N U212 ( .A(n177), .B(n259), .Z(B[13]) );
  MXB2DM0N U213 ( .A(n203), .B(n235), .S(n172), .Z(n259) );
  MXB2DM0N U214 ( .A(n248), .B(n246), .S(n174), .Z(n235) );
  CKND2M2N U215 ( .A(n260), .B(n176), .Z(n246) );
  MXB2DM0N U216 ( .A(n261), .B(n262), .S(n175), .Z(n248) );
  MXB2DM0N U217 ( .A(n240), .B(n247), .S(n174), .Z(n203) );
  MXB2DM0N U218 ( .A(n263), .B(n264), .S(n175), .Z(n247) );
  MXB2DM0N U219 ( .A(n265), .B(n266), .S(SH[1]), .Z(n240) );
  NR2M0N U220 ( .A(n177), .B(n267), .Z(B[12]) );
  MXB2DM0N U221 ( .A(n209), .B(n236), .S(n172), .Z(n267) );
  MXB2DM0N U222 ( .A(n268), .B(n269), .S(SH[2]), .Z(n236) );
  MXB2DM0N U223 ( .A(n270), .B(n271), .S(SH[2]), .Z(n209) );
  NR2M0N U224 ( .A(n177), .B(n272), .Z(B[11]) );
  MXB2DM0N U225 ( .A(n215), .B(n243), .S(n172), .Z(n272) );
  MXB2DM0N U226 ( .A(n253), .B(n251), .S(n174), .Z(n243) );
  MXB2DM0N U227 ( .A(n262), .B(n260), .S(n175), .Z(n251) );
  CKMUX2M2N U228 ( .A(A[26]), .B(A[25]), .S(n173), .Z(n260) );
  CKMUX2M2N U229 ( .A(A[24]), .B(A[23]), .S(n173), .Z(n262) );
  MXB2DM0N U230 ( .A(n264), .B(n261), .S(SH[1]), .Z(n253) );
  CKMUX2M2N U231 ( .A(A[22]), .B(A[21]), .S(n173), .Z(n261) );
  CKMUX2M2N U232 ( .A(A[20]), .B(A[19]), .S(n173), .Z(n264) );
  MXB2DM0N U233 ( .A(n193), .B(n252), .S(SH[2]), .Z(n215) );
  MXB2DM0N U234 ( .A(n266), .B(n263), .S(SH[1]), .Z(n252) );
  CKMUX2M2N U235 ( .A(A[18]), .B(A[17]), .S(n173), .Z(n263) );
  CKMUX2M2N U236 ( .A(A[16]), .B(A[15]), .S(n173), .Z(n266) );
  MXB2DM0N U237 ( .A(n241), .B(n265), .S(n175), .Z(n193) );
  CKMUX2M2N U238 ( .A(A[14]), .B(A[13]), .S(n173), .Z(n265) );
  CKMUX2M2N U239 ( .A(A[12]), .B(A[11]), .S(n173), .Z(n241) );
  MXB2DM0N U240 ( .A(n273), .B(n230), .S(n177), .Z(B[10]) );
  CKND2M2N U241 ( .A(n245), .B(n178), .Z(n230) );
  NR2M0N U242 ( .A(n256), .B(n174), .Z(n245) );
  CKND2M2N U243 ( .A(n274), .B(n176), .Z(n256) );
  MXB2DM0N U244 ( .A(n224), .B(n244), .S(n172), .Z(n273) );
  MXB2DM0N U245 ( .A(n258), .B(n255), .S(SH[2]), .Z(n244) );
  MXB2DM0N U246 ( .A(n275), .B(n276), .S(n175), .Z(n255) );
  MXB2DM0N U247 ( .A(n277), .B(n278), .S(n175), .Z(n258) );
  MXB2DM0N U248 ( .A(n199), .B(n257), .S(SH[2]), .Z(n224) );
  MXB2DM0N U249 ( .A(n279), .B(n280), .S(n175), .Z(n257) );
  MXB2DM0N U250 ( .A(n281), .B(n282), .S(n175), .Z(n199) );
  MXB2DM0N U251 ( .A(n283), .B(n249), .S(n177), .Z(B[0]) );
  MXB2DM0N U252 ( .A(n187), .B(n232), .S(n172), .Z(n249) );
  NR2M0N U253 ( .A(n269), .B(n174), .Z(n232) );
  MXB2DM0N U254 ( .A(n276), .B(n274), .S(n175), .Z(n269) );
  NR2B1M0N U255 ( .NA(A[26]), .B(SH[0]), .Z(n274) );
  CKMUX2M2N U256 ( .A(A[25]), .B(A[24]), .S(n179), .Z(n276) );
  MXB2DM0N U257 ( .A(n271), .B(n268), .S(SH[2]), .Z(n187) );
  MXB2DM0N U258 ( .A(n278), .B(n275), .S(n175), .Z(n268) );
  CKMUX2M2N U259 ( .A(A[23]), .B(A[22]), .S(n179), .Z(n275) );
  CKMUX2M2N U260 ( .A(A[21]), .B(A[20]), .S(n179), .Z(n278) );
  MXB2DM0N U261 ( .A(n280), .B(n277), .S(n175), .Z(n271) );
  CKMUX2M2N U262 ( .A(A[19]), .B(A[18]), .S(n173), .Z(n277) );
  CKMUX2M2N U263 ( .A(A[17]), .B(A[16]), .S(n179), .Z(n280) );
  MXB2DM0N U264 ( .A(n284), .B(n186), .S(n172), .Z(n283) );
  MXB2DM0N U265 ( .A(n211), .B(n270), .S(n174), .Z(n186) );
  MXB2DM0N U266 ( .A(n282), .B(n279), .S(n175), .Z(n270) );
  CKMUX2M2N U267 ( .A(A[15]), .B(A[14]), .S(n179), .Z(n279) );
  CKMUX2M2N U268 ( .A(A[13]), .B(A[12]), .S(n179), .Z(n282) );
  MXB2DM0N U269 ( .A(n227), .B(n281), .S(n175), .Z(n211) );
  CKMUX2M2N U270 ( .A(A[11]), .B(A[10]), .S(n179), .Z(n281) );
  CKMUX2M2N U271 ( .A(A[9]), .B(A[8]), .S(n173), .Z(n227) );
  MXB2DM0N U272 ( .A(n285), .B(n210), .S(n174), .Z(n284) );
  MXB2DM0N U273 ( .A(n229), .B(n226), .S(n175), .Z(n210) );
  CKMUX2M2N U274 ( .A(A[7]), .B(A[6]), .S(n173), .Z(n226) );
  CKMUX2M2N U275 ( .A(A[5]), .B(A[4]), .S(n173), .Z(n229) );
  CKND2M2N U276 ( .A(n228), .B(n175), .Z(n285) );
  NR2B1M0N U277 ( .NA(A[3]), .B(n179), .Z(n228) );
endmodule


module pre_norm_DW01_sub_0 ( A, B, CI, DIFF, CO );
  input [7:0] A;
  input [7:0] B;
  output [7:0] DIFF;
  input CI;
  output CO;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9;
  wire   [8:0] carry;

  XOR3M0N U2_7 ( .A(A[7]), .B(n1), .C(carry[7]), .Z(DIFF[7]) );
  ADFM2N U2_5 ( .A(A[5]), .B(n3), .CI(carry[5]), .CO(carry[6]), .S(DIFF[5]) );
  ADFM2N U2_3 ( .A(A[3]), .B(n5), .CI(carry[3]), .CO(carry[4]), .S(DIFF[3]) );
  ADFM2N U2_6 ( .A(A[6]), .B(n2), .CI(carry[6]), .CO(carry[7]), .S(DIFF[6]) );
  ADFM2N U2_4 ( .A(A[4]), .B(n4), .CI(carry[4]), .CO(carry[5]), .S(DIFF[4]) );
  ADFM2N U2_2 ( .A(A[2]), .B(n6), .CI(carry[2]), .CO(carry[3]), .S(DIFF[2]) );
  ADFM2N U2_0 ( .A(A[0]), .B(n8), .CI(n9), .CO(carry[1]), .S(DIFF[0]) );
  ADFM2N U2_1 ( .A(A[1]), .B(n7), .CI(carry[1]), .CO(carry[2]), .S(DIFF[1]) );
  INVM2N U1 ( .A(B[1]), .Z(n7) );
  INVM2N U2 ( .A(CI), .Z(n9) );
  INVM2N U3 ( .A(B[0]), .Z(n8) );
  INVM2N U4 ( .A(B[2]), .Z(n6) );
  INVM2N U5 ( .A(B[4]), .Z(n4) );
  INVM2N U6 ( .A(B[6]), .Z(n2) );
  INVM2N U7 ( .A(B[3]), .Z(n5) );
  INVM2N U8 ( .A(B[5]), .Z(n3) );
  INVM2N U9 ( .A(B[7]), .Z(n1) );
endmodule


module pre_norm_DW01_cmp6_0 ( A, B, TC, LT, GT, EQ, LE, GE, NE );
  input [22:0] A;
  input [22:0] B;
  input TC;
  output LT, GT, EQ, LE, GE, NE;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16,
         n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30,
         n31, n32, n33, n34, n35, n36, n37, n38, n39, n40, n41, n42, n43, n44,
         n45, n46, n47, n48, n49, n50, n51, n52, n53, n54, n55, n56, n57, n58,
         n59, n60, n61, n62, n63, n64, n65, n66, n67, n68, n69, n70, n71, n72,
         n73, n74, n75, n76;

  NR4M1N U1 ( .A(n24), .B(n25), .C(n26), .D(n27), .Z(EQ) );
  INVM2N U2 ( .A(A[12]), .Z(n6) );
  INVM2N U3 ( .A(A[10]), .Z(n7) );
  INVM2N U4 ( .A(A[16]), .Z(n4) );
  INVM2N U5 ( .A(A[18]), .Z(n3) );
  INVM2N U6 ( .A(B[3]), .Z(n21) );
  INVM2N U7 ( .A(B[2]), .Z(n22) );
  INVM2N U8 ( .A(B[5]), .Z(n20) );
  INVM2N U9 ( .A(B[1]), .Z(n23) );
  INVM2N U10 ( .A(A[4]), .Z(n10) );
  INVM2N U11 ( .A(A[6]), .Z(n9) );
  INVM2N U12 ( .A(A[1]), .Z(n11) );
  INVM2N U13 ( .A(B[7]), .Z(n19) );
  INVM2N U14 ( .A(B[9]), .Z(n18) );
  INVM2N U15 ( .A(B[11]), .Z(n17) );
  INVM2N U16 ( .A(A[8]), .Z(n8) );
  INVM2N U17 ( .A(B[13]), .Z(n16) );
  INVM2N U18 ( .A(B[15]), .Z(n15) );
  INVM2N U19 ( .A(B[17]), .Z(n14) );
  INVM2N U20 ( .A(B[19]), .Z(n13) );
  INVM2N U21 ( .A(A[14]), .Z(n5) );
  INVM2N U22 ( .A(A[20]), .Z(n2) );
  INVM2N U23 ( .A(A[22]), .Z(n1) );
  INVM2N U24 ( .A(B[21]), .Z(n12) );
  OAI211M0N U25 ( .A1(B[22]), .A2(n1), .B(n28), .C(n29), .Z(n27) );
  AN3M0N U26 ( .A(n30), .B(n31), .C(n32), .Z(n29) );
  OAI22M0N U27 ( .A1(A[1]), .A2(n33), .B1(n33), .B2(n23), .Z(n28) );
  NR2B1M0N U28 ( .NA(A[0]), .B(B[0]), .Z(n33) );
  ND4M0N U29 ( .A(n34), .B(n35), .C(n36), .D(n37), .Z(n26) );
  AN3M0N U30 ( .A(n38), .B(n39), .C(n40), .Z(n37) );
  ND4M0N U31 ( .A(n41), .B(n42), .C(n43), .D(n44), .Z(n25) );
  AN3M0N U32 ( .A(n45), .B(n46), .C(n47), .Z(n44) );
  ND4B1M0N U33 ( .NA(LT), .B(n48), .C(n49), .D(n50), .Z(n24) );
  AN3M0N U34 ( .A(n51), .B(n52), .C(n53), .Z(n50) );
  OAI21B20M1N U35 ( .NA1(n1), .NA2(B[22]), .B(n54), .Z(LT) );
  OAI211M0N U36 ( .A1(B[22]), .A2(n1), .B(n55), .C(n30), .Z(n54) );
  CKND2M2N U37 ( .A(A[21]), .B(n12), .Z(n30) );
  OAI21M0N U38 ( .A1(A[21]), .A2(n12), .B(n56), .Z(n55) );
  AOI32M0N U39 ( .A1(n32), .A2(n31), .A3(n57), .B1(B[20]), .B2(n2), .Z(n56) );
  OAI21M0N U40 ( .A1(A[19]), .A2(n13), .B(n58), .Z(n57) );
  AOI32M0N U41 ( .A1(n36), .A2(n34), .A3(n59), .B1(B[18]), .B2(n3), .Z(n58) );
  OAI21M0N U42 ( .A1(A[17]), .A2(n14), .B(n60), .Z(n59) );
  AOI32M0N U43 ( .A1(n35), .A2(n38), .A3(n61), .B1(B[16]), .B2(n4), .Z(n60) );
  OAI21M0N U44 ( .A1(A[15]), .A2(n15), .B(n62), .Z(n61) );
  AOI32M0N U45 ( .A1(n40), .A2(n39), .A3(n63), .B1(B[14]), .B2(n5), .Z(n62) );
  OAI21M0N U46 ( .A1(A[13]), .A2(n16), .B(n64), .Z(n63) );
  AOI32M0N U47 ( .A1(n43), .A2(n41), .A3(n65), .B1(B[12]), .B2(n6), .Z(n64) );
  OAI21M0N U48 ( .A1(A[11]), .A2(n17), .B(n66), .Z(n65) );
  AOI32M0N U49 ( .A1(n42), .A2(n45), .A3(n67), .B1(B[10]), .B2(n7), .Z(n66) );
  OAI21M0N U50 ( .A1(A[9]), .A2(n18), .B(n68), .Z(n67) );
  AOI32M0N U51 ( .A1(n47), .A2(n46), .A3(n69), .B1(B[8]), .B2(n8), .Z(n68) );
  OAI21M0N U52 ( .A1(A[7]), .A2(n19), .B(n70), .Z(n69) );
  AOI32M0N U53 ( .A1(n51), .A2(n53), .A3(n71), .B1(B[6]), .B2(n9), .Z(n70) );
  OAI21M0N U54 ( .A1(A[5]), .A2(n20), .B(n72), .Z(n71) );
  AOI32M0N U55 ( .A1(n52), .A2(n49), .A3(n73), .B1(B[4]), .B2(n10), .Z(n72) );
  OAI221M0N U56 ( .A1(A[2]), .A2(n22), .B1(A[3]), .B2(n21), .C(n74), .Z(n73)
         );
  OAI211M0N U57 ( .A1(n75), .A2(n11), .B(n76), .C(n48), .Z(n74) );
  CKND2M2N U58 ( .A(A[2]), .B(n22), .Z(n48) );
  OAI21B20M1N U59 ( .NA1(n11), .NA2(n75), .B(n23), .Z(n76) );
  NR2B1M0N U60 ( .NA(B[0]), .B(A[0]), .Z(n75) );
  CKND2M2N U61 ( .A(A[3]), .B(n21), .Z(n49) );
  OR2M0N U62 ( .A(B[4]), .B(n10), .Z(n52) );
  CKND2M2N U63 ( .A(A[5]), .B(n20), .Z(n53) );
  OR2M0N U64 ( .A(B[6]), .B(n9), .Z(n51) );
  CKND2M2N U65 ( .A(A[7]), .B(n19), .Z(n46) );
  OR2M0N U66 ( .A(B[8]), .B(n8), .Z(n47) );
  CKND2M2N U67 ( .A(A[9]), .B(n18), .Z(n45) );
  ND2B1M0N U68 ( .NA(B[10]), .B(A[10]), .Z(n42) );
  CKND2M2N U69 ( .A(A[11]), .B(n17), .Z(n41) );
  ND2B1M0N U70 ( .NA(B[12]), .B(A[12]), .Z(n43) );
  CKND2M2N U71 ( .A(A[13]), .B(n16), .Z(n39) );
  OR2M0N U72 ( .A(B[14]), .B(n5), .Z(n40) );
  CKND2M2N U73 ( .A(A[15]), .B(n15), .Z(n38) );
  ND2B1M0N U74 ( .NA(B[16]), .B(A[16]), .Z(n35) );
  CKND2M2N U75 ( .A(A[17]), .B(n14), .Z(n34) );
  ND2B1M0N U76 ( .NA(B[18]), .B(A[18]), .Z(n36) );
  CKND2M2N U77 ( .A(A[19]), .B(n13), .Z(n31) );
  OR2M0N U78 ( .A(B[20]), .B(n2), .Z(n32) );
endmodule


module pre_norm ( clk, rmode, add, opa, opb, opa_nan, opb_nan, fracta_out, 
        fractb_out, exp_dn_out, sign, nan_sign, result_zero_sign, fasu_op );
  input [1:0] rmode;
  input [31:0] opa;
  input [31:0] opb;
  output [26:0] fracta_out;
  output [26:0] fractb_out;
  output [7:0] exp_dn_out;
  input clk, add, opa_nan, opb_nan;
  output sign, nan_sign, result_zero_sign, fasu_op;
  wire   N102, exp_lt_27, \exp_diff_sft[3] , fractb_lt_fracta, sign_d, signa_r,
         signb_r, add_r, N200, N201, fracta_lt_fractb, N202, fracta_eq_fractb,
         N211, N222, n139, n140, n141, n142, n143, n144, n145, n146, n147,
         n148, n149, n150, n151, n152, n153, n154, n155, n156, n157, n158,
         n159, n160, n161, n162, n163, n164, n165, n166, n167, n168, n169,
         n170, n171, n172, n173, n174, n175, n176, n177, n178, n179, n180,
         n181, n182, n183, n184, n185, n186, n187, n188, n189, n190, n191,
         n192, n193, n194, n195, n196, n197, n198, n199, n200, n201, n202,
         n203, n204, n205, n206, n207, n208, n209, n210, n211, n212, n213,
         n214, n215, n216, n217, n218, n219, n220, n221, n222, n223, n224,
         n225, n226, n227, n228, n229, n230, n231, n232, n233, n234, n235,
         n236, n237, n238, n239, n240, n241, n242, n243, n244, n245, n246,
         n247, n248, n249, n250, n251, n252, n253, n254, n255, n256, n257,
         n258, n259, n260, n261, n262, n263, n264, n265, n266, n267, n268,
         n269, n270, n271, n272, n273, n274, n275, n276, \gt_135/A[3] , n285,
         n286, n287, n288, n289, n290, n291, n292, n293, n294, n295, n296,
         n297, n298, n299, n300, n301, n302, n303, n304, n305, n306, n307,
         n308, n309, n310, n311, n312, n313, n314, n315, n316, n317, n318,
         n319, n320, n321, n322, n323, n324, n325, n326, n327, n328, n329,
         n330, n331, n332, n333, n334, n335, n336, n337, n338, n339, n340,
         n341, n342, n343, n344, n345, n346, n347, n348, n349, n350, n351,
         n352, n353, n354, n355, n356, n357, n358, n359, n360, n361, n362,
         n363, n364, n365, n366, n367, n368, n369, n370, n371, n372, n373,
         n374, n375, n376, n377, n378, n379, n380, n381, n382, n383, n384,
         n385, n386, n387, n388, n389, n390, n391, n392, n393, n394, n395,
         n396, n397, n398, n399, n400, n401, n402, n403, n404, n405;
  wire   [7:0] exp_small;
  wire   [7:0] exp_large;
  wire   [7:0] exp_diff2;
  wire   [7:0] exp_diff;
  wire   [22:0] adj_op;
  wire   [26:0] adj_op_out_sft;
  wire   [26:0] fracta_s;
  wire   [26:0] fractb_s;

  OAI221M2N U122 ( .A1(n211), .A2(n376), .B1(n212), .B2(n379), .C(n213), .Z(
        n201) );
  ND4B1M4N U228 ( .NA(n268), .B(n269), .C(N202), .D(n270), .Z(n254) );
  pre_norm_DW_cmp_0 gt_184 ( .A({n355, n369, n367, n365, n363, n361, n359, 
        n357, n339, n341, n373, n343, n345, n347, n349, n351, n353, n321, n323, 
        n325, n327, n329, n331, n333, n335, n337, n371}), .B({n354, n368, n366, 
        n364, n362, n360, n358, n356, n338, n340, n372, n342, n344, n346, n348, 
        n350, n352, n320, n322, n324, n326, n328, n330, n332, n334, n336, n370}), .TC(1'b0), .GE_LT(1'b0), .GE_GT_EQ(1'b1), .GE_LT_GT_LE(fractb_lt_fracta) );
  pre_norm_DW_rightsh_0 srl_137 ( .A({n276, adj_op[22], n383, adj_op[20:17], 
        n385, adj_op[15:2], n384, n386, 1'b0, 1'b0, 1'b0}), .DATA_TC(1'b0), 
        .SH({n382, \exp_diff_sft[3] , n374, n381, n378}), .B(adj_op_out_sft)
         );
  pre_norm_DW01_sub_0 sub_1_root_sub_119_aco ( .A(exp_large), .B(exp_small), 
        .CI(N102), .DIFF(exp_diff2) );
  pre_norm_DW01_cmp6_0 r342 ( .A(opa[22:0]), .B(opb[22:0]), .TC(1'b0), .LT(
        N201), .EQ(N202) );
  LDFQM2N add_r_reg ( .D(add), .CK(clk), .Q(add_r) );
  LDFQM2N fracta_lt_fractb_reg ( .D(N201), .CK(clk), .Q(fracta_lt_fractb) );
  LDFQM1N fracta_eq_fractb_reg ( .D(N202), .CK(clk), .Q(fracta_eq_fractb) );
  LDFQM2N signb_r_reg ( .D(opb[31]), .CK(clk), .Q(signb_r) );
  LDFQM2N signa_r_reg ( .D(opa[31]), .CK(clk), .Q(signa_r) );
  LDFQM2N sign_reg ( .D(sign_d), .CK(clk), .Q(sign) );
  LDFQM2N result_zero_sign_reg ( .D(N200), .CK(clk), .Q(result_zero_sign) );
  LDFQM2N nan_sign_reg ( .D(N211), .CK(clk), .Q(nan_sign) );
  LDFQM2N fasu_op_reg ( .D(N222), .CK(clk), .Q(fasu_op) );
  DFZRM1N \exp_dn_out_reg[7]  ( .D(n254), .RB(exp_large[7]), .CK(clk), .Q(
        exp_dn_out[7]) );
  DFZRM1N \exp_dn_out_reg[6]  ( .D(n254), .RB(exp_large[6]), .CK(clk), .Q(
        exp_dn_out[6]) );
  DFZRM1N \exp_dn_out_reg[5]  ( .D(n254), .RB(exp_large[5]), .CK(clk), .Q(
        exp_dn_out[5]) );
  DFZRM1N \exp_dn_out_reg[4]  ( .D(n254), .RB(exp_large[4]), .CK(clk), .Q(
        exp_dn_out[4]) );
  DFZRM1N \exp_dn_out_reg[3]  ( .D(n254), .RB(exp_large[3]), .CK(clk), .Q(
        exp_dn_out[3]) );
  DFZRM1N \exp_dn_out_reg[2]  ( .D(n254), .RB(exp_large[2]), .CK(clk), .Q(
        exp_dn_out[2]) );
  DFZRM1N \exp_dn_out_reg[1]  ( .D(n254), .RB(exp_large[1]), .CK(clk), .Q(
        exp_dn_out[1]) );
  DFZRM1N \exp_dn_out_reg[0]  ( .D(n254), .RB(exp_large[0]), .CK(clk), .Q(
        exp_dn_out[0]) );
  LDFQM2N \fracta_out_reg[25]  ( .D(fracta_s[25]), .CK(clk), .Q(fracta_out[25]) );
  LDFQM2N \fracta_out_reg[24]  ( .D(fracta_s[24]), .CK(clk), .Q(fracta_out[24]) );
  LDFQM2N \fracta_out_reg[23]  ( .D(fracta_s[23]), .CK(clk), .Q(fracta_out[23]) );
  LDFQM2N \fracta_out_reg[22]  ( .D(fracta_s[22]), .CK(clk), .Q(fracta_out[22]) );
  LDFQM2N \fracta_out_reg[21]  ( .D(fracta_s[21]), .CK(clk), .Q(fracta_out[21]) );
  LDFQM2N \fracta_out_reg[20]  ( .D(fracta_s[20]), .CK(clk), .Q(fracta_out[20]) );
  LDFQM2N \fracta_out_reg[19]  ( .D(fracta_s[19]), .CK(clk), .Q(fracta_out[19]) );
  LDFQM2N \fracta_out_reg[18]  ( .D(fracta_s[18]), .CK(clk), .Q(fracta_out[18]) );
  LDFQM2N \fracta_out_reg[17]  ( .D(fracta_s[17]), .CK(clk), .Q(fracta_out[17]) );
  LDFQM2N \fracta_out_reg[16]  ( .D(fracta_s[16]), .CK(clk), .Q(fracta_out[16]) );
  LDFQM2N \fracta_out_reg[15]  ( .D(fracta_s[15]), .CK(clk), .Q(fracta_out[15]) );
  LDFQM2N \fracta_out_reg[14]  ( .D(fracta_s[14]), .CK(clk), .Q(fracta_out[14]) );
  LDFQM2N \fracta_out_reg[13]  ( .D(fracta_s[13]), .CK(clk), .Q(fracta_out[13]) );
  LDFQM2N \fracta_out_reg[12]  ( .D(fracta_s[12]), .CK(clk), .Q(fracta_out[12]) );
  LDFQM2N \fracta_out_reg[11]  ( .D(fracta_s[11]), .CK(clk), .Q(fracta_out[11]) );
  LDFQM2N \fracta_out_reg[10]  ( .D(fracta_s[10]), .CK(clk), .Q(fracta_out[10]) );
  LDFQM2N \fracta_out_reg[9]  ( .D(fracta_s[9]), .CK(clk), .Q(fracta_out[9])
         );
  LDFQM2N \fracta_out_reg[8]  ( .D(fracta_s[8]), .CK(clk), .Q(fracta_out[8])
         );
  LDFQM2N \fracta_out_reg[7]  ( .D(fracta_s[7]), .CK(clk), .Q(fracta_out[7])
         );
  LDFQM2N \fracta_out_reg[6]  ( .D(fracta_s[6]), .CK(clk), .Q(fracta_out[6])
         );
  LDFQM2N \fracta_out_reg[5]  ( .D(fracta_s[5]), .CK(clk), .Q(fracta_out[5])
         );
  LDFQM2N \fracta_out_reg[4]  ( .D(fracta_s[4]), .CK(clk), .Q(fracta_out[4])
         );
  LDFQM2N \fracta_out_reg[3]  ( .D(fracta_s[3]), .CK(clk), .Q(fracta_out[3])
         );
  LDFQM2N \fractb_out_reg[25]  ( .D(fractb_s[25]), .CK(clk), .Q(fractb_out[25]) );
  LDFQM2N \fractb_out_reg[24]  ( .D(fractb_s[24]), .CK(clk), .Q(fractb_out[24]) );
  LDFQM2N \fractb_out_reg[23]  ( .D(fractb_s[23]), .CK(clk), .Q(fractb_out[23]) );
  LDFQM2N \fractb_out_reg[22]  ( .D(fractb_s[22]), .CK(clk), .Q(fractb_out[22]) );
  LDFQM2N \fractb_out_reg[21]  ( .D(fractb_s[21]), .CK(clk), .Q(fractb_out[21]) );
  LDFQM2N \fractb_out_reg[20]  ( .D(fractb_s[20]), .CK(clk), .Q(fractb_out[20]) );
  LDFQM2N \fractb_out_reg[19]  ( .D(fractb_s[19]), .CK(clk), .Q(fractb_out[19]) );
  LDFQM2N \fractb_out_reg[18]  ( .D(fractb_s[18]), .CK(clk), .Q(fractb_out[18]) );
  LDFQM2N \fractb_out_reg[17]  ( .D(fractb_s[17]), .CK(clk), .Q(fractb_out[17]) );
  LDFQM2N \fractb_out_reg[16]  ( .D(fractb_s[16]), .CK(clk), .Q(fractb_out[16]) );
  LDFQM2N \fractb_out_reg[15]  ( .D(fractb_s[15]), .CK(clk), .Q(fractb_out[15]) );
  LDFQM2N \fractb_out_reg[14]  ( .D(fractb_s[14]), .CK(clk), .Q(fractb_out[14]) );
  LDFQM2N \fractb_out_reg[13]  ( .D(fractb_s[13]), .CK(clk), .Q(fractb_out[13]) );
  LDFQM2N \fractb_out_reg[12]  ( .D(fractb_s[12]), .CK(clk), .Q(fractb_out[12]) );
  LDFQM2N \fractb_out_reg[11]  ( .D(fractb_s[11]), .CK(clk), .Q(fractb_out[11]) );
  LDFQM2N \fractb_out_reg[10]  ( .D(fractb_s[10]), .CK(clk), .Q(fractb_out[10]) );
  LDFQM2N \fractb_out_reg[9]  ( .D(fractb_s[9]), .CK(clk), .Q(fractb_out[9])
         );
  LDFQM2N \fractb_out_reg[8]  ( .D(fractb_s[8]), .CK(clk), .Q(fractb_out[8])
         );
  LDFQM2N \fractb_out_reg[7]  ( .D(fractb_s[7]), .CK(clk), .Q(fractb_out[7])
         );
  LDFQM2N \fractb_out_reg[6]  ( .D(fractb_s[6]), .CK(clk), .Q(fractb_out[6])
         );
  LDFQM2N \fractb_out_reg[5]  ( .D(fractb_s[5]), .CK(clk), .Q(fractb_out[5])
         );
  LDFQM2N \fractb_out_reg[4]  ( .D(fractb_s[4]), .CK(clk), .Q(fractb_out[4])
         );
  LDFQM2N \fractb_out_reg[3]  ( .D(fractb_s[3]), .CK(clk), .Q(fractb_out[3])
         );
  LDFQM2N \fracta_out_reg[26]  ( .D(fracta_s[26]), .CK(clk), .Q(fracta_out[26]) );
  LDFQM2N \fractb_out_reg[26]  ( .D(fractb_s[26]), .CK(clk), .Q(fractb_out[26]) );
  LDFQM2N \fracta_out_reg[2]  ( .D(fracta_s[2]), .CK(clk), .Q(fracta_out[2])
         );
  LDFQM2N \fracta_out_reg[0]  ( .D(fracta_s[0]), .CK(clk), .Q(fracta_out[0])
         );
  LDFQM2N \fractb_out_reg[2]  ( .D(fractb_s[2]), .CK(clk), .Q(fractb_out[2])
         );
  LDFQM2N \fractb_out_reg[0]  ( .D(fractb_s[0]), .CK(clk), .Q(fractb_out[0])
         );
  LDFQM2N \fracta_out_reg[1]  ( .D(fracta_s[1]), .CK(clk), .Q(fracta_out[1])
         );
  LDFQM2N \fractb_out_reg[1]  ( .D(fractb_s[1]), .CK(clk), .Q(fractb_out[1])
         );
  BUFM2N U338 ( .A(n302), .Z(n299) );
  INVM0N U339 ( .A(n285), .Z(n303) );
  CKBUFM2N U340 ( .A(n315), .Z(n309) );
  CKBUFM2N U341 ( .A(n317), .Z(n308) );
  CKBUFM2N U342 ( .A(n300), .Z(n293) );
  CKBUFM2N U343 ( .A(n301), .Z(n292) );
  CKBUFM2N U344 ( .A(n301), .Z(n291) );
  NR2M2N U345 ( .A(exp_lt_27), .B(exp_diff[0]), .Z(n204) );
  OAI211M0N U346 ( .A1(n197), .A2(n198), .B(n199), .C(n200), .Z(n196) );
  ND2M2N U347 ( .A(n388), .B(n397), .Z(n246) );
  ND4M0N U348 ( .A(n395), .B(n394), .C(n274), .D(n275), .Z(n247) );
  INVM4N U349 ( .A(n309), .Z(n304) );
  INVM4N U350 ( .A(n309), .Z(n305) );
  INVM4N U351 ( .A(n308), .Z(n306) );
  INVM4N U352 ( .A(n308), .Z(n307) );
  CKBUFM2N U353 ( .A(n315), .Z(n310) );
  CKBUFM2N U354 ( .A(n317), .Z(n311) );
  CKBUFM2N U355 ( .A(n317), .Z(n312) );
  CKBUFM2N U356 ( .A(n317), .Z(n313) );
  CKBUFM2N U357 ( .A(n317), .Z(n314) );
  INVM2N U358 ( .A(n157), .Z(n354) );
  OAI22M1N U359 ( .A1(n307), .A2(n170), .B1(n309), .B2(n171), .Z(fractb_s[1])
         );
  CKBUFM2N U360 ( .A(n316), .Z(n315) );
  OAI22M1N U361 ( .A1(n310), .A2(n170), .B1(n304), .B2(n171), .Z(fracta_s[1])
         );
  INVM2N U362 ( .A(n214), .Z(n377) );
  INVM2N U363 ( .A(n171), .Z(n336) );
  INVM2N U364 ( .A(n170), .Z(n337) );
  NR2M2N U365 ( .A(n286), .B(adj_op_out_sft[26]), .Z(n157) );
  OAI22M1N U366 ( .A1(n307), .A2(n154), .B1(n309), .B2(n155), .Z(fractb_s[2])
         );
  OAI22M1N U367 ( .A1(n306), .A2(n192), .B1(n309), .B2(n193), .Z(fractb_s[0])
         );
  INVM4N U368 ( .A(n292), .Z(n286) );
  INVM2N U369 ( .A(fractb_lt_fracta), .Z(n316) );
  INVM2N U370 ( .A(fractb_lt_fracta), .Z(n317) );
  OAI22M1N U371 ( .A1(n310), .A2(n154), .B1(n305), .B2(n155), .Z(fracta_s[2])
         );
  OAI22M1N U372 ( .A1(n309), .A2(n192), .B1(n304), .B2(n193), .Z(fracta_s[0])
         );
  INVM2N U373 ( .A(n228), .Z(n374) );
  INVM4N U374 ( .A(n292), .Z(n287) );
  INVM2N U375 ( .A(n155), .Z(n334) );
  INVM2N U376 ( .A(n154), .Z(n335) );
  INVM2N U377 ( .A(n193), .Z(n370) );
  ND2M2N U378 ( .A(adj_op_out_sft[1]), .B(n292), .Z(n171) );
  ND2M2N U379 ( .A(adj_op_out_sft[1]), .B(n286), .Z(n170) );
  NR2M2N U380 ( .A(n378), .B(n381), .Z(n214) );
  INVM2N U381 ( .A(n209), .Z(n379) );
  INVM2N U382 ( .A(n207), .Z(n376) );
  INVM4N U383 ( .A(n291), .Z(n289) );
  INVM2N U384 ( .A(n216), .Z(n380) );
  INVM2N U385 ( .A(n192), .Z(n371) );
  INVM2N U386 ( .A(n197), .Z(n382) );
  INVM2N U387 ( .A(n291), .Z(n290) );
  INVM4N U388 ( .A(n292), .Z(n288) );
  INVM2N U389 ( .A(n204), .Z(n378) );
  ND2M2N U390 ( .A(adj_op_out_sft[2]), .B(n291), .Z(n155) );
  ND2M2N U391 ( .A(adj_op_out_sft[2]), .B(n286), .Z(n154) );
  ND2M2N U392 ( .A(n196), .B(n293), .Z(n193) );
  INVM2N U393 ( .A(exp_lt_27), .Z(n375) );
  ND2M2N U394 ( .A(n375), .B(n245), .Z(\exp_diff_sft[3] ) );
  ND2M2N U395 ( .A(exp_diff[2]), .B(n375), .Z(n228) );
  CKBUFM2N U396 ( .A(n300), .Z(n294) );
  INVM2N U397 ( .A(n243), .Z(n381) );
  NR2M2N U398 ( .A(n204), .B(n243), .Z(n209) );
  NR2M2N U399 ( .A(n204), .B(n381), .Z(n216) );
  NR2M2N U400 ( .A(n243), .B(n378), .Z(n207) );
  NR2M2N U401 ( .A(exp_lt_27), .B(exp_diff[4]), .Z(n197) );
  ND2M2N U402 ( .A(n196), .B(n286), .Z(n192) );
  BUFM4N U403 ( .A(n298), .Z(n296) );
  CKBUFM2N U404 ( .A(n299), .Z(n295) );
  CKBUFM2N U405 ( .A(n298), .Z(n297) );
  INVM2N U406 ( .A(n245), .Z(\gt_135/A[3] ) );
  AN2M2N U407 ( .A(exp_diff2[0]), .B(n246), .Z(exp_diff[0]) );
  OAI22M1N U408 ( .A1(n307), .A2(n156), .B1(n157), .B2(n310), .Z(fractb_s[26])
         );
  OAI22M1N U409 ( .A1(n156), .A2(n313), .B1(n305), .B2(n157), .Z(fracta_s[26])
         );
  CKBUFM2N U410 ( .A(n302), .Z(n301) );
  OAI211M0N U411 ( .A1(n218), .A2(n219), .B(\exp_diff_sft[3] ), .C(n374), .Z(
        n199) );
  AOI211M2N U412 ( .A1(n224), .A2(\exp_diff_sft[3] ), .B(n225), .C(n226), .Z(
        n198) );
  AOI221M2N U413 ( .A1(n201), .A2(\exp_diff_sft[3] ), .B1(n374), .B2(n202), 
        .C(adj_op_out_sft[0]), .Z(n200) );
  NR2M2N U414 ( .A(exp_lt_27), .B(exp_diff[1]), .Z(n243) );
  AN2M2N U415 ( .A(exp_diff2[1]), .B(n246), .Z(exp_diff[1]) );
  ND2M2N U416 ( .A(exp_diff2[3]), .B(n246), .Z(n245) );
  AN2M2N U417 ( .A(exp_diff2[4]), .B(n246), .Z(exp_diff[4]) );
  AN2M2N U418 ( .A(exp_diff2[2]), .B(n246), .Z(exp_diff[2]) );
  AN2M2N U419 ( .A(exp_diff2[6]), .B(n246), .Z(exp_diff[6]) );
  AN2M2N U420 ( .A(exp_diff2[5]), .B(n246), .Z(exp_diff[5]) );
  CKBUFM2N U421 ( .A(n302), .Z(n300) );
  OAI22M1N U422 ( .A1(n397), .A2(n296), .B1(n388), .B2(n287), .Z(n276) );
  OAI222M1N U423 ( .A1(n235), .A2(n380), .B1(n236), .B2(n377), .C1(n237), .C2(
        n376), .Z(n225) );
  AOI22M2N U424 ( .A1(n214), .A2(n215), .B1(n216), .B2(n217), .Z(n213) );
  OAI22M1N U425 ( .A1(n227), .A2(n228), .B1(n229), .B2(n379), .Z(n226) );
  AOI221M2N U426 ( .A1(n214), .A2(n230), .B1(n216), .B2(n231), .C(n232), .Z(
        n227) );
  OAI22M1N U427 ( .A1(n233), .A2(n379), .B1(n234), .B2(n376), .Z(n232) );
  OAI22M1N U428 ( .A1(n220), .A2(n379), .B1(n221), .B2(n376), .Z(n219) );
  OAI22M1N U429 ( .A1(n222), .A2(n380), .B1(n223), .B2(n377), .Z(n218) );
  INVM2N U430 ( .A(n156), .Z(n355) );
  CKBUFM2N U431 ( .A(n303), .Z(n298) );
  OAI22M1N U432 ( .A1(n293), .A2(n395), .B1(n286), .B2(n404), .Z(exp_large[0])
         );
  OAI22M1N U433 ( .A1(n306), .A2(n180), .B1(n181), .B2(n311), .Z(fractb_s[15])
         );
  OAI22M1N U434 ( .A1(n306), .A2(n186), .B1(n187), .B2(n312), .Z(fractb_s[12])
         );
  OAI22M1N U435 ( .A1(n306), .A2(n178), .B1(n179), .B2(n311), .Z(fractb_s[16])
         );
  OAI22M1N U436 ( .A1(n306), .A2(n176), .B1(n177), .B2(n311), .Z(fractb_s[17])
         );
  OAI22M1N U437 ( .A1(n306), .A2(n174), .B1(n175), .B2(n311), .Z(fractb_s[18])
         );
  OAI22M1N U438 ( .A1(n307), .A2(n172), .B1(n173), .B2(n311), .Z(fractb_s[19])
         );
  OAI22M1N U439 ( .A1(n307), .A2(n168), .B1(n169), .B2(n311), .Z(fractb_s[20])
         );
  OAI22M1N U440 ( .A1(n307), .A2(n166), .B1(n167), .B2(n311), .Z(fractb_s[21])
         );
  OAI22M1N U441 ( .A1(n307), .A2(n164), .B1(n165), .B2(n311), .Z(fractb_s[22])
         );
  OAI22M1N U442 ( .A1(n307), .A2(n162), .B1(n163), .B2(n311), .Z(fractb_s[23])
         );
  OAI22M1N U443 ( .A1(n307), .A2(n160), .B1(n161), .B2(n311), .Z(fractb_s[24])
         );
  OAI22M1N U444 ( .A1(n307), .A2(n158), .B1(n159), .B2(n310), .Z(fractb_s[25])
         );
  OAI22M1N U445 ( .A1(n306), .A2(n188), .B1(n189), .B2(n312), .Z(fractb_s[11])
         );
  OAI22M1N U446 ( .A1(n306), .A2(n184), .B1(n185), .B2(n312), .Z(fractb_s[13])
         );
  OAI22M1N U447 ( .A1(n306), .A2(n182), .B1(n183), .B2(n312), .Z(fractb_s[14])
         );
  OAI22M1N U448 ( .A1(n180), .A2(n314), .B1(n304), .B2(n181), .Z(fracta_s[15])
         );
  OAI22M1N U449 ( .A1(n178), .A2(n314), .B1(n304), .B2(n179), .Z(fracta_s[16])
         );
  OAI22M1N U450 ( .A1(n176), .A2(n313), .B1(n304), .B2(n177), .Z(fracta_s[17])
         );
  OAI22M1N U451 ( .A1(n174), .A2(n312), .B1(n304), .B2(n175), .Z(fracta_s[18])
         );
  OAI22M1N U452 ( .A1(n172), .A2(n313), .B1(n304), .B2(n173), .Z(fracta_s[19])
         );
  OAI22M1N U453 ( .A1(n168), .A2(n313), .B1(n305), .B2(n169), .Z(fracta_s[20])
         );
  OAI22M1N U454 ( .A1(n166), .A2(n313), .B1(n305), .B2(n167), .Z(fracta_s[21])
         );
  OAI22M1N U455 ( .A1(n164), .A2(n313), .B1(n305), .B2(n165), .Z(fracta_s[22])
         );
  OAI22M1N U456 ( .A1(n162), .A2(n313), .B1(n305), .B2(n163), .Z(fracta_s[23])
         );
  OAI22M1N U457 ( .A1(n160), .A2(n313), .B1(n305), .B2(n161), .Z(fracta_s[24])
         );
  OAI22M1N U458 ( .A1(n158), .A2(n313), .B1(n305), .B2(n159), .Z(fracta_s[25])
         );
  OAI22M1N U459 ( .A1(n186), .A2(n314), .B1(n304), .B2(n187), .Z(fracta_s[12])
         );
  OAI22M1N U460 ( .A1(n188), .A2(n314), .B1(n304), .B2(n189), .Z(fracta_s[11])
         );
  OAI22M1N U461 ( .A1(n184), .A2(n314), .B1(n304), .B2(n185), .Z(fracta_s[13])
         );
  OAI22M1N U462 ( .A1(n182), .A2(n314), .B1(n304), .B2(n183), .Z(fracta_s[14])
         );
  OAI22M1N U463 ( .A1(n307), .A2(n144), .B1(n145), .B2(n310), .Z(fractb_s[7])
         );
  OAI22M1N U464 ( .A1(n306), .A2(n142), .B1(n143), .B2(n310), .Z(fractb_s[8])
         );
  OAI22M1N U465 ( .A1(n307), .A2(n140), .B1(n141), .B2(n310), .Z(fractb_s[9])
         );
  OAI22M1N U466 ( .A1(n306), .A2(n190), .B1(n191), .B2(n311), .Z(fractb_s[10])
         );
  OAI22M1N U467 ( .A1(n307), .A2(n150), .B1(n151), .B2(n310), .Z(fractb_s[4])
         );
  OAI22M1N U468 ( .A1(n306), .A2(n146), .B1(n147), .B2(n310), .Z(fractb_s[6])
         );
  OAI22M1N U469 ( .A1(n307), .A2(n152), .B1(n153), .B2(n310), .Z(fractb_s[3])
         );
  OAI22M1N U470 ( .A1(n307), .A2(n148), .B1(n149), .B2(n310), .Z(fractb_s[5])
         );
  XOR2M1N U471 ( .A(n394), .B(n403), .Z(n267) );
  OAI22M1N U472 ( .A1(n144), .A2(n312), .B1(n306), .B2(n145), .Z(fracta_s[7])
         );
  OAI22M1N U473 ( .A1(n142), .A2(n312), .B1(n306), .B2(n143), .Z(fracta_s[8])
         );
  OAI22M1N U474 ( .A1(n140), .A2(n312), .B1(n306), .B2(n141), .Z(fracta_s[9])
         );
  OAI22M1N U475 ( .A1(n190), .A2(n312), .B1(n304), .B2(n191), .Z(fracta_s[10])
         );
  OAI22M1N U476 ( .A1(n150), .A2(n313), .B1(n305), .B2(n151), .Z(fracta_s[4])
         );
  OAI22M1N U477 ( .A1(n146), .A2(n312), .B1(n305), .B2(n147), .Z(fracta_s[6])
         );
  OAI22M1N U478 ( .A1(n152), .A2(n313), .B1(n305), .B2(n153), .Z(fracta_s[3])
         );
  OAI22M1N U479 ( .A1(n148), .A2(n312), .B1(n305), .B2(n149), .Z(fracta_s[5])
         );
  INVM2N U480 ( .A(n178), .Z(n373) );
  OAI22M1N U481 ( .A1(n294), .A2(n403), .B1(n286), .B2(n394), .Z(exp_small[1])
         );
  ND2M2N U482 ( .A(n247), .B(n195), .Z(N102) );
  OAI22M1N U483 ( .A1(n293), .A2(n402), .B1(n286), .B2(n393), .Z(exp_small[2])
         );
  OAI22M1N U484 ( .A1(n294), .A2(n400), .B1(n287), .B2(n391), .Z(exp_small[4])
         );
  OAI22M1N U485 ( .A1(n294), .A2(n398), .B1(n286), .B2(n389), .Z(exp_small[6])
         );
  OAI22M1N U486 ( .A1(n294), .A2(n401), .B1(n287), .B2(n392), .Z(exp_small[3])
         );
  OAI22M1N U487 ( .A1(n294), .A2(n399), .B1(n287), .B2(n390), .Z(exp_small[5])
         );
  AN2M2N U488 ( .A(exp_diff2[7]), .B(n246), .Z(exp_diff[7]) );
  OAI22M1N U489 ( .A1(n294), .A2(n396), .B1(n287), .B2(n387), .Z(exp_small[7])
         );
  INVM2N U490 ( .A(n285), .Z(n302) );
  OAI22M1N U491 ( .A1(n293), .A2(n394), .B1(n286), .B2(n403), .Z(exp_large[1])
         );
  OAI22M1N U492 ( .A1(n293), .A2(n393), .B1(n286), .B2(n402), .Z(exp_large[2])
         );
  OAI22M1N U493 ( .A1(n293), .A2(n391), .B1(n286), .B2(n400), .Z(exp_large[4])
         );
  OAI22M1N U494 ( .A1(n293), .A2(n389), .B1(n286), .B2(n398), .Z(exp_large[6])
         );
  OAI22M1N U495 ( .A1(n293), .A2(n392), .B1(n286), .B2(n401), .Z(exp_large[3])
         );
  OAI22M1N U496 ( .A1(n293), .A2(n390), .B1(n286), .B2(n399), .Z(exp_large[5])
         );
  OAI22M1N U497 ( .A1(n293), .A2(n404), .B1(n286), .B2(n395), .Z(exp_small[0])
         );
  INVM2N U498 ( .A(n174), .Z(n339) );
  INVM2N U499 ( .A(n177), .Z(n340) );
  INVM2N U500 ( .A(n187), .Z(n348) );
  INVM2N U501 ( .A(n143), .Z(n322) );
  INVM2N U502 ( .A(n164), .Z(n363) );
  INVM2N U503 ( .A(n188), .Z(n351) );
  INVM2N U504 ( .A(n179), .Z(n372) );
  INVM2N U505 ( .A(n189), .Z(n350) );
  INVM2N U506 ( .A(n175), .Z(n338) );
  INVM2N U507 ( .A(n176), .Z(n341) );
  INVM2N U508 ( .A(n186), .Z(n349) );
  INVM2N U509 ( .A(n150), .Z(n331) );
  INVM2N U510 ( .A(n145), .Z(n324) );
  INVM2N U511 ( .A(n144), .Z(n325) );
  INVM2N U512 ( .A(n142), .Z(n323) );
  INVM2N U513 ( .A(n162), .Z(n365) );
  INVM2N U514 ( .A(n151), .Z(n330) );
  AOI22M2N U515 ( .A1(n287), .A2(adj_op_out_sft[26]), .B1(n195), .B2(n293), 
        .Z(n156) );
  OAI211M0N U516 ( .A1(n203), .A2(n204), .B(n205), .C(n206), .Z(n202) );
  AOI22M2N U517 ( .A1(n207), .A2(n208), .B1(n209), .B2(n210), .Z(n206) );
  OAI211M0N U518 ( .A1(n238), .A2(n377), .B(n239), .C(n240), .Z(n224) );
  AOI22M2N U519 ( .A1(n216), .A2(n241), .B1(n209), .B2(n276), .Z(n240) );
  OAI22M1N U520 ( .A1(n207), .A2(n209), .B1(adj_op[22]), .B2(n241), .Z(n239)
         );
  ND2M2N U521 ( .A(n238), .B(n242), .Z(n241) );
  NR2B1M2N U522 ( .NA(n237), .B(adj_op[15]), .Z(n229) );
  INVM2N U523 ( .A(n184), .Z(n347) );
  NR2B1M2N U524 ( .NA(n233), .B(adj_op[20]), .Z(n238) );
  NR2B1M2N U525 ( .NA(n212), .B(adj_op[8]), .Z(n223) );
  NR2B1M2N U526 ( .NA(n222), .B(adj_op[10]), .Z(n221) );
  NR2M2N U527 ( .A(n231), .B(adj_op[18]), .Z(n234) );
  NR2B1M2N U528 ( .NA(n223), .B(adj_op[9]), .Z(n222) );
  NR2B1M2N U529 ( .NA(n234), .B(adj_op[19]), .Z(n233) );
  NR2B1M2N U530 ( .NA(n221), .B(adj_op[11]), .Z(n220) );
  NR2B1M2N U531 ( .NA(n211), .B(adj_op[7]), .Z(n212) );
  NR2B1M2N U532 ( .NA(n235), .B(adj_op[14]), .Z(n237) );
  NR2B1M2N U533 ( .NA(n220), .B(adj_op[12]), .Z(n236) );
  NR2B1M2N U534 ( .NA(n236), .B(adj_op[13]), .Z(n235) );
  INVM2N U535 ( .A(n180), .Z(n343) );
  INVM2N U536 ( .A(n168), .Z(n359) );
  INVM2N U537 ( .A(n160), .Z(n367) );
  NR2M2N U538 ( .A(n217), .B(adj_op[6]), .Z(n211) );
  INVM2N U539 ( .A(n173), .Z(n356) );
  INVM2N U540 ( .A(n163), .Z(n364) );
  INVM2N U541 ( .A(n159), .Z(n368) );
  INVM2N U542 ( .A(n183), .Z(n344) );
  INVM2N U543 ( .A(n191), .Z(n352) );
  INVM2N U544 ( .A(n149), .Z(n328) );
  INVM2N U545 ( .A(n153), .Z(n332) );
  INVM2N U546 ( .A(n146), .Z(n327) );
  INVM2N U547 ( .A(n140), .Z(n321) );
  INVM2N U548 ( .A(n152), .Z(n333) );
  INVM2N U549 ( .A(n195), .Z(n397) );
  INVM2N U550 ( .A(n203), .Z(n384) );
  ND2M2N U551 ( .A(n229), .B(n244), .Z(n230) );
  INVM2N U552 ( .A(n205), .Z(n386) );
  INVM2N U553 ( .A(n185), .Z(n346) );
  INVM2N U554 ( .A(n247), .Z(n388) );
  OR3M2N U555 ( .A(adj_op[2]), .B(n384), .C(n386), .Z(n208) );
  INVM2N U556 ( .A(n147), .Z(n326) );
  INVM2N U557 ( .A(n141), .Z(n320) );
  INVM2N U558 ( .A(n148), .Z(n329) );
  INVM2N U559 ( .A(n190), .Z(n353) );
  INVM2N U560 ( .A(n242), .Z(n383) );
  INVM2N U561 ( .A(n244), .Z(n385) );
  INVM2N U562 ( .A(n181), .Z(n342) );
  OR2M2N U563 ( .A(n230), .B(adj_op[17]), .Z(n231) );
  OR2M2N U564 ( .A(n215), .B(adj_op[5]), .Z(n217) );
  INVM2N U565 ( .A(n161), .Z(n366) );
  INVM2N U566 ( .A(n169), .Z(n358) );
  INVM2N U567 ( .A(n182), .Z(n345) );
  INVM2N U568 ( .A(n158), .Z(n369) );
  INVM2N U569 ( .A(n172), .Z(n357) );
  ND2M2N U570 ( .A(n387), .B(n396), .Z(exp_large[7]) );
  OR2M2N U571 ( .A(n210), .B(adj_op[4]), .Z(n215) );
  OR2M2N U572 ( .A(n208), .B(adj_op[3]), .Z(n210) );
  INVM2N U573 ( .A(n165), .Z(n362) );
  INVM2N U574 ( .A(n167), .Z(n360) );
  INVM2N U575 ( .A(n166), .Z(n361) );
  NR3B1M2N U576 ( .NA(n265), .B(N222), .C(n267), .Z(n271) );
  AOI22M2N U577 ( .A1(n288), .A2(adj_op_out_sft[16]), .B1(n295), .B2(opb[13]), 
        .Z(n178) );
  INVM2N U578 ( .A(opa[24]), .Z(n394) );
  AOI22M2N U579 ( .A1(n261), .A2(n262), .B1(opa[27]), .B2(n400), .Z(n259) );
  OAI22M1N U580 ( .A1(opb[26]), .A2(n392), .B1(n263), .B2(n264), .Z(n262) );
  AOI22M2N U581 ( .A1(n265), .A2(n266), .B1(opa[25]), .B2(n402), .Z(n263) );
  OAI32M0N U582 ( .A1(n395), .A2(opb[23]), .A3(n267), .B1(opb[24]), .B2(n394), 
        .Z(n266) );
  CKBUFM2N U583 ( .A(n194), .Z(n285) );
  OAI22M1N U584 ( .A1(opb[30]), .A2(n387), .B1(n255), .B2(n256), .Z(n194) );
  AOI22M2N U585 ( .A1(n257), .A2(n258), .B1(opa[29]), .B2(n398), .Z(n255) );
  OAI22M1N U586 ( .A1(opb[28]), .A2(n390), .B1(n259), .B2(n260), .Z(n258) );
  AOI22M2N U587 ( .A1(n288), .A2(opa[13]), .B1(n299), .B2(adj_op_out_sft[16]), 
        .Z(n179) );
  AOI22M2N U588 ( .A1(n290), .A2(opa[14]), .B1(n296), .B2(adj_op_out_sft[17]), 
        .Z(n177) );
  AOI22M2N U589 ( .A1(n290), .A2(opa[15]), .B1(n299), .B2(adj_op_out_sft[18]), 
        .Z(n175) );
  AOI22M2N U590 ( .A1(n287), .A2(adj_op_out_sft[22]), .B1(n295), .B2(opb[19]), 
        .Z(n164) );
  AOI22M2N U591 ( .A1(n288), .A2(adj_op_out_sft[17]), .B1(n295), .B2(opb[14]), 
        .Z(n176) );
  AOI22M2N U592 ( .A1(n288), .A2(adj_op_out_sft[18]), .B1(n291), .B2(opb[15]), 
        .Z(n174) );
  AOI22M2N U593 ( .A1(n287), .A2(adj_op_out_sft[23]), .B1(n296), .B2(opb[20]), 
        .Z(n162) );
  AOI22M2N U594 ( .A1(n288), .A2(adj_op_out_sft[12]), .B1(n297), .B2(opb[9]), 
        .Z(n186) );
  AOI22M2N U595 ( .A1(n288), .A2(adj_op_out_sft[11]), .B1(n295), .B2(opb[8]), 
        .Z(n188) );
  AOI22M2N U596 ( .A1(n288), .A2(opa[1]), .B1(n297), .B2(adj_op_out_sft[4]), 
        .Z(n151) );
  AOI22M2N U597 ( .A1(n288), .A2(opa[4]), .B1(n291), .B2(adj_op_out_sft[7]), 
        .Z(n145) );
  AOI22M2N U598 ( .A1(n288), .A2(opa[5]), .B1(n296), .B2(adj_op_out_sft[8]), 
        .Z(n143) );
  AOI22M2N U599 ( .A1(n290), .A2(opa[8]), .B1(n296), .B2(adj_op_out_sft[11]), 
        .Z(n189) );
  AOI22M2N U600 ( .A1(n290), .A2(opa[9]), .B1(n298), .B2(adj_op_out_sft[12]), 
        .Z(n187) );
  AOI22M2N U601 ( .A1(n288), .A2(adj_op_out_sft[4]), .B1(n295), .B2(opb[1]), 
        .Z(n150) );
  AOI22M2N U602 ( .A1(n287), .A2(adj_op_out_sft[7]), .B1(n294), .B2(opb[4]), 
        .Z(n144) );
  AOI22M2N U603 ( .A1(n287), .A2(adj_op_out_sft[8]), .B1(n294), .B2(opb[5]), 
        .Z(n142) );
  ND4M2N U604 ( .A(n404), .B(n403), .C(n272), .D(n273), .Z(n195) );
  NR2M2N U605 ( .A(opb[26]), .B(opb[25]), .Z(n272) );
  NR4M1N U606 ( .A(opb[30]), .B(opb[29]), .C(opb[28]), .D(opb[27]), .Z(n273)
         );
  XOR2M1N U607 ( .A(opa[27]), .B(n400), .Z(n261) );
  XOR2M1N U608 ( .A(opa[30]), .B(opb[30]), .Z(n256) );
  NR2M2N U609 ( .A(opa[26]), .B(opa[25]), .Z(n274) );
  NR4M1N U610 ( .A(opa[30]), .B(opa[29]), .C(opa[28]), .D(opa[27]), .Z(n275)
         );
  XOR2M1N U611 ( .A(opa[28]), .B(opb[28]), .Z(n260) );
  XOR2M1N U612 ( .A(opa[26]), .B(opb[26]), .Z(n264) );
  XOR2M1N U613 ( .A(opa[25]), .B(n402), .Z(n265) );
  XOR2M1N U614 ( .A(opa[29]), .B(n398), .Z(n257) );
  OAI22B20M2N U615 ( .B1(n139), .B2(n308), .NA1(n314), .NA2(opa[31]), .Z(
        sign_d) );
  INVM2N U616 ( .A(opb[24]), .Z(n403) );
  INVM2N U617 ( .A(opb[23]), .Z(n404) );
  INVM2N U618 ( .A(opb[25]), .Z(n402) );
  INVM2N U619 ( .A(opb[27]), .Z(n400) );
  INVM2N U620 ( .A(opb[29]), .Z(n398) );
  INVM2N U621 ( .A(opa[23]), .Z(n395) );
  INVM2N U622 ( .A(opa[30]), .Z(n387) );
  INVM2N U623 ( .A(opa[26]), .Z(n392) );
  INVM2N U624 ( .A(opa[28]), .Z(n390) );
  AOI22M2N U625 ( .A1(n287), .A2(adj_op_out_sft[19]), .B1(n295), .B2(opb[16]), 
        .Z(n172) );
  AOI22M2N U626 ( .A1(n287), .A2(adj_op_out_sft[20]), .B1(n295), .B2(opb[17]), 
        .Z(n168) );
  AOI22M2N U627 ( .A1(n288), .A2(adj_op_out_sft[15]), .B1(n295), .B2(opb[12]), 
        .Z(n180) );
  AOI22M2N U628 ( .A1(n287), .A2(adj_op_out_sft[24]), .B1(n295), .B2(opb[21]), 
        .Z(n160) );
  AOI22M2N U629 ( .A1(n288), .A2(adj_op_out_sft[25]), .B1(n294), .B2(opb[22]), 
        .Z(n158) );
  AOI22M2N U630 ( .A1(n288), .A2(adj_op_out_sft[14]), .B1(n303), .B2(opb[11]), 
        .Z(n182) );
  AOI22M2N U631 ( .A1(n288), .A2(adj_op_out_sft[13]), .B1(n298), .B2(opb[10]), 
        .Z(n184) );
  AOI22M2N U632 ( .A1(n287), .A2(opa[0]), .B1(n296), .B2(adj_op_out_sft[3]), 
        .Z(n153) );
  AOI22M2N U633 ( .A1(n288), .A2(opa[2]), .B1(n296), .B2(adj_op_out_sft[5]), 
        .Z(n149) );
  AOI22M2N U634 ( .A1(n288), .A2(opa[3]), .B1(n303), .B2(adj_op_out_sft[6]), 
        .Z(n147) );
  AOI22M2N U635 ( .A1(n288), .A2(opa[6]), .B1(n296), .B2(adj_op_out_sft[9]), 
        .Z(n141) );
  AOI22M2N U636 ( .A1(n285), .A2(opa[7]), .B1(n299), .B2(adj_op_out_sft[10]), 
        .Z(n191) );
  AOI22M2N U637 ( .A1(n287), .A2(opa[10]), .B1(n298), .B2(adj_op_out_sft[13]), 
        .Z(n185) );
  AOI22M2N U638 ( .A1(n194), .A2(opa[11]), .B1(n298), .B2(adj_op_out_sft[14]), 
        .Z(n183) );
  AOI22M2N U639 ( .A1(n285), .A2(opa[12]), .B1(n299), .B2(adj_op_out_sft[15]), 
        .Z(n181) );
  AOI22M2N U640 ( .A1(n290), .A2(opa[19]), .B1(n291), .B2(adj_op_out_sft[22]), 
        .Z(n165) );
  AOI22M2N U641 ( .A1(n286), .A2(opa[16]), .B1(n298), .B2(adj_op_out_sft[19]), 
        .Z(n173) );
  AOI22M2N U642 ( .A1(n194), .A2(opa[17]), .B1(n299), .B2(adj_op_out_sft[20]), 
        .Z(n169) );
  AOI22M2N U643 ( .A1(n285), .A2(opa[21]), .B1(n303), .B2(adj_op_out_sft[24]), 
        .Z(n161) );
  AOI22M2N U644 ( .A1(n290), .A2(opa[20]), .B1(n291), .B2(adj_op_out_sft[23]), 
        .Z(n163) );
  AOI22M2N U645 ( .A1(n285), .A2(opa[22]), .B1(n299), .B2(adj_op_out_sft[25]), 
        .Z(n159) );
  AOI22M2N U646 ( .A1(n287), .A2(adj_op_out_sft[3]), .B1(n294), .B2(opb[0]), 
        .Z(n152) );
  AOI22M2N U647 ( .A1(n287), .A2(adj_op_out_sft[5]), .B1(n294), .B2(opb[2]), 
        .Z(n148) );
  AOI22M2N U648 ( .A1(n287), .A2(adj_op_out_sft[6]), .B1(n295), .B2(opb[3]), 
        .Z(n146) );
  AOI22M2N U649 ( .A1(n290), .A2(adj_op_out_sft[9]), .B1(n296), .B2(opb[6]), 
        .Z(n140) );
  AOI22M2N U650 ( .A1(n288), .A2(adj_op_out_sft[10]), .B1(n291), .B2(opb[7]), 
        .Z(n190) );
  AOI22M2N U651 ( .A1(n289), .A2(opb[16]), .B1(n296), .B2(opa[16]), .Z(n244)
         );
  AOI22M2N U652 ( .A1(n289), .A2(opb[21]), .B1(n291), .B2(opa[21]), .Z(n242)
         );
  AOI22M2N U653 ( .A1(n289), .A2(opb[1]), .B1(n296), .B2(opa[1]), .Z(n203) );
  AOI22M2N U654 ( .A1(n287), .A2(opb[0]), .B1(n295), .B2(opa[0]), .Z(n205) );
  AO22M0N U655 ( .A1(n289), .A2(opb[18]), .B1(n296), .B2(opa[18]), .Z(
        adj_op[18]) );
  AO22M0N U656 ( .A1(n289), .A2(opb[13]), .B1(n297), .B2(opa[13]), .Z(
        adj_op[13]) );
  AO22M0N U657 ( .A1(n289), .A2(opb[14]), .B1(n297), .B2(opa[14]), .Z(
        adj_op[14]) );
  AO22M0N U658 ( .A1(n289), .A2(opb[15]), .B1(n297), .B2(opa[15]), .Z(
        adj_op[15]) );
  AO22M0N U659 ( .A1(n289), .A2(opb[19]), .B1(n296), .B2(opa[19]), .Z(
        adj_op[19]) );
  AO22M0N U660 ( .A1(n289), .A2(opb[20]), .B1(n296), .B2(opa[20]), .Z(
        adj_op[20]) );
  AO22M0N U661 ( .A1(n289), .A2(opb[22]), .B1(n296), .B2(opa[22]), .Z(
        adj_op[22]) );
  AO22M0N U662 ( .A1(n289), .A2(opb[2]), .B1(n296), .B2(opa[2]), .Z(adj_op[2])
         );
  AO22M0N U663 ( .A1(n289), .A2(opb[17]), .B1(n297), .B2(opa[17]), .Z(
        adj_op[17]) );
  INVM2N U664 ( .A(opb[30]), .Z(n396) );
  INVM2N U665 ( .A(opa[25]), .Z(n393) );
  INVM2N U666 ( .A(opb[26]), .Z(n401) );
  INVM2N U667 ( .A(opa[27]), .Z(n391) );
  INVM2N U668 ( .A(opb[28]), .Z(n399) );
  INVM2N U669 ( .A(opa[29]), .Z(n389) );
  XOR2M1N U670 ( .A(opa[23]), .B(n404), .Z(n269) );
  NR3B1M2N U671 ( .NA(n257), .B(n256), .C(n260), .Z(n270) );
  ND3B1M2N U672 ( .NA(n264), .B(n271), .C(n261), .Z(n268) );
  AOI22M2N U673 ( .A1(n288), .A2(adj_op_out_sft[21]), .B1(n291), .B2(opb[18]), 
        .Z(n166) );
  AOI22M2N U674 ( .A1(n285), .A2(opa[18]), .B1(n297), .B2(adj_op_out_sft[21]), 
        .Z(n167) );
  AO22M0N U675 ( .A1(n289), .A2(opb[6]), .B1(n297), .B2(opa[6]), .Z(adj_op[6])
         );
  AO22M0N U676 ( .A1(n289), .A2(opb[7]), .B1(n296), .B2(opa[7]), .Z(adj_op[7])
         );
  AO22M0N U677 ( .A1(n289), .A2(opb[8]), .B1(n296), .B2(opa[8]), .Z(adj_op[8])
         );
  AO22M0N U678 ( .A1(n289), .A2(opb[9]), .B1(n296), .B2(opa[9]), .Z(adj_op[9])
         );
  AO22M0N U679 ( .A1(n289), .A2(opb[12]), .B1(n297), .B2(opa[12]), .Z(
        adj_op[12]) );
  AO22M0N U680 ( .A1(n290), .A2(opb[10]), .B1(n297), .B2(opa[10]), .Z(
        adj_op[10]) );
  AO22M0N U681 ( .A1(n290), .A2(opb[11]), .B1(n297), .B2(opa[11]), .Z(
        adj_op[11]) );
  AO22M0N U682 ( .A1(n289), .A2(opb[3]), .B1(n296), .B2(opa[3]), .Z(adj_op[3])
         );
  AO22M0N U683 ( .A1(n289), .A2(opb[4]), .B1(n296), .B2(opa[4]), .Z(adj_op[4])
         );
  AO22M0N U684 ( .A1(n289), .A2(opb[5]), .B1(n296), .B2(opa[5]), .Z(adj_op[5])
         );
  AO22B10M2N U685 ( .B1(n248), .B2(signa_r), .A1(signb_r), .NA2(n249), .Z(N211) );
  OAI31M2N U686 ( .A1(fracta_eq_fractb), .A2(fracta_lt_fractb), .A3(n250), .B(
        opb_nan), .Z(n248) );
  AOI211M2N U687 ( .A1(opb_nan), .A2(n250), .B(signa_r), .C(n251), .Z(n249) );
  NR3B1M2N U688 ( .NA(fracta_lt_fractb), .B(fracta_eq_fractb), .C(n250), .Z(
        n251) );
  XOR2M1N U689 ( .A(opb[31]), .B(add), .Z(n139) );
  XOR2M1N U690 ( .A(opa[31]), .B(n139), .Z(N222) );
  OAI21M0N U691 ( .A1(n405), .A2(n252), .B(n253), .Z(N200) );
  INVM2N U692 ( .A(signa_r), .Z(n405) );
  OAI211B100M0N U693 ( .NA2(n252), .A1(signa_r), .B(rmode[0]), .C(rmode[1]), 
        .Z(n253) );
  XOR2M1N U694 ( .A(signb_r), .B(add_r), .Z(n252) );
  ND2M2N U695 ( .A(opa_nan), .B(opb_nan), .Z(n250) );
  AOI31M0N U696 ( .A1(exp_diff[2]), .A2(exp_diff[4]), .A3(\gt_135/A[3] ), .B(
        exp_diff[5]), .Z(n319) );
  NR2M0N U697 ( .A(exp_diff[7]), .B(exp_diff[6]), .Z(n318) );
  CKND2M2N U698 ( .A(n319), .B(n318), .Z(exp_lt_27) );
endmodule

