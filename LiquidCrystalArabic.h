#include <LiquidCrystal.h>

#define UTF_SPACE                 32
#define UTF_EXCLAMATION_MARK      33
#define UTF_DOUBLE_QUOTE          34
#define UTF_NUMBER_SIGN           35
#define UTF_DOLLAR_SIGN           36
#define UTF_PERCENT_SIGN          37
#define UTF_AMPERSAND             38
#define UTF_SINGLE_QUOTE          39
#define UTF_LEFT_PARENTHESIS      40
#define UTF_RIGHT_PARENTHESIS     41
#define UTF_ASTERISK              42
#define UTF_PLUS_SIGN             43
#define UTF_COMMA                 44
#define UTF_HYPHEN_MINUS          45
#define UTF_DOT                   46
#define UTF_SLASH                 47
#define UTF_DIGIT_0               48
#define UTF_DIGIT_1               49
#define UTF_DIGIT_2               50
#define UTF_DIGIT_3               51
#define UTF_DIGIT_4               52
#define UTF_DIGIT_5               53
#define UTF_DIGIT_6               54
#define UTF_DIGIT_7               55
#define UTF_DIGIT_8               56
#define UTF_DIGIT_9               57
#define UTF_COLON                 58
#define UTF_SEMICOLON             59
#define UTF_LESS_THAN_SIGN        60
#define UTF_EQUAL_SIGN            61
#define UTF_GREATER_THAN_SIGN     62
#define UTF_QUESTION_MARK         63
#define UTF_AT_SIGN               64
#define UTF_LEFT_SQUARE_BRACKET   91
#define UTF_BACKSLASH             92
#define UTF_RIGHT_SQUARE_BRACKET  93
#define UTF_CIRCUMFLEX_ACCENT     94
#define UTF_UNDERSCORE            95
#define UTF_GRAVE_ACCENT          96
#define UTF_LEFT_CURLY_BRACKET    123
#define UTF_VERTICAL_BAR          124
#define UTF_RIGHT_CURLY_BRACKET   125
#define UTF_TILDE                 126
#define UTF_DELETE                127

#define UTF_ARABIC_PREFIX_1       216
#define UTF_ARABIC_PREFIX_2       217
#define UTF_ALEF                  167
#define UTF_BAA                   168
#define UTF_TAA                   170
#define UTF_THAA                  171
#define UTF_JEEM                  172
#define UTF_7AA                   173
#define UTF_KHAA                  174
#define UTF_DAL                   175
#define UTF_THAL                  176
#define UTF_RAA                   177
#define UTF_ZAIN                  178
#define UTF_SEEN                  179
#define UTF_SHEEN                 180
#define UTF_SAAD                  181
#define UTF_DAAD                  182
#define UTF_6AA                   183
#define UTF_DAA                   184
#define UTF_AYN                   185
#define UTF_GHAYN                 186
#define UTF_FAA                   129
#define UTF_QAF                   130
#define UTF_KAF                   131
#define UTF_LAM                   132
#define UTF_MEEM                  133
#define UTF_NOON                  134
#define UTF_HAA                   135
#define UTF_WAW                   136
#define UTF_YAA                   138
#define UTF_HAMZA                 161
#define UTF_ALEF_MAMDODA          162
#define UTF_HAMZA_ON_ALEF_MAQSORA 166
#define UTF_HAMZA_ON_ALEF         163
#define UTF_HAMZA_ON_WAW          164
#define UTF_ALEF_MAQSORA          137
#define UTF_KASHIDA               128
#define UTF_TAA_MARBOTA           169
#define UTF_HAMZA_UNDER_ALEF      165

#define CODE_ALEF                  0
#define CODE_BAA                   1
#define CODE_TAA                   2
#define CODE_THAA                  3
#define CODE_JEEM                  4
#define CODE_7AA                   5
#define CODE_KHAA                  6
#define CODE_DAL                   7
#define CODE_THAL                  8
#define CODE_RAA                   9
#define CODE_ZAIN                  10
#define CODE_SEEN                  11
#define CODE_SHEEN                 12
#define CODE_SAAD                  13
#define CODE_DAAD                  14
#define CODE_6AA                   15
#define CODE_DAA                   16
#define CODE_AYN                   17
#define CODE_GHAYN                 18
#define CODE_FAA                   19
#define CODE_QAF                   20
#define CODE_KAF                   21
#define CODE_LAM                   22
#define CODE_MEEM                  23
#define CODE_NOON                  24
#define CODE_HAA                   25
#define CODE_WAW                   26
#define CODE_YAA                   27
#define CODE_HAMZA                 28
#define CODE_ALEF_MAMDODA          29
#define CODE_HAMZA_ON_ALEF_MAQSORA 30
#define CODE_HAMZA_ON_ALEF         31
#define CODE_HAMZA_ON_WAW          32
#define CODE_ALEF_MAQSORA          33
#define CODE_KASHIDA               34
#define CODE_TAA_MARBOTA           35
#define CODE_HAMZA_UNDER_ALEF      36
#define CODE_LAM_ALEF              37
#define CODE_ALEF_LAM              38
#define CODE_TERMINATION           255
#define CODE_SPACE                 254
#define CODE_EXCLAMATION_MARK      253
#define CODE_DOUBLE_QUOTE          252
#define CODE_NUMBER_SIGN           251
#define CODE_DOLLAR_SIGN           250
#define CODE_PERCENT_SIGN          249
#define CODE_AMPERSAND             248
#define CODE_SINGLE_QUOTE          247
#define CODE_LEFT_PARENTHESIS      246
#define CODE_RIGHT_PARENTHESIS     245
#define CODE_ASTERISK              244
#define CODE_PLUS_SIGN             243
#define CODE_COMMA                 242
#define CODE_HYPHEN_MINUS          241
#define CODE_DOT                   240
#define CODE_SLASH                 239
#define CODE_DIGIT_0               238
#define CODE_DIGIT_1               237
#define CODE_DIGIT_2               236
#define CODE_DIGIT_3               235
#define CODE_DIGIT_4               234
#define CODE_DIGIT_5               233
#define CODE_DIGIT_6               232
#define CODE_DIGIT_7               231
#define CODE_DIGIT_8               230
#define CODE_DIGIT_9               229
#define CODE_COLON                 228
#define CODE_SEMICOLON             227
#define CODE_LESS_THAN_SIGN        226
#define CODE_EQUAL_SIGN            225
#define CODE_GREATER_THAN_SIGN     224
#define CODE_QUESTION_MARK         223
#define CODE_AT_SIGN               222
#define CODE_LEFT_SQUARE_BRACKET   221
#define CODE_BACKSLASH             220
#define CODE_RIGHT_SQUARE_BRACKET  219
#define CODE_CIRCUMFLEX_ACCENT     218
#define CODE_UNDERSCORE            217
#define CODE_GRAVE_ACCENT          216
#define CODE_LEFT_CURLY_BRACKET    215
#define CODE_VERTICAL_BAR          214
#define CODE_RIGHT_CURLY_BRACKET   213
#define CODE_TILDE                 212
#define CODE_DELETE                211

#define FORM_ISOLATED 0
#define FORM_FINAL    1
#define FORM_INITIAL  2
#define FORM_MEDIAL   3

const uint8_t arabicLetterToIndexMap[39] PROGMEM  = {
    0,    // ا
    2,    // ب
    6,    // ت
    10,   // ت
    14,   // ج
    18,   // ح
    22,   // خ
    26,   // د
    28,   // ذ
    30,   // ر
    32,   // ز
    34,   // س
    38,   // ش
    42,   // ص
    46,   // ض
    50,   // ط
    54,   // ظ
    58,   // ع
    62,   // غ
    66,   // ف
    70,   // ق
    74,   // ك
    78,   // ل
    82,   // م
    86,   // ن
    90,   // ه
    94,   // و
    96,   // ي
    100,  // ء
    101,  // آ
    103,  // ئ
    107,  // أ
    109,  // ؤ
    111,  // ى
    115,  // ـ
    116,  // ة
    118,  // إ
    120,  // لا
    122   // ال
};

const uint8_t arabicBitmap[126][8] PROGMEM  = {
    {B00100, B00100, B00100, B00100, B00100, B00100, B00000, B00000},   // ا
    {B00100, B00100, B00100, B00100, B00100, B00111, B00000, B00000},   // ـا
    {B00000, B00000, B00000, B10001, B10001, B01111, B00000, B00100},   // ب
    {B00000, B00000, B00000, B10001, B10001, B01111, B00000, B00100},   // ـب
    {B00000, B00000, B00000, B00001, B00001, B11111, B00000, B00100},   // بـ
    {B00000, B00000, B00000, B00100, B00100, B11111, B00000, B00100},   // ـبـ
    {B00000, B01010, B00000, B10001, B10001, B01111, B00000, B00000},   // ت
    {B00000, B01010, B00000, B10001, B10001, B01111, B00000, B00000},   // ـت
    {B00000, B01010, B00000, B00001, B00001, B11111, B00000, B00000},   // تـ
    {B00000, B01010, B00000, B00100, B00100, B11111, B00000, B00000},   // ـتـ
    {B00100, B01010, B00000, B10001, B10001, B01111, B00000, B00000},   // ث
    {B00100, B01010, B00000, B10001, B10001, B01111, B00000, B00000},   // ـث
    {B00100, B01010, B00000, B00001, B00001, B11111, B00000, B00000},   // ثـ
    {B00100, B01010, B00000, B00100, B00100, B11111, B00000, B00000},   // ـثـ
    {B00000, B00000, B01110, B00011, B00100, B01010, B01000, B00111},   // ج
    {B00000, B00000, B11100, B00110, B01001, B10100, B10000, B01110},   // ـج
    {B00000, B00000, B00000, B01110, B00001, B11111, B00000, B00100},   // جـ
    {B00000, B00000, B00000, B01100, B00010, B11111, B00000, B00100},   // ـجـ
    {B00000, B00000, B01110, B00011, B00100, B01000, B01000, B00111},   // ح
    {B00000, B00000, B01100, B00010, B01101, B10000, B10000, B01110},   // ـح
    {B00000, B00000, B00000, B01110, B00001, B11111, B00000, B00000},   // حـ
    {B00000, B00000, B00000, B01100, B00010, B11111, B00000, B00000},   // ـحـ
    {B00100, B00000, B01110, B00011, B00100, B01000, B01000, B00111},   // خ
    {B00100, B00000, B01100, B00010, B01101, B10000, B10000, B01110},   // ـخ
    {B00100, B00000, B00000, B01110, B00001, B11111, B00000, B00000},   // خـ
    {B00100, B00000, B00000, B01100, B00010, B11111, B00000, B00000},   // ـخـ
    {B00000, B00000, B00000, B01100, B00010, B01110, B00000, B00000},   // د
    {B00000, B00000, B00000, B01100, B00010, B01111, B00000, B00000},   // ـد
    {B00000, B00100, B00000, B01100, B00010, B01110, B00000, B00000},   // ذ
    {B00000, B00100, B00000, B01100, B00010, B01111, B00000, B00000},   // ـذ
    {B00000, B00000, B00000, B00010, B00010, B00010, B00010, B01100},   // ر
    {B00000, B00000, B00000, B00100, B00100, B00111, B00100, B11000},   // ـر
    {B00000, B00010, B00000, B00010, B00010, B00010, B00010, B01100},   // ز
    {B00000, B00100, B00000, B00100, B00100, B00111, B00100, B11000},   // ـز
    {B00000, B00000, B00000, B00101, B10101, B10111, B10100, B01000},   // س
    {B00000, B00000, B00000, B00101, B10101, B10111, B10100, B01000},   // ـس
    {B00000, B00000, B00000, B10101, B10101, B11111, B00000, B00000},   // سـ
    {B00000, B00000, B00000, B10101, B10101, B11111, B00000, B00000},   // ـسـ
    {B00000, B00010, B00101, B00000, B10101, B10111, B10100, B01000},   // ش
    {B00000, B00010, B00101, B00000, B10101, B10111, B10100, B01000},   // ـش
    {B00100, B01010, B00000, B10101, B10101, B11111, B00000, B00000},   // شـ
    {B00100, B01010, B00000, B10101, B10101, B11111, B00000, B00000},   // ـشـ
    {B00000, B00000, B00000, B00011, B10101, B10111, B11100, B00000},   // ص
    {B00000, B00000, B00000, B00011, B10101, B10111, B11100, B00000},   // ـص
    {B00000, B00000, B00000, B00111, B01001, B11111, B00000, B00000},   // صـ
    {B00000, B00000, B00000, B00111, B01001, B11111, B00000, B00000},   // ـصـ
    {B00000, B00010, B00000, B00011, B10101, B10111, B11100, B00000},   // ض
    {B00000, B00010, B00000, B00011, B10101, B10111, B11100, B00000},   // ـض
    {B00000, B00010, B00000, B00111, B01001, B11111, B00000, B00000},   // ضـ
    {B00000, B00010, B00000, B00111, B01001, B11111, B00000, B00000},   // ـضـ
    {B00000, B01000, B01000, B01110, B01001, B11111, B00000, B00000},   // ط
    {B00000, B01000, B01000, B01110, B01001, B11111, B00000, B00000},   // ـط
    {B00000, B01000, B01000, B01110, B01001, B11111, B00000, B00000},   // طـ
    {B00000, B01000, B01000, B01110, B01001, B11111, B00000, B00000},   // ـطـ
    {B00000, B01010, B01000, B01110, B01001, B11111, B00000, B00000},   // ظ
    {B00000, B01010, B01000, B01110, B01001, B11111, B00000, B00000},   // ـظ
    {B00000, B01010, B01000, B01110, B01001, B11111, B00000, B00000},   // ظـ
    {B00000, B01010, B01000, B01110, B01001, B11111, B00000, B00000},   // ـظـ
    {B00000, B00000, B00110, B01000, B01110, B10000, B10000, B01110},   // ع
    {B00000, B01100, B11100, B01000, B11100, B10111, B10000, B01100},   // ـع
    {B00000, B00000, B00000, B00011, B00100, B11111, B00000, B00000},   // عـ
    {B00000, B00000, B01110, B01010, B00100, B11111, B00000, B00000},   // ـعـ
    {B00100, B00000, B00110, B01000, B01110, B10000, B10000, B01110},   // غ
    {B01000, B00000, B11100, B01100, B11000, B10111, B10000, B01100},   // ـغ
    {B00000, B00010, B00000, B00011, B00100, B11111, B00000, B00000},   // غـ
    {B00100, B00000, B01110, B01010, B00100, B11111, B00000, B00000},   // ـغـ
    {B00000, B00010, B00000, B10111, B10101, B01111, B00000, B00000},   // ف
    {B00000, B00010, B00000, B10111, B10101, B01111, B00000, B00000},   // ـف
    {B00000, B00010, B00000, B00111, B00101, B11111, B00000, B00000},   // فـ
    {B00000, B00100, B00000, B01110, B01010, B11111, B00000, B00000},   // ـفـ
    {B00101, B00000, B00111, B10101, B10111, B10001, B01110, B00000},   // ق
    {B00101, B00000, B00111, B10101, B10111, B10001, B01110, B00000},   // ـق
    {B01010, B00000, B00110, B01010, B00110, B11110, B00000, B00000},   // قـ
    {B01010, B00000, B00110, B01010, B00110, B11111, B00000, B00000},   // ـقـ
    {B00000, B01101, B10001, B11101, B00001, B11111, B00000, B00000},   // ك
    {B00000, B01101, B10001, B01101, B00001, B11111, B00000, B00000},   // ـك
    {B00000, B01110, B10000, B11110, B00001, B11111, B00000, B00000},   // كـ
    {B00000, B01110, B10000, B11110, B00001, B11111, B00000, B00000},   // ـكـ
    {B00010, B00010, B00010, B00010, B10010, B10010, B01100, B00000},   // ل
    {B00010, B00010, B00010, B00010, B10010, B10011, B01100, B00000},   // ـل
    {B00001, B00001, B00001, B00001, B00001, B11111, B00000, B00000},   // لـ
    {B00100, B00100, B00100, B00100, B00100, B11111, B00000, B00000},   // ـلـ
    {B00000, B00110, B01001, B01111, B10000, B10000, B10000, B00000},   // م
    {B00000, B00000, B00000, B00110, B01010, B11111, B10000, B10000},   // ـم
    {B00000, B00000, B00000, B00000, B00011, B11101, B00111, B00000},   // مـ
    {B00000, B00000, B00000, B00000, B00110, B11011, B01110, B00000},   // ـمـ
    {B00000, B00000, B00100, B10001, B10001, B10001, B01110, B00000},   // ن
    {B00000, B00000, B00000, B00100, B10001, B10001, B10001, B01110},   // ـن
    {B00000, B00000, B00100, B00001, B00001, B11111, B00000, B00000},   // نـ
    {B00000, B00100, B00000, B00100, B00100, B11111, B00000, B00000},   // ـنـ
    {B00000, B00000, B00110, B01001, B01001, B00110, B00000, B00000},   // ه
    {B00000, B00000, B00110, B01010, B01110, B00011, B00000, B00000},   // ـه
    {B00000, B00110, B01001, B01101, B10101, B11111, B00000, B00000},   // هـ
    {B00000, B00000, B00000, B00110, B01010, B11101, B01010, B01100},   // ـهـ
    {B00000, B00000, B00000, B00110, B01010, B01110, B00010, B01100},   // و
    {B00000, B00000, B00000, B00110, B01010, B01111, B00010, B01100},   // ـو
    {B00000, B00011, B00100, B10011, B10001, B01110, B00000, B01010},   // ي
    {B00000, B00000, B00000, B10110, B10101, B11101, B00000, B10100},   // ـي
    {B00000, B00000, B00000, B00001, B00001, B11111, B00000, B01010},   // يـ
    {B00000, B00000, B00000, B00100, B00100, B11111, B00000, B01010},   // ـيـ
    {B00000, B00000, B00000, B00110, B01000, B01110, B00000, B00000},   // ء
    {B01100, B10011, B00000, B00100, B00100, B00100, B00000, B00000},   // آ
    {B01100, B10011, B00000, B00100, B00100, B00111, B00000, B00000},   // ـآ
    {B01000, B10000, B11011, B00100, B10011, B10001, B01110, B00000},   // ئ
    {B01100, B10000, B11100, B00000, B10010, B10101, B10100, B01100},   // ـئ
    {B00011, B00100, B00111, B00000, B00010, B11110, B00000, B00000},   // ئـ
    {B00110, B01000, B01110, B00000, B00100, B11111, B00000, B00000},   // ـئـ
    {B00110, B01000, B01110, B00000, B00100, B00100, B00100, B00000},   // أ
    {B00110, B01100, B00000, B00100, B00100, B00111, B00000, B00000},   // ـأ
    {B00110, B01100, B00000, B00110, B01010, B01110, B00010, B01100},   // ؤ
    {B00110, B01100, B00000, B00110, B01010, B01111, B00010, B01100},   // ـؤ
    {B00000, B00011, B00100, B10011, B10001, B01110, B00000, B00000},   // ى
    {B00000, B00000, B00000, B10110, B10101, B11101, B00000, B00000},   // ـى
    {B00000, B00000, B00000, B00010, B00010, B11110, B00000, B00000},   // ىـ
    {B00000, B00000, B00000, B00100, B00100, B11111, B00000, B00000},   // ـىـ
    {B00000, B00000, B00000, B00000, B00000, B11111, B00000, B00000},   // ـ
    {B00000, B01010, B00000, B01110, B01010, B01110, B00000, B00000},   // ة
    {B01010, B00000, B00110, B01010, B01110, B00011, B00000, B00000},   // ـة
    {B00100, B00100, B00100, B00100, B00000, B00110, B01000, B01110},   // إ
    {B00000, B00100, B00100, B00100, B00100, B00111, B01000, B00110},   // ـإ
    {B10010, B10010, B10010, B01010, B00110, B11110, B00000, B00000},   // لا
    {B10010, B10010, B10010, B01010, B00110, B11011, B00000, B00000},   // ـلا
    {B00101, B00101, B00101, B10101, B10101, B10101, B01000, B00000},   // ال
    {B00101, B00101, B00101, B10101, B10101, B10101, B01000, B00000},   // ـال
    {B01001, B01001, B01001, B01001, B01001, B11001, B00000, B00000},   // الـ
    {B01010, B01010, B01010, B01010, B01010, B11011, B00000, B00000},   // ـالـ
};

const struct {
    uint8_t utf;
    uint8_t code;
} ALREADY_DEFINED_CHARS_MAPPING[] = {
    {UTF_SPACE, CODE_SPACE},
    {UTF_EXCLAMATION_MARK, CODE_EXCLAMATION_MARK},
    {UTF_DOUBLE_QUOTE, CODE_DOUBLE_QUOTE},
    {UTF_NUMBER_SIGN, CODE_NUMBER_SIGN},
    {UTF_DOLLAR_SIGN, CODE_DOLLAR_SIGN},
    {UTF_PERCENT_SIGN, CODE_PERCENT_SIGN},
    {UTF_AMPERSAND, CODE_AMPERSAND},
    {UTF_SINGLE_QUOTE, CODE_SINGLE_QUOTE},
    {UTF_LEFT_PARENTHESIS, CODE_LEFT_PARENTHESIS},
    {UTF_RIGHT_PARENTHESIS, CODE_RIGHT_PARENTHESIS},
    {UTF_ASTERISK, CODE_ASTERISK},
    {UTF_PLUS_SIGN, CODE_PLUS_SIGN},
    {UTF_COMMA, CODE_COMMA},
    {UTF_HYPHEN_MINUS, CODE_HYPHEN_MINUS},
    {UTF_DOT, CODE_DOT},
    {UTF_SLASH, CODE_SLASH},
    {UTF_DIGIT_0, CODE_DIGIT_0},
    {UTF_DIGIT_1, CODE_DIGIT_1},
    {UTF_DIGIT_2, CODE_DIGIT_2},
    {UTF_DIGIT_3, CODE_DIGIT_3},
    {UTF_DIGIT_4, CODE_DIGIT_4},
    {UTF_DIGIT_5, CODE_DIGIT_5},
    {UTF_DIGIT_6, CODE_DIGIT_6},
    {UTF_DIGIT_7, CODE_DIGIT_7},
    {UTF_DIGIT_8, CODE_DIGIT_8},
    {UTF_DIGIT_9, CODE_DIGIT_9},
    {UTF_COLON, CODE_COLON},
    {UTF_SEMICOLON, CODE_SEMICOLON},
    {UTF_LESS_THAN_SIGN, CODE_LESS_THAN_SIGN},
    {UTF_EQUAL_SIGN, CODE_EQUAL_SIGN},
    {UTF_GREATER_THAN_SIGN, CODE_GREATER_THAN_SIGN},
    {UTF_QUESTION_MARK, CODE_QUESTION_MARK},
    {UTF_AT_SIGN, CODE_AT_SIGN},
    {UTF_LEFT_SQUARE_BRACKET, CODE_LEFT_SQUARE_BRACKET},
    {UTF_BACKSLASH, CODE_BACKSLASH},
    {UTF_RIGHT_SQUARE_BRACKET, CODE_RIGHT_SQUARE_BRACKET},
    {UTF_CIRCUMFLEX_ACCENT, CODE_CIRCUMFLEX_ACCENT},
    {UTF_UNDERSCORE, CODE_UNDERSCORE},
    {UTF_GRAVE_ACCENT, CODE_GRAVE_ACCENT},
    {UTF_LEFT_CURLY_BRACKET, CODE_LEFT_CURLY_BRACKET},
    {UTF_VERTICAL_BAR, CODE_VERTICAL_BAR},
    {UTF_RIGHT_CURLY_BRACKET, CODE_RIGHT_CURLY_BRACKET},
    {UTF_TILDE, CODE_TILDE},
    {UTF_DELETE, CODE_DELETE},
};

const struct {
    uint8_t right;    // Right character (e.g., CODE_LAM)
    uint8_t left;     // Left character (e.g., CODE_ALEF)
    uint8_t ligature; // Ligature code (e.g., CODE_LAM_ALEF)
    uint8_t halting_next;  // if the next character after the 2 ligature characters is this, then don't make a liature
} ligatures [] = {
    {CODE_LAM, CODE_ALEF, CODE_LAM_ALEF, CODE_TERMINATION},
    {CODE_ALEF, CODE_LAM, CODE_ALEF_LAM, CODE_ALEF},
};


class LiquidCrystalArabic : public LiquidCrystal {
private:
    uint8_t lcd_cols;
    uint8_t lcd_rows;
    uint8_t cursor_position;
    uint8_t *arabic_text;
    uint8_t *arabic_text_form;
    uint8_t arabic_text_size;

    uint8_t checkForLigature(uint8_t right, uint8_t left, uint8_t next) {
        const uint8_t ligaturesCount = sizeof(ligatures) / sizeof(ligatures[0]);

        for (uint8_t i = 0; i < ligaturesCount; i++) {
             if (ligatures[i].right == right && ligatures[i].left == left && 
                 (ligatures[i].halting_next == CODE_TERMINATION || next != ligatures[i].halting_next)) {
                return ligatures[i].ligature; // Return the ligature code
            }
        }
        return CODE_TERMINATION; // Return termination code if no ligature is found
    }

    // Function to convert English string to Arabic letter codes
    void romanizedArabicStrToByteArray(String input, bool useLigatures) {
        // Mapping of English letters to Arabic codes
        const struct {
            char letter;    // Arabizi character
            uint8_t code;   // Corresponding Arabic code
        } charToCode[] = {
            {'a', CODE_ALEF},
            {'b', CODE_BAA},
            {'t', CODE_TAA},
            {'T', CODE_THAA},
            {'j', CODE_JEEM},
            {'H', CODE_7AA},      
            {'K', CODE_KHAA},
            {'d', CODE_DAL}, 
            {'Z', CODE_THAL},
            {'r', CODE_RAA}, 
            {'z', CODE_ZAIN},
            {'s', CODE_SEEN},
            {'V', CODE_SHEEN},
            {'X', CODE_SAAD},
            {'x', CODE_DAAD},
            {'P', CODE_6AA}, 
            {'p', CODE_DAA}, 
            {'A', CODE_AYN}, 
            {'G', CODE_GHAYN},
            {'f', CODE_FAA}, 
            {'q', CODE_QAF}, 
            {'k', CODE_KAF}, 
            {'l', CODE_LAM}, 
            {'m', CODE_MEEM},
            {'n', CODE_NOON},
            {'h', CODE_HAA}, 
            {'w', CODE_WAW}, 
            {'e', CODE_YAA}, 
            {'c', CODE_HAMZA},
            {'W', CODE_ALEF_MAMDODA}, 
            {'u', CODE_HAMZA_ON_ALEF_MAQSORA},
            {'U', CODE_HAMZA_ON_ALEF},
            {'O', CODE_HAMZA_ON_WAW},
            {'Y', CODE_ALEF_MAQSORA},
            {'M', CODE_KASHIDA},
            {'o', CODE_TAA_MARBOTA},
            {'i', CODE_HAMZA_UNDER_ALEF},
        };

        uint8_t outputIndex = 0, ligature;

        // Iterate through each character in the input string
        for (uint8_t i = 0; input[i] != '\0' && outputIndex < this->lcd_cols * this->lcd_rows; ++i) {

            uint8_t result = mapAlreadyDefinedUTFToCode(input[i]);
            if(result != CODE_TERMINATION){
                this->arabic_text[outputIndex++] = result;
                continue;
            }
            
            // Search for the character in the mapping
            for (uint8_t j = 0; j < sizeof(charToCode) / sizeof(charToCode[0]); ++j) {
                if (input[i] == charToCode[j].letter) {
                    if (i >= 1 && useLigatures){
                        ligature = checkForLigature(arabic_text[outputIndex-1], charToCode[j].code, 3);
                        if (ligature != CODE_TERMINATION){
                            arabic_text[outputIndex-1] = ligature;
                            break;
                        }
                    }
                    this->arabic_text[outputIndex++] = charToCode[j].code;
                    break;
                }
            }
        }

        this->arabic_text_size = outputIndex;     
    }

    void arabicStrToByteArray(String str, bool useLigatures) {
        uint8_t arr_len, i, j, current_prefix, current_byte, current_byte_code, current_prefix_code, ligature, next;
        for (arr_len = 0, i = 0, j = 0; i < str.length() && j < this->lcd_cols * this->lcd_rows; i++){   
            current_prefix = (uint8_t) str[i];
            current_byte = (uint8_t) str[i+1];

            if (current_prefix == UTF_ARABIC_PREFIX_1 || current_prefix == UTF_ARABIC_PREFIX_2){
                i++;
                current_byte_code = mapArabicUTFToCode(current_byte);

                if (j >= 1 && useLigatures){
                    next = (i + 2 < str.length()) ? mapArabicUTFToCode(str[i+2]) : CODE_TERMINATION;
                           
                    ligature = checkForLigature(arabic_text[j-1], current_byte_code, next);
                    if (ligature != CODE_TERMINATION){
                        arabic_text[j-1] = ligature;
                        continue;
                    }
                }
                arabic_text[j++] = current_byte_code;
            }
            
            current_prefix_code = mapArabicUTFToCode(current_prefix);
            if(current_prefix_code != CODE_TERMINATION)
                arabic_text[j++] = current_prefix_code;
        }

        this->arabic_text_size = j;      
    }
    
    uint8_t mapAlreadyDefinedUTFToCode(uint8_t utf) {
        const uint8_t length = sizeof(ALREADY_DEFINED_CHARS_MAPPING) / sizeof(ALREADY_DEFINED_CHARS_MAPPING[0]);

        for (uint8_t i = 0; i < length; i++)
            if (ALREADY_DEFINED_CHARS_MAPPING[i].utf == utf)
                return ALREADY_DEFINED_CHARS_MAPPING[i].code;
        return CODE_TERMINATION;
    }

    uint8_t mapAlreadyDefinedCodeToUTF(uint8_t code) {
        const uint8_t length = sizeof(ALREADY_DEFINED_CHARS_MAPPING) / sizeof(ALREADY_DEFINED_CHARS_MAPPING[0]);

        for (uint8_t i = 0; i < length; i++)
            if (ALREADY_DEFINED_CHARS_MAPPING[i].code == code)
                return ALREADY_DEFINED_CHARS_MAPPING[i].utf;
        return CODE_TERMINATION;
    }

    uint8_t mapArabicUTFToCode(uint8_t utf) {
        uint8_t result = mapAlreadyDefinedUTFToCode(utf);
        if(result != CODE_TERMINATION)
            return result;

        const uint8_t numbers[] = {
            UTF_ALEF, UTF_BAA, UTF_TAA, UTF_THAA, UTF_JEEM, UTF_7AA, UTF_KHAA, UTF_DAL, UTF_THAL, UTF_RAA, UTF_ZAIN, UTF_SEEN,
            UTF_SHEEN, UTF_SAAD, UTF_DAAD, UTF_6AA, UTF_DAA, UTF_AYN, UTF_GHAYN, UTF_FAA, UTF_QAF, UTF_KAF, UTF_LAM, UTF_MEEM,
            UTF_NOON, UTF_HAA, UTF_WAW, UTF_YAA, UTF_HAMZA, UTF_ALEF_MAMDODA, UTF_HAMZA_ON_ALEF_MAQSORA, UTF_HAMZA_ON_ALEF,
            UTF_HAMZA_ON_WAW, UTF_ALEF_MAQSORA, UTF_KASHIDA, UTF_TAA_MARBOTA, UTF_HAMZA_UNDER_ALEF};

        const uint8_t size = sizeof(numbers) / sizeof(numbers[0]);
        
        for (uint8_t i = 0; i < size; i++)
            if (numbers[i] == utf)
                return i;

        return CODE_TERMINATION;
    }

    void createAndPrintCustomChars() {
        uint8_t bitmap[8]; 
        uint8_t letterIndexToBitmap[this->lcd_cols * this->lcd_rows];
        bool found_duplicate = false;

        for (uint8_t ptr = 0, num_created_chars = 0; ptr < this->arabic_text_size; ptr++) {

            if (printAlreadyDefined(this->arabic_text[ptr])){
                continue;
            }
            
            found_duplicate = false;
            for (uint8_t j = 0; j < this->arabic_text_size && j < ptr; j++) {
                if (this->arabic_text[ptr] == this->arabic_text[j] && this->arabic_text_form[ptr] == this->arabic_text_form[j]){
                    writeChar(letterIndexToBitmap[j]);
                    found_duplicate = true;
                    break;
                }
            }

            if (found_duplicate)
                continue;
            if(num_created_chars >= 8)
                break;
            
            memcpy_P(bitmap, arabicBitmap[pgm_read_byte(&arabicLetterToIndexMap[this->arabic_text[ptr]]) + this->arabic_text_form[ptr]], 8);
            createChar(num_created_chars, bitmap);  
            writeChar(num_created_chars);
            letterIndexToBitmap[ptr] = num_created_chars++;
        }
    }

    bool printAlreadyDefined(uint8_t character){
        uint8_t result = mapAlreadyDefinedCodeToUTF(character);
        if (result == CODE_TERMINATION) 
            return false;
        
        writeChar(result, true);
        return true;
    }

    void writeChar(uint8_t character, bool alreadyDefinedstringToPrint=false) {
        setCursorArabic(cursor_position % lcd_cols, cursor_position / lcd_cols);
        if (alreadyDefinedstringToPrint)
            print((char)character);
        else
            write(character);
        moveCursorToLeft();
    }

    void getLettersForm() {
        uint8_t next, isConnectedFromBehind, isConnectedFromAhead, previous = CODE_TERMINATION;

        for (uint8_t i = 0; i < this->arabic_text_size; i++) {

            // Calculate the next character or assign termination code
            next = (i + 1 < this->arabic_text_size) ? arabic_text[i + 1] : CODE_TERMINATION;

            // Evaluate connectivity
            isConnectedFromAhead = canConnectToNext(arabic_text[i]) && canConnectToPrevious(next);
            isConnectedFromBehind = canConnectToNext(previous) && canConnectToPrevious(arabic_text[i]);

            // Update the previous character
            previous = arabic_text[i];

            // Kashida is the only character that connects from both sides but has one form
            if (arabic_text[i] == CODE_KASHIDA){
                arabic_text_form[i] = FORM_ISOLATED;
                continue;
            }

            // Assign the correct form based on connectivity
            arabic_text_form[i] = (isConnectedFromBehind && isConnectedFromAhead) ? FORM_MEDIAL : isConnectedFromBehind ? FORM_FINAL : isConnectedFromAhead ? FORM_INITIAL : FORM_ISOLATED;
        }
    }

    bool canConnectToNext(uint8_t c) {
        if (c == CODE_BAA || c == CODE_TAA || c == CODE_THAA || c == CODE_JEEM || c == CODE_7AA || c == CODE_KHAA ||
            c == CODE_SEEN || c == CODE_SHEEN || c == CODE_SAAD || c == CODE_DAAD || c == CODE_6AA || c == CODE_DAA ||
            c == CODE_AYN || c == CODE_GHAYN || c == CODE_FAA || c == CODE_QAF || c == CODE_KAF || c == CODE_LAM ||
            c == CODE_MEEM || c == CODE_NOON || c == CODE_HAA || c == CODE_KASHIDA || c == CODE_YAA ||
            c == CODE_HAMZA_ON_ALEF_MAQSORA || c == CODE_ALEF_MAQSORA || c == CODE_ALEF_LAM)
            return true;
        return false;
    }

    bool canConnectToPrevious(uint8_t c) {
        if (canConnectToNext(c) || c == CODE_ALEF || c == CODE_DAL || c == CODE_THAL || c == CODE_RAA ||
            c == CODE_ZAIN || c == CODE_WAW || c == CODE_ALEF_MAMDODA || c == CODE_HAMZA_ON_ALEF ||
            c == CODE_HAMZA_ON_WAW || c == CODE_TAA_MARBOTA || c == CODE_HAMZA_UNDER_ALEF || c == CODE_LAM_ALEF)
            return true;
        return false;
    }
    
public:
    LiquidCrystalArabic(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3): LiquidCrystal(rs, enable, d0, d1, d2, d3),
    cursor_position(0),
    arabic_text_size(0) {}

    void begin(uint8_t lcd_cols, uint8_t lcd_rows) {
        LiquidCrystal::begin(lcd_cols, lcd_rows);
        this->lcd_cols = lcd_cols;
        this->lcd_rows = lcd_rows;
        this->arabic_text = new uint8_t[lcd_cols * lcd_rows];
        this->arabic_text_form = new uint8_t[lcd_cols * lcd_rows];
    }

    void setCursorArabic(uint8_t x, uint8_t y) {
        LiquidCrystal::setCursor(lcd_cols - 1 - x, y);
        cursor_position = x + y * (lcd_cols);
    }

    void moveCursorToLeft() {
        cursor_position = (cursor_position + 1) % (lcd_cols * lcd_rows);
    }

    void printArabic(String text, bool isRomanized = false, bool useLigatures = true) {
        if (isRomanized)
            romanizedArabicStrToByteArray(text, useLigatures);
        else
            arabicStrToByteArray(text, useLigatures);
        getLettersForm();
        createAndPrintCustomChars();
    }
};
