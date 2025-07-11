/* Generated by gep (125/05/23 10:52:00) copyright (c) 2008 IRIT - UPS */
#ifndef GLISS_MOS6502_INCLUDE_MOS6502_ID_H
#define GLISS_MOS6502_INCLUDE_MOS6502_ID_H

#define MOS6502_INSTRUCTIONS_NB 251

/* (mos6502_ident_t enumeration */
typedef enum mos6502_ident_t {
	MOS6502_UNKNOWN = 0,
	MOS6502_JAM = 1,
	MOS6502_JAM_0 = 2,
	MOS6502_JAM_1 = 3,
	MOS6502_JAM_2 = 4,
	MOS6502_JAM_3 = 5,
	MOS6502_JAM_4 = 6,
	MOS6502_JAM_5 = 7,
	MOS6502_JAM_6 = 8,
	MOS6502_JAM_7 = 9,
	MOS6502_JAM_8 = 10,
	MOS6502_JAM_9 = 11,
	MOS6502_JAM_10 = 12,
	MOS6502_IGN__242X__X = 13,
	MOS6502_IGN__242X__X_0 = 14,
	MOS6502_IGN__242X__X_1 = 15,
	MOS6502_IGN__242X__X_2 = 16,
	MOS6502_IGN__242X__X_3 = 17,
	MOS6502_IGN__242X__X_4 = 18,
	MOS6502_IGN__242X = 19,
	MOS6502_IGN__242X_0 = 20,
	MOS6502_IGN__242X_1 = 21,
	MOS6502_IGN__242X2X__X = 22,
	MOS6502_IGN__242X2X__X_0 = 23,
	MOS6502_IGN__242X2X__X_1 = 24,
	MOS6502_IGN__242X2X__X_2 = 25,
	MOS6502_IGN__242X2X__X_3 = 26,
	MOS6502_IGN__242X2X__X_4 = 27,
	MOS6502_IGN__242X2X = 28,
	MOS6502_SKB__I2X = 29,
	MOS6502_SKB__I2X_0 = 30,
	MOS6502_SKB__I2X_1 = 31,
	MOS6502_SKB__I2X_2 = 32,
	MOS6502_SKB__I2X_3 = 33,
	MOS6502_NOP = 34,
	MOS6502_NOP_0 = 35,
	MOS6502_NOP_1 = 36,
	MOS6502_NOP_2 = 37,
	MOS6502_NOP_3 = 38,
	MOS6502_NOP_4 = 39,
	MOS6502_USBC__I2X = 40,
	MOS6502_SLO__LP__242X_RP___Y = 41,
	MOS6502_SLO__LP__242X__X_RP_ = 42,
	MOS6502_SLO__242X2X__Y = 43,
	MOS6502_SLO__242X2X__X = 44,
	MOS6502_SLO__242X2X = 45,
	MOS6502_SLO__242X__X = 46,
	MOS6502_SLO__242X = 47,
	MOS6502_RLA__LP__242X_RP___Y = 48,
	MOS6502_RLA__LP__242X__X_RP_ = 49,
	MOS6502_RLA__242X2X__Y = 50,
	MOS6502_RLA__242X2X__X = 51,
	MOS6502_RLA__242X2X = 52,
	MOS6502_RLA__242X__X = 53,
	MOS6502_RLA__242X = 54,
	MOS6502_RRA__LP__242X_RP__Y = 55,
	MOS6502_RRA__LP__242X_X_RP_ = 56,
	MOS6502_RRA__242X2X__Y = 57,
	MOS6502_RRA__242X2X__X = 58,
	MOS6502_RRA__242X2X = 59,
	MOS6502_RRA__242X__X = 60,
	MOS6502_RRA__242X = 61,
	MOS6502_SRE__LP__242X_RP___Y = 62,
	MOS6502_SRE__LP__242X__X_RP_ = 63,
	MOS6502_SRE__242X2X__Y = 64,
	MOS6502_SRE__242X2X__X = 65,
	MOS6502_SRE__242X2X = 66,
	MOS6502_SRE__242X__X = 67,
	MOS6502_SRE__242X = 68,
	MOS6502_ISC__LP__242X_RP___Y = 69,
	MOS6502_ISC__LP__242X__X_RP_ = 70,
	MOS6502_ISC__242X2X__Y = 71,
	MOS6502_ISC__242X2X__X = 72,
	MOS6502_ISC__242X2X = 73,
	MOS6502_ISC__242X__X = 74,
	MOS6502_ISC__242X = 75,
	MOS6502_DCP__LP__242X_RP___Y = 76,
	MOS6502_DCP__LP__242X__X_RP_ = 77,
	MOS6502_DCP__242X2X__Y = 78,
	MOS6502_DCP__242X2X__X = 79,
	MOS6502_DCP__242X2X = 80,
	MOS6502_DCP__242X__X = 81,
	MOS6502_DCP__242X = 82,
	MOS6502_SHA__LP__242X_RP___Y = 83,
	MOS6502_SHA__242X2X = 84,
	MOS6502_SHY__242X2X = 85,
	MOS6502_SHX__242X2X = 86,
	MOS6502_SAX__LP__242X__X_RP_ = 87,
	MOS6502_SAX__242X2X = 88,
	MOS6502_SAX__242X__Y = 89,
	MOS6502_SAX__242X = 90,
	MOS6502_LAX__LP__242X_RP___Y = 91,
	MOS6502_LAX__LP__242X__X_RP_ = 92,
	MOS6502_LAX__242X2X__Y = 93,
	MOS6502_LAX__242X2X = 94,
	MOS6502_LAX__242X__Y = 95,
	MOS6502_LAX__242X = 96,
	MOS6502_SBX__I2X = 97,
	MOS6502_ARR__I2X = 98,
	MOS6502_ANC2__I2X = 99,
	MOS6502_ANC__I2X = 100,
	MOS6502_ALR__I2X = 101,
	MOS6502_NOP_5 = 102,
	MOS6502_BIT__242X = 103,
	MOS6502_BIT__242X2X = 104,
	MOS6502_RTS = 105,
	MOS6502_JSR__242X2X = 106,
	MOS6502_JMP__LP__242X2X_RP_ = 107,
	MOS6502_JMP__242X2X = 108,
	MOS6502_BVS__I2X = 109,
	MOS6502_BVC__I2X = 110,
	MOS6502_BPL__I2X = 111,
	MOS6502_BNE__I2X = 112,
	MOS6502_BMI__I2X = 113,
	MOS6502_BEQ__I2X = 114,
	MOS6502_BCS__I2X = 115,
	MOS6502_BCC__I2X = 116,
	MOS6502_ROR__242X2X__X = 117,
	MOS6502_ROR__242X2X = 118,
	MOS6502_ROR__242X__X = 119,
	MOS6502_ROR__242X = 120,
	MOS6502_ROR_A = 121,
	MOS6502_ROL__242X2X = 122,
	MOS6502_ROL__242X2X_0 = 123,
	MOS6502_ROL_2X__X = 124,
	MOS6502_ROL__242X = 125,
	MOS6502_ROL_A = 126,
	MOS6502_LSR__242X2X__X = 127,
	MOS6502_LSR__242X2X = 128,
	MOS6502_LSR__242X__X = 129,
	MOS6502_LSR__242X = 130,
	MOS6502_LSR_A = 131,
	MOS6502_ASL__242X2X__X = 132,
	MOS6502_ASL__242X2X = 133,
	MOS6502_ASL__242X__X = 134,
	MOS6502_ASL__242X = 135,
	MOS6502_ASL_A = 136,
	MOS6502_CPY__242X2X = 137,
	MOS6502_CPY__242X = 138,
	MOS6502_CPY__I2X = 139,
	MOS6502_CPX__242X2X = 140,
	MOS6502_CPX__242X = 141,
	MOS6502_CPX__I2X = 142,
	MOS6502_CMP__LP__242X_RP___Y = 143,
	MOS6502_CMP__LP__242X__X_RP_ = 144,
	MOS6502_CMP__242X2X__Y = 145,
	MOS6502_CMP__242X2X__X = 146,
	MOS6502_CMP__242X2X = 147,
	MOS6502_CMP__242X__X = 148,
	MOS6502_CMP__242X = 149,
	MOS6502_CMP__I2X = 150,
	MOS6502_SBC__LP__242X_RP___Y = 151,
	MOS6502_SBC__LP__242X__X_RP_ = 152,
	MOS6502_SBC__242X2X__Y = 153,
	MOS6502_SBC__242X2X__X = 154,
	MOS6502_SBC__242X2X = 155,
	MOS6502_SBC__242X__X = 156,
	MOS6502_SBC__242X = 157,
	MOS6502_SBC__I2X = 158,
	MOS6502_ADC__LP__242X_RP___Y = 159,
	MOS6502_ADC__LP__242X__X_RP_ = 160,
	MOS6502_ADC__242X2X__Y = 161,
	MOS6502_ADC__242X2X__X = 162,
	MOS6502_ADC__242X2X = 163,
	MOS6502_ADC__242X__X = 164,
	MOS6502_ADC__242X = 165,
	MOS6502_ADC__ID = 166,
	MOS6502_DEC__242X2X__X = 167,
	MOS6502_DEC__242X2X = 168,
	MOS6502_DEC__242X__X = 169,
	MOS6502_DEC__242X = 170,
	MOS6502_INC__242X2X__X = 171,
	MOS6502_INC__242X2X = 172,
	MOS6502_INC__242X__X = 173,
	MOS6502_INC__242X = 174,
	MOS6502_DEY = 175,
	MOS6502_INY = 176,
	MOS6502_DEX = 177,
	MOS6502_INX = 178,
	MOS6502_EOR__LP__242X_RP___Y = 179,
	MOS6502_EOR__LP__242X__X_RP_ = 180,
	MOS6502_EOR__242X2X__Y = 181,
	MOS6502_EOR__242X2X__X = 182,
	MOS6502_EOR__242X2X = 183,
	MOS6502_EOR__242X__X = 184,
	MOS6502_EOR__242X = 185,
	MOS6502_EOR__I2X = 186,
	MOS6502_ORA__LP__242X_RP___Y = 187,
	MOS6502_ORA__LP__242X__X_RP_ = 188,
	MOS6502_ORA__242X2X__Y = 189,
	MOS6502_ORA__242X2X__X = 190,
	MOS6502_ORA__242X2X = 191,
	MOS6502_ORA__242X__X = 192,
	MOS6502_ORA__242X = 193,
	MOS6502_ORA__I2X = 194,
	MOS6502_AND__LP__242X_RP___Y = 195,
	MOS6502_AND__LP__242X__X_RP_ = 196,
	MOS6502_AND__242X2X__Y = 197,
	MOS6502_AND__242X2X__X = 198,
	MOS6502_AND__242X2X = 199,
	MOS6502_AND__242X__X = 200,
	MOS6502_AND__242X = 201,
	MOS6502_AND__I2X = 202,
	MOS6502_SEI = 203,
	MOS6502_SEC = 204,
	MOS6502_SED = 205,
	MOS6502_CLV = 206,
	MOS6502_CLI = 207,
	MOS6502_CLD = 208,
	MOS6502_CLC = 209,
	MOS6502_PLP = 210,
	MOS6502_PHP = 211,
	MOS6502_PLA = 212,
	MOS6502_PHA = 213,
	MOS6502_TYA = 214,
	MOS6502_TXS = 215,
	MOS6502_TXA = 216,
	MOS6502_TSX = 217,
	MOS6502_TAY = 218,
	MOS6502_TAX = 219,
	MOS6502_STY__242X2X = 220,
	MOS6502_STY__242X__X = 221,
	MOS6502_STY__242X = 222,
	MOS6502_STX__242X2X = 223,
	MOS6502_STX__242X__Y = 224,
	MOS6502_STX__242X = 225,
	MOS6502_STA__LP__242X__X_RP_ = 226,
	MOS6502_STA__LP__242X_RP___Y = 227,
	MOS6502_STA__242X2X__Y = 228,
	MOS6502_STA__242X2X__X = 229,
	MOS6502_STA__242X2X = 230,
	MOS6502_STA__242X__X = 231,
	MOS6502_STA__242X = 232,
	MOS6502_LDY__242X2X__X = 233,
	MOS6502_LDY__242X2X = 234,
	MOS6502_LDY__242X__X = 235,
	MOS6502_LDY__242X = 236,
	MOS6502_LDY__I2X = 237,
	MOS6502_LDX__242X2X__Y = 238,
	MOS6502_LDX__242X2X = 239,
	MOS6502_LDX__242X__Y = 240,
	MOS6502_LDX__242X = 241,
	MOS6502_LDX__I2X = 242,
	MOS6502_LDA__LP__242X_RP___Y = 243,
	MOS6502_LDA__LP__242X__X_RP_ = 244,
	MOS6502_LDA__242X2X__Y = 245,
	MOS6502_LDA__242X2X__X = 246,
	MOS6502_LDA__242X2X = 247,
	MOS6502_LDA__242X__X = 248,
	MOS6502_LDA__242X = 249,
	MOS6502_LDA__I2X = 250,
	MOS6502_TOP
} mos6502_ident_t;

#endif /* GLISS_MOS6502_INCLUDE_MOS6502_ID_H */
