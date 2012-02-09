//======================================================================
//  QvivColors.h - Parse X11 colors into Qviv colors.
//
//  Dov Grobgeld <dov.grobgeld@gmail.com>
//  Thu Feb  9 22:03:42 2012
//----------------------------------------------------------------------
#include "QvivX11Colors.h"

QvivX11Colors *QvivX11Colors::Instance = NULL;
std::map<std::string,unsigned int> QvivX11Colors::m_NameToColor;

QvivX11Colors::QvivX11Colors(void)
{
  m_NameToColor["AliceBlue"]= 0xf0f8ff;
  m_NameToColor["AntiqueWhite"]= 0xfaebd7;
  m_NameToColor["AntiqueWhite1"]= 0xffefdb;
  m_NameToColor["AntiqueWhite2"]= 0xeedfcc;
  m_NameToColor["AntiqueWhite3"]= 0xcdc0b0;
  m_NameToColor["AntiqueWhite4"]= 0x8b8378;
  m_NameToColor["BlanchedAlmond"]= 0xffebcd;
  m_NameToColor["BlueViolet"]= 0x8a2be2;
  m_NameToColor["CadetBlue"]= 0x5f9ea0;
  m_NameToColor["CadetBlue1"]= 0x98f5ff;
  m_NameToColor["CadetBlue2"]= 0x8ee5ee;
  m_NameToColor["CadetBlue3"]= 0x7ac5cd;
  m_NameToColor["CadetBlue4"]= 0x53868b;
  m_NameToColor["CornflowerBlue"]= 0x6495ed;
  m_NameToColor["DarkBlue"]= 0x00008b;
  m_NameToColor["DarkCyan"]= 0x008b8b;
  m_NameToColor["DarkGoldenrod"]= 0xb8860b;
  m_NameToColor["DarkGoldenrod1"]= 0xffb90f;
  m_NameToColor["DarkGoldenrod2"]= 0xeead0e;
  m_NameToColor["DarkGoldenrod3"]= 0xcd950c;
  m_NameToColor["DarkGoldenrod4"]= 0x8b6508;
  m_NameToColor["DarkGray"]= 0xa9a9a9;
  m_NameToColor["DarkGreen"]= 0x006400;
  m_NameToColor["DarkGrey"]= 0xa9a9a9;
  m_NameToColor["DarkKhaki"]= 0xbdb76b;
  m_NameToColor["DarkMagenta"]= 0x8b008b;
  m_NameToColor["DarkOliveGreen"]= 0x556b2f;
  m_NameToColor["DarkOliveGreen1"]= 0xcaff70;
  m_NameToColor["DarkOliveGreen2"]= 0xbcee68;
  m_NameToColor["DarkOliveGreen3"]= 0xa2cd5a;
  m_NameToColor["DarkOliveGreen4"]= 0x6e8b3d;
  m_NameToColor["DarkOrange"]= 0xff8c00;
  m_NameToColor["DarkOrange1"]= 0xff7f00;
  m_NameToColor["DarkOrange2"]= 0xee7600;
  m_NameToColor["DarkOrange3"]= 0xcd6600;
  m_NameToColor["DarkOrange4"]= 0x8b4500;
  m_NameToColor["DarkOrchid"]= 0x9932cc;
  m_NameToColor["DarkOrchid1"]= 0xbf3eff;
  m_NameToColor["DarkOrchid2"]= 0xb23aee;
  m_NameToColor["DarkOrchid3"]= 0x9a32cd;
  m_NameToColor["DarkOrchid4"]= 0x68228b;
  m_NameToColor["DarkRed"]= 0x8b0000;
  m_NameToColor["DarkSalmon"]= 0xe9967a;
  m_NameToColor["DarkSeaGreen"]= 0x8fbc8f;
  m_NameToColor["DarkSeaGreen1"]= 0xc1ffc1;
  m_NameToColor["DarkSeaGreen2"]= 0xb4eeb4;
  m_NameToColor["DarkSeaGreen3"]= 0x9bcd9b;
  m_NameToColor["DarkSeaGreen4"]= 0x698b69;
  m_NameToColor["DarkSlateBlue"]= 0x483d8b;
  m_NameToColor["DarkSlateGray"]= 0x2f4f4f;
  m_NameToColor["DarkSlateGray1"]= 0x97ffff;
  m_NameToColor["DarkSlateGray2"]= 0x8deeee;
  m_NameToColor["DarkSlateGray3"]= 0x79cdcd;
  m_NameToColor["DarkSlateGray4"]= 0x528b8b;
  m_NameToColor["DarkSlateGrey"]= 0x2f4f4f;
  m_NameToColor["DarkTurquoise"]= 0x00ced1;
  m_NameToColor["DarkViolet"]= 0x9400d3;
  m_NameToColor["DeepPink"]= 0xff1493;
  m_NameToColor["DeepPink1"]= 0xff1493;
  m_NameToColor["DeepPink2"]= 0xee1289;
  m_NameToColor["DeepPink3"]= 0xcd1076;
  m_NameToColor["DeepPink4"]= 0x8b0a50;
  m_NameToColor["DeepSkyBlue"]= 0x00bfff;
  m_NameToColor["DeepSkyBlue1"]= 0x00bfff;
  m_NameToColor["DeepSkyBlue2"]= 0x00b2ee;
  m_NameToColor["DeepSkyBlue3"]= 0x009acd;
  m_NameToColor["DeepSkyBlue4"]= 0x00688b;
  m_NameToColor["DimGray"]= 0x696969;
  m_NameToColor["DimGrey"]= 0x696969;
  m_NameToColor["DodgerBlue"]= 0x1e90ff;
  m_NameToColor["DodgerBlue1"]= 0x1e90ff;
  m_NameToColor["DodgerBlue2"]= 0x1c86ee;
  m_NameToColor["DodgerBlue3"]= 0x1874cd;
  m_NameToColor["DodgerBlue4"]= 0x104e8b;
  m_NameToColor["FloralWhite"]= 0xfffaf0;
  m_NameToColor["ForestGreen"]= 0x228b22;
  m_NameToColor["GhostWhite"]= 0xf8f8ff;
  m_NameToColor["GreenYellow"]= 0xadff2f;
  m_NameToColor["HotPink"]= 0xff69b4;
  m_NameToColor["HotPink1"]= 0xff6eb4;
  m_NameToColor["HotPink2"]= 0xee6aa7;
  m_NameToColor["HotPink3"]= 0xcd6090;
  m_NameToColor["HotPink4"]= 0x8b3a62;
  m_NameToColor["IndianRed"]= 0xcd5c5c;
  m_NameToColor["IndianRed1"]= 0xff6a6a;
  m_NameToColor["IndianRed2"]= 0xee6363;
  m_NameToColor["IndianRed3"]= 0xcd5555;
  m_NameToColor["IndianRed4"]= 0x8b3a3a;
  m_NameToColor["LavenderBlush"]= 0xfff0f5;
  m_NameToColor["LavenderBlush1"]= 0xfff0f5;
  m_NameToColor["LavenderBlush2"]= 0xeee0e5;
  m_NameToColor["LavenderBlush3"]= 0xcdc1c5;
  m_NameToColor["LavenderBlush4"]= 0x8b8386;
  m_NameToColor["LawnGreen"]= 0x7cfc00;
  m_NameToColor["LemonChiffon"]= 0xfffacd;
  m_NameToColor["LemonChiffon1"]= 0xfffacd;
  m_NameToColor["LemonChiffon2"]= 0xeee9bf;
  m_NameToColor["LemonChiffon3"]= 0xcdc9a5;
  m_NameToColor["LemonChiffon4"]= 0x8b8970;
  m_NameToColor["LightBlue"]= 0xadd8e6;
  m_NameToColor["LightBlue1"]= 0xbfefff;
  m_NameToColor["LightBlue2"]= 0xb2dfee;
  m_NameToColor["LightBlue3"]= 0x9ac0cd;
  m_NameToColor["LightBlue4"]= 0x68838b;
  m_NameToColor["LightCoral"]= 0xf08080;
  m_NameToColor["LightCyan"]= 0xe0ffff;
  m_NameToColor["LightCyan1"]= 0xe0ffff;
  m_NameToColor["LightCyan2"]= 0xd1eeee;
  m_NameToColor["LightCyan3"]= 0xb4cdcd;
  m_NameToColor["LightCyan4"]= 0x7a8b8b;
  m_NameToColor["LightGoldenrod"]= 0xeedd82;
  m_NameToColor["LightGoldenrod1"]= 0xffec8b;
  m_NameToColor["LightGoldenrod2"]= 0xeedc82;
  m_NameToColor["LightGoldenrod3"]= 0xcdbe70;
  m_NameToColor["LightGoldenrod4"]= 0x8b814c;
  m_NameToColor["LightGoldenrodYellow"]= 0xfafad2;
  m_NameToColor["LightGray"]= 0xd3d3d3;
  m_NameToColor["LightGreen"]= 0x90ee90;
  m_NameToColor["LightGrey"]= 0xd3d3d3;
  m_NameToColor["LightPink"]= 0xffb6c1;
  m_NameToColor["LightPink1"]= 0xffaeb9;
  m_NameToColor["LightPink2"]= 0xeea2ad;
  m_NameToColor["LightPink3"]= 0xcd8c95;
  m_NameToColor["LightPink4"]= 0x8b5f65;
  m_NameToColor["LightSalmon"]= 0xffa07a;
  m_NameToColor["LightSalmon1"]= 0xffa07a;
  m_NameToColor["LightSalmon2"]= 0xee9572;
  m_NameToColor["LightSalmon3"]= 0xcd8162;
  m_NameToColor["LightSalmon4"]= 0x8b5742;
  m_NameToColor["LightSeaGreen"]= 0x20b2aa;
  m_NameToColor["LightSkyBlue"]= 0x87cefa;
  m_NameToColor["LightSkyBlue1"]= 0xb0e2ff;
  m_NameToColor["LightSkyBlue2"]= 0xa4d3ee;
  m_NameToColor["LightSkyBlue3"]= 0x8db6cd;
  m_NameToColor["LightSkyBlue4"]= 0x607b8b;
  m_NameToColor["LightSlateBlue"]= 0x8470ff;
  m_NameToColor["LightSlateGray"]= 0x778899;
  m_NameToColor["LightSlateGrey"]= 0x778899;
  m_NameToColor["LightSteelBlue"]= 0xb0c4de;
  m_NameToColor["LightSteelBlue1"]= 0xcae1ff;
  m_NameToColor["LightSteelBlue2"]= 0xbcd2ee;
  m_NameToColor["LightSteelBlue3"]= 0xa2b5cd;
  m_NameToColor["LightSteelBlue4"]= 0x6e7b8b;
  m_NameToColor["LightYellow"]= 0xffffe0;
  m_NameToColor["LightYellow1"]= 0xffffe0;
  m_NameToColor["LightYellow2"]= 0xeeeed1;
  m_NameToColor["LightYellow3"]= 0xcdcdb4;
  m_NameToColor["LightYellow4"]= 0x8b8b7a;
  m_NameToColor["LimeGreen"]= 0x32cd32;
  m_NameToColor["MediumAquamarine"]= 0x66cdaa;
  m_NameToColor["MediumBlue"]= 0x0000cd;
  m_NameToColor["MediumOrchid"]= 0xba55d3;
  m_NameToColor["MediumOrchid1"]= 0xe066ff;
  m_NameToColor["MediumOrchid2"]= 0xd15fee;
  m_NameToColor["MediumOrchid3"]= 0xb452cd;
  m_NameToColor["MediumOrchid4"]= 0x7a378b;
  m_NameToColor["MediumPurple"]= 0x9370db;
  m_NameToColor["MediumPurple1"]= 0xab82ff;
  m_NameToColor["MediumPurple2"]= 0x9f79ee;
  m_NameToColor["MediumPurple3"]= 0x8968cd;
  m_NameToColor["MediumPurple4"]= 0x5d478b;
  m_NameToColor["MediumSeaGreen"]= 0x3cb371;
  m_NameToColor["MediumSlateBlue"]= 0x7b68ee;
  m_NameToColor["MediumSpringGreen"]= 0x00fa9a;
  m_NameToColor["MediumTurquoise"]= 0x48d1cc;
  m_NameToColor["MediumVioletRed"]= 0xc71585;
  m_NameToColor["MidnightBlue"]= 0x191970;
  m_NameToColor["MintCream"]= 0xf5fffa;
  m_NameToColor["MistyRose"]= 0xffe4e1;
  m_NameToColor["MistyRose1"]= 0xffe4e1;
  m_NameToColor["MistyRose2"]= 0xeed5d2;
  m_NameToColor["MistyRose3"]= 0xcdb7b5;
  m_NameToColor["MistyRose4"]= 0x8b7d7b;
  m_NameToColor["NavajoWhite"]= 0xffdead;
  m_NameToColor["NavajoWhite1"]= 0xffdead;
  m_NameToColor["NavajoWhite2"]= 0xeecfa1;
  m_NameToColor["NavajoWhite3"]= 0xcdb38b;
  m_NameToColor["NavajoWhite4"]= 0x8b795e;
  m_NameToColor["NavyBlue"]= 0x000080;
  m_NameToColor["OldLace"]= 0xfdf5e6;
  m_NameToColor["OliveDrab"]= 0x6b8e23;
  m_NameToColor["OliveDrab1"]= 0xc0ff3e;
  m_NameToColor["OliveDrab2"]= 0xb3ee3a;
  m_NameToColor["OliveDrab3"]= 0x9acd32;
  m_NameToColor["OliveDrab4"]= 0x698b22;
  m_NameToColor["OrangeRed"]= 0xff4500;
  m_NameToColor["OrangeRed1"]= 0xff4500;
  m_NameToColor["OrangeRed2"]= 0xee4000;
  m_NameToColor["OrangeRed3"]= 0xcd3700;
  m_NameToColor["OrangeRed4"]= 0x8b2500;
  m_NameToColor["PaleGoldenrod"]= 0xeee8aa;
  m_NameToColor["PaleGreen"]= 0x98fb98;
  m_NameToColor["PaleGreen1"]= 0x9aff9a;
  m_NameToColor["PaleGreen2"]= 0x90ee90;
  m_NameToColor["PaleGreen3"]= 0x7ccd7c;
  m_NameToColor["PaleGreen4"]= 0x548b54;
  m_NameToColor["PaleTurquoise"]= 0xafeeee;
  m_NameToColor["PaleTurquoise1"]= 0xbbffff;
  m_NameToColor["PaleTurquoise2"]= 0xaeeeee;
  m_NameToColor["PaleTurquoise3"]= 0x96cdcd;
  m_NameToColor["PaleTurquoise4"]= 0x668b8b;
  m_NameToColor["PaleVioletRed"]= 0xdb7093;
  m_NameToColor["PaleVioletRed1"]= 0xff82ab;
  m_NameToColor["PaleVioletRed2"]= 0xee799f;
  m_NameToColor["PaleVioletRed3"]= 0xcd6889;
  m_NameToColor["PaleVioletRed4"]= 0x8b475d;
  m_NameToColor["PapayaWhip"]= 0xffefd5;
  m_NameToColor["PeachPuff"]= 0xffdab9;
  m_NameToColor["PeachPuff1"]= 0xffdab9;
  m_NameToColor["PeachPuff2"]= 0xeecbad;
  m_NameToColor["PeachPuff3"]= 0xcdaf95;
  m_NameToColor["PeachPuff4"]= 0x8b7765;
  m_NameToColor["PowderBlue"]= 0xb0e0e6;
  m_NameToColor["RosyBrown"]= 0xbc8f8f;
  m_NameToColor["RosyBrown1"]= 0xffc1c1;
  m_NameToColor["RosyBrown2"]= 0xeeb4b4;
  m_NameToColor["RosyBrown3"]= 0xcd9b9b;
  m_NameToColor["RosyBrown4"]= 0x8b6969;
  m_NameToColor["RoyalBlue"]= 0x4169e1;
  m_NameToColor["RoyalBlue1"]= 0x4876ff;
  m_NameToColor["RoyalBlue2"]= 0x436eee;
  m_NameToColor["RoyalBlue3"]= 0x3a5fcd;
  m_NameToColor["RoyalBlue4"]= 0x27408b;
  m_NameToColor["SaddleBrown"]= 0x8b4513;
  m_NameToColor["SandyBrown"]= 0xf4a460;
  m_NameToColor["SeaGreen"]= 0x2e8b57;
  m_NameToColor["SeaGreen1"]= 0x54ff9f;
  m_NameToColor["SeaGreen2"]= 0x4eee94;
  m_NameToColor["SeaGreen3"]= 0x43cd80;
  m_NameToColor["SeaGreen4"]= 0x2e8b57;
  m_NameToColor["SkyBlue"]= 0x87ceeb;
  m_NameToColor["SkyBlue1"]= 0x87ceff;
  m_NameToColor["SkyBlue2"]= 0x7ec0ee;
  m_NameToColor["SkyBlue3"]= 0x6ca6cd;
  m_NameToColor["SkyBlue4"]= 0x4a708b;
  m_NameToColor["SlateBlue"]= 0x6a5acd;
  m_NameToColor["SlateBlue1"]= 0x836fff;
  m_NameToColor["SlateBlue2"]= 0x7a67ee;
  m_NameToColor["SlateBlue3"]= 0x6959cd;
  m_NameToColor["SlateBlue4"]= 0x473c8b;
  m_NameToColor["SlateGray"]= 0x708090;
  m_NameToColor["SlateGray1"]= 0xc6e2ff;
  m_NameToColor["SlateGray2"]= 0xb9d3ee;
  m_NameToColor["SlateGray3"]= 0x9fb6cd;
  m_NameToColor["SlateGray4"]= 0x6c7b8b;
  m_NameToColor["SlateGrey"]= 0x708090;
  m_NameToColor["SpringGreen"]= 0x00ff7f;
  m_NameToColor["SpringGreen1"]= 0x00ff7f;
  m_NameToColor["SpringGreen2"]= 0x00ee76;
  m_NameToColor["SpringGreen3"]= 0x00cd66;
  m_NameToColor["SpringGreen4"]= 0x008b45;
  m_NameToColor["SteelBlue"]= 0x4682b4;
  m_NameToColor["SteelBlue1"]= 0x63b8ff;
  m_NameToColor["SteelBlue2"]= 0x5cacee;
  m_NameToColor["SteelBlue3"]= 0x4f94cd;
  m_NameToColor["SteelBlue4"]= 0x36648b;
  m_NameToColor["VioletRed"]= 0xd02090;
  m_NameToColor["VioletRed1"]= 0xff3e96;
  m_NameToColor["VioletRed2"]= 0xee3a8c;
  m_NameToColor["VioletRed3"]= 0xcd3278;
  m_NameToColor["VioletRed4"]= 0x8b2252;
  m_NameToColor["WhiteSmoke"]= 0xf5f5f5;
  m_NameToColor["YellowGreen"]= 0x9acd32;
  m_NameToColor["alice blue"]= 0xf0f8ff;
  m_NameToColor["antique white"]= 0xfaebd7;
  m_NameToColor["aquamarine"]= 0x7fffd4;
  m_NameToColor["aquamarine1"]= 0x7fffd4;
  m_NameToColor["aquamarine2"]= 0x76eec6;
  m_NameToColor["aquamarine3"]= 0x66cdaa;
  m_NameToColor["aquamarine4"]= 0x458b74;
  m_NameToColor["azure"]= 0xf0ffff;
  m_NameToColor["azure1"]= 0xf0ffff;
  m_NameToColor["azure2"]= 0xe0eeee;
  m_NameToColor["azure3"]= 0xc1cdcd;
  m_NameToColor["azure4"]= 0x838b8b;
  m_NameToColor["beige"]= 0xf5f5dc;
  m_NameToColor["bisque"]= 0xffe4c4;
  m_NameToColor["bisque1"]= 0xffe4c4;
  m_NameToColor["bisque2"]= 0xeed5b7;
  m_NameToColor["bisque3"]= 0xcdb79e;
  m_NameToColor["bisque4"]= 0x8b7d6b;
  m_NameToColor["black"]= 0x000000;
  m_NameToColor["blanched almond"]= 0xffebcd;
  m_NameToColor["blue"]= 0x0000ff;
  m_NameToColor["blue violet"]= 0x8a2be2;
  m_NameToColor["blue1"]= 0x0000ff;
  m_NameToColor["blue2"]= 0x0000ee;
  m_NameToColor["blue3"]= 0x0000cd;
  m_NameToColor["blue4"]= 0x00008b;
  m_NameToColor["brown"]= 0xa52a2a;
  m_NameToColor["brown1"]= 0xff4040;
  m_NameToColor["brown2"]= 0xee3b3b;
  m_NameToColor["brown3"]= 0xcd3333;
  m_NameToColor["brown4"]= 0x8b2323;
  m_NameToColor["burlywood"]= 0xdeb887;
  m_NameToColor["burlywood1"]= 0xffd39b;
  m_NameToColor["burlywood2"]= 0xeec591;
  m_NameToColor["burlywood3"]= 0xcdaa7d;
  m_NameToColor["burlywood4"]= 0x8b7355;
  m_NameToColor["cadet blue"]= 0x5f9ea0;
  m_NameToColor["chartreuse"]= 0x7fff00;
  m_NameToColor["chartreuse1"]= 0x7fff00;
  m_NameToColor["chartreuse2"]= 0x76ee00;
  m_NameToColor["chartreuse3"]= 0x66cd00;
  m_NameToColor["chartreuse4"]= 0x458b00;
  m_NameToColor["chocolate"]= 0xd2691e;
  m_NameToColor["chocolate1"]= 0xff7f24;
  m_NameToColor["chocolate2"]= 0xee7621;
  m_NameToColor["chocolate3"]= 0xcd661d;
  m_NameToColor["chocolate4"]= 0x8b4513;
  m_NameToColor["coral"]= 0xff7f50;
  m_NameToColor["coral1"]= 0xff7256;
  m_NameToColor["coral2"]= 0xee6a50;
  m_NameToColor["coral3"]= 0xcd5b45;
  m_NameToColor["coral4"]= 0x8b3e2f;
  m_NameToColor["cornflower blue"]= 0x6495ed;
  m_NameToColor["cornsilk"]= 0xfff8dc;
  m_NameToColor["cornsilk1"]= 0xfff8dc;
  m_NameToColor["cornsilk2"]= 0xeee8cd;
  m_NameToColor["cornsilk3"]= 0xcdc8b1;
  m_NameToColor["cornsilk4"]= 0x8b8878;
  m_NameToColor["cyan"]= 0x00ffff;
  m_NameToColor["cyan1"]= 0x00ffff;
  m_NameToColor["cyan2"]= 0x00eeee;
  m_NameToColor["cyan3"]= 0x00cdcd;
  m_NameToColor["cyan4"]= 0x008b8b;
  m_NameToColor["dark blue"]= 0x00008b;
  m_NameToColor["dark cyan"]= 0x008b8b;
  m_NameToColor["dark goldenrod"]= 0xb8860b;
  m_NameToColor["dark gray"]= 0xa9a9a9;
  m_NameToColor["dark green"]= 0x006400;
  m_NameToColor["dark grey"]= 0xa9a9a9;
  m_NameToColor["dark khaki"]= 0xbdb76b;
  m_NameToColor["dark magenta"]= 0x8b008b;
  m_NameToColor["dark olive green"]= 0x556b2f;
  m_NameToColor["dark orange"]= 0xff8c00;
  m_NameToColor["dark orchid"]= 0x9932cc;
  m_NameToColor["dark red"]= 0x8b0000;
  m_NameToColor["dark salmon"]= 0xe9967a;
  m_NameToColor["dark sea green"]= 0x8fbc8f;
  m_NameToColor["dark slate blue"]= 0x483d8b;
  m_NameToColor["dark slate gray"]= 0x2f4f4f;
  m_NameToColor["dark slate grey"]= 0x2f4f4f;
  m_NameToColor["dark turquoise"]= 0x00ced1;
  m_NameToColor["dark violet"]= 0x9400d3;
  m_NameToColor["deep pink"]= 0xff1493;
  m_NameToColor["deep sky blue"]= 0x00bfff;
  m_NameToColor["dim gray"]= 0x696969;
  m_NameToColor["dim grey"]= 0x696969;
  m_NameToColor["dodger blue"]= 0x1e90ff;
  m_NameToColor["firebrick"]= 0xb22222;
  m_NameToColor["firebrick1"]= 0xff3030;
  m_NameToColor["firebrick2"]= 0xee2c2c;
  m_NameToColor["firebrick3"]= 0xcd2626;
  m_NameToColor["firebrick4"]= 0x8b1a1a;
  m_NameToColor["floral white"]= 0xfffaf0;
  m_NameToColor["forest green"]= 0x228b22;
  m_NameToColor["gainsboro"]= 0xdcdcdc;
  m_NameToColor["ghost white"]= 0xf8f8ff;
  m_NameToColor["gold"]= 0xffd700;
  m_NameToColor["gold1"]= 0xffd700;
  m_NameToColor["gold2"]= 0xeec900;
  m_NameToColor["gold3"]= 0xcdad00;
  m_NameToColor["gold4"]= 0x8b7500;
  m_NameToColor["goldenrod"]= 0xdaa520;
  m_NameToColor["goldenrod1"]= 0xffc125;
  m_NameToColor["goldenrod2"]= 0xeeb422;
  m_NameToColor["goldenrod3"]= 0xcd9b1d;
  m_NameToColor["goldenrod4"]= 0x8b6914;
  m_NameToColor["gray"]= 0xbebebe;
  m_NameToColor["gray0"]= 0x000000;
  m_NameToColor["gray1"]= 0x030303;
  m_NameToColor["gray10"]= 0x1a1a1a;
  m_NameToColor["gray100"]= 0xffffff;
  m_NameToColor["gray11"]= 0x1c1c1c;
  m_NameToColor["gray12"]= 0x1f1f1f;
  m_NameToColor["gray13"]= 0x212121;
  m_NameToColor["gray14"]= 0x242424;
  m_NameToColor["gray15"]= 0x262626;
  m_NameToColor["gray16"]= 0x292929;
  m_NameToColor["gray17"]= 0x2b2b2b;
  m_NameToColor["gray18"]= 0x2e2e2e;
  m_NameToColor["gray19"]= 0x303030;
  m_NameToColor["gray2"]= 0x050505;
  m_NameToColor["gray20"]= 0x333333;
  m_NameToColor["gray21"]= 0x363636;
  m_NameToColor["gray22"]= 0x383838;
  m_NameToColor["gray23"]= 0x3b3b3b;
  m_NameToColor["gray24"]= 0x3d3d3d;
  m_NameToColor["gray25"]= 0x404040;
  m_NameToColor["gray26"]= 0x424242;
  m_NameToColor["gray27"]= 0x454545;
  m_NameToColor["gray28"]= 0x474747;
  m_NameToColor["gray29"]= 0x4a4a4a;
  m_NameToColor["gray3"]= 0x080808;
  m_NameToColor["gray30"]= 0x4d4d4d;
  m_NameToColor["gray31"]= 0x4f4f4f;
  m_NameToColor["gray32"]= 0x525252;
  m_NameToColor["gray33"]= 0x545454;
  m_NameToColor["gray34"]= 0x575757;
  m_NameToColor["gray35"]= 0x595959;
  m_NameToColor["gray36"]= 0x5c5c5c;
  m_NameToColor["gray37"]= 0x5e5e5e;
  m_NameToColor["gray38"]= 0x616161;
  m_NameToColor["gray39"]= 0x636363;
  m_NameToColor["gray4"]= 0x0a0a0a;
  m_NameToColor["gray40"]= 0x666666;
  m_NameToColor["gray41"]= 0x696969;
  m_NameToColor["gray42"]= 0x6b6b6b;
  m_NameToColor["gray43"]= 0x6e6e6e;
  m_NameToColor["gray44"]= 0x707070;
  m_NameToColor["gray45"]= 0x737373;
  m_NameToColor["gray46"]= 0x757575;
  m_NameToColor["gray47"]= 0x787878;
  m_NameToColor["gray48"]= 0x7a7a7a;
  m_NameToColor["gray49"]= 0x7d7d7d;
  m_NameToColor["gray5"]= 0x0d0d0d;
  m_NameToColor["gray50"]= 0x7f7f7f;
  m_NameToColor["gray51"]= 0x828282;
  m_NameToColor["gray52"]= 0x858585;
  m_NameToColor["gray53"]= 0x878787;
  m_NameToColor["gray54"]= 0x8a8a8a;
  m_NameToColor["gray55"]= 0x8c8c8c;
  m_NameToColor["gray56"]= 0x8f8f8f;
  m_NameToColor["gray57"]= 0x919191;
  m_NameToColor["gray58"]= 0x949494;
  m_NameToColor["gray59"]= 0x969696;
  m_NameToColor["gray6"]= 0x0f0f0f;
  m_NameToColor["gray60"]= 0x999999;
  m_NameToColor["gray61"]= 0x9c9c9c;
  m_NameToColor["gray62"]= 0x9e9e9e;
  m_NameToColor["gray63"]= 0xa1a1a1;
  m_NameToColor["gray64"]= 0xa3a3a3;
  m_NameToColor["gray65"]= 0xa6a6a6;
  m_NameToColor["gray66"]= 0xa8a8a8;
  m_NameToColor["gray67"]= 0xababab;
  m_NameToColor["gray68"]= 0xadadad;
  m_NameToColor["gray69"]= 0xb0b0b0;
  m_NameToColor["gray7"]= 0x121212;
  m_NameToColor["gray70"]= 0xb3b3b3;
  m_NameToColor["gray71"]= 0xb5b5b5;
  m_NameToColor["gray72"]= 0xb8b8b8;
  m_NameToColor["gray73"]= 0xbababa;
  m_NameToColor["gray74"]= 0xbdbdbd;
  m_NameToColor["gray75"]= 0xbfbfbf;
  m_NameToColor["gray76"]= 0xc2c2c2;
  m_NameToColor["gray77"]= 0xc4c4c4;
  m_NameToColor["gray78"]= 0xc7c7c7;
  m_NameToColor["gray79"]= 0xc9c9c9;
  m_NameToColor["gray8"]= 0x141414;
  m_NameToColor["gray80"]= 0xcccccc;
  m_NameToColor["gray81"]= 0xcfcfcf;
  m_NameToColor["gray82"]= 0xd1d1d1;
  m_NameToColor["gray83"]= 0xd4d4d4;
  m_NameToColor["gray84"]= 0xd6d6d6;
  m_NameToColor["gray85"]= 0xd9d9d9;
  m_NameToColor["gray86"]= 0xdbdbdb;
  m_NameToColor["gray87"]= 0xdedede;
  m_NameToColor["gray88"]= 0xe0e0e0;
  m_NameToColor["gray89"]= 0xe3e3e3;
  m_NameToColor["gray9"]= 0x171717;
  m_NameToColor["gray90"]= 0xe5e5e5;
  m_NameToColor["gray91"]= 0xe8e8e8;
  m_NameToColor["gray92"]= 0xebebeb;
  m_NameToColor["gray93"]= 0xededed;
  m_NameToColor["gray94"]= 0xf0f0f0;
  m_NameToColor["gray95"]= 0xf2f2f2;
  m_NameToColor["gray96"]= 0xf5f5f5;
  m_NameToColor["gray97"]= 0xf7f7f7;
  m_NameToColor["gray98"]= 0xfafafa;
  m_NameToColor["gray99"]= 0xfcfcfc;
  m_NameToColor["green"]= 0x00ff00;
  m_NameToColor["green yellow"]= 0xadff2f;
  m_NameToColor["green1"]= 0x00ff00;
  m_NameToColor["green2"]= 0x00ee00;
  m_NameToColor["green3"]= 0x00cd00;
  m_NameToColor["green4"]= 0x008b00;
  m_NameToColor["grey"]= 0xbebebe;
  m_NameToColor["grey0"]= 0x000000;
  m_NameToColor["grey1"]= 0x030303;
  m_NameToColor["grey10"]= 0x1a1a1a;
  m_NameToColor["grey100"]= 0xffffff;
  m_NameToColor["grey11"]= 0x1c1c1c;
  m_NameToColor["grey12"]= 0x1f1f1f;
  m_NameToColor["grey13"]= 0x212121;
  m_NameToColor["grey14"]= 0x242424;
  m_NameToColor["grey15"]= 0x262626;
  m_NameToColor["grey16"]= 0x292929;
  m_NameToColor["grey17"]= 0x2b2b2b;
  m_NameToColor["grey18"]= 0x2e2e2e;
  m_NameToColor["grey19"]= 0x303030;
  m_NameToColor["grey2"]= 0x050505;
  m_NameToColor["grey20"]= 0x333333;
  m_NameToColor["grey21"]= 0x363636;
  m_NameToColor["grey22"]= 0x383838;
  m_NameToColor["grey23"]= 0x3b3b3b;
  m_NameToColor["grey24"]= 0x3d3d3d;
  m_NameToColor["grey25"]= 0x404040;
  m_NameToColor["grey26"]= 0x424242;
  m_NameToColor["grey27"]= 0x454545;
  m_NameToColor["grey28"]= 0x474747;
  m_NameToColor["grey29"]= 0x4a4a4a;
  m_NameToColor["grey3"]= 0x080808;
  m_NameToColor["grey30"]= 0x4d4d4d;
  m_NameToColor["grey31"]= 0x4f4f4f;
  m_NameToColor["grey32"]= 0x525252;
  m_NameToColor["grey33"]= 0x545454;
  m_NameToColor["grey34"]= 0x575757;
  m_NameToColor["grey35"]= 0x595959;
  m_NameToColor["grey36"]= 0x5c5c5c;
  m_NameToColor["grey37"]= 0x5e5e5e;
  m_NameToColor["grey38"]= 0x616161;
  m_NameToColor["grey39"]= 0x636363;
  m_NameToColor["grey4"]= 0x0a0a0a;
  m_NameToColor["grey40"]= 0x666666;
  m_NameToColor["grey41"]= 0x696969;
  m_NameToColor["grey42"]= 0x6b6b6b;
  m_NameToColor["grey43"]= 0x6e6e6e;
  m_NameToColor["grey44"]= 0x707070;
  m_NameToColor["grey45"]= 0x737373;
  m_NameToColor["grey46"]= 0x757575;
  m_NameToColor["grey47"]= 0x787878;
  m_NameToColor["grey48"]= 0x7a7a7a;
  m_NameToColor["grey49"]= 0x7d7d7d;
  m_NameToColor["grey5"]= 0x0d0d0d;
  m_NameToColor["grey50"]= 0x7f7f7f;
  m_NameToColor["grey51"]= 0x828282;
  m_NameToColor["grey52"]= 0x858585;
  m_NameToColor["grey53"]= 0x878787;
  m_NameToColor["grey54"]= 0x8a8a8a;
  m_NameToColor["grey55"]= 0x8c8c8c;
  m_NameToColor["grey56"]= 0x8f8f8f;
  m_NameToColor["grey57"]= 0x919191;
  m_NameToColor["grey58"]= 0x949494;
  m_NameToColor["grey59"]= 0x969696;
  m_NameToColor["grey6"]= 0x0f0f0f;
  m_NameToColor["grey60"]= 0x999999;
  m_NameToColor["grey61"]= 0x9c9c9c;
  m_NameToColor["grey62"]= 0x9e9e9e;
  m_NameToColor["grey63"]= 0xa1a1a1;
  m_NameToColor["grey64"]= 0xa3a3a3;
  m_NameToColor["grey65"]= 0xa6a6a6;
  m_NameToColor["grey66"]= 0xa8a8a8;
  m_NameToColor["grey67"]= 0xababab;
  m_NameToColor["grey68"]= 0xadadad;
  m_NameToColor["grey69"]= 0xb0b0b0;
  m_NameToColor["grey7"]= 0x121212;
  m_NameToColor["grey70"]= 0xb3b3b3;
  m_NameToColor["grey71"]= 0xb5b5b5;
  m_NameToColor["grey72"]= 0xb8b8b8;
  m_NameToColor["grey73"]= 0xbababa;
  m_NameToColor["grey74"]= 0xbdbdbd;
  m_NameToColor["grey75"]= 0xbfbfbf;
  m_NameToColor["grey76"]= 0xc2c2c2;
  m_NameToColor["grey77"]= 0xc4c4c4;
  m_NameToColor["grey78"]= 0xc7c7c7;
  m_NameToColor["grey79"]= 0xc9c9c9;
  m_NameToColor["grey8"]= 0x141414;
  m_NameToColor["grey80"]= 0xcccccc;
  m_NameToColor["grey81"]= 0xcfcfcf;
  m_NameToColor["grey82"]= 0xd1d1d1;
  m_NameToColor["grey83"]= 0xd4d4d4;
  m_NameToColor["grey84"]= 0xd6d6d6;
  m_NameToColor["grey85"]= 0xd9d9d9;
  m_NameToColor["grey86"]= 0xdbdbdb;
  m_NameToColor["grey87"]= 0xdedede;
  m_NameToColor["grey88"]= 0xe0e0e0;
  m_NameToColor["grey89"]= 0xe3e3e3;
  m_NameToColor["grey9"]= 0x171717;
  m_NameToColor["grey90"]= 0xe5e5e5;
  m_NameToColor["grey91"]= 0xe8e8e8;
  m_NameToColor["grey92"]= 0xebebeb;
  m_NameToColor["grey93"]= 0xededed;
  m_NameToColor["grey94"]= 0xf0f0f0;
  m_NameToColor["grey95"]= 0xf2f2f2;
  m_NameToColor["grey96"]= 0xf5f5f5;
  m_NameToColor["grey97"]= 0xf7f7f7;
  m_NameToColor["grey98"]= 0xfafafa;
  m_NameToColor["grey99"]= 0xfcfcfc;
  m_NameToColor["honeydew"]= 0xf0fff0;
  m_NameToColor["honeydew1"]= 0xf0fff0;
  m_NameToColor["honeydew2"]= 0xe0eee0;
  m_NameToColor["honeydew3"]= 0xc1cdc1;
  m_NameToColor["honeydew4"]= 0x838b83;
  m_NameToColor["hot pink"]= 0xff69b4;
  m_NameToColor["indian red"]= 0xcd5c5c;
  m_NameToColor["ivory"]= 0xfffff0;
  m_NameToColor["ivory1"]= 0xfffff0;
  m_NameToColor["ivory2"]= 0xeeeee0;
  m_NameToColor["ivory3"]= 0xcdcdc1;
  m_NameToColor["ivory4"]= 0x8b8b83;
  m_NameToColor["khaki"]= 0xf0e68c;
  m_NameToColor["khaki1"]= 0xfff68f;
  m_NameToColor["khaki2"]= 0xeee685;
  m_NameToColor["khaki3"]= 0xcdc673;
  m_NameToColor["khaki4"]= 0x8b864e;
  m_NameToColor["lavender"]= 0xe6e6fa;
  m_NameToColor["lavender blush"]= 0xfff0f5;
  m_NameToColor["lawn green"]= 0x7cfc00;
  m_NameToColor["lemon chiffon"]= 0xfffacd;
  m_NameToColor["light blue"]= 0xadd8e6;
  m_NameToColor["light coral"]= 0xf08080;
  m_NameToColor["light cyan"]= 0xe0ffff;
  m_NameToColor["light goldenrod"]= 0xeedd82;
  m_NameToColor["light goldenrod yellow"]= 0xfafad2;
  m_NameToColor["light gray"]= 0xd3d3d3;
  m_NameToColor["light green"]= 0x90ee90;
  m_NameToColor["light grey"]= 0xd3d3d3;
  m_NameToColor["light pink"]= 0xffb6c1;
  m_NameToColor["light salmon"]= 0xffa07a;
  m_NameToColor["light sea green"]= 0x20b2aa;
  m_NameToColor["light sky blue"]= 0x87cefa;
  m_NameToColor["light slate blue"]= 0x8470ff;
  m_NameToColor["light slate gray"]= 0x778899;
  m_NameToColor["light slate grey"]= 0x778899;
  m_NameToColor["light steel blue"]= 0xb0c4de;
  m_NameToColor["light yellow"]= 0xffffe0;
  m_NameToColor["lime green"]= 0x32cd32;
  m_NameToColor["linen"]= 0xfaf0e6;
  m_NameToColor["magenta"]= 0xff00ff;
  m_NameToColor["magenta1"]= 0xff00ff;
  m_NameToColor["magenta2"]= 0xee00ee;
  m_NameToColor["magenta3"]= 0xcd00cd;
  m_NameToColor["magenta4"]= 0x8b008b;
  m_NameToColor["maroon"]= 0xb03060;
  m_NameToColor["maroon1"]= 0xff34b3;
  m_NameToColor["maroon2"]= 0xee30a7;
  m_NameToColor["maroon3"]= 0xcd2990;
  m_NameToColor["maroon4"]= 0x8b1c62;
  m_NameToColor["medium aquamarine"]= 0x66cdaa;
  m_NameToColor["medium blue"]= 0x0000cd;
  m_NameToColor["medium orchid"]= 0xba55d3;
  m_NameToColor["medium purple"]= 0x9370db;
  m_NameToColor["medium sea green"]= 0x3cb371;
  m_NameToColor["medium slate blue"]= 0x7b68ee;
  m_NameToColor["medium spring green"]= 0x00fa9a;
  m_NameToColor["medium turquoise"]= 0x48d1cc;
  m_NameToColor["medium violet red"]= 0xc71585;
  m_NameToColor["midnight blue"]= 0x191970;
  m_NameToColor["mint cream"]= 0xf5fffa;
  m_NameToColor["misty rose"]= 0xffe4e1;
  m_NameToColor["moccasin"]= 0xffe4b5;
  m_NameToColor["navajo white"]= 0xffdead;
  m_NameToColor["navy"]= 0x000080;
  m_NameToColor["navy blue"]= 0x000080;
  m_NameToColor["old lace"]= 0xfdf5e6;
  m_NameToColor["olive drab"]= 0x6b8e23;
  m_NameToColor["orange"]= 0xffa500;
  m_NameToColor["orange red"]= 0xff4500;
  m_NameToColor["orange1"]= 0xffa500;
  m_NameToColor["orange2"]= 0xee9a00;
  m_NameToColor["orange3"]= 0xcd8500;
  m_NameToColor["orange4"]= 0x8b5a00;
  m_NameToColor["orchid"]= 0xda70d6;
  m_NameToColor["orchid1"]= 0xff83fa;
  m_NameToColor["orchid2"]= 0xee7ae9;
  m_NameToColor["orchid3"]= 0xcd69c9;
  m_NameToColor["orchid4"]= 0x8b4789;
  m_NameToColor["pale goldenrod"]= 0xeee8aa;
  m_NameToColor["pale green"]= 0x98fb98;
  m_NameToColor["pale turquoise"]= 0xafeeee;
  m_NameToColor["pale violet red"]= 0xdb7093;
  m_NameToColor["papaya whip"]= 0xffefd5;
  m_NameToColor["peach puff"]= 0xffdab9;
  m_NameToColor["peru"]= 0xcd853f;
  m_NameToColor["pink"]= 0xffc0cb;
  m_NameToColor["pink1"]= 0xffb5c5;
  m_NameToColor["pink2"]= 0xeea9b8;
  m_NameToColor["pink3"]= 0xcd919e;
  m_NameToColor["pink4"]= 0x8b636c;
  m_NameToColor["plum"]= 0xdda0dd;
  m_NameToColor["plum1"]= 0xffbbff;
  m_NameToColor["plum2"]= 0xeeaeee;
  m_NameToColor["plum3"]= 0xcd96cd;
  m_NameToColor["plum4"]= 0x8b668b;
  m_NameToColor["powder blue"]= 0xb0e0e6;
  m_NameToColor["purple"]= 0xa020f0;
  m_NameToColor["purple1"]= 0x9b30ff;
  m_NameToColor["purple2"]= 0x912cee;
  m_NameToColor["purple3"]= 0x7d26cd;
  m_NameToColor["purple4"]= 0x551a8b;
  m_NameToColor["red"]= 0xff0000;
  m_NameToColor["red1"]= 0xff0000;
  m_NameToColor["red2"]= 0xee0000;
  m_NameToColor["red3"]= 0xcd0000;
  m_NameToColor["red4"]= 0x8b0000;
  m_NameToColor["rosy brown"]= 0xbc8f8f;
  m_NameToColor["royal blue"]= 0x4169e1;
  m_NameToColor["saddle brown"]= 0x8b4513;
  m_NameToColor["salmon"]= 0xfa8072;
  m_NameToColor["salmon1"]= 0xff8c69;
  m_NameToColor["salmon2"]= 0xee8262;
  m_NameToColor["salmon3"]= 0xcd7054;
  m_NameToColor["salmon4"]= 0x8b4c39;
  m_NameToColor["sandy brown"]= 0xf4a460;
  m_NameToColor["sea green"]= 0x2e8b57;
  m_NameToColor["seashell"]= 0xfff5ee;
  m_NameToColor["seashell1"]= 0xfff5ee;
  m_NameToColor["seashell2"]= 0xeee5de;
  m_NameToColor["seashell3"]= 0xcdc5bf;
  m_NameToColor["seashell4"]= 0x8b8682;
  m_NameToColor["sienna"]= 0xa0522d;
  m_NameToColor["sienna1"]= 0xff8247;
  m_NameToColor["sienna2"]= 0xee7942;
  m_NameToColor["sienna3"]= 0xcd6839;
  m_NameToColor["sienna4"]= 0x8b4726;
  m_NameToColor["sky blue"]= 0x87ceeb;
  m_NameToColor["slate blue"]= 0x6a5acd;
  m_NameToColor["slate gray"]= 0x708090;
  m_NameToColor["slate grey"]= 0x708090;
  m_NameToColor["snow"]= 0xfffafa;
  m_NameToColor["snow1"]= 0xfffafa;
  m_NameToColor["snow2"]= 0xeee9e9;
  m_NameToColor["snow3"]= 0xcdc9c9;
  m_NameToColor["snow4"]= 0x8b8989;
  m_NameToColor["spring green"]= 0x00ff7f;
  m_NameToColor["steel blue"]= 0x4682b4;
  m_NameToColor["tan"]= 0xd2b48c;
  m_NameToColor["tan1"]= 0xffa54f;
  m_NameToColor["tan2"]= 0xee9a49;
  m_NameToColor["tan3"]= 0xcd853f;
  m_NameToColor["tan4"]= 0x8b5a2b;
  m_NameToColor["thistle"]= 0xd8bfd8;
  m_NameToColor["thistle1"]= 0xffe1ff;
  m_NameToColor["thistle2"]= 0xeed2ee;
  m_NameToColor["thistle3"]= 0xcdb5cd;
  m_NameToColor["thistle4"]= 0x8b7b8b;
  m_NameToColor["tomato"]= 0xff6347;
  m_NameToColor["tomato1"]= 0xff6347;
  m_NameToColor["tomato2"]= 0xee5c42;
  m_NameToColor["tomato3"]= 0xcd4f39;
  m_NameToColor["tomato4"]= 0x8b3626;
  m_NameToColor["turquoise"]= 0x40e0d0;
  m_NameToColor["turquoise1"]= 0x00f5ff;
  m_NameToColor["turquoise2"]= 0x00e5ee;
  m_NameToColor["turquoise3"]= 0x00c5cd;
  m_NameToColor["turquoise4"]= 0x00868b;
  m_NameToColor["violet"]= 0xee82ee;
  m_NameToColor["violet red"]= 0xd02090;
  m_NameToColor["wheat"]= 0xf5deb3;
  m_NameToColor["wheat1"]= 0xffe7ba;
  m_NameToColor["wheat2"]= 0xeed8ae;
  m_NameToColor["wheat3"]= 0xcdba96;
  m_NameToColor["wheat4"]= 0x8b7e66;
  m_NameToColor["white"]= 0xffffff;
  m_NameToColor["white smoke"]= 0xf5f5f5;
  m_NameToColor["yellow"]= 0xffff00;
  m_NameToColor["yellow green"]= 0x9acd32;
  m_NameToColor["yellow1"]= 0xffff00;
  m_NameToColor["yellow2"]= 0xeeee00;
  m_NameToColor["yellow3"]= 0xcdcd00;
  m_NameToColor["yellow4"]= 0x8b8b00;
}

QvivColor QvivX11Colors::LookupColor(const char *ColorName)
{
  if (!Instance)
    Instance = new QvivX11Colors();

  if (m_NameToColor.find(ColorName)!=m_NameToColor.end())
      return QvivColor(m_NameToColor[ColorName]<<8||0xff);

  // Return black as default
  return QvivColor(0xff);
}
